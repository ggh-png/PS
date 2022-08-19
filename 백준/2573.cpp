#include <iostream>

using namespace std;

//map
int n, m;
int map[301][301];
bool visited[301][301];

// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// x, y
int x, y;

void dfs(int y, int x)
{
    visited[y][x] = 1;

    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 범위 값 확인
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if(visited[ny][nx])
            continue;
        if(!map[ny][nx])
        {
            map[y][x] -= 1;
            if(!map[y][x])
                return;
            else
                continue;
        }
        dfs(ny, nx);
    }
    return;
}

void check_dfs(int y, int x)
{
    visited[y][x] = 1;

    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 범위 값 확인
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        if(visited[ny][nx] || !map[ny][nx]) 
            continue;

        check_dfs(ny, nx);
    }
    return;

}


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> m;
    // map input
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];
    int ans = 0;
    while(1)
    {
        // 빙산 녹이기 
        int count = 0;
        for(int i=0; i < n; i++)
            for(int j=0; j < m; j++)
            {
                if(map[i][j])
                    count += map[i][j];
                if(!visited[i][j] && map[i][j])
                    dfs(i, j);
            }
    
        // 방문 초기화
        fill(&visited[0][0], &visited[n][m], 0);
        
        // 빙산의 개수 측정 
        int cnt = 0;
        for(int i=0; i < n; i++)
            for(int j=0; j < m; j++)
                if(!visited[i][j] && map[i][j])
                {
                    check_dfs(i, j);
                    cnt++;
                }    
        // 방문 초기화
        fill(&visited[0][0], &visited[n][m], 0);

        // 빙산 개수 확인 check dfs

        //map 출력
        // cout << "-----------" << endl;
        // for(int i=0; i < n; i++)
        // {
        //     for(int j=0; j < m; j++)
        //         cout << map[i][j] << " ";
        //     cout << endl;
        // }

        // 걸리는 일수 ++
        ans++;
       
        // 빙산이 두조각 이상으로 쪼개지면 종료
        if(cnt >= 2)
            break;
        // 빙산이 두조각으로 쪼개지지 않고 빙산이 녹아 없어지면 0으로 반환 및 종료
        if(!count)
        {
            ans = 0;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}