#include <iostream>

using namespace std;

int main()
{
    bool arr[31] = {0};
    for(int i=0; i < 28; i++)
    {
        int tmp;
        cin >> tmp;
        arr[tmp] = 1;
    }
    
    for(int i=1; i <= 30; i++)
    {
        if(arr[i] == 0)
            cout << i << endl;
    }
    return 0;
}