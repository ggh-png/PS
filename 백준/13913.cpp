#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// trace
const int MAX = 200005;
int trace[MAX];
int visited[MAX];

int n, m;

vector<int> v;

void bfs(int idx)
{
    queue<int> q;
    q.push(idx);
    visited[idx] = 1;
    trace[idx] = 1;
    while(q.size())
    {
        int t = q.front();
        q.pop();
        if(t == m)
        {
            cout << visited[t] - 1 << endl;
            break;
        }
        for(auto &el : {t-1, t+1, t*2})
            if(el >= 0 && el < MAX)
                if(!visited[el])
                {
                    q.push(el);
                    trace[el] = t;
                    visited[el] = visited[t] + 1;
                }
    }
    for(int i=m; i != n; i = trace[i])
        v.push_back(i);
    v.push_back(n);
    reverse(v.begin(), v.end());
}

int main()
{
    cin >> n >> m;
    bfs(n);
    
    for(auto &el : v)
        cout << el << " ";
    cout << endl;
    return 0;
}