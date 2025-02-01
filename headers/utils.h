#pragma once

#include "State.h"
#include "TransitionTable.h"
#include <vector>
#include <optional>

class Utils {
public:
    static std::vector<State> epsilonClosure(const std::vector<State>&, const TransitionTable&, const std::string& epsilon = EPSILON);

    static std::vector<State> epsilonClosure(const State&, const TransitionTable&, const std::string& epsilon = EPSILON);

    static State getStartState(const TransitionTable &);

    static std::vector<State> getFinalState(const TransitionTable &);

    static std::vector<State> getStates(const TransitionTable &);

    static std::vector<std::string> getSymbols(const TransitionTable &);

    static std::optional<State> getStateByName(const std::vector<State>&, std::string);

};
