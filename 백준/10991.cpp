#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;

    for(int i=0; i < num; i++)
    {
        for(int j=num-i; j > 1; j--)
            cout << " ";

        cout << "*";
        for(int j=0; j < i; j++)
            cout << " " << "*";

        cout << endl;
    }
    
    return 0;
}