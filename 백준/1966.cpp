#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

/* SOL
우선순위 리스트에 찾을 요소를 따로 표기할 pair vector생성 
내림차순으로 first 내림차순 정렬 
같은 수가 나올 시 sec값으로 정렬 

따로 표기한 요소의 index값을 answer에 입력
*/

bool compare(pair<int, int> a,
             pair<int, int> b)
{   // 학생의 점수가 같은 경우 나이가 많은 순으로 
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

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
        vector<int> TempCount(101, 0);
        int max = 0;
        for(int j=0; j < N; j++)
        {
            int temp;
            
            cin >> temp;
            q.push_back(pair<int, int>(temp, j));
            
        }
        // 1 2 3 4 
        //
        vector<pair<int, int>> pq; 
        for(int j=0; j < q.size(); j++)
        {
            
            for(int k=j; k < q.size(); k++)
                max = max < q[k].first ? q[k].first : max;
            for()
            pq.push_back(pair<int, int>())
        }



        int count = 0;
        cout << M << endl;
        for(int j=0; j < q.size(); j++)
        {
            if(q[j].second == M)
            {
                count++;
                answer.push_back(count);
                //break;
            }
            else
                count++;
            cout << q[j].second << " ";
        }
        cout << endl;
        q.clear();
    }
    for(auto &el : answer)
        cout << el << '\n';

    return 0;
}