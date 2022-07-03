#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    num--;
    for(int i=0; i < num; i++)
    {
        for(int j=0; j < i; j++)
            cout << " ";
        for(int j=(num-i)*2; j > 0; j--)
            cout << "*";

        cout << "*";
        cout << endl;
    }

    for(int i=0; i < num; i++)
        cout << " ";

    cout << "*" << endl;
    return 0;
}