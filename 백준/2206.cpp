#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// map
int n, m;
bool map[1004][1004];
int visited[1004][1004][2];
// answer
int dp[1004];
int ans;
// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int x, y, bk;



int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j < m; j++)
        {
            if(str[j] == '1')
                map[i][j] = 1;
        }
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0][1] = 1;
    while(q.size())
    {
        y = q.front().first.first;
        x = q.front().first.second;
        bk = q.front().second;
        q.pop();
        if(y == n-1 && x == m-1)
        {
            ans = visited[y][x][bk];
            break;
        }
        
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            
            // 벽으로 막혀 있고, 벽이 부순 경험이 없고(bk == 1), 방문한 적이 없는 경우
            if(map[ny][nx] && bk && !visited[ny][nx][bk-1])
            {
                // 방문한 벽을 부수고, 가중치 입력 
                visited[ny][nx][bk-1] = visited[y][x][bk] + 1;
                q.push({{ny, nx}, bk-1});
            }
            // 길이고, 방문하지 않았을 경우 
            else if(!map[ny][nx] && !visited[ny][nx][bk])
            {
                // 가중치를 입력하고, 벽을 부순 여부는 그대로 이행
                visited[ny][nx][bk] = visited[y][x][bk] + 1;
                q.push({{ny, nx}, bk});
            }
        }
    }
    if(ans != 0)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}