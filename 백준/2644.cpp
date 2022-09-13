#include <iostream>
#include <vector>

using namespace std;

vector<int> gp[104];

bool visited[104];

int n, m, num, a, b, c, d;

int cnt = 0;
int ans;
bool flag = 1;
void dfs(int idx)
{  
    visited[idx] = 1;
    for(auto &el : gp[idx])
        if(!visited[el])
        {
            cnt++;
            if(el == d)
            {
                ans = cnt;
                flag = 0;
                return;
            }
            dfs(el);
            // 그래프의 끝점에 다다를 경우 감소
            cnt--;
        }
    return;
}


int main()
{
    cin >> n;
    cin >> c >> d;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        cin >> a >> b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }

    dfs(c);
    if(flag)
        cout << -1 << endl;
    else 
        cout << ans << endl;

    return 0;
}