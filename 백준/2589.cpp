#include <iostream>
#include <queue>

using namespace std;

// map
int n, m;
bool map[51][51];
int visited[51][51];

// answer
vector<pair<int, int>> dp;
int ans = 0;

// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int sy, int sx)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if(!visited[ny][nx] && !map[ny][nx])
            {
                visited[ny][nx] = visited[y][x] + 1;
                ans = max(visited[ny][nx], ans);
                q.push({ny, nx});
            }
        }
    }
}




int main()
{
    cin >> n >> m;
    // map 입력
    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j < m; j++)
        {
            map[i][j] = str[j] == 'W' ? 1 : 0;
            if(!map[i][j])
                dp.push_back({i, j});
        }
    }

    for(auto &el : dp)
    {
        bfs(el.first, el.second);
        fill(&visited[0][0], &visited[n][m], 0);
    }
    cout << ans-1 << endl;
    return 0;
}