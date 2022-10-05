#include <iostream>
#include <vector>

using namespace std;

// map
int n, m;
int map[55][55];
bool visited[55][55];
// joy 대각선 
int dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dx[] = {0, 1, 0, -1, 1, -1, -1, 1};

// ans 
int ans;

void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i=0; i < 8; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if(!visited[ny][nx] && map[ny][nx])
            dfs(ny, nx);
        
    }
    return;
}

int main()
{
    while(1)
    {
        cin >> m >> n;
        if(!n && !m)
            break;
        else
        {
            ans = 0;
            for(int i=0; i < n; i++)
                for(int j=0; j < m; j++)
                    cin >> map[i][j];

            for(int i=0; i < n; i++)
                for(int j=0; j < m; j++)
                    if(!visited[i][j] && map[i][j])
                    {
                        ans++;
                        dfs(i, j);
                    }
            cout << ans << endl;
            fill(&visited[0][0], &visited[n][m], 0);
            fill(&map[0][0], &map[n][m], 0);
        }
    }
    return 0;
}
