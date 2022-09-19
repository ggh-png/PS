#include <iostream>
#include <vector>

using namespace std;


// map
int N;
int map[55][55];
int tmpmap[55][55];
int visited[55][55];

// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int y, x;

// 국경이 열려있는 곳의 좌표 벡터
vector<pair<int, int>> v;
// 인구 차 기준 
int mn, mx;
int sub;
// 열린 국가들의 인구 합
int sum; 
int num=1;
// ans 
int ans  = 0;
int answer = 0;
bool flag = 0;


void dfs(int y, int x)
{
    visited[y][x] = 1;
    sum += map[y][x];
    num++;
    // 국경이 열린 죄표 저장 
    v.push_back({y, x});
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        // 인구차 
        sub = abs(map[y][x] - map[ny][nx]);
        // 방문하지 않고, 국경이 열리는 조건일 경우 
        if(!visited[ny][nx] && sub >= mn && sub <= mx)
        {
            flag = 1;
            dfs(ny, nx);
        }
    }
    return;
}

int main()
{
    cin >> N >> mn >> mx;
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            cin >> map[i][j];

    while(1)
    {
        flag = 0;
        for(int i=0; i < N; i++)
        {
            for(int j=0; j < N; j++)
            {
                tmpmap[i][j] = map[i][j];
                sum = 0;
                num = 0;
                if(!visited[i][j])
                {
                    dfs(i, j);
                    int tmp = sum / num;
                    // 인구 이동을 해야하는 경우 
                    if(v.size())
                    {
                        ans++;
                        for(auto &el : v)
                            map[el.first][el.second] = tmp;
                    }
                    v.clear();
                }
            }
        }
        fill(&visited[0][0], &visited[N][N], 0);
        
        // 인구이동이 있었는가 확인
        if(flag == 1)
            answer++;
        // 없었다면 종료
        if(!flag)
            break;
    }
    cout << answer << endl;    
    return 0;
}