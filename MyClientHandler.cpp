//
// Created by oriya on 1/3/19.
//

#include "MyClientHandler.h"
#include "SolverSearcher.h"
#include "MatrixBuilder.h"
#include "MyString.h"
#include "Bfs.h"
#include "BestFirstSearch.h"
#include "A_Star.h"
#include <iostream>
#include <sys/types.h>
#include <algorithm>
#include <unistd.h>
#include <list>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <iostream>

#include <netinet/in.h>


using namespace std;
#define END "end"


MyClientHandler::MyClientHandler(CacheManager<Stringable, Stringable> *cacheManager) {
    this->cacheManager = cacheManager;
}


void MyClientHandler::handleClient(int new_socket) {
    char buffer[5000];
    int erez = 0;
    int natalie = 0;
    string str;
    //reads from client as long as input is not stop
    string buff;
    string check;
    while (str != END) {
        bzero(buffer, sizeof(str));
        erez = read(new_socket, buffer, 5000);

        if (erez < 0) {
            //perror("cannot read from client");
            break;
        }
        buff += buffer;
        str = buffer;
        if (buff.find(END) != string::npos) {
            buff = buff.substr(0, buff.find('e'));
            str = END;
        }
    }
    string *shortest_path = &solveProblem(buff);
    const char *ret = shortest_path->c_str();

    send(new_socket, ret, shortest_path->size(), 0);
    delete (shortest_path);

    close(new_socket);
}

Solver<Searchable<Point> *, Stringable *> *MyClientHandler::getSolver() const {
    return solver;
}

void MyClientHandler::setSolver(Solver<Searchable<Point> *, Stringable *> *solver) {
    this->solver = solver;
}

CacheManager<Stringable, Stringable> *MyClientHandler::getCacheManager() const {
    return cacheManager;
}

void MyClientHandler::setCacheManager(CacheManager<Stringable, Stringable> *cacheManager) {
    MyClientHandler::cacheManager = cacheManager;
}

string &MyClientHandler::solveProblem(string &problem) {
    Stringable *str = new MyString(problem);
    if (this->getCacheManager()->isProblemExist(str)) {
        Stringable *temp = this->getCacheManager()->search(str);
        string *str1 = new string(temp->toString());
        delete (temp);
        delete (str);
        return *str1;

    }
    string *solution;
    Searchable<Point> *searchable = cast_to_matrix(problem);
    Searcher<Point> *bfs = new A_Star<Point>();
    this->solver = new SolverSearcher(bfs);
    Stringable *str_able = this->solver->solve(searchable);
    string b = str_able->toString();
    reverse(b.begin(), b.end());
    solution = new string(b);
    this->cacheManager->save(str, str_able);
    delete (str);
    delete (str_able);
    delete (searchable);
    delete (bfs);
    return *solution;
}

Searchable<Point> *MyClientHandler::cast_to_matrix(string &problem) {
    vector<string> problem_lines;
    string my_problem = string(problem);
    vector<string> sep_lines;
    std::string delimiter = "\n";

    size_t pos = 0;
    std::string token;
    while ((pos = my_problem.find(delimiter)) != std::string::npos) {
        token = my_problem.substr(0, pos);
        sep_lines.push_back(token);
        //std::cout << token << std::endl;
        my_problem.erase(0, pos + delimiter.length());
    }
    vector<string>::iterator begin = sep_lines.begin();
    vector<string>::iterator end = sep_lines.end();
    end--;
    end--;
    vector<string> matrix_lines(begin, end);
    vector<vector<double>> num_matrix = cast_to_num_matrix(matrix_lines);
    Point *init;
    init = lexer_point(sep_lines.at(sep_lines.size() - 2));
    Point *goal;
    goal = lexer_point(sep_lines.at(sep_lines.size() - 1));
    MatrixBuilder builder;
    SearchableMatrix *searrchable_matrix = builder.create(&num_matrix, init, goal);
    return searrchable_matrix;
}

vector<vector<double>> &MyClientHandler::cast_to_num_matrix(vector<string> &matrix_lines) {
    vector<vector<double>> *victor = new vector<vector<double>>();
    vector<double> mini_victor;
    std::string delimiter = ",";

    size_t pos = 0;
    std::string token;
    for (string line:matrix_lines) {
        mini_victor.clear();
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            mini_victor.push_back(stod(token));
            //std::cout << token << std::endl;
            line.erase(0, pos + delimiter.length());
        }
        mini_victor.push_back(stod(line));
        victor->push_back(mini_victor);
    }
    return *victor;
}

Point *MyClientHandler::lexer_point(string &str) {
    int i = stoi(str.substr(0, str.find(',')));
    int j = stoi(str.substr(str.find(',') + 1));
    Point *p = new Point(i, j);
    return p;
}
