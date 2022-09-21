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

void bfs(int idx)
{
    queue<int> q;
    q.push(idx);
    visited[idx] = 1;
    while(q.size())
    {
        int t = q.front();
        q.pop();
        // 걷기
        if(t == m)
        {
            ans = visited[t];
            break;
        }
        int nt_under = t - 1;
        int nt_over = t + 1;
        // 순간이동 
        int nt_tel = t * 2;
        if(!visited[nt_under] && nt_under < mx)
        {
            visited[nt_under] = visited[t] + 1;
            q.push(nt_under);
        }
        if(!visited[nt_over] && nt_over < mx)
        {
            visited[nt_over] = visited[t] + 1;
            q.push(nt_over);
        }
        if(!visited[nt_tel] && nt_tel < mx)
        {
            visited[nt_tel] = visited[t] + 1;
            q.push(nt_tel);
        }
    }
}

int main()
{
    cin >> n >> m;
    bfs(n);
    cout << ans-1 << endl;
    return 0;
}