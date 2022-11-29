#include <iostream>
#include <vector>

using namespace std;

// map
vector<int> map[1004];
int visited[1004];
int n, m;
int cnt = 0;

void dfs(int idx)
{
    visited[idx] = 1;
    for(auto &el : map[idx])
    {
        int index = el;
        if(!visited[index])
            dfs(el);
    }
}

int main()
{
    cin >> n >> m;
    int u, v;
    // 연결 리스트 생성 
    for(int i=0; i < m; i++)
    {
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    // 완전 탐색, 방문하지 않았더라면 == 간선++
    for (int i = 1; i <= n; i++) 
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    
    cout << cnt;
    return 0;
}