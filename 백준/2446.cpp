#include <iostream>

using namespace std;


int main()
{
    int num;
    cin >> num;
    for(int i=num; i > 1; i--)
    {
        for(int j=0; j < num - i; j++)
            cout << " ";
        for(int j=1; j < 2*i; j++)
            cout << "*";

        cout << endl;
    }
    for(int i=num; i > 0; i--)
    {
        for(int j=1; j < i; j++)
            cout << " ";
        cout << "*";
        for(int j=0; j < num - i; j++)
            cout << "*";
        for(int j=0; j < num - i; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}