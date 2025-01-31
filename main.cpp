#include <iostream>
#include "headers/FiniteStateAutomaton.h"

using namespace std;


int main(){
    FiniteStateAutomaton fsa = FiniteStateAutomaton::getSimpleFSA();
    cout << fsa;
}
    