#pragma once
#include "Lion.h"

    void Lion::step()  {
        if (getIsMoving()) { // if the Lion is currently moving
            int row = getLocation().row; // get the current row of the Lion's location
            int col = getLocation().col; // get the current column of the Lion's location
            if (row % 4 == 0 || row % 4 == 1) { // if the current row is a multiple of 4 or 1 more than a multiple of 4
                if (col + 2 < 40) { // if moving 2 columns to the right won't go off the board
                    col += 2; // move 2 columns to the right
                }
                else { // if moving 2 columns to the right would go off the board
                    col = 38 - (col + 2 - 40); // wrap around to the left side of the board
                    turnHorizontally(); // turn the Lion horizontally
                }
            }
            else { // if the current row is 2 more than a multiple of 4 or 3 more than a multiple of 4
                if (col - 2 >= 0) { // if moving 2 columns to the left won't go off the board
                    col -= 2; // move 2 columns to the left
                }
                else { // if moving 2 columns to the left would go off the board
                    col = 2 - col; // wrap around to the right side of the board
                    turnHorizontally(); // turn the Lion horizontally
                }
            }
            location.col = col; // update the Lion's location with the new column value
        }
    }
 

