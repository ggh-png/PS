#include <iostream>

using namespace std;

int main()
{
    int num, k;
    cin >> num >> k;
    // k번째 약수 구하기 

    int cnt = 0;
    int answer = 0;
    for(int i=1; i <= num; i++)
    {
        if(num % i == 0)
        {
            cnt++;
            if(cnt == k)
            {
                answer = i;
                break;
            }
        }
    }
    cout << answer << endl;
    return 0;
}