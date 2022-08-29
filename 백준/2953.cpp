#include <iostream>
using namespace std;

int main()
{
    int max = 0;
    int num  = 1;
    for(int i=1; i <= 5; i++)
    {
        int sum = 0;
        for(int j=0; j < 4; j++)
        {
            int tmp;
            cin >> tmp;
            sum += tmp;
        }
        if(sum > max)
        {
            max = sum;
            num = i;
        }
    }
    cout << num << " " << max << endl;
    return 0;
}
