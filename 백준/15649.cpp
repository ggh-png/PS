#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 서로다른 5개의 구슬이 들어있는 구슬망에서 3개의 구슬을
// 뽑는 조합 구현 
// nCr = 5C3

int n, m;
int arr[9];
bool visited[9];
vector<int> v;

void CombiPrint(vector<int> v)
{
    for(auto &el : v)
        cout << el << " ";
    cout << '\n';
}

void combi(int start, vector<int> v)
{
    // 3개의 구슬이 뽑아지면
    if(v.size() == m)
    {
        CombiPrint(v);
        return;
    }
    for(int i=0; i < n; i++)
        if(!visited[i])
        {
            v.push_back(arr[i]);
            visited[i] = 1;
            combi(i, v);
            v.pop_back();
            visited[i] = 0;
        }
    return;
}

int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        arr[i] = i+1;
    combi(0, v);
    return 0;
}