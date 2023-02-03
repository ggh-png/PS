#include <iostream>
#include <vector>
using namespace std;

char cookie[1004][1004];
bool visited[1004][1004];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

vector<pair<int, int>> v;

pair<int, int> heart;
// 왼 오 팔
int l_arm, r_arm;
// 허리 
int stick;
// 왼 오 다리
int l_leg, r_leg;


int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
        for(int j=0; j < num; j++)
        {
            cin >> cookie[i][j];
            if(cookie[i][j] == '*')
                v.push_back({i, j});
        }
    // 심장 탐색 
    for(auto &el : v)
    {
        int cnt = 0;
        for(int i=0; i < 4; i++)
        {
            int ny = el.first + dy[i];
            int nx = el.second + dx[i];
            if(ny < 0 || ny >= num || nx >= num || nx < 0)
                continue;
            if(cookie[ny][nx] == '*')
                cnt++;
        }
        if(cnt == 4)
        {
            heart.first = el.first;
            heart.second = el.second;
        }
    }
    // 왼오 팔 
    int cnt = 0;
    while(1)
    {
        int ny = heart.first + dy[3];
        int nx = heart.second + dx[3] - l_arm;
        if(ny < 0 || ny >= num || nx >= num || nx < 0)
            break;
        if(cookie[ny][nx] == '*')
            l_arm++;
        else
            break;
    }
    while(1)
    {
        int ny = heart.first + dy[1];
        int nx = heart.second + dx[1] + r_arm;
        if(ny < 0 || ny >= num || nx >= num || nx < 0)
            break;
        if(cookie[ny][nx] == '_')
            break;
        else
            r_arm++;
    }
    // 허리
    // 왼 오 다리 시작 
    pair<int, int> st, st_l, st_r;

    while(1)
    {
        int ny = heart.first + dy[2] + stick;
        int nx = heart.second + dx[2];
        if(ny < 0 || ny >= num || nx >= num || nx < 0)
            break;
        if(cookie[ny][nx] == '_')
            break;
        else
            stick++;
    }
    st.first = heart.first + stick-1;
    st.second = heart.second;

    st_l.first = st.first+1;
    st_l.second = st.second-1;
    st_r.first = st.first+1;
    st_r.second = st.second+1;
    
    // 왼 오 다리 
    
    while(1)
    {
        int ny = st_l.first + dy[2] + l_leg;
        int nx = st_l.second + dx[2];
        if(ny < 0 || ny >= num || nx >= num || nx < 0)
            break;
        if(cookie[ny][nx] == '_')
            break;
        else
            l_leg++;
    }
    while(1)
    {
        int ny = st_r.first + dy[2] + r_leg;
        int nx = st_r.second + dx[2];
        if(ny < 0 || ny >= num || nx >= num || nx < 0)
            break;
        if(cookie[ny][nx] == '_')
            break;
        else
            r_leg++;
    }
    cout << heart.first+1 << " " << heart.second+1 << endl;
    cout << l_arm << " " << r_arm << " ";
    cout << stick << " ";
    cout << l_leg << " " << r_leg << endl;
    return 0;
}