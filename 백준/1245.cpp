#include <iostream>

using namespace std;

// map
int n, m;
int map[104][104];
bool visited[104][104];

// joy
int dy[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dx[] = {0, 1, 0, -1, 1, -1, -1, 1};
// ans
int ans = 0;
bool peak;
void dfs(int y, int x)
{
    visited[y][x] = 1;
    for(int i=0; i < 8; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if(map[ny][nx] > map[y][x])
            peak = 0;
        if(map[ny][nx] == map[y][x] && !visited[ny][nx])
            dfs(ny, nx);
        
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];

    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            if(!visited[i][j] && map[i][j])
            {
                peak = 1;
                dfs(i, j);
                if(peak)
                    ans++;
            }

    cout << ans << endl;
    return 0;
}