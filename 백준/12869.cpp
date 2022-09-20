#include <iostream>
#include <queue>

using namespace std;

// map
int n, m, num;
int map[64][64][64];
int visited[64][64][64];

//joy
int dz[] = {9, 9, 3, 3, 1, 1};
int dy[] = {3, 1, 1, 9, 9, 3};
int dx[] = {1, 3, 9, 1, 3, 9};

//unit
int unit[3];

void bfs(int sz, int sy, int sx)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{sz, sy}, sx});
    visited[sz][sy][sx] = 1;
    while(q.size())
    {
        int z = q.front().first.first;
        int y = q.front().first.second;
        int x = q.front().second;
        q.pop();
        if(visited[0][0][0])
            break;
        for(int i=0; i < 6; i++)
        {   // 0이되면 죽은것이기 때문
            int nz = max(0, z - dz[i]);
            int ny = max(0, y - dy[i]);
            int nx = max(0, x - dx[i]);
            if(visited[nz][ny][nx])
                continue;
            visited[nz][ny][nx] = visited[z][y][x] + 1;
            q.push({{nz, ny}, nx});
        }
    }
}

int main()
{
    cin >> num;
    for(int i=0; i < num; i++)
        cin >> unit[i];
    bfs(unit[0], unit[1], unit[2]);
    cout << visited[0][0][0]-1 << endl;
    return 0;
}