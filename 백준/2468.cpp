#include <iostream>

using namespace std;

// map 
int n;
int map[101][101];
bool mp[101][101];
bool visited[101][101];
// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
// 현 위치 
int x, y;

void dfs(int y, int x)
{   // 방문
    visited[y][x] = 1;
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // map을 벗어나면
        if(ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;

        // 안전구역이고, 방문하지 않았더라면 
        if(mp[ny][nx] && !visited[ny][nx])
            dfs(ny, nx);
    }
    return;

}
// 침수지역 표기 
int main()
{
    cin >> n;
    int ans = -1;

    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            cin >> map[i][j];
        
    for(int k=0; k < 101; k++)
    {
        for(int i=0; i < n; i++)
            for(int j=0; j < n; j++)
            {
                // 안전지역일 경우 1로 표기 
                if(map[i][j] > k)
                    mp[i][j] = 1;
            }
        // 안전지역 탐색
        int cnt=0;
        for(int i=0; i < n; i++)
            for(int j=0; j < n; j++)
                if(mp[i][j] && !visited[i][j])
                {
                    cnt++;
                    dfs(i, j);
                }
        if(ans < cnt)
            ans = cnt;
        // 초기화
        for(int i=0; i < 101; i++)
            for(int j=0; j < 101; j++)
            {
                mp[i][j] = 0;
                visited[i][j] = 0;
            }
    } 
    cout << ans << endl;

    return 0;
}