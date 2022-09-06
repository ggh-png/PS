#include <iostream>
#include <vector>

using namespace std;
int delNum;
vector<int> v[51];
bool visited[51];
int cnt = 0;
// 방문 횟수  dfs 
int dfs(int idx)
{
    int ret = 0;
    int child = 0;
    
    for(int i=0; i < v[idx].size(); i++)
    {
        // 삭제된 노드면 넘긴다.  
        if(v[idx][i] == delNum)
            continue;
        // 자식 노드를 방문하지 않았더라면
        ret += dfs(v[idx][i]);
        child++;
    }
    if(child == 0)
        return 1;
    return ret;
}

int main()
{
    int num;
    cin >> num;
    // root
    int root;
    for(int i=0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp == -1)
            root = i;
        else
            v[tmp].push_back(i);
    }
    // delete node
    cin >> delNum;
    if(root == delNum)
        cout << 0 << endl;
    else
        cout << dfs(root) << endl;
    return 0;
}