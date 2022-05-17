#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    cin >> num;

    for(int i=0; i < num; i++)
    {
        double N;
        cin >> N;
        vector<int> v(N);
        double sum = 0;
        for(int j=0; j < N; j++)
        {
            cin >> v[j];
            sum += v[j];
        }
        // 평균
        sum /= N;
        double cnt = 0;
        for(auto &el : v)
            if(el > sum)
                cnt++;
        cout << fixed;
        cout.precision(3);
        double answer = (cnt / N) * 100;
        cout << answer << "%" <<'\n';
       
    }
    return 0;
}