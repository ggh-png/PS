#include <iostream>
#include <string>
using namespace std;

// m n까지의 수중 0이 포함되어있는 경우의 개수를 구해라.

int main()
{
    int num, M, N;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int cnt=0;
        cin >> N >> M;
        for(int j=N; j <= M; j++)
        {   // 1004
            string temp = to_string(j);
            for(auto &el : temp)
            {
                if(el == '0')
                    cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}