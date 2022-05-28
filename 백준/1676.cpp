#include <iostream>
#include <string> 
using namespace std;

int main()
{
    int num;
    cin >> num;
    int tmp1, tmp2, tmp3;
    tmp1 = num / 5;
    tmp2 = num / 25;
    tmp3 = num / 125;
    cout << tmp1 + tmp2 + tmp3;
    return 0;
}