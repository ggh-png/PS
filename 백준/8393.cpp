#include <iostream>
using namespace std;

int main()
{
    int num;
    int answer = 0;
    cin >> num;

    for(int i=1; i <= num; i++)
    {
        answer += i;
    }
    cout << answer;
    return 0;
}