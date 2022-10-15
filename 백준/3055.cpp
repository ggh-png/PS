#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// map
int n, m;
char map[55][55];
int fvisited[55][55];
int evisited[55][55];

// joy 
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
// 도치, 비버 굴
int Sy, Sx;
int Dy, Dx;
// 홍수 위치
queue<pair<int, int>> wq;

// 홍수 bfs 
void flood()
{
    while(wq.size())
    {
        int y = wq.front().first;
        int x = wq.front().second;
        wq.pop();
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || fvisited[ny][nx])
                continue;
            if(map[ny][nx] == '.')
            {
                fvisited[ny][nx] = fvisited[y][x] + 1;
                wq.push({ny, nx});
            }
            if(map[ny][nx] == 'D')
                fvisited[ny][nx] = fvisited[y][x];
            
        }
    }
}

void escape(int sy, int sx)
{
    queue<pair<int, int>> q;
    q.push({sy, sx});
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || evisited[ny][nx])
                continue;
            if(map[ny][nx] == 'D' || map[ny][nx] == '.' && (!fvisited[ny][nx] || (fvisited[ny][nx] > evisited[y][x] + 1)))
            {
                evisited[ny][nx] = evisited[y][x] + 1;
                q.push({ny, nx});
            }
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
            if(map[i][j] == '*')
                wq.push({i, j});
            if(map[i][j] == 'D')
            {
                Dy = i;
                Dx = j;
            }
            if(map[i][j] == 'S')
            {
                Sy = i;
                Sx = j;
            }
        }
    flood();
    escape(Sy, Sx);
    if(!evisited[Dy][Dx])
        cout << "KAKTUS" << endl;
    else    
        cout << evisited[Dy][Dx] << endl;

    return 0;
}
