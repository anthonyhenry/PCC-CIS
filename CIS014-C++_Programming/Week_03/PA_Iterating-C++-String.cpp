#include <iostream>

using namespace std;

int main()
{
    string str = "C++ is fun!";

    cout << "First character: " << str[0] << endl;
    cout << "Exclamation character: " << str[str.length()-1] << endl;

    for(int i=0; i < str.length(); i++)
    {
        cout << "Character " << i << ":" << str[i] << endl;
    }

    return 0;
}