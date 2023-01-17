#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// map 
int n, m;
int map[304][304];
//  섬 번호 visited
int cvisited[304][304];
int visited[304][304];

// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
//int y, x;

// ans
int ans = 987654321;

// 각 섬의 시작 좌표를 담는 큐 
queue<pair<pair<int, int>, int>> q;


// cnt는 각 섬에 부여된 번호를 뜻합니다. 
void bfs(int sy, int sx, int scnt)
{
    queue<pair<pair<int, int>, int>> qqq;
    qqq.push({{sy, sx}, scnt});

    while(qqq.size())
    {
        int y = qqq.front().first.first;
        int x = qqq.front().first.second;
        int cnt = qqq.front().second;
        qqq.pop();
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;

            // 방문하지 않고, 같은 섬일 경우  
            if(!visited[ny][nx] && map[ny][nx] == cnt)
            {
                visited[ny][nx] = 1;
                qqq.push({{ny, nx}, cnt});
            }
            // 방문하지 않고, 바다일 경우 
            if(!visited[ny][nx] && !map[ny][nx])
            {
                visited[ny][nx] = visited[y][x] + 1;
                qqq.push({{ny, nx}, cnt});
            }
            // 다른 섬일 경우 == 다른 섬에 도착 하였을 경우  
            if(map[ny][nx] && map[ny][nx] != cnt)
            {
                visited[ny][nx] = 1;
                ans = min(visited[y][x], ans);
                return;
            }
           
        }
    }
}

// 섬 번호 부여 bfs 
void color(int sy, int sx, int scnt)
{
    queue<pair<pair<int, int>, int>> qq;
    qq.push({{sy, sx}, scnt});
 
    while(qq.size())
    {
        int y = qq.front().first.first;
        int x = qq.front().first.second;
        int cnt = qq.front().second;

        qq.pop();
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;

            if(!map[ny][nx])
                q.push({{y, x}, cnt});
            if(!cvisited[ny][nx] && map[ny][nx])
            {
                cvisited[ny][nx] = 1;
                map[ny][nx] = cnt;
                qq.push({{ny, nx}, cnt});
            }
        }
    }
}

int main()
{
    cin >> n;
    m = n;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];
        
    // 섬 번호 부여     
    int cnt = 0;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            if(!cvisited[i][j] && map[i][j])
            {
                cnt++;
                map[i][j] = cnt;
                color(i, j, cnt);
            }

    while(q.size())
    {
        bfs(q.front().first.first, q.front().first.second, q.front().second);
        fill(&visited[0][0], &visited[n][n], 0);
        q.pop();
    }
    
    cout << ans << endl;
    return 0;
}
