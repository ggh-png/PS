#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// map 
int n, m;
int map[1004][1004];
int visited[1004][1004];

// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// 현 위치, 익은 토마도 위치
int x, y, tx, ty;

vector<pair<int, int>> v;

int main()
{
    cin >> m >> n;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
        {
            cin >> map[i][j];
            // 익은 도마도 위치
            if(map[i][j] == 1)
                v.push_back({i, j});
        }

    queue<pair<int, int>> q;
    // 초기 위치 입력, 방문처리 
    for(auto &el : v)
    {   // 익은 토마토가 2개 이상일 경우 
        q.push({el.first, el.second});
        visited[el.first][el.second] = 1;
        map[el.first][el.second] = 1004;
    }
    int ans;
    while (q.size())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 범위값 확인
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == -1)
                continue;
            if(visited[ny][nx])
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            map[ny][nx] = 1004;
            q.push({ny, nx});
        }
    }
    bool flag = 0;
    int max = 0;

    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
        {   // 익지 않은 토마토가 있을 경우 
            if(!map[i][j])
            {
                flag = 1;
                break;
            }   
            if(max < visited[i][j])
                max = visited[i][j];
        }

    if(flag)
        cout << -1 << endl;
    else
        cout << max - 1 << endl;
    // map 출력

    // for(int i=0; i < n; i++)
    // {
    //     for(int j=0; j < m; j++)
    //         cout << visited[i][j] << " ";
    //     cout << endl;
    // }
    return 0;

}