#include <iostream>
#include <vector>
using namespace std;

// map
int n, m;
int map[10][10];
int tmpmap[10][10];
bool visited[10][10];

// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// x y
int x, y;

// 바이러스
vector<pair<int, int>> v;
// 벽을 새울 수 있는 후보 
vector<pair<int, int>> wallv;

// 안전지대 
int safe_zone = 0;

void dfs(int y, int x, bool flag)
{
    visited[y][x] = 1;
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;

        // 방문하지 않고, 벽만 아니면  
        if(!visited[ny][nx] && tmpmap[ny][nx] != 1 && flag)
        {
            // 감염 
            tmpmap[ny][nx] = 2;
            dfs(ny, nx, 1);
        }
    }
    return;
}

int solve()
{
    int cnt = 0;
    // map temp
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            tmpmap[i][j] = map[i][j];

    // 오염 시키기 
    for(auto &el : v)
        if(!visited[el.first][el.second] && tmpmap[el.first][el.second] != 1)
            dfs(el.first, el.second, 1);


    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            if(!tmpmap[i][j])
                cnt++;
        
    return cnt;
}

int main()
{
    cin >> n >> m;

    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
        {
            // 맵 입력 && 바이러스 좌표 추출
            cin >> map[i][j];
            if(map[i][j] == 2)
                v.push_back({i, j});
            // 벽 새우기 후보
            else if(!map[i][j])
                wallv.push_back({i, j});
        }

    // 3개의 벽 새우기 
    int ans = 0;
    for(int i=0; i < wallv.size(); i++)
    {
        for(int j=i+1; j < wallv.size(); j++)
        {
            for(int k=j+1; k < wallv.size(); k++)
            {
                map[wallv[i].first][wallv[i].second] = 1;
                map[wallv[j].first][wallv[j].second] = 1;
                map[wallv[k].first][wallv[k].second] = 1;
                ans = max(solve(), ans);
                // 초기화
                map[wallv[i].first][wallv[i].second] = 0;
                map[wallv[j].first][wallv[j].second] = 0;
                map[wallv[k].first][wallv[k].second] = 0;
                // 방문 초기화
                for(int i=0; i < n; i++)
                    fill(visited[i], visited[i] + m, 0);
            }
        }
    }
    cout << ans << endl;
        
    return 0;
}