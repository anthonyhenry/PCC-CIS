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
    int n = maze.size();
    if (n == 0) {
        return 0; // Empty input, no points can be earned
    }

    // Iterate from the top row to the second-to-last row
    for (int row = 1; row < n; row++) {
        int m = maze[row].size();
        for (int col = 0; col < m; col++) {
            // Update the current cell with the maximum points by choosing the best path
            if (col == 0) {
                maze[row][col] += maze[row - 1][col];
            } else if (col == m - 1) {
                maze[row][col] += maze[row - 1][col - 1];
            } else {
                maze[row][col] += max(maze[row - 1][col - 1], maze[row - 1][col]);
            }
        }
    }

    // Find the maximum points in the last row (bottom row)
    int maxPoints = maze[n - 1][0];
    for (int col = 1; col < maze[n - 1].size(); col++) {
        maxPoints = max(maxPoints, maze[n - 1][col]);
    }

    return maxPoints;



    // int maxPoints = 0;

    // // cout << "Row 1 size: " << maze[1].size() << endl;








    // // int rows = maze.size();
    // // int cols = 1;
    // // int placeToBranch = maze.size() - 1;

    // // int X = 0;
    // // int Y = 0;
    // // int xToBranchAt = maze.size();

    // // while()

    // // while(Y < maze.size())
    // // {
    // //     while(X < maze.size())
    // //     {
    // //         cout << "(" << X << ", " << Y << "): ";
    // //         cout << maze[X][Y] << endl;
    // //         X++;
    // //     }
    // //     cout << "---" << endl;
    // //     X = 0;
    // //     Y++;
    // // }

    // int x = 0;
    // int y = 0;
    // // int startYChange = 3;

    // int beginYChangeAt = maze.size();
    // int numTimesToChangeY = 0;

    // int iterator = 0;

    // while(iterator < 8/*x != maze.size() && y != maze.size()*/)
    // {
    //     while(x < maze.size())
    //     {
    //         cout << "(" << x << ", " << y << "): " << maze[x][y] << endl;
    //         if(x == beginYChangeAt)
    //         {
    //             y++;
    //         }
    //         x++;
    //     }
    //     x=0;
    //     beginYChangeAt--;
    //     cout << "---" << endl;

    //     iterator++;
    // }


    // // cout << "---" << endl;

    // cout << maze[0][0] << maze[1][0] << maze[2][0] << maze[3][0] << endl;

    // cout << maze[0][0] << maze[1][0] << maze[2][0] << maze[3][1] << endl;
    // cout << maze[0][0] << maze[1][0] << maze[2][1] << maze[3][1] << endl;
    // cout << maze[0][0] << maze[1][1] << maze[2][1] << maze[3][1] << endl;
    

    // cout << maze[0][0] << maze[1][0] << maze[2][1] << maze[3][2] << endl;
    // cout << maze[0][0] << maze[1][1] << maze[2][1] << maze[3][2] << endl;
    
    // cout << maze[0][0] << maze[1][1] << maze[2][2] << maze[3][2] << endl;
    // cout << maze[0][0] << maze[1][1] << maze[2][2] << maze[3][3] << endl;

    // return maxPoints;
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