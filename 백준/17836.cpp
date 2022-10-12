#include <iostream>
#include <queue>

using namespace std;

// map
int n, m, k;
int map[104][104];
// n, m, 벽 부순 유무
bool visited[104][104][2];

// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
// ans 
int ans = 0;

void bfs(int sy, int sx, bool sbk, int scnt)
{
    queue<pair<pair<int, int>, pair<bool, int>>> q;
    q.push({{sy, sx}, {sbk, scnt}});
    visited[sy][sx][sbk] = 1;
    while(q.size())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        bool bk = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if(y == n-1 && x == m-1)
        {
            ans = cnt;
            break;
        }
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m )
                continue;
                
            if(map[ny][nx] == 0 && !visited[ny][nx][bk])
            {
                visited[ny][nx][bk] = 1;
                q.push({{ny, nx}, {bk, cnt+1}});
            }
            // 검 획득 
            if(map[ny][nx] == 2 && !visited[ny][nx][bk+1])
            {
                visited[ny][nx][bk+1] = 1;
                q.push({{ny, nx}, {1, cnt+1}});
            }
            if(map[ny][nx] == 1 && bk && !visited[ny][nx][bk])
            {
                visited[ny][nx][bk] = 1;
                q.push({{ny, nx}, {bk, cnt+1}});
            }
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];

    bfs(0,0,0,0);
    if(ans == 0 || ans > k)
        cout << "Fail" << endl;
    else
        cout << ans << endl;
    return 0;
}


