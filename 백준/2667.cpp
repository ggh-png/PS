#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// map
int n, m;
bool map[1004][1004];
bool visited[1004][1004];

// joy 
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int x, y;

// 단지수, 가구수
int cnt;
vector<int> v;

void dfs(int y, int x)
{
    visited[y][x] = 1;
    cnt++;
    for(int i=0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 범위
        if(ny < 0 || nx < 0 || ny >= n || nx >= m)
            continue;
        // 방문하지 않았고, 집이 있으면
        if(!visited[ny][nx] && map[ny][nx])
        {
            dfs(ny, nx);
        }
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
        {
            if(str[j] == '0')
                map[i][j] = 0;
            else
                map[i][j] = 1;
        }
    }
        
    
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            if(!visited[i][j] && map[i][j])
            {
                cnt = 0;
                dfs(i, j);
                v.push_back(cnt);
            }
    

    // 오름차순 정렬
    sort(v.begin(), v.end());

    // 출력
    cout << v.size() << '\n';
    for(auto &el : v)
        cout << el << '\n';


    return 0;
}