#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// map
int n, m, num;
bool map[1004][1004];

// y x bk 밤낮 
int visited[1004][1004][11][2];

// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// ans
int ans = 0;

void bfs(int sy, int sx, int sbk, int sbn)
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{sy, sx},{sbk, sbn}});
    visited[sy][sx][sbk][sbn] = 1;

    while(q.size())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int bk = q.front().second.first;
        int bn = q.front().second.second;
        q.pop();

        // 출구에 도착하면 
        if(y == n-1 && x == m-1)
        {
            ans = visited[y][x][bk][bn];
            break;
        }

        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            // 낮인데  
            if(bn == 1)
            {   // 방문하지 않았고, 길인 경우
                if(!visited[ny][nx][bk][bn-1] && !map[ny][nx])
                {
                    visited[ny][nx][bk][bn-1] = visited[y][x][bk][bn] + 1;
                    q.push({{ny, nx}, {bk, bn-1}});
                }
                // 방문하지 않았고, 벽인 경우 (단. 벽을 부술 수 있는 경우)
                else if(bk && !visited[ny][nx][bk-1][bn-1] && map[ny][nx])
                {
                    visited[ny][nx][bk-1][bn-1] = visited[y][x][bk][bn] + 1;
                    q.push({{ny, nx}, {bk-1, bn-1}});
                }
            }
            else
            {   // 밤인데 
                if(!visited[ny][nx][bk][bn+1] && !map[ny][nx])
                {   // 방문하지 않았고, 길인경우
                    visited[ny][nx][bk][bn+1] = visited[y][x][bk][bn] + 1;
                    q.push({{ny, nx}, {bk, bn+1}});
                }
                // 방문하지 않았고, 벽인 경우 (단. 벽을 부술 수 있는 경우)
                else if(bk && !visited[ny][nx][bk-1][bn+1] && map[ny][nx])
                {
                    visited[y][x][bk][bn+1] = visited[y][x][bk][bn]+1;
                    q.push({{y, x}, {bk, bn+1}});
                }
            }
        }
    }
}


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> m >> num;
    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j < m; j++)
            if(str[j]=='1')
                map[i][j] = 1;
    }

    bfs(0, 0, num, 1);
    if(ans)
        cout << ans << '\n';
    else   
        cout << -1 << '\n';
    return 0;
}