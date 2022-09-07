
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> q;
vector<int> gp[100004];
bool visited[100004];
int ans[100004];
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
        gp[a].push_back(b);
        gp[b].push_back(a);        
    }

    for(int i=1; i <= n; i++)
        sort(gp[i].begin(), gp[i].end(), greater<int>());

    q.push(srt);
    visited[srt] = 1;
    ans[srt] = 1;
    int cnt = 1;
    while(q.size())
    {
        int y = q.front();
        q.pop();
        for(auto &el : gp[y])
            if(!visited[el])
            {
                visited[el] = 1;
                ans[el] = ++cnt;
                q.push(el);
            }
    }
    for(int i=1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}