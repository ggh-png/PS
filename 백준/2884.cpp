#include <iostream>
using namespace std;

// 입력시간보다 45분 일찍 일나야댐

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int H, M;
    cin >> H >> M;
    M -= 45; 
    if(M < 0)
    {
        H--;
        if(H < 0)
            H = 23;
        M += 60; 
    }
    cout << H << " " << M;
    return 0;
}