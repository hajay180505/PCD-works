#pragma once
#include "TransitionTable.h"
#include "State.h"
#include <vector>

class FiniteStateAutomaton{

private:
    std::string name;

    std::vector<State> states;
    std::vector<std::string> symbols;
    TransitionTable transitionTable;
    State startState;
    std::vector<State> finalState;
public:
//    FiniteStateAutomaton() = delete;
    explicit FiniteStateAutomaton(const TransitionTable &, const std::string&);
    const std::string &getName() const;

    const std::vector<State> &getStates() const;
    const std::vector<std::string> &getSymbols() const;
    const TransitionTable &getTransitionTable() const;
    const State &getStartState() const;
    const std::vector<State> &getFinalState() const;

    void setTransitionTable(const TransitionTable &);
    void setName(const std::string &name);

    friend std::ostream& operator<< (std::ostream& , const FiniteStateAutomaton&);

    static FiniteStateAutomaton getSimpleFSA();
};

