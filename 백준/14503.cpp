#include <iostream>

using namespace std;

// map
int n, m;
bool map[50][50];
int visited[50][50];

// joy 북 동 남 서 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


void dfs(int y, int x, int w, int sum)
{
    for(int i=0; i < 4; i++)
    {   // 왼쪽부터 탐색
        int rotate = (w + 3 - i) % 4;

        int ny = y + dy[rotate];
        int nx = x + dx[rotate];
        
        // map 범위를 벗어날 경우
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || map[ny][nx] == 1)
            continue;
        // 청소가 되어있지 않고, 벽이 아닐 경우 
        if(!visited[ny][nx] && !map[ny][nx])
        {
            visited[ny][nx] = 1;  
            dfs(ny, nx, rotate, sum+1);
        }
    }
    // robot 후진 
    int backrotate = w + 2 < 4 ? w+2 : w-2;
    int backy = y + dy[backrotate];
    int backx = x + dx[backrotate];
    if(0 <= backy && 0 <= backx && backy <= n && backx <= m)
    {
        if(!map[backy][backx])
            dfs(backy, backx, w, sum);
        else
        {
            cout << sum << endl;
            exit(0);
        }
    }
}

int main()
{
    int x, y, w;
    cin >> n >> m;
    cin >> y >> x >> w;

    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];

    visited[y][x] = 1;
    dfs(y, x, w, 1);

    // map 출력
    // for(int i=0; i < n; i++)
    // {
    //     for(int j=0; j < m; j++)
    //         cout << visited[i][j] << " ";
        
    //     cout << endl;
    // }

    return 0;
}
