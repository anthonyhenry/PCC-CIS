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
 * PURPOSE: Determine the route down a 2D pyramid of numbers that earns you the maximum amount of points
 * PARAMETERS: The getMaxPoints function takes a 2D vector of integers
 * RETURN VALUES: The getMaxPoints function returns the maximumn amount of points that can be earned in the given vector
 */
int CIS14::getMaxPoints(vector<vector<int>> &maze) {
    // Make sure the maze is not empty
    if (maze.size() == 0)
    {
        return 0;
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

    // The bottom row of the pyramid has the largest numbers, loop through to find which one is the max
    int maxPoints = 0;
    for (int i = 0; i < maze[maze.size() - 1].size(); i++)
    {
        cout << maze[maze.size() - 1][i] << " ";

        if(maze[maze.size() - 1][i] > maxPoints)
        {
            maxPoints = maze[maze.size() - 1][i];
        }
    }

    cout << endl;

    return maxPoints;
}

int main()
{
    // Instantiate an instance of the CIS14 class
    CIS14 cis14;    
    
    // Your target method will be tested as such, with random input
    // as the following example illustrates
    vector<vector<int>> maze = {{0}, {4,1}, {5,3,8}, {1,6,7,3}};
    cout << cis14.getMaxPoints(maze) << endl; // 16
    
    return 0;
}

/*
   0
  4 1
 5 3 8
1 6 7 3
*/