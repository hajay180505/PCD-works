
#include "FiniteStateAutomaton.h"
#include <iostream>
#include "utils.h"

FiniteStateAutomaton::FiniteStateAutomaton(const TransitionTable &transitionTable, const std::string &name) {
    this->name = name;
    this->finalState = Utils::getFinalState(transitionTable);
    this->startState = Utils::getStartState(transitionTable);
    this->states = Utils::getStates(transitionTable);
    this->transitionTable = transitionTable;
    this->symbols = Utils::getSymbols(transitionTable);

}

const std::vector<State> &FiniteStateAutomaton::getStates() const {
    return states;
}


const std::vector<std::string> &FiniteStateAutomaton::getSymbols() const {
    return symbols;
}


const TransitionTable &FiniteStateAutomaton::getTransitionTable() const {
    return transitionTable;
}

void FiniteStateAutomaton::setTransitionTable(const TransitionTable &transitionTable) {
    this->transitionTable = transitionTable;
    this->finalState = Utils::getFinalState(transitionTable);
    this->startState = Utils::getStartState(transitionTable);
    this->states = Utils::getStates(transitionTable);
    this->symbols = Utils::getSymbols(transitionTable);
}

const State &FiniteStateAutomaton::getStartState() const {
    return startState;
}

const std::vector<State> &FiniteStateAutomaton::getFinalState() const {
    return finalState;
}

std::ostream &operator<<(std::ostream &os, const FiniteStateAutomaton &fsa) {
    os << "Name : " << fsa.getName() << std::endl;
    os << "States :";
    for (auto state: fsa.getStates()) {
        os << state.getName() << " ";
    }
    os << std::endl << "Start state : " << fsa.getStartState().getName() << std::endl;
    os << "Final states : ";
    for (auto state: fsa.getFinalState()) {
        os << state.getName() << " " << std::endl;
    }
    os << std::endl << "Transitions :" << std::endl;
    for (auto transition: fsa.getTransitionTable().getTransitions()) {
        os << transition << std::endl;
    }

    return os;
}

const std::string &FiniteStateAutomaton::getName() const {
    return name;
}

void FiniteStateAutomaton::setName(const std::string &name) {
    this->name = name;
}

FiniteStateAutomaton FiniteStateAutomaton::getSimpleFSA() {

    // create states

    State A = State("0", false, true);
    State B = State("1", false, false);
    State C = State("2", false, false);
    State D = State("3", false, false);
    State E = State("4", false, false);
    State F = State("5", false, false);
    State G = State("6", false, false);
    State H = State("7", false, false);
    State I = State("8", false, false);
    State J = State("9", false, false);
    State K = State("10", true, false);

    // add transitions to transition table

    TransitionTable transitionTable;
    transitionTable.addTransition(Transition(A, B, "epsilon"));
    transitionTable.addTransition(Transition(B, C, "epsilon"));
    transitionTable.addTransition(Transition(B, E, "epsilon"));
    transitionTable.addTransition(Transition(A, H, "epsilon"));
    transitionTable.addTransition(Transition(C, D, "a"));
    transitionTable.addTransition(Transition(E, F, "b"));
    transitionTable.addTransition(Transition(D, G, "epsilon"));
    transitionTable.addTransition(Transition(F, G, "epsilon"));
    transitionTable.addTransition(Transition(G, B, "epsilon"));
    transitionTable.addTransition(Transition(G, H, "epsilon"));
    transitionTable.addTransition(Transition(H, I, "a"));
    transitionTable.addTransition(Transition(I, J, "b"));
    transitionTable.addTransition(Transition(J, K, "b"));

    FiniteStateAutomaton fsa = FiniteStateAutomaton(transitionTable, "M");
    return fsa;

}

