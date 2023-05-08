#pragma once
#include "Animal.h"
#include "Goose.h"
#include "Lion.h"
#include "Monkey.h"
#include "Owl.h"


class Zoo {
private:
    std::vector<Animal*> animals;


    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }

    void move(int index);
    void stop(int index);

    void printAnimals() const;


        // create a new animal and add it to the list
    void create(std::string type, std::string name);

        // delete an animal from the list
    void del(int index);

        // delete all animals of a certain type from the list
    void delAll(std::string type);

        // print a help text explaining the possible commands
    void help();

        // advance the program to the next line
    void dot();


public:
    void run();
    Zoo() {
        // Create initial animals
        create("Lion", "Simba");
        create("Lion", "Mufasa");
        create("Monkey", "Rafiki");
        create("Goose", "Akka");
        create("Goose", "Morten");
        create("Owl", "Hedwig");
    }


    ~Zoo() {
        for (auto& animal : animals) {
            delete animal;
        }
    } 
};

