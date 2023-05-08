#include "Goose.h"

void Goose::step() {
        if (getIsMoving()) {
            int row = getLocation().row;
            int col = getLocation().col;

            // Determine direction of next step
            int rowOffset = (stepCount % 2 == 0) ? 0 : ((direction == 0) ? 1 : -1);
            int colOffset = (direction == 0) ? 1 : -1;

            // Check if next step is within board boundaries
            if (col + colOffset >= 0 && col + colOffset < 40 && row + rowOffset >= 0 && row + rowOffset < 20) {
                row += rowOffset;
                col += colOffset;
                stepCount++;
            }
            else {  // Change direction if next step would go out of bounds
                direction = (direction == 0) ? 1 : 0;
                rowOffset = (stepCount % 2 == 0) ? 0 : ((direction == 0) ? 1 : -1);
                colOffset = (direction == 0) ? 1 : -1;
                row += rowOffset;
                col += colOffset;
                stepCount++;
            }

            location.row = row;
            location.col = col;
        }
}