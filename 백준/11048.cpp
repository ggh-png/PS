#include <iostream>
#include <queue>

using namespace std;


// map
int n, m;
bool visited[1004][1004];
int map[1004][1004];
int ans[1004][1004];

// joy 
int dy[] = {0, 1, 1};
int dx[] = {1, 0, 1};


void solv(int sy, int sx)
{
    queue<pair<int, int>> q;
    q.push({sy, sx});
    ans[sy][sx] = map[sy][sx];
    while (q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i < 3; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny >= n || nx >= m || ny < 0 || nx < 0)
                continue;
            // 방문치 않은경우 
            if(!visited[ny][nx]) 
            {
                visited[ny][nx] = 1;
                ans[ny][nx] = ans[y][x] + map[ny][nx];
                q.push({ny, nx});
            }
            // 방문 했지만, 이전 값보다 작은 경우 
            else if(ans[ny][nx] < ans[y][x] + map[ny][nx])
            {
                ans[ny][nx] = ans[y][x] + map[ny][nx];
                q.push({ny, nx});
            }    
        }
    }
}


int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];
    solv(0, 0);
    cout << ans[n-1][m-1] << endl;
    

    return 0;
}