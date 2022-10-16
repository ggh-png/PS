#include <iostream>
#include <queue>

using namespace std;

// map
bool map[1004][1004];
int visited[1004][1004][2];
int n, m;

// xy 
int hy, hx;
int ey, ex;
// joy
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};
// ans
int ans = -1;


void bfs(int sy, int sx, bool sbk)
{
    queue<pair<pair<int, int>, bool>> q;
    q.push({{sy, sx}, sbk});
    while(q.size())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        bool bk = q.front().second;
        q.pop();
        if(y == ey-1 && x == ex-1)
        {
            ans = visited[y][x][bk];
            break;
        }
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if(!map[ny][nx] && !visited[ny][nx][bk])
            {
                visited[ny][nx][bk] = visited[y][x][bk] + 1;
                q.push({{ny, nx}, bk});
            }
            if(map[ny][nx] && !bk && !visited[ny][nx][bk+1])
            {
                visited[ny][nx][bk+1] = visited[y][x][bk] + 1;
                q.push({{ny, nx}, bk+1});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> hy >> hx;
    cin >> ey >> ex;
    
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];

    bfs(hy-1, hx-1, 0);
    cout << ans << endl;
}

