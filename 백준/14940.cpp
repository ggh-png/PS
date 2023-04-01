#include <iostream>
#include <queue>

using namespace std;

// map
int n, m;
int map[1004][1004];
int visited[1004][1004];

// joy
int sy, sx;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int ssy, int ssx)
{
    queue<pair<int, int>> q;
    q.push({ssy, ssx});
    while (q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= n || nx >= m || ny < 0 || nx < 0 || visited[ny][nx] || !map[ny][nx])
                continue;
            
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        
        }
    }
}



int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 2)
            {
                sy = i;
                sx = j;
            }
        }
    bfs(sy, sx);
    visited[sy][sx] = 0; 
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            if(i == sy && j == sx)
            {
                cout << visited[i][j] << " ";
                continue;
            }
            if(map[i][j] && !visited[i][j])
                cout << "-1" << " ";
            else
                cout << visited[i][j] << " ";
        }
        cout << '\n';
    }

}