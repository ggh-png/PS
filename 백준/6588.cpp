#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    vector<bool> arr(1000001, 0);
    arr[0] = true;
    arr[1] = true;
    // 소수 추출
    int cnt = 2;
    for(int i=0; i <= sqrt(1000001); i++)
        if(!arr[i])
            for(int j=i+i; j <= 1000001; j+=i)
            {
                arr[j] = true;
                cnt++;
            }

    // test case 
    while(1)
    {
        int N;
        cin >> N;
        if(N == 0)
            break;

        int a=0, b=0;
        for(int j=3; j <= N; j+=2)
            if(!arr[j] && !arr[N-j])
            {
                a = j;
                b = N-j;
                cout << N << " = " << a << " + " << b << '\n';
                break;
            }
        if(!a && !b)
            cout << "Goldbach's conjecture is wrong.\n";
    }
    return 0;
}