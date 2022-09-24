#include <iostream>
#include <deque>

using namespace std;

// map
const int MAX = 200004;
int visited[MAX];

int n, m, ans;

void bfs(int idx)
{
    deque<int> dq;
    dq.push_back(idx);
    visited[idx] = 1;
    while(dq.size())
    {
        int t = dq.front();
        dq.pop_front();
        if(t == m)
        {
            ans = visited[t];
            break;
        }
        if(!visited[t*2] && t*2 >= 0 && t*2 <= MAX)
        {
            visited[t*2] = visited[t];
            dq.push_front(t*2);
        }
        for(auto &el : {t+1, t-1})
            if(el >= 0 && el <= MAX)
                if(!visited[el])
                {
                    visited[el] = visited[t] + 1;
                    dq.push_back(el);
                }
    }
}

int main()
{
    cin >> n >> m;
    bfs(n);
    cout << ans-1 << endl;
    return 0;
}
