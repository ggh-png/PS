#include <iostream>
#include <queue>

using namespace std;
const int mx = 200004;
// map
int map[mx];
int visited[mx];
// ans
int n, m;
int ans = 0;
int cnt = 0;
void bfs(int idx)
{
    queue<int> q;
    q.push(idx);
    visited[idx] = 1;
    map[idx] = 1;
    while(q.size())
    {
        int t = q.front();
        q.pop();
        // 걷기
        if(t == m)
        {
            ans = visited[t];
            cnt = map[t];
            break;
        }
        for(auto &el : {t+1, t-1, t*2})
        {   // 범위에 충족하고 
            if(el >= 0 && el < mx)
            {   // 방문하지 않았더라면
                if(!visited[el])
                {
                    q.push(el);
                    // 가산 최단거리 
                    visited[el] = visited[t] + 1;
                    // 경로 횟수
                    map[el] += map[t];
                }
                // 이미 방문을 한 상태에서 최단 거리는 같은데 경로가 다를 경우 
                else if(visited[el] == visited[t] + 1)
                    map[el] += map[t];
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    bfs(n);
    cout << ans-1 << endl << cnt << endl;
    return 0;
}