#include <iostream>

using namespace std;

// map
char map[22][22];
//  알파뱃 방문 유무 
bool alpa[26];
int n, m;
// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
// ans 
int ans = 0;

void dfs(int y, int x, int cnt)
{
    ans = max(cnt, ans);
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        int next = int(map[ny][nx] - 'A');
        if(!alpa[next])
        {
            alpa[next] = 1;
            dfs(ny, nx, cnt+1);
            alpa[next] = 0;
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
    
        for(int j=0; j < m; j++)
            map[i][j] = str[j];
    }
    int first = int(map[0][0] - 'A');
    alpa[first] = 1;
    dfs(0, 0, 1);
    cout << ans << endl;
    return 0;
}