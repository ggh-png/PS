#include <iostream>
#include <queue>
using namespace std;

// map
char map[505][505];
bool visited[505][505];
int n, m;
// 주난, 초콜릿 좌표
int jx, jy;
int cx, cy;
// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// ans
bool flag = 1;
int ans = 0;
void bfs(int sy, int sx)
{
    visited[sy][sx] = 1;
    // 초콜릿에 도착하면 
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            // 벽이 아니고, 방문하지 않았더라면 
            if(map[ny][nx] == '0' && !visited[ny][nx])
            {
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
            // 벽이고, 방문하지 않았더라면 
            else if((map[ny][nx] == '1' || map[ny][nx] == '#') && !visited[ny][nx])
            {
                map[ny][nx] = '0';
                visited[ny][nx] = 1;
                continue;
            }
        }  
    }
}


int main()
{
    cin >> n >> m;
    cin >> jy >> jx >> cy >> cx;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];

    if(jy == cy && jx == cx)
        cout << 0 << endl;
    else
    {
        
        while(1)
        {
            flag = 0;
            bfs(jy-1, jx-1);    
            
            for(int i=0; i < n; i++)
                for(int j=0; j < m; j++)
                    if(map[i][j] == '#')
                        flag = 1;
            
            fill(&visited[0][0], &visited[n][m], 0);
            // cout << " ---- " << endl;
            // for(int i=0; i < n; i++)
            // {
            //     for(int j=0; j < m; j++)
            //         cout << map[i][j] << " ";
            //     cout << endl;
            // }
            if(flag)
                ans++;  
            else
                break;
        }
        cout << ans+1 << endl;
    }
    return 0;
}