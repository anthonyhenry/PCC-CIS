#include <iostream>
#include <vector>

using namespace std;

class CIS14 {
public:
     int getMaxPoints(vector<vector<int>> &maze);
}; 

// ------------------------------------------------------------
// DO NOT MODIFY ABOVE THIS LINE. The above is your C++ class 
// named CIS14 with a method called getMaxPoints(...) you will
// implement
// ------------------------------------------------------------

/**
 * PURPOSE:
 * PARAMETERS:
 * RETURN VALUES:
 */
int CIS14::getMaxPoints(vector<vector<int>> &maze) {
    if (maze.size() == 0) {
        return 0; // Empty input, no points can be earned
    }

    //Start at row 2 (maze[1]) and work down the pyramid comparing with the numbers above to see which results in a higher number
    for(int row = 1; row < maze.size(); row++)
    {
        for(int col = 0; col < maze[row].size(); col++)
        {
            cout << "Previous: " << maze[row][col] << " | ";

            // For the first column, can only add with the number in the column immediately above 
            if(col == 0)
            {
                maze[row][col] += maze[row - 1][col];
            }
            // For the last column in a row, can only add with the number in the previous column of the row above
            else if (col == maze[row].size() - 1)
            {
                maze[row][col] += maze[row - 1][col - 1];
            }
            // For all other columns, need to check which previous number is larger and add with that number
            else
            {
                // Conditional operator to only add the larger number
                maze[row][col] += (maze[row - 1][col] > maze[row - 1][col - 1]) ? maze[row - 1][col] : maze[row - 1][col - 1];

                // This does the same as above but in more lines of code
                // if(maze[row - 1][col] > maze[row - 1][col - 1])
                // {
                //     maze[row][col] += maze[row - 1][col];
                // }
                // else
                // {
                //     maze[row][col] += maze[row - 1][col - 1];
                // }
            }
            cout << "Row: " << row << " | Col: " << col << " | New: " << maze[row][col] << endl;
        }
    }

    // Find the maximum points in the last row (bottom row)
    int maxPoints = maze[maze.size() - 1][0];

    cout << "maxPoints" << endl;

    for (int col = 1; col < maze[maze.size() - 1].size(); col++) {
        maxPoints = max(maxPoints, maze[maze.size() - 1][col]);
    }

    return maxPoints;
}

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;    
    
    // Your target method will be tested as such, with random input
    // as the following example illustrates
    vector<vector<int>> /*maze = {{0}, {4,1}, {5,3,8}, {1,6,7,3}};*/maze = {{1}, {1,22305}, {1,29394,1}, {1,1,1234,1}, {1,1,3,1,10}}; // output = 52937



    cout << cis14.getMaxPoints(maze) << endl; // 16
    
    return 0;
}

/*
   0
  4 1
 5 3 8
1 6 7 3
*/