#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Zoo.h"

int main() {
    srand(time(nullptr));
    Zoo zoo;
    zoo.run();

    return 0;
}
