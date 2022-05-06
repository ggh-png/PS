#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int num;
    cin >> num;
    int input = num;
    int cnt=0;
    // 10 보다 작으면 10 곱 
    // 26 8
    do
    {
        num = (num % 10) * 10 + (num / 10 + num % 10) % 10;     
        cnt++;
    }
    while(num != input);
    
    cout << cnt; 
    return 0;
}

