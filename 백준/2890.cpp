#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// n - 2 
// map
int n, m;
char map[55][55];

// 위치, 선수번호
vector<pair<int, int>> v;
int arr[10];

bool compare(pair<int, int> a, pair<int, int> b)
{  
    return a.first > b.first;
}


int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++)
            cin >> map[i][j];

    for(int i=0; i < n; i++)
    {
        int srt = 0;
        int nn = 99;
        for(int j=0; j < m; j++)
        {
            if(map[i][j] == '.')
                srt++;
            else if(map[i][j] >= '0' && map[i][j] <= '9')
            {
                nn = map[i][j] - 48;
                v.push_back({srt, nn});
                break;
            }
        }
    }
    sort(v.begin(), v.end(), compare);

    int rank = 1;
    arr[v[0].second] = rank;
    int prev = v[0].first;
    for (int i = 1; i < v.size(); i++)
        if (prev == v[i].first)
            arr[v[i].second] = rank;
        else
        {
            arr[v[i].second] = ++rank;
            prev = v[i].first;
        }
    for (int i = 1; i <= 9; i++)
        cout << arr[i] << "\n";
  
    return 0;
}