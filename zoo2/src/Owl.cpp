#include "Owl.h"

void Owl::step() {
    // Get the current location of the owl
    Location loc = getLocation();
    int row = loc.row;
    int col = loc.col;

    // Determine the offset for the next row and column
    // based on whether the current row and column are even or odd
    int rowOffset = (row % 2 == 0) ? 1 : -1;
    int colOffset = (col % 2 == 0) ? 1 : -1;

    // Calculate the new row and column based on the current row and offset
    // and the specific pattern the owl follows

    // If the remainder of row divided by 6 is 0 or 1, move the owl 3 rows in the direction indicated by the row offset
    if (row % 6 == 0 || row % 6 == 1) {
        row += rowOffset * 3;
    }
    // If the remainder of row divided by 6 is 2 or 3, move the owl 2 rows and 2 columns in the direction indicated by the row and column offsets
    else if (row % 6 == 2 || row % 6 == 3) {
        row += rowOffset * 2;
        col += colOffset * 2;
    }
    // Otherwise (remainder of row divided by 6 is 4 or 5), move the owl 1 row and 3 columns in the direction indicated by the row and column offsets
    else {
        row += rowOffset;
        col += colOffset * 3;
    }

    // Check if the new location is within the board bounds
    if (row >= 0 && row < 20 && col >= 0 && col < 40) {
        // If it is, set the owl's location to the new location
        location = Location(row, col);
    }
    else {
        // If it isn't, go back to the previous location
       // by subtracting the row and column offsets from the current location
        int prevRow = row - rowOffset;
        int prevCol = col - colOffset;
        location = Location(prevRow, prevCol);
    }
}