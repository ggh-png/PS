#include <iostream>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int num;
    cin >> num;
    int cnt = 2;
    while (1)
    {
        int cnt = 2;
        if(num == 1)
            break;
        else
            while(1)
            {   // 나눠 떨어지면
                if(!(num % cnt))
                {
                    num /= cnt;
                    cout << cnt << '\n';
                    break;
                }
                else
                    cnt++;
            }
    }
}