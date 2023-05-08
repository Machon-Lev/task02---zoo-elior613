#pragma once
#include "Animal.h"
class Monkey : public Animal {
private:
    int turnsCount; // Counter for the number of turns since the last direction change
    int stepSize; // Size of the step the monkey takes (1 or 2)
    Location direction; // Direction of the monkey's movement

public:
    Monkey(const std::string& name, const Location& loc)
        : Animal(name, loc), turnsCount(0), stepSize(1), direction({ 0, 0 }) {}

    char getInitial() const override {
        return 'M';
    }

    void step() override;
};


