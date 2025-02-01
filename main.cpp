#include <iostream>
#include "headers/FiniteStateAutomaton.h"
#include "headers/utils.h"

using namespace std;


int main() {
    FiniteStateAutomaton fsa = FiniteStateAutomaton::getSimpleFSA();
    cout << fsa;
    vector<State> s;
    s.push_back(fsa.getStartState());

    cout << "Epsilon closure of " << fsa.getStartState() << ": ";
    for (const auto &state: Utils::epsilonClosure(s, fsa.getTransitionTable())) {
        cout << state << " ";
    }

    cout << endl;

}
    