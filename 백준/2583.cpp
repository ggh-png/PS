#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// x1, y1, x2, y2 사각형의 영역 칠하기 
// map
bool map[101][101];
bool visited[101][101];
// 현 위치
int x, y;
// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int m, n, a;
int cnt=0;
void dfs(int y, int x)
{
    visited[y][x] = 1;
    cnt++;
    // joy
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 범위 확인
        if(ny < 0 || nx < 0 || ny >= m || nx >= n)
            continue;
        // 갈 수 있는 구간이고, 방문하지 않았더라면
        if(!map[ny][nx] && !visited[ny][nx])
            dfs(ny, nx);
    }
    return;
}



int main()
{

    cin >> m >> n >> a;

    for(int i=0; i < a; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int j=y1; j < y2; j++)
            for(int k=x1; k < x2; k++)
                map[j][k] = 1;
    }

    int ans=0;
    // map 탐색
    vector<int> v;
    for(int i=0; i < m; i++)
        for(int j=0; j < n; j++)
            if(!map[i][j] && !visited[i][j])
            {
                ans++;
                dfs(i, j);
                v.push_back(cnt);
                cnt = 0;
            }
    
    sort(v.begin(), v.end());
    cout << ans << endl;
    for(auto &el : v)
        cout << el << " ";
    cout << endl;
    
    // map 출력 
    // for(int i=0; i < m; i++)
    // {
    //     for(int j=0; j < n; j++)
    //         cout << map[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}