#include <iostream>

using namespace std;

// map
int map[11][11];
bool visited[11][11];
int n;

// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// ans
int cnt;
int ans = 999999999;
// check 
bool check(int y, int x)
{
    if(visited[y][x])
        return 0;
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n)
            return 0;
        if(visited[ny][nx])
            return 0;
    }
    return 1;
}

// seed 
int seed(int y, int x)
{
    visited[y][x] = 1;
    int tmp = map[y][x];
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        tmp += map[ny][nx];
    }
    return tmp;
}

void delseed(int y, int x)
{
    visited[y][x] = 0;
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}
void solution(int cnt, int money)
{
    if(cnt == 3)
    {
        ans = min(money, ans);
        return;
    }
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
        {
            if(check(i, j))
            {
                solution(cnt+1, money + seed(i, j));
                delseed(i, j);
            }
        }
}



int main()
{
    cin >> n; 
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            cin >> map[i][j];

    solution(0, 0);
    cout << ans << endl;

    return 0;
}