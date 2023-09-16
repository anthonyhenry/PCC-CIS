#include <iostream>

using namespace std;

int main()
{
    //For statement syntax
    for(int i=0; i<3; i++)
    {
        cout << "C++" << endl;
    }

    int j = 0;
    for(;j < 3; j++)
    {
        cout << "You can initialize a for variable outside the for loop" << endl;
    }

    int k = 0;
    for(; k < 3;)
    {
        cout << "Only the for condition is required in the for loop" << endl;
        k++;
    }

    return 0;
}