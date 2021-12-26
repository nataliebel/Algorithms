//
// Created by oriya on 1/9/19.
//

#ifndef UNTITLED9_STATE_H
#define UNTITLED9_STATE_H

template<class T>
class State {
    // the state represented by a string
    T *state;
    // cost to reach this state (set by a setter)
    double cost;
    // the state we came from to this state (setter)
    State<T> *cameFrom;
    double sumOfVertex;
    double fHeuristics;
public:
    State(T *stet, double cost) {
        this->state = stet;
        this->cost = cost;
        this->cameFrom = nullptr;
        this->sumOfVertex = 0;
    }

//    State(State<T> &s) {
//        this->state = s.getState();
//        this->cost = s.getCost();
//        this->sumOfVertex = s.getSumOfVertex();
//        this->cameFrom = new State(s.getCameFrom());
//    }

    T *getState() const {
        return state;
    }

    void setState(T *state) {
        State::state = state;
    }

    double getCost() const {
        return cost;
    }

    void setCost(double cost) {
        State::cost = cost;
    }

    State<T> *getCameFrom() const {
        return cameFrom;
    }

    void setCameFrom(State<T> *cameFrom) {
        this->cameFrom = cameFrom;
    }

    double getSumOfVertex() const {
        return sumOfVertex;
    }

    void setSumOfVertex(double sumOfVertex) {
        State::sumOfVertex = sumOfVertex;
    }

    // we overload Object's Equals method
    bool ifIsEquals(State<T> *s) {
        return (*this->state == *s->state);
    }

    void setFHeuristics(double f) {
        this->fHeuristics = f;
    }

    double getFHeuristics() {
        return fHeuristics;
    }

    ~State() {

    }
};

#endif //UNTITLED9_STATE_H
