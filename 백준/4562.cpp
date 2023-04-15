#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a >= b)
            cout << "MMM BRAINS" << endl;
        else 
            cout << "NO BRAINS" << endl;
    }
}