#include <iostream>
using namespace std;

// API DOCUMENTATION BELOW. PLEASE FILL THE FOLLOWING API PRIOR TO CODING
/**
 * PURPOSE: The canAlwaysWin function analyzes whether given any number of pebbles greater than 0, that there is 100% certainty that you can win the pebble game.
 * PARAMETER: The function canAlwaysWin takes an integer grater than 0 representing the number of pebbles remainig in the game
 * RETURN VALUE: canAlwaysWin returns true if you are able to win the pebble game with the integer count provided, false if you are unable to win
*/ 

bool canAlwaysWin(int n) {
    //If the number of pebbles remaining is a multiple of 7 you cannot win
    if(n % 7 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main() {
    //Replace the argument here to test ability to win with any number of pebbles
    canAlwaysWin(23034);
    
    return 0;
}