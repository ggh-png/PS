#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> gp[200004];
bool visited[200004];
int ans[200004];

int cnt = 0;
void dfs(int idx)
{
    // 방문순서 
    ans[idx] = ++cnt;

    visited[idx] = 1;
    for(auto &el : gp[idx])
        if(!visited[el])
            dfs(el);
    return;
}

int n, m, a, b, srt;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin >> n >> m >> srt;
    for(int i=0; i < m; i++)
    {
        cin >> a >> b;
        // 양 방향 간선이기 떄문에 
        gp[a].push_back(b);
        gp[b].push_back(a);
    }

    for(int i=1; i <= n; i++)
        sort(gp[i].begin(), gp[i].end(), greater<int>());
    dfs(srt);
    //cout << 0 << '\n';
    for(int i=1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}