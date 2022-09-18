#include <iostream>
using namespace std;

// map 
int n, m;
bool map[505][505];
bool visited[505][505];

// joy 
int y, x;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// ans
int ans = 0;
int cnt = 0;
int num = 0;

void dfs(int y, int x)
{
    visited[y][x] = 1;
    cnt++;
    for(int i=0; i < 4; i++)
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
    cin >> n >> m;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];
    
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
        {
            cnt = 0;
            if(!visited[i][j] && map[i][j])
            {
                num++;
                dfs(i, j);
                ans = max(cnt, ans);
            }
        }
    }
    cout << num << endl << ans << endl;
    
    
    return 0;
}