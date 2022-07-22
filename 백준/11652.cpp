#include <iostream>
#include <map>

using namespace std;

int main()
{
    int num;
    map<long long, int> mapSet;

    cin >> num;
    for(int i=0; i < num; i++)
    {
        long long tmp;
        cin >> tmp;
        mapSet[tmp] += 1; 
    }
    int max = 0;
    long long ans;
    for(auto &el : mapSet)
        if(max < el.second)
        {
            max = el.second;
            ans = el.first;
        }
    
    cout << ans << endl;
    return 0;
}