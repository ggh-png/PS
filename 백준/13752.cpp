#include <iostream>

using namespace std;


int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int n;
        cin >> n;
        for(int j=0; j < n; j++)
            cout << "=";
        cout << endl;
    }
    return 0;
}