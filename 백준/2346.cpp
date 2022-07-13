#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/* 리뷰 
ggh-png.github.io/posts/BOJ-2346/
*/

class Balloon
{
public:
    int num;
    int number;
};


int main()
{
    int num;
    cin >> num;

    deque<Balloon> dq;

    for(int i=1; i <= num; i++)
    {
        Balloon tmp;
        cin >> tmp.num;
        tmp.number = i;
        dq.push_back(tmp);
    }

    int temp = dq.front().num;
    vector<int> answer;
    // 1회차 풍선 펑!
    answer.push_back(dq.front().number);
    dq.pop_front();

    while(!dq.empty())
    {   // 터진 풍선이 양수일 경우 
        if(temp > 0)
        {   // 새겨진 숫자만큼 이동 
            for(int i=1; i < temp; i++)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            // 오른쪽 이동 후 풍선 넘버 저장 후 펑!  
            answer.push_back(dq.front().number);
            temp = dq.front().num;
            dq.pop_front();
        }
        // 음수일 경우
        else
        {   // 새겨진 숫자만큼 이동 
            for(int i=1; i < abs(temp); i++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            // 왼쪽 이동 후 풍선 넘버 저장 후 펑!
            answer.push_back(dq.back().number);
            temp = dq.back().num;
            dq.pop_back();
        }
    }
    // 결과 출력 
    for(auto &el : answer)
        cout << el << " ";
    cout << endl;
    return 0;
}
