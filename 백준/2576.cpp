#include <iostream>

using namespace std;

int main()   
{
    int sum = 0;
    int min = 999;
    for(int i=0; i < 7; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp % 2)
        {
            sum += tmp;
            if(min > tmp)
                min = tmp;
        }
    }
    if(min != 999)
        cout << sum << endl << min << endl;
    else
        cout << -1 << endl;
    return 0;
}
