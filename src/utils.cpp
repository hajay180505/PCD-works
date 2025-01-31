#include "utils.h"
#include <stack>
#include <algorithm>
#include <stdexcept>

std::vector<State> Utils::epsilonClosure(std::vector<State> T) {
    std::stack<State> stackOfStates;
    for (const auto& state : T){
        stackOfStates.push(state);
    }

    std::vector<State> ans;
    for (const auto& state : T){
        ans.push_back(state);
    }


    while(! stackOfStates.empty()){
        auto s = stackOfStates.top();
        stackOfStates.pop();
        TransitionTable transition;
        auto curr = transition.getEndStates(s, "epsilon" ) ;
        for(const auto& state : curr){
            if(std::find(ans.begin(), ans.end(), state) != ans.end()){
                stackOfStates.push(state);
                ans.push_back(state);
            }
        }
    }
    return ans;
}

State Utils::getStartState(const TransitionTable& transitionTable) {
    for(auto state : getStates(transitionTable)) {
        if (state.isStart()) {
            return state;
        }
    }
    throw std::runtime_error("No start state");
}

std::vector<State> Utils::getFinalState(const TransitionTable& transitionTable) {
    std::vector<State> ans;
    for(auto state : getStates(transitionTable)){
        if(state.isFinal()){
            ans.push_back(state);
        }
    }
    return ans;
}

std::vector<State> Utils::getStates(const TransitionTable & transitionTable) {
    std::vector<State> ans;
    for (auto transition : transitionTable.getTransitions()) {
        auto start = transition.getStartState();
        auto end = transition.getEndState();
        if (std::find(ans.begin(), ans.end(), start) != ans.end()) {
            ans.push_back(start);
        }
        if (std::find(ans.begin(), ans.end(), end) != ans.end()) {
            ans.push_back(end);
        }
    }
    return ans;
}

std::vector<std::string> Utils::getSymbols(const TransitionTable & transitionTable) {
    std::vector<std::string> ans;
    for (auto transition : transitionTable.getTransitions()) {
        if (std::find(ans.begin(), ans.end(), transition.getSymbol()) != ans.end()) {
            ans.push_back(transition.getSymbol());
        }
    }
    return ans;
}

std::optional<State> Utils::getStateByName(std::vector<State> states, std::string name) {
    for(auto state : states){
        if(state.getName() == name) return state;
    }
    return {};
}

