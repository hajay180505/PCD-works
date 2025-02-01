#include "TransitionTable.h"

bool TransitionTable::addTransition(const Transition &transition) {
    if (std::find(transitions.begin(), transitions.end(), transition) == transitions.end()) {
        transitions.push_back(transition);
        return true;
    }
    return false;
}

std::vector<Transition> TransitionTable::getTransitionsFromStart(State start) {
    std::vector<Transition> ans;
    for (auto transition: transitions) {
        if (transition.getStartState() == start) {
            ans.push_back(transition);
        }
    }
    return ans;
}

std::vector<State> TransitionTable::getEndStates(State start, std::string symbol) const {
    std::vector<State> ans;
    for (auto transition: transitions) {
        if (transition.getStartState() == start && transition.getSymbol() == symbol) {
            ans.push_back(transition.getEndState());
        }
    }
    return ans;

}

std::vector<Transition> TransitionTable::getTransitionsFromSymbol(std::string symbol) {
    std::vector<Transition> ans;
    for (auto transition: transitions) {
        if (transition.getSymbol() == symbol) {
            ans.push_back(transition);
        }
    }
    return ans;
}

TransitionTable::TransitionTable(std::vector<Transition> transitions) {
    this->transitions = transitions;
}


TransitionTable::TransitionTable() {
}

const std::vector<Transition> &TransitionTable::getTransitions() const {
    return transitions;
}

std::ostream &operator<<(std::ostream &os, const TransitionTable &table) {
    os << "Transitions: ";
    for (const auto &transition: table.transitions) {
        os << transition << std::endl;
    }
    return os;
}
