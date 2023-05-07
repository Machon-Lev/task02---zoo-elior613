#include "Zoo.h"

void Zoo::printAnimals() const {
    // Print the map
    std::cout << "Map:" << std::endl;
    for (int row = 0; row < 20; ++row) {
        for (int col = 0; col < 40; ++col) {
            bool animalPresent = false;
            char animalSymbol = ' ';

            // Check if an animal is present at the current location
            for (const auto& animal : animals) {
                if (animal->getLocation().row == row && animal->getLocation().col == col) {
                    animalPresent = true;
                    animalSymbol = animal->getInitial(); // Get the first character of the animal's name
                    break;
                }
            }

            std::cout << animalSymbol ;
        }
        std::cout << std::endl;

    }
    // Print the list of animals
    for (const auto& animal : animals) {
        animal->printDetails();
    }
}

void Zoo:: stop(int index) {
    if (index >= 0 && index < animals.size()) {
        animals[index]->stop();
        std::cout << "Animal " << index + 1 << " stopped." << std::endl;
    }
    else {
        std::cout << "Invalid animal index." << std::endl;
    }
}

void Zoo::move(int index) {
    if (index >= 0 && index < animals.size()) {
        animals[index]->move();
        std::cout << "Animal " << index + 1 << " moved." << std::endl;
    }
    else {
        std::cout << "Invalid animal index." << std::endl;
    }
}

// create a new animal and add it to the list
void Zoo::create(std::string type, std::string name) {
    Location loc(rand() % 20, rand() % 40);
    Animal* animal = nullptr;
    if (type != "Owl" && type != "Lion" && type != "Monkey" && type != "Goose") {
        std::cout << "Invalid animal name." << std::endl;
        return;
    }
    else if (type == "Owl") {
        animal = new Owl(name, loc);
    }
    else if (type == "Lion") {
        animal = new Lion(name, loc);
    }
    else if (type == "Monkey") {
        animal = new Monkey(name, loc);
    }
    else if (type == "Goose") {
        animal = new Goose(name, loc);
    }
    if (animal != nullptr) {
        animals.push_back(animal);
    }
}

// delete an animal from the list
void Zoo::del(int index) {
    if (index >= 0 && index < animals.size()) {
        delete animals[index];
        animals.erase(animals.begin() + index);
    }
}

// delete all animals of a certain type from the list
void Zoo::delAll(std::string type) {
    for (auto it = animals.begin(); it != animals.end();) {
        Animal* animal = *it;
        if (type != "Owl" && type != "Lion" && type != "Monkey" && type != "Goose") {
            std::cout << "Invalid animal name." << std::endl;
            break;
        }

        else if (type == "Owl" && dynamic_cast<Owl*>(animal) != nullptr) {
            it = animals.erase(it);
            delete animal;
        }
        else if (type == "Lion" && dynamic_cast<Lion*>(animal) != nullptr) {
            it = animals.erase(it);
            delete animal;
        }
        else if (type == "Monkey" && dynamic_cast<Monkey*>(animal) != nullptr) {
            it = animals.erase(it);
            delete animal;
        }
        else if (type == "Goose" && dynamic_cast<Goose*>(animal) != nullptr) {
            it = animals.erase(it);
            delete animal;
        }
        else {
            ++it;
        }
    }
}

// print a help text explaining the possible commands
void Zoo::help() {
    std::cout << "Possible commands:\n"
        << "create type name - create a new animal\n"
        << "stop index- Make the animal at the specified index stop moving.\n" 
        << "move index- Make the animal at the specified index start moving again.\n"
        << "del index - delete an animal\n"
        << "delAll type - delete all animals of a certain type\n"
        << "help - show this help text\n"
        << "exit - exit the program\n"
        << ". - advance the program to the next line\n";
}

// advance the program to the next line
void Zoo:: dot() {
    for (Animal* animal : animals) {
        if (animal->getIsMoving()) {
            animal->step();
        }
    }
}

void Zoo::run(){
    std::string command;
    printAnimals();
    while (command != "exit") {
        std::cout << "Enter a command: ";
        std::cin >> command;
        if (command == "stop") {
            int index;
            std::cin >> index;
            stop(index - 1);
            printAnimals();
        }
        else if (command == "move") {
            int index;
            std::cin >> index;
            move(index - 1);
            printAnimals();
        }
        else if (command == "create") {
            std::string type, name;
            std::cin >> type >> name;
            create(type, name);
            printAnimals();
        }
        else if (command == "del") {
            int index;
            std::cin >> index;
            del(index);
            printAnimals();
        }
        else if (command == "delAll") {
            std::string type;
            std::cin >> type;
            delAll(type);
            printAnimals();
        }
        else if (command == "help") {
            help();
        }
        else if (command == ".") {
            dot();
            printAnimals();
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Invalid command! Type 'help' for a list of available commands." << std::endl;
        }
    }
}
