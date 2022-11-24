#include <iostream>
#include <vector>

using namespace std;


// map 
int n, m, k;
int map[204][204];
int visited[204][204];
int sy, sx, ss;
// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v[1004];
vector<pair<int, int>> tmp[1004];


void spread(int y, int x, int color)
{ 
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= n || nx >= m || ny < 0 || nx < 0)
            continue;
        if(!map[ny][nx])
        {
            map[ny][nx] = color;
            tmp[color].push_back({ny, nx});
        }
    }
}


int main()
{
    cin >> n >> k;
    m = n;
    int mx=0;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
        {
            cin >> map[i][j];
            if(map[i][j])
                v[map[i][j]].push_back({i, j});
            mx = max(mx, map[i][j]);
        }

    cin >> ss >> sy >> sx;

    for(int j=0; j < ss; j++)
        for(int i=0; i <= mx; i++)
        {
            while(v[i].size())
            {
                spread(v[i].front().first, v[i].front().second , i);
                v[i].erase(v[i].begin());
            }
            while(tmp[i].size())
            {
                v[i].push_back({tmp[i].front().first, tmp[i].front().second});
                tmp[i].erase(tmp[i].begin());
            }
        }

    cout << map[sy-1][sx-1] << endl;
    return 0;
}