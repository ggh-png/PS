#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct Coords {int y,x;};
// map
int n, m;
char map[6][6];
bool see[6][6];
// joy
int dy[] = {0,0,-1,1};
int dx[] = {1,-1,0,0};

// 선생 좌표 
vector<Coords> teach;
// 벽을 새울 수 있는 좌표 
vector<Coords> wall;
vector<Coords> student;
bool ans;
// 학생을 찾았다면 
void check_student()
{
    for(auto el : teach)
    {
        int ny = el.y;
        int nx = el.x;
        see[ny][nx] = 1;
        for(int i=0; i < 4; i++)
            while(1)
            {
                ny += dy[i];
                nx += dx[i];
                if(ny >= m || nx >= n || ny < 0 || nx < 0)
                    break;
                if(map[ny][nx] == 'O')
                    break;
                see[ny][nx] = 1;
            }
    }
}


void combi(int cnt, int idx)
{
    if(cnt == 3)
    {
        memset(see,0,sizeof(see));
        check_student();
        // 학생 확인 
        for(auto &el : student)
            if(see[el.y][el.x])
                return;
        
        ans = 1;
        return;
    }
    for(int i=idx; i < wall.size(); i++)
    {
        int wy = wall[i].y;
        int wx = wall[i].x;
        map[wy][wx] = 'O';
        combi(cnt+1, i+1);
        map[wy][wx] = 'X';
    }

}


int main()
{
    cin >> n;
    m = n;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
        {
            cin >> map[i][j];
            // 선생이면 
            if(map[i][j] == 'T')
                teach.push_back({i, j});
            if(map[i][j] == 'X')
                wall.push_back({i, j});
            if(map[i][j] == 'S')
                student.push_back({i, j});
        }

    combi(0, 0);
    if(ans)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}