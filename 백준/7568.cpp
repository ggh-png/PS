#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int num, x, y;
    cin >> num;
    vector<pair<int, int>> xy;
    vector<int> rank(num, 1);
    for(int i=0; i < num; i++)
    {
        cin >> x >> y;
        xy.push_back(pair<int, int>(x, y));
    }
    for(int i=0; i < num; i++)
        for(int j=0; j < num; j++)
        {
            // 덩치가 확실히 비교가 된다면. 
            if((i != j) && xy[i].first < xy[j].first && xy[i].second < xy[j].second)
                rank[i]++;     
        }
    for(auto &el : rank)
        cout << el << " ";

    return 0;
}