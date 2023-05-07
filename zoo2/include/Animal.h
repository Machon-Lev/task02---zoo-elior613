#pragma once
#include <iostream>
#include <vector>
#include <string>

struct Location {
    int row;
    int col;

    Location(int r = 0, int c = 0) : row(r), col(c) {}

    friend std::ostream& operator<<(std::ostream& os, const Location& loc) {
        os << "(" << loc.row << "," << loc.col << ")";
        return os;
    }

    Location operator+(const Location& other) const {
        return Location(row + other.row, col + other.col);
    }

    bool operator==(const Location& other) const {
        return row == other.row && col == other.col;
    }

    bool operator!=(const Location& other) const {
        return !(*this == other);
    }

};

class Animal {
protected:
    std::string name;
    Location location;
    bool isMoving;
    bool forward;

public:
    Animal(const std::string& name, const Location& loc)
        : name(name), location(loc), isMoving(false) {}

    virtual ~Animal() = default;
    Animal(const Animal& other) = default;
    Animal& operator=(const Animal& other) = default;

    virtual char getInitial() const = 0;
    virtual void step() = 0;

    virtual void printDetails() const {
        std::cout << "Name: " << name << ", Type: " << typeid(*this).name() << ", Location: " << location << std::endl;
    }

    bool getIsMoving() {
        return this->isMoving;
    }

    Location getLocation() const {
        return location;
    }

    // stop the animal from moving
    void stop() {
        
            this->isMoving = false;
        }

    // move the animal and reset its direction
    void move() {
        this->isMoving = true;
    }

    void turnVertically() {
        location.row = -location.row;
    }

    void turnHorizontally() {
        location.col = -location.col;
    }

    bool getIsMoving() const {
        return isMoving;
    }
};
