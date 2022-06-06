#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;
    double answer = 69 - str[0];
    if(str[0] == 'F')
        answer = 0.0;

    if(str[1] == '+')
        answer += 0.3;
    else if(str[1] == '-')
        answer -= 0.3;
    cout << fixed;
    cout.precision(1);
    cout << answer;
    return 0;
}