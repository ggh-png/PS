#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;
int arr[9];
bool visited[9];


void combi(int srt, int idx)
{
    if(srt == m)
    {
        for(auto &el : v) 
            cout << el << " ";
        cout << endl;
    }
    for(int i=idx; i < n; i++)
        if(!visited[i])
        {
            visited[i] = 1;
            v.push_back(arr[i]);
            combi(srt + 1, i);
            visited[i] = 0;
            v.pop_back();
        }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    combi(0, 0);
}