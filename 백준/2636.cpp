#include <iostream>
#include <queue>

using namespace std;

// map
int n, m;
int map[104][104];
int tmpmap[104][104];
int visited[104][104];

// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int x, y;
// bfs로 푼다. 
// 단 조건은 인접하는 치즈인 부분은 녹이는걸로 


int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];



    queue<pair<int, int>> q;
 

    int count = 1;
    int ans = 0;
    int cnt;
    while(count)
    {
        cnt = 0;
        // map 복사 
        for(int i=0; i < n; i++)
            for(int j=0; j < m; j++)
            {
                tmpmap[i][j] = map[i][j];
                if(tmpmap[i][j])
                    cnt++;
            }

        count = 0;
        q.push({0,0});
        while(q.size())
        {
            y = q.front().first;
            x = q.front().second;
            q.pop();
            for(int i=0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                    continue;
                // 방문하지 않았고 치즈 외부일 경우 
                if(!visited[ny][nx] && !map[ny][nx])
                {
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push({ny, nx});
                }
                // 방문하지 않았고, 외부와 치즈와 인접한 경우

                if(!visited[ny][nx] && map[ny][nx])
                {    
                    map[ny][nx] = 0;
                    visited[ny][nx] = visited[y][x] + 1;
                }
            }
        }
        for(int i=0; i < n; i++)
            for(int j=0; j < m; j++)
                if(map[i][j])
                    count++;
        ans++;
        // 방문 초기화 
        fill(&visited[0][0], &visited[n][m], 0);
    }


    cout << ans << endl << cnt << endl;

    return 0;
}