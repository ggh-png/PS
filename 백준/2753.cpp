#include <iostream>
using namespace std; 

// 윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.
int main()
{
    int year;
    cin >> year;
    if(!(year % 4) && (year % 100) || !(year % 400))
    {
        cout << "1";
    }
    else
        cout << "0";
    return 0;
}