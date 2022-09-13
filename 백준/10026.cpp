#include <iostream>

using namespace std;

// map 
int n, m;
char map[1004][1004];
bool Rvisited[1004][1004];
bool Gvisited[1004][1004];
bool Bvisited[1004][1004];
bool RGvisited[1004][1004];

// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// xy
int rx, ry;
int gx, gy;
int bx, by;
int rgx, rgy;

void Rdfs(int ry, int rx)
{
    Rvisited[ry][rx] = 1;

    for(int i=0; i < 4; i++)
    {
        int ny = ry + dy[i];
        int nx = rx + dx[i];

        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;

        if(!Rvisited[ny][nx] && map[ny][nx] == 'R')
            Rdfs(ny, nx);
    }
    return;
}
void Gdfs(int gy, int gx)
{
    Gvisited[gy][gx] = 1;

    for(int i=0; i < 4; i++)
    {
        int ny = gy + dy[i];
        int nx = gx + dx[i];

        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;

        if(!Gvisited[ny][nx] && map[ny][nx] == 'G')
            Gdfs(ny, nx);
    }
    return;
}

void Bdfs(int by, int bx)
{
    Bvisited[by][bx] = 1;

    for(int i=0; i < 4; i++)
    {
        int ny = by + dy[i];
        int nx = bx + dx[i];

        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;

        if(!Bvisited[ny][nx] && map[ny][nx] == 'B')
            Bdfs(ny, nx);
    }
    return;
}

void RGdfs(int rgy, int rgx)
{
    RGvisited[rgy][rgx] = 1;

    for(int i=0; i < 4; i++)
    {
        int ny = rgy + dy[i];
        int nx = rgx + dx[i];

        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;

        if(!RGvisited[ny][nx] && (map[ny][nx] == 'R' || map[ny][nx] == 'G'))
            RGdfs(ny, nx);
    }
    return;
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
            map[i][j] = str[j];
    }

    int R = 0;
    int G = 0;
    int B = 0; 
    int RG = 0;

    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
        {
            if(!Rvisited[i][j] && map[i][j] == 'R')
            {
                R++;
                Rdfs(i, j);
            }
            if(!Gvisited[i][j] && map[i][j] == 'G')
            {
                G++;
                Gdfs(i, j);
            }
            if(!Bvisited[i][j] && map[i][j] == 'B')
            {
                B++;
                Bdfs(i, j);
            }
            if(!RGvisited[i][j] && (map[i][j] == 'R' || map[i][j] == 'G'))
            {
                RG++;
                RGdfs(i, j);
            }
        }

    cout << R + G + B << " " << RG + B << endl;

    // // map 출력
    // for(int i=0; i < n; i++)
    // {
    //     for(int j=0; j < m; j++)
    //         cout << map[i][j] << " ";
    //     cout << endl;
    // }
    
    return 0;
}