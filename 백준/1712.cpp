#include <iostream>

using namespace std;

// A B C 가 주어지면

int main()
{   
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    // 초기비용, 양산비용, 판매금액
    int A, B, C;
    cin >> A >> B >> C;
    // 1회 생산비
    int sum = A;
    double cnt = 0;

    if(B < C)
    {
        cnt = sum / (C - B);
        if(cnt >= (int)cnt)
            cnt++;
    }
    if(cnt == 0)
        cout << "-1";
    else
        cout << (int)cnt;

    return 0;
}