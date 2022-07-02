#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    num--;
    for(int i=0; i < num; i++)
    {
        for(int j=num-i; j > 0; j--)
        {
            cout << " ";
        }
        cout << "*";
        for(int j=0; j < (i)*2; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for(int i=0; i <= num; i++)
    {
        for(int j=0; j < i; j++)
        {
            cout << " ";
        }
        cout << "*";
        for(int j=(num-i)*2; j > 0; j--)
        {
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}