#include <iostream>
using namespace std;

/*
point 
주어진 맵의 인접한 곳들은 모두 하나의 ans값으로 취급한다.
1. 맵 생성 후 주어진 좌표에 배추를 심는다. 
2. 맵 전체를 순회 하면서 dfs를 실행시킨다.
*/
// 배추밭, 방문여부, 배추밭의 크기
int n, m;
bool map[51][51];
bool visited[51][51];
// 좌표
int x, y;
// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x)
{
    // 방문 
    visited[y][x] = 1;
    // 동서남북 탐색 
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        // 주어진 배추밭의 크기를 넘기면 콘티뉴
        if(ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        // 배추가 존재하고, 방문하지 않을 경우
        // 즉, 인접해 있을 경우 방문
        if(map[ny][nx] == 1 && !visited[ny][nx])
            dfs(ny, nx);
    }
    // 인접하지 않을 경우 함수 종료
    return;
}

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        // 지렁이의 필요 개수
        int ans = 0;
        // 배추밭의 크기, 배추의 개수 입력
        int N;
        cin >> m >> n >> N;
        // 배추 심기
        for(int j=0; j < N; j++)
        {
            int tmpx, tmpy;
            cin >> tmpx >> tmpy;
            map[tmpy][tmpx] = 1;
        }
        // 배추밭 탐색
        for(int j=0; j < n; j++)
            for(int k=0; k < m; k++)
                // 배추가 존재하고, 방문하지 않았다면
                if(map[j][k] == 1 && !visited[j][k])
                {
                    ans++;
                    dfs(j, k);
                }
                
        // 필요 지렁이 개수 출력
        cout << ans << '\n';
        //배추밭 출력
        // for(int j=0; j < n; j++)
        // {
        //     for(int k=0; k < m; k++)
        //         cout << map[j][k] << " ";
        //     cout << endl;   
        // }
        
        // 배추밭 초기화 
        for(int j=0; j < 51; j++)
            for(int k=0; k < 51; k++)
            {
                map[j][k] = 0;
                visited[j][k] = 0;
            }
    }

    return 0;
}