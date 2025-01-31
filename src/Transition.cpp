#include "Transition.h"

Transition::Transition(State start, State end, std::string symbol)
    : start(start), end(end), symbol(symbol) {}

State Transition::getStartState() {
  return start;
}
State Transition::getEndState() {
  return end;
 }
std::string Transition::getSymbol() {
  return symbol;
 }
void Transition::setStartState(State state){
  start = state;
}
void Transition::setEndState(State state){
  end = state;
}
void Transition::setSymbol(std::string symbol){
  this->symbol = symbol;
}

bool Transition::operator==(Transition other) {
    return other.getStartState() == start && other.getEndState() == end && other.getSymbol() == symbol;
}

std::ostream &operator<<(std::ostream &os, const Transition &transition) {
    os << transition.start.getName() << "---" << transition.symbol << "--->" << transition.end.getName();
    return os;
}
