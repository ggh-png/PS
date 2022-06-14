#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    string tmp = str;

    reverse(str.begin(), str.end());
    bool answer = tmp == str ? true : false;
    cout << answer << endl;
    return 0;
}