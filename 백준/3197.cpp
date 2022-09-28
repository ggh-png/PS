#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// map 
int n, m;
char map[1505][1505];
bool meltvisited[1505][1505];
bool movevisited[1505][1505];
// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
// ans 
bool flag = 1;
int ly, lx;
int ans = 0;
// q
queue<pair<int, int>> meltq;
queue<pair<int, int>> moveq;
queue<pair<int, int>> tmpmelt;
queue<pair<int, int>> tmpmove;



void clearQ(queue<pair<int, int>> &q)
{
    queue<pair<int, int>> eq;
    swap(eq, q);
}


void melt()
{
    while(meltq.size())
    {
        int y = meltq.front().first;
        int x = meltq.front().second;
        meltq.pop();
        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            // 방문하지 않았고, 빙판인 경우 
            else if(!meltvisited[ny][nx] && map[ny][nx] == 'X')
            {
                meltvisited[ny][nx] = 1;
                map[ny][nx] = '.';
                // 임시 큐에 저장 
                tmpmelt.push({ny, nx});
            }
        }
    }
}


void movedfs()
{
    while(moveq.size())
    {
        int y = moveq.front().first;
        int x = moveq.front().second;
        moveq.pop();

        for(int i=0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            // 방문하지 않았고, 호수인 경우 
            if(!movevisited[ny][nx] && map[ny][nx] == '.')
                moveq.push({ny, nx});
            // 방문하지 않았고, 빙하인 경우 
            else if(!movevisited[ny][nx] && map[ny][nx] == 'X')
                tmpmove.push({ny, nx});
            // 방문하지 않았고, 백조를 만난경우 
            else if(!movevisited[ny][nx] && map[ny][nx] == 'L')
            {
                flag = 0;
                return;
            }
            movevisited[ny][nx] = 1;
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
        for(int j=0; j < m; j++)
        {
            cin >> map[i][j];
            // 백조인 경우 
            if(map[i][j] == 'L')
            {
                ly = i;
                lx = j;
            }
            // 물인 경우 || 백조인 경우 
            if(map[i][j] == 'L' || map[i][j] == '.')
            {
                meltq.push({i, j});
                meltvisited[i][j] = 1;
            }
        }

    moveq.push({ly, lx});
    movevisited[ly][lx] = 1;
    while(flag)
    {
        // 백조 움직이기 
        movedfs();
        // 빙하 녹이기 
        melt();
        // map 출력
        // for(int i=0; i < n; i++)
        // {
        //     for(int j=0; j < m; j++)
        //         cout << map[i][j] << ' ';
        //     cout << endl;
        // }
        // 버퍼에 담긴 큐 복사 
        moveq = tmpmove;
        meltq = tmpmelt;
        clearQ(tmpmelt);
        clearQ(tmpmove);
        ans++;
    }
    cout << ans-1 << '\n';
    // for(int i=0; i < n; i++)
    // {
    //     for(int j=0; j < m; j++)
    //         cout << map[i][j] << ' ';
    //     cout << endl;
    // }
    return 0;
}