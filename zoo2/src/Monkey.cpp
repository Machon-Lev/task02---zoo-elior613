#include "Monkey.h"

void Monkey::step() {
    if (getIsMoving()) {
        turnsCount++;

        // Change the direction every five turns
        if (turnsCount % 5 == 0) {
            stepSize = rand() % 2 + 1; // Choose a new step size of 1 or 2
            direction = { rand() % 3 - 1, rand() % 3 - 1 }; // Choose a new random direction
        }

        // Calculate the new location
        Location newLoc;
        int row = getLocation().row;
        int col = getLocation().col;
        newLoc.row = row + (direction.row * stepSize);
        newLoc.col = col + (direction.col * stepSize);

        // Check if new location is within the board boundaries
        if (newLoc.row >= 0 && newLoc.row < 20 && newLoc.col >= 0 && newLoc.col < 40) {
            location = newLoc;
        }

        else {
            // If the new location is outside the board boundaries, stop moving and turn around
            stop();
            direction.row = -direction.row;
            direction.col = -direction.col;
        }
    }
}