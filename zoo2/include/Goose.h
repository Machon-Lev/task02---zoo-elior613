#pragma once
#include "Animal.h"
class Goose : public Animal {
private:
    int stepCount;  // Keep track of number of steps taken in current direction
    int direction;  // 0 = right, 1 = left
public:
    Goose(const std::string& name, const Location& loc) : Animal(name, loc), stepCount(0), direction(0) {}

    char getInitial() const override {
        return 'G';
    }

    void step() override;
};

