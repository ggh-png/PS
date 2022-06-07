#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int a=100, b=100;
    
    for(int i=0; i < num; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        a -= tmp1 < tmp2 ? tmp2 : 0;
        b -= tmp1 > tmp2 ? tmp1 : 0;        
    }
    cout << a << endl;
    cout << b << endl;

    return 0;
}