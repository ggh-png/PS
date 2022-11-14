#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// map
int n, m;
int map[55][55];
int visited[55][55][255];

// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<int> v;

void bfs(int sy, int sx, int sbk)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({{sy, sx}, sbk});
    while(q.size())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int bk = q.front().second;

        if(y == n-1 && x == m-1)
            v.push_back(bk);

        q.pop();
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if(map[ny][nx] && !visited[ny][nx][bk])
            {
                visited[ny][nx][bk] = visited[y][x][bk] + 1;
                q.push({{ny, nx}, bk});
            }
            if(!map[ny][nx] && !visited[ny][nx][bk+1])
            {
                visited[ny][nx][bk+1] = visited[y][x][bk] + 1;
                q.push({{ny, nx}, bk+1});
            }
        }
    }
}

int main()
{
    cin >> n;
    m = n;
    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j < m; j++)
            map[i][j] = str[j] - 48;
    }

    bfs(0, 0, 0);
    sort(v.begin(), v.end());
    
    cout << v[0] << endl;

    return 0;
}