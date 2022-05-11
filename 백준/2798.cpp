#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 


int main()
{
    int num, jack;
    cin >> num >> jack;
    vector<int> v(num);
    // 카드입력 5 6 7 8 9
    // jack 21
    // 6 7 8  21
    for(int i=0; i < num; i++)
        cin >> v[i];
    // 3개의 수를 더한 모든 경우를 구한다.
    int answer=0;
    int min = 999999;
    for(int i=0; i < num; i++)
        for(int j=i+1; j < num; j++)
            for(int k=j+1; k < num; k++)
            {
                int tmp = jack - (v[i] + v[j] + v[k]);
                if(0 <= tmp && tmp <= min)
                {
                    min = tmp;
                    answer = v[i] + v[j] + v[k];
                }
            }

    cout << answer;


    return 0;
}