#include <iostream>
#include <vector>
using namespace std;
/*
N
테스트케이스의 첫 번째 줄에는 문서의 개수 N(1 ≤ N ≤ 100)
M
몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue에서 몇 번째에 놓여 있는지를 나타내는 정수 M(0 ≤ M < N)이 주어진다. 
output
궁금 문서의 입쇄 번수
input
3
1 0 - N = 1, M = 0 
5           output = 1
4 2 - N = 4, M = 2
1 2 [3] 4     output = 2
4 [3] 2 1 
6 0 - N = 6, M = 0
1 1 9 1 1 1 output = 5
workflow
[A] B C D E F
C D E F [A] B
1 2 3 4 [5] 6
output 
1 2 5
*/

int a = 0;
int main()
{
    int num; // test case
    int N;   // list size
    int M;   // 확인할 요소의 index 값    
    cin >> num;
    vector<int> answer;
    
    for(int i=0; i < num; i++)
    {
        cin >> N >> M;
        vector<pair<int, int>> q;
        for(int j=0; j < N; j++)
        {
            int temp;
            cin >> temp;
            // 우선순위, 초기 순서 
            q.push_back(pair<int, int>(temp, j));
        }
        /*
        work flow
        1 2 3 4
        2 3 4 1
        3 4 1 2
        4 1 2 3
        4 2 3 1
        4 3 2 1
        */
        for(int j=0; j < q.size(); j++)
        {
            for(int k=j; k < q.size(); k++)
            {   // 보다 큰 수를 찾으면 
                if(q[j].first < q[k].first)
                {   
                    for(int l=0; l < abs(k - j); l++)
                    {   // 확인을 하지 않은 앞 요소 저장 
                        int fir = q[j].first;
                        int sec = q[j].second;
                        // 큐 pop 
                        q.erase(q.begin()+j);
                        q.push_back(pair<int, int>(fir, sec));
                        // work flow 출력 
                        // for(auto el : q)
                        //     cout << el.first << " ";
                        // cout << "," << k-j << endl;    
                    }
                    // if문이 작동하면 for문이 도는동안 k값 고정
                    k--;
                }
            }
        }
        int count=0;
        for(int j=0; j < q.size(); j++)
        {
            if(q[j].second == M)
            {
                count++;
                answer.push_back(count);
            }
            else
                count++;
        }
    }
    //answer
    for(auto &el : answer)
        cout << el << '\n';
    return 0;
}