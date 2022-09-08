#include <iostream>
#include <vector>

using namespace std;

vector<int> v[104];
bool visited[104];

int n, m, a, b;
int cnt = 0;
void dfs(int srt)
{
    cnt++;
    visited[srt] = 1;

    for(auto &el : v[srt])
        if(!visited[el])
            dfs(el);
    return;
}

int main()
{
    cin >> n >> m;
    for(int i=0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    cout << cnt-1 << endl;
    return 0;
}