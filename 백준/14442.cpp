#include <iostream>
#include <queue>

using namespace std;

// map
int n, m;
bool map[1004][1004];
int visited[1004][1004][11];
// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// 부술 수 있는 벽의 개수 
int num;
int ans = 0;

void bfs(int sy, int sx, int N)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{sy, sx}, N});
    visited[sy][sx][N] = 1;

    while(q.size())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int bk = q.front().second;
        q.pop();
        if(y == n-1 && x == m-1)
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
            // 방문하지 않았고, 길인 경우
            if(!visited[ny][nx][bk] && !map[ny][nx])
            {
                visited[ny][nx][bk] = visited[y][x][bk] + 1;
                q.push({{ny, nx}, bk});
            }
            // 방문하지 않았고, 벽이고, 부술 수 있는 기회가 있을 경우 
            if(!visited[ny][nx][bk-1] && map[ny][nx] && bk)
            {
                visited[ny][nx][bk-1] = visited[y][x][bk] + 1;
                q.push({{ny, nx}, bk-1});
            }
        }
    }
}


int main()
{
    cin >> n >> m >> num;
    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j < m; j++)
            if(str[j] == '1')
                map[i][j] = 1;
    }

    bfs(0, 0, num);
    if(!ans)
        cout << -1 << endl;
    else    
        cout << ans << endl;

    return 0;
}