#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 두 수를 입력받아 크기비교
int main()
{
    string a, b;
    int A, B;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(stoi(a) > stoi(b))
        cout << a;
    else
        cout << b;
    return 0;
}