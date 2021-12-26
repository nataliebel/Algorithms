//
// Created by oriya on 1/15/19.
//
//
// Created by natalie on 1/14/19.
//

#ifndef UNTITLED9_A_STAR_H
#define UNTITLED9_A_STAR_H

#define WALL "-1"

#include "State.h"
#include "Searcher.h"
#include "Searchable.h"
#include "Point.h"
#include "MyString.h"
#include <queue>

template<class T>
class A_Star : public Searcher<T> {
    class CompState {
    public:
        bool operator()(State<T> *first, State<T> *second) {
            return (first->getFHeuristics() > second->getFHeuristics());
        }
    };
    int counter=0;
    Searchable<T> *searchable;
public:
    bool insideOpen(State<T> *state, priority_queue<State<T> *, vector<State<T> *>, CompState> openPriorityQueue) {
        while (!openPriorityQueue.empty()) {
            if (state->ifIsEquals(openPriorityQueue.top())) {
                return true;
            }
            openPriorityQueue.pop();
        }
        return false;
    }

    bool insideClosed(State<T> *state, vector<State<T> *> closed) {
        for (State<T> *s : closed) {
            if (state->ifIsEquals(s)) {
                return true;
            }
        }
        return false;
    }

    double calFHeuristics(State<T> *state, State<T> *destination) {
        double f, h, g;
        h = abs(state->getState()->getI() - destination->getState()->getI()) +
            abs(state->getState()->getJ() - destination->getState()->getJ());
        g = state->getCost();
        f = g+h;
        return f;
    }

    virtual Stringable *search(Searchable<T> *searchable) {
        //open a priority queue of states to be evaluated
        //little to big
        this->searchable=searchable;
        priority_queue<State<T> *, vector<State<T> *>, CompState> openPriorityQueue;
        openPriorityQueue.push(searchable->getInitialState());
        searchable->getInitialState()->setFHeuristics(0);
        //close a set of states already evaluated
        vector<State<T> *> closed;
        vector<State<T> *> neighbors;
        //Up, Down, Left, Right
        string theSolution = "";
        while (openPriorityQueue.size() != 0) {
            // Remove the best node from OPEN
            State<T> *node = openPriorityQueue.top();
            //if is wall
            if (node->ifIsEquals(searchable->getInitialState()) && (node->getCost()) == (-1)) {
                theSolution = "-1";
                Stringable *str = new MyString(theSolution);
                return str;
            }
            closed.push_back(node);
            openPriorityQueue.pop();
            counter++;
            // if node is the goal state
            if (node->ifIsEquals(searchable->getGoalState())) {
                vector<State<T> *> path;
                path.push_back(node);
                while (!(node->ifIsEquals(searchable->getInitialState()))) {
                    node = node->getCameFrom();
                    path.push_back(node);
                }
                theSolution = node->getState()->getPath(path);
                Stringable *str = new MyString(theSolution);
                return str;
            } else {
                neighbors = searchable->getAllPossibleStates(*node);
                for (State<T> *neighbor : neighbors) {
                    if (!(insideOpen(neighbor, openPriorityQueue)) && !(insideClosed(neighbor, closed))) {
                        neighbor->setCameFrom(node);
                        neighbor->setCost(neighbor->getCost() + node->getCost());
                        neighbor->setFHeuristics(calFHeuristics(neighbor, searchable->getGoalState()));
                        openPriorityQueue.push(neighbor);
                    } else if ((neighbor->getCameFrom() != nullptr) &&
                               (neighbor->getCost() >
                                (neighbor->getCost() - neighbor->getCameFrom()->getCost() + node->getCost()))) {
                        if (insideClosed(neighbor, closed)) {
                        } else {
                            neighbor->setCost(
                                    neighbor->getCost() - neighbor->getCameFrom()->getCost() + node->getCost());
                            neighbor->setFHeuristics(calFHeuristics(neighbor, searchable->getGoalState()));
                            neighbor->setCameFrom(node);
                            openPriorityQueue = updateOpenQueue(openPriorityQueue);
                        }
                    }
                }
            }
        }
        theSolution = WALL;
        Stringable *str = new MyString(theSolution);
        return str;
    }

    priority_queue<State<T> *, vector<State<T> *>, CompState>
    updateOpenQueue(priority_queue<State<T> *, vector<State<T> *>, CompState> &openPriorityQueu) {
        priority_queue<State<T> *, vector<State<T> *>, CompState> result;
        while (!openPriorityQueu.empty()) {
            State<T> *node = openPriorityQueu.top();
            result.push(node);
            openPriorityQueu.pop();
        }
        return result;
    }

    int getCostOfNodesEvaluated() override {
        int cost = 0;
        State<Point> *goal = this->searchable->getGoalState();
//        State<Point> *node = goal;
//        while (node != NULL) {
//            cost += node->getCost();
//            node = node->getCameFrom();
//        }
        return goal->getCost();
    }

    int getNumberOfNodesEvaluated() override;
};

template<class T>
int A_Star<T>::getNumberOfNodesEvaluated() {
    return this->counter;
}

#endif //UNTITLED9_A_STAR_H