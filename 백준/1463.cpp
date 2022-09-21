#include <iostream>
#include <queue>

using namespace std;

// map
long long map[1000004];
long long visited[1000004];
// joy
int dt[] = {3,2,1};
int t;
int ans;
// bfs
void bfs(int sidx)
{
    queue<int> q;
    q.push(sidx);
    visited[sidx] = 1;
    while(q.size())
    {
        t = q.front();
        q.pop();
        if(t == 1)
        {
            ans = visited[t];
            break;
        }
        int nt3 = (t%3 == 0) ? t/3 : t;
        int nt2 = (t%2 == 0) ? t/2 : t;
        int nt1 = t-1;
        if(!visited[nt3])
        {   
            visited[nt3] = visited[t] + 1;
            q.push(nt3);
        }
        if(!visited[nt2])
        {   
            visited[nt2] = visited[t] + 1;
            q.push(nt2);
        }
        if(!visited[nt1])
        {   
            visited[nt1] = visited[t] + 1;
            q.push(nt1);
        }
    }
}



int main()
{
    int tmp;
    cin >> tmp;
    bfs(tmp);
    cout << ans-1 << endl;
    return 0;
}