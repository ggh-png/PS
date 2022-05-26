#include <iostream>
#include <vector>

using namespace std;

/* 점 3개가 주어짐.
5 5
5 7 
7 5 
---
30 20
10 10
10 20 
----
30 10 
*/
// 높이는 2 가로는 2
// 7 7
// x죄표가 3개중에 개수가 제일 적은 구해야하는 x좌표로 
int main()
{
    vector<int> x(3);
    vector<int> y(3);

    // input값 입력 
    for(int i=0; i < 3; i++)
    {   
        int tmp_x, tmp_y;
        cin >> tmp_x >> tmp_y;
        x[i] = tmp_x;
        y[i] = tmp_y;
    }

    // 정답, output 출력
    int answer_x, answer_y;
    if(x[0] == x[1])
        answer_x = x[2];
    else if(x[1] == x[2])
        answer_x = x[0];
    else
        answer_x = x[1];

    if(y[0] == y[1])
        answer_y = y[2];
    else if(y[1] == y[2])
        answer_y = y[0];
    else
        answer_y = y[1];
    cout << answer_x << " " << answer_y;

    return 0;
}