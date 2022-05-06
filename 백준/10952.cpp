#include <iostream>
using namespace std;

// 입력시간보다 45분 일찍 일나야댐

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int a, b;
    while(1)
    {
        cin >> a >> b;
        if(a && b)
            cout << a + b << '\n';
        else
            break;
    }
    return 0;
}