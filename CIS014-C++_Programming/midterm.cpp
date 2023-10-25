#include <iostream>
#include <cstring>

using namespace std;

void question1()
{
    int a = 2;
    int k = 10;
    while( k >= 1 )
    {
        a = a * k;
        k--;
        cout << a << endl;
    }

    cout << "---" << endl;

    a = 2;
    // k = 10;
    for(int k = 10; k >= 1; k--)
    {
        a = a * k;
        cout << a << endl;
    }
}

void question7()
{
    // char* a = "C++";
    // cout << "a: " << strlen(a) << endl;

    char c[20] = "C++";
    cout << "c: " << strlen(c) << endl;

    char d[20] = {'C', '+', '+', '\0'};
    cout << "d: " << strlen(d) << endl;

    char e[20];
    cout << "e: " << strlen(e) << endl;

    char g[20] = "";
    cout << "g: " << strlen(g) << endl;
}

void question8()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(i % 2 == 0)
            {
                if(j % 2 == 0)
                {
                    cout << "#";       
                }
                else
                {
                    cout << "_";
                }
            }
            else
            {
                if(j % 2 == 0)
                {
                    cout << "_";
                    if(j == 6)
                    {
                        cout << "#_";
                    }
                }
                else
                {
                    cout << "#";   
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    question1();
    question7();
    question8();

    int foo;
    cout << "foo: " << foo << endl;

    string test;
    cout << "test: " << test;

    return 0;
}


// #include <iostream>

// using namespace std;

// int main()
// {
//     for(int i = 0; i < 3; i++)
//     {
//         for(int j = 0; j < 7; j++)
//         {
//             if(i % 2 == 0)
//             {
//                 if(j % 2 == 0)
//                 {
//                     cout << "#";       
//                 }
//                 else
//                 {
//                     cout << "_";
//                 }
//             }
//             else
//             {
//                 if(j % 2 == 0)
//                 {
//                     cout << "_";
//                     if(j == 6)
//                     {
//                         cout << "#_";
//                     }
//                 }
//                 else
//                 {
//                     cout << "#";   
//                 }
//             }
//         }
//         cout << endl;
//     }
//     return 0;
// }