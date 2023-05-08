#pragma once
#include "Animal.h"
class Owl : public Animal {
public:
    Owl(std::string& name, Location& loc) : Animal(name, loc) {}


    char getInitial() const override {
        return 'O';
    }

    void step() override;
};


