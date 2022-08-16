#include <iostream>
#include <queue>

using namespace std;

// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// map 
bool map[101][101];
int visited [101][101];
// map 크기 
int n, m;
// 현 위치 
int x, y;

int main()
{
    cin >> n >> m;

    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;

        // map 생성 
        for(int j=0; j < m; j++)
        {
            if(str[j] == '1')
                map[i][j] = 1;
        }
    }
    // (1, 1)에서 출발 함으로 해당 좌표 방문처리
    visited[0][0] = 1;

    queue<pair<int, int>> q;
    // 방문한 곳 푸쉬
    q.push({0, 0});
    while(q.size())
    {
        // 현재 위치 값 초기화
        y = q.front().first;
        x = q.front().second;
        q.pop();
        // joy 탐색
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            // 범위 값을 넘어갈 경우, 이미 방문한 경우, 벽인 경우 
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || !map[ny][nx])
                continue;
            if(visited[ny][nx])
                continue;
            // 위 조건이 아닐 경우 가산 값 추가     
            visited[ny][nx] += visited[y][x] + 1;
            // 방문한 다음 위치 다시 푸쉬
            q.push({ny, nx});
        }
    }
    // 최단 거리 맵 출력
    // for(int i=0; i < n; i++)
    // {
    //     for(int j=0; j < m; j++)
    //     {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << visited[n-1][m-1] << endl;
    return 0;
}