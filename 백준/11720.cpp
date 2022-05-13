#include <iostream>
#include <string>

using namespace std;


int main()
{
    int num, answer=0;
    string str;
    cin >> num >> str;
    for(auto &el : str)
        answer += el - 48;
    cout << answer;
    return 0;
}