#pragma once
#include <string>
class State
{
    std::string name;
    bool final, start;

public:
    State();
    State(std::string name, bool isFinal, bool isStart);

    std::string getName() const;
    bool isFinal();
    bool isStart();

    void setName(std::string name);
    void setFinal(bool isFinal);
    void setStart(bool isFinal);

    bool operator==(State other);
};
