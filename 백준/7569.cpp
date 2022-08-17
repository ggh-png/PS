#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// map 
int n, m, h;
int map[104][104][104];
int visited[104][104][104];

// joy
int dy[] = {0, 0, -1, 0, 1, 0};
int dx[] = {0, 0, 0, 1, 0, -1};
int dz[] = {1, -1, 0, 0, 0, 0};
// 현 위치, 익은 토마도 위치
int x, y, z;

class tomato
{
public:
    int tx, ty, tz;
};


vector<tomato> v;
queue<tomato> q;

int main()
{
    cin >> m >> n >> h;
    
    for(int k=0; k < h; k++)
        for(int i=0; i < n; i++)
            for(int j=0; j < m; j++)
            {
                cin >> map[k][i][j];
                // 익은 도마도 위치
                if(map[k][i][j] == 1)
                    v.push_back({j, i, k});
            }

    
    // 초기 위치 입력, 방문처리 
    for(auto &el : v)
    {   // 익은 토마토가 2개 이상일 경우 
        q.push({el.tx, el.ty, el.tz});
        visited[el.tz][el.ty][el.tx] = 1;
        map[el.tz][el.ty][el.tx] = 1004;
    }
    
    while (q.size())
    {
        z = q.front().tz;
        y = q.front().ty;
        x = q.front().tx;
        q.pop();
        for(int i=0; i < 6; i++)
        {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 범위값 확인
            if(nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m || map[nz][ny][nx] == -1)
                continue;
            if(visited[nz][ny][nx])
                continue;
            
            visited[nz][ny][nx] = visited[z][y][x] + 1;
            map[nz][ny][nx] = 1004;
            q.push({nx, ny, nz});
        }
    }
    bool flag = 0;
    int max = 0;
    for(int k=0; k < h; k++)
        for(int i=0; i < n; i++)
            for(int j=0; j < m; j++)
            {   // 익지 않은 토마토가 있을 경우 
                if(!map[k][i][j])
                {
                    flag = 1;
                    break;
                }   
                if(max < visited[k][i][j])
                    max = visited[k][i][j];
            }

    if(flag)
        cout << -1 << endl;
    else
        cout << max - 1 << endl;
    // map 출력

    // for(int k=0; k < h; k++)
    // {
    //     for(int i=0; i < n; i++)
    //     {
    //         for(int j=0; j < m; j++)
    //             cout << visited[k][i][j] << " ";
    //         cout << endl;
    //     }
    //     cout << "---------" << endl;
    // }

    return 0;

}