#include <iostream>
#include <vector>

using namespace std;

// 테케, 정점, 간선
int k, v, e;
int visited[20004];
// dfs 
void dfs(int start, vector<int> v[])
{
    // 방문하지 않았더라면 색 1 부여
    if(!visited[start])
        visited[start] = 1;
    
    // 색 1을 부여한 접한 접점들 조사 
    for(int i=0; i < v[start].size(); i++)
    {
        int idx = v[start][i];
        // 방문을 하지 않았더라면 
        if(!visited[idx])
        {   // 이전 방문 요소가 1번 색이라면 
            if(visited[start] == 1)
                visited[idx] = 2;
            // 이전 방문 요소가 2번 색이라면 
            else if(visited[start] == 2)
                visited[idx] = 1;
            // 다음 요소 방문 
            dfs(idx, v);
        }
    }
}

string check(int V, vector<int> v[])
{
    for(int j=1; j <= V; j++)
        for(int a=0; a < v[j].size(); a++)
        {
            int idx = v[j][a];
            if(visited[j] == visited[idx])
                return "NO";
        }
    return "YES";
}


// 2분 그래프 ... 두 색으로 표현 하되 

int main()
{
    cin >> k;
    for(int i=0; i < k; i++)
    {
        cin >> v >> e;
        int V, E;
        vector<int> v[200004];
        // graph 생성 
        for(int j=0; j < e; j++)
        {
            cin >> V >> E;
            v[V].push_back(E);
            v[E].push_back(V);
        }
        for (int i = 1; i <= V; i++)
            if (!visited[i])
                dfs(i, v);

        cout << check(V, v) << endl;
        // 초기화
        fill(visited, visited + 20004, 0);
    }
    return 0;
}