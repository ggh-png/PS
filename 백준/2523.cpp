#include <iostream>

using namespace std;

int main ()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        cout << "*";
        for(int j=0; j < i; j++)
            cout << "*";
    
        cout << endl;
    }
    for(int i=1; i < num; i++)
    {
        for(int j=num-i; j > 0; j--)
            cout << "*";

        cout << endl;
    }
    return 0;
}