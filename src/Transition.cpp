#include "Transition.h"

#include <utility>

Transition::Transition(State start, State end, std::string symbol)
        : start(std::move(start)), end(std::move(end)), symbol(std::move(symbol)) {}

State Transition::getStartState() {
    return start;
}

State Transition::getEndState() {
    return end;
}

std::string Transition::getSymbol() {
    return symbol;
}

void Transition::setStartState(State state) {
    start = std::move(state);
}

void Transition::setEndState(State state) {
    end = std::move(state);
}

void Transition::setSymbol(std::string symbol) {
    this->symbol = std::move(symbol);
}

bool Transition::operator==(Transition other) {
    return other.getStartState() == start && other.getEndState() == end && other.getSymbol() == symbol;
}

std::ostream &operator<<(std::ostream &os, const Transition &transition) {
    os << transition.start.getName() << "---" << transition.symbol << "--->" << transition.end.getName();
    return os;
}
