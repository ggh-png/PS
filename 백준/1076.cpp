#include <iostream>
#include <string>
using namespace std;


int main()
{
    string arr[10] = {"black", "brown", "red", "orange"
                    , "yellow", "green", "blue", "violet"
                    , "grey", "white"};

    int tmp[3];
    for(int i=0; i < 3; ++i)
    {
        string order;
        cin >> order;
        for(int j=0; j < 10; ++j)
            if(arr[j] == order)
                tmp[i] += j;
    }
    unsigned long long answer = ((tmp[0]*10) + tmp[1]);
    for(int i=0; i < tmp[2]; ++i)
        answer *= 10;

    cout << answer << endl;
    return 0;
}