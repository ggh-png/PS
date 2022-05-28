#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int tmp = stoi(a) + stoi(b);
    string ans = to_string(tmp);
    reverse(ans.begin(), ans.end());
    cout << stoi(ans); 
    return 0;
}