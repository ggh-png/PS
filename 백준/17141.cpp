#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// map
int n, m;
int map[55][55];
int visited[55][55];
bool combi[55];
// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// ans
int ans = 987654321;

// virus

vector<pair<int, int>> buff;

vector<pair<int, int>> VirusPos;
vector<pair<int, int>> check;




void virus()
{
    fill(&visited[0][0], &visited[n][n], 0);
    queue<pair<int, int>> q;
    for(int i=0; i < buff.size(); i++)
    {
        q.push({buff[i].first, buff[i].second});
        visited[buff[i].first][buff[i].second] = 1;
    }
    while(q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n || map[ny][nx] == 1)
                continue;
            // 방문하지 않았고, 감염 가능한 경우 
            if(!visited[ny][nx])
            {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
    return;
}

// virus add 
void virusadd(int idx, int cnt)
{   // 바이러스를 다 써버리면 
    if(cnt == m)
    {
        virus();
        bool flag = 0;
        int tmp = 0;
        for(auto &el : check)
        {
            int ff = el.first;
            int ss = el.second;
            if(visited[ff][ss] == 0)
            {
                flag = 1;
                break;
            }
            else
                tmp = max(visited[ff][ss], tmp);
        }
        if(!flag)
            ans = min(ans, tmp);
        // cout << " ---- " << endl;
        // for(int i=0; i < n; i++)
        // {
        //     for(int j=0; j < n; j++)
        //         cout << visited[i][j] << " ";
        //     cout << endl;
        // }
        // cout << ans << endl;
        return;
    }
    for(int i=idx; i < VirusPos.size(); i++)
    {
        if(combi[i])
            continue;
        else
        {
            combi[i] = 1;
            buff.push_back({VirusPos[i].first, VirusPos[i].second});
            virusadd(i, cnt+1);
            buff.pop_back();
            combi[i] = 0;
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 2)
                VirusPos.push_back({i, j});
            if(map[i][j] == 0 || map[i][j] == 2)
                check.push_back({i, j});
        }
    virusadd(0, 0);
    if(ans == 987654321)
        cout << -1 << '\n';
    else
        cout << ans-1 << '\n';
    return 0;
}
