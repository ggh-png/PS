#include <iostream>
using namespace std;

int main()
{
    int money, num;
    cin >> money >> num;
    
    for(int i=0; i < num; i++)
    {
        int n, coin;
        cin >> coin >> n;
        money -= (coin * n);
    }
    if(money != 0)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}