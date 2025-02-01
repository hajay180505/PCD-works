#include "State.h"

State::State(std::string name, bool isFinal, bool isStart) : name(name), final(isFinal), start(isStart) {}

std::string State::getName() const {
    return name;
}

void State::setName(std::string name) {
    this->name = name;
}

bool State::operator==(State other) {
    return (other.name == name) &&
           (other.final == final) &&
           (other.start == start);
}

bool State::isFinal() const {
    return final;
}

void State::setFinal(bool isFinal) {
    this->final = isFinal;
}

bool State::isStart() const {
    return start;
}

void State::setStart(bool isStart) {
    this->start = isStart;
}

State::State() {

}

std::ostream &operator<<(std::ostream &os, const State &state) {
    os << state.name;
    if (state.start) {
        os << "(START)";
    }
    if (state.final) {
        os << "(FINAL)";
    }

    return os;
}
