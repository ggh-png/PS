#include <iostream>

using namespace std;

// map
int n, m;
bool map[104][104];
int visited[104][104];

// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i=0; i < 4; i++)
    {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        // 방문하지 않았고, 밖인 경우 
        if(!visited[ny][nx] && !map[ny][nx])
        {
            visited[ny][nx] = 1;
            dfs(ny, nx);
        }
        if(map[ny][nx])
            visited[ny][nx]++;
    }
}


int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];
    int cnt = 0;
    while(1)
    {
        bool flag = 1;
        cnt++;
        dfs(0, 0);
        
        for(int i=0; i < n; i++)
        {
            for(int j=0; j < m; j++)
            {
                if(visited[i][j] >= 2)
                    map[i][j] = 0;
                if(map[i][j] == 1)
                    flag = 0;
            }
        }
        fill(&visited[0][0], &visited[n][m], 0);
        if(flag == 1)
            break;
    }
    cout << cnt << endl;
    return 0;
}