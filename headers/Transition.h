#pragma once
#include "State.h"
#include <algorithm>
#include <ostream>

class Transition{
    State start;
    State end;
    std::string symbol;
  public:
    Transition(State start, State end, std::string symbol);

    State getStartState();
    State getEndState();
    std::string getSymbol();

    void setStartState(State state);
    void setEndState(State state);
    void setSymbol(std::string symbol);

    bool operator==(Transition other);

    friend std::ostream &operator<<(std::ostream &os, const Transition &transition);

};
