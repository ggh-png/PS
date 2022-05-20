#include <iostream>
using namespace std;


int main()
{
    int num, answer=1;
    cin >> num;

    while(1)
    {
        if(num != 0)
            answer *= num;
        else
        {
            answer *= 1;
            break;
        }
        num--;
    }

    cout << answer;
    return 0;
}