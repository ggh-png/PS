#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
vector<int> v;
int visited[9];
void printarr()
{
    for(auto &el : v)
        cout << el << " ";
    cout << '\n';
    return;
}

void combi(int cnt, int mm)
{
    if(cnt == mm)
    {
        printarr();
        return;
    }
    for(int i=0; i < n; i++)
        if(!visited[i])
        {
            v.push_back(arr[i]);
            visited[i] = 1;
            combi(cnt+1, mm);
            v.pop_back();
            visited[i] = 0;
        }

    return;
}


int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    combi(0, m);

    return 0;
}