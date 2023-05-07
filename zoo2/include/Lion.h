#pragma once
#include "Animal.h"
class Lion : public Animal {
public:
    Lion(const std::string& name, const Location& loc)
        : Animal(name, loc) {}

    char getInitial() const override {
        return 'L';
    }
    void step() override;

};