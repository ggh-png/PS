#include <iostream>
#include <vector>

using namespace std;

vector<int> v[10004];
int visited[10004];
int dp[10004];

int n, m, a, b, mx;

// root node를 찾아라
int dfs(int here)
{
    int ret = 1;
    visited[here] = 1;
    for(auto &el : v[here])
    {   // 방문했음 넘기고 
        if(visited[el])
            continue;
        ret += dfs(el);
    }
    return ret;
}

int main()
{
    cin >> n  >> m;

    for(int i=0; i < m; i++)
    {
        cin >> a >> b;
        v[b].push_back(a);
    }
    for(int i=1; i <= n; i++)
    {
        // 방문 초기화 
        fill(visited, visited + 10004, 0);
        // 노드 i에 따른 값 저장.
        dp[i] = dfs(i);
        // 최댓값 
        mx = max(dp[i], mx);
    }

    for(int i=1; i <= n; i++)
        if(mx == dp[i])
            cout << i << " ";

    cout << endl;
    
    return 0;
}