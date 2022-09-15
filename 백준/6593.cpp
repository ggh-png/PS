#include <iostream>
#include <queue>

using namespace std;

// map[z][y][x]
int n=1, m=1, l=1;
bool map[33][33][33];
int visited[33][33][33];

// joy 상 하 남 동 북 서 
int dz[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 0, 1, 0};
int dx[] = {0, 0, 0, 1, 0, -1};
int x, y, z;

// 시작점, 끝점
int sz, sy, sx;
int ez, ey, ex;
void bfs(int tz, int ty, int tx)
{
    queue<pair<int, pair<int, int>>> q;
    q.push({tz, {ty, tx}});
    visited[tz][ty][tx] = 1;

    while(q.size())
    {
        int z = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();
        for(int i=0; i < 6; i++)
        {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nz < 0 || nz >= l || ny < 0 || ny >= n || 
               nx < 0 || nx >= m)
                continue;
            if(!visited[nz][ny][nx] && !map[nz][ny][nx])
            {
                visited[nz][ny][nx] = visited[z][y][x] + 1;
                q.push({nz, {ny, nx}});
            }
        }
    }
}

int main()
{
    while(m || n || l)
    {
        // z y x
        cin >> l >> n >> m;
        for(int i=0; i < l; i++)
            for(int j=0; j < n; j++)
                for(int k=0; k < m; k++)
                {
                    char tmp;
                    cin >> tmp;
                    if(tmp == 'E')
                    {
                        ez = i;
                        ey = j;
                        ex = k;
                    }
                    else if(tmp == 'S')
                    {
                        sz = i;
                        sy = j;
                        sx = k;
                    }
                    else if(tmp == '#')
                        map[i][j][k] = 1;
                }
        
        bfs(sz, sy, sx);
        // map 출력
        // cout << " ---- " << endl; 
        // for(int i=0; i < l; i++)
        // {
        //     for(int j=0; j < n; j++)
        //     {
        //         for(int k=0; k < m; k++)
        //             cout << visited[i][j][k] << " ";
        //         cout << endl;
        //     }
        //     cout << " ---- " << endl;
        // }
        
        if(m || n || l)
        {
            if(visited[ez][ey][ex])
                cout << "Escaped in " << visited[ez][ey][ex] - 1 
                << " minute(s)." << endl;
            else
                cout << "Trapped!" << endl;
        }
        fill(&map[0][0][0], &map[l][n][m], 0);
        fill(&visited[0][0][0], &visited[l][n][m], 0);
    }
    return 0;
}