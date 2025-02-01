#pragma once

#include <string>
#include <ostream>

class State {
    std::string name;
    bool final, start;

public:
    State();

    State(std::string name, bool isFinal, bool isStart);

    std::string getName() const;

    bool isFinal() const;

    bool isStart() const;

    void setName(std::string name);

    void setFinal(bool isFinal);

    void setStart(bool isFinal);

    bool operator==(const State& other);

    friend std::ostream &operator<<(std::ostream &os, const State &state);
};
