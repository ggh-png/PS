#include <iostream>

using namespace std;

int main()
{
    int min1 = 9999, min2 = 9999;
    for(int i=0; i < 3; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp < min1)
            min1 = tmp;
    }
    for(int i=0; i < 2; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp < min2)
            min2 = tmp;
    }
    cout << min1 + min2 - 50 << endl;
    return 0;
}