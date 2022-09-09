#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;

vector<int> v[1004];
bool visited[1004];

int n, m, srt, a, b;

void dfs(int idx)
{
    visited[idx] = 1;
    cout << idx << " ";
    for(auto &el : v[idx])
        if(!visited[el])
            dfs(el);
}

void bfs(int idx)
{
    queue<int> q;
    q.push(idx);
    visited[idx] = 1;
    while(q.size())
    {
        int y = q.front();
        cout << y << " ";
        q.pop();
        for(auto &el : v[y])
            if(!visited[el])
            {
                visited[el] = 1;
                q.push(el);
            }
    } 
}

int main()
{
    cin >> n >> m >> srt;
    for(int i=0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i <= n; i++)
        sort(v[i].begin(), v[i].end());
    
    dfs(srt);
    cout << endl;

    fill(visited, visited + n+1, 0);
    bfs(srt);
   
    
    cout << endl;
    return 0;
}