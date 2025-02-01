#pragma once

#include "Transition.h"
#include <vector>
#include <ostream>

class TransitionTable {
    std::vector<Transition> transitions;
public:
    TransitionTable();

    explicit TransitionTable(std::vector<Transition> transitions);

    bool addTransition(const Transition &transition);

    std::vector<Transition> getTransitionsFromStart(const State& start);

    std::vector<State> getEndStates(const State& start, const std::string& symbol) const;

    std::vector<Transition> getTransitionsFromSymbol(const std::string& symbol);

    const std::vector<Transition> &getTransitions() const;


    friend std::ostream &operator<<(std::ostream &os, const TransitionTable &table);
};