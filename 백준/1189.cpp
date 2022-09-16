#include <iostream>
using namespace std;

// map
int n, m, num;
bool map[10][10];
int visited[10][10];

// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int y, x;

// dfs
int dfs(int y, int x)
{
    // 기저사례
    // 집은 오른쪽 위에 있다.
    if(y == 0 && x == m-1)
    {   // 집에 도착하면 
        if(num == visited[y][x])
            return 1;
        return 0;
    }
    int cnt = 0;
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if(!visited[ny][nx] && !map[ny][nx])
        {
            visited[ny][nx] = visited[y][x] + 1;
            // 목적지에 도착하면 
            cnt += dfs(ny, nx);
            // 지나온 흔적은 지운다. 
            visited[ny][nx] = 0;
        }
    }
    return cnt;
}

int main()
{
    cin >> n >> m >> num;
    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j < m; j++)
            if(str[j] == 'T')
                map[i][j] = 1;
    }
    // 한수는 현재 왼쪽 아래점에 있다.
    visited[n-1][0] = 1;
    cout << dfs(n-1, 0) << endl;
}



