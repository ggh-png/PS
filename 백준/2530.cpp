#include <iostream>

using namespace std;

// 초를 분과 시간으로 더해 출력함.

int main()
{   // 시간, 분, 초
    int h, m, s;
    // 필요시간 
    int D;
    // 시간 분 초 && 경과시간 입력 
    cin >> h >> m >> s >> D;
    
    // 200 초 입력
    // 14 : 30 : 00
    s += D;
    if(s >= 60)
    {   // 분++ 몫
        m += (s / 60);
        // 나머지 초++
        s %= 60;
        if(m >= 60)
        {
            h += (m / 60);
            m %= 60;
            if(h >= 24)
                h %= 24;
        }
    }    
    cout << h << " " << m << " " << s;
    return 0;
}