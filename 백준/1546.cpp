#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    float num;
    cin >> num;
    vector<int> v(num);
    for(int i=0; i < num; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    float sum = 0; 
    float max = v.back();

    for(auto &el : v)
        sum += (el / max) * 100;
  
    cout << sum/num;
    return 0;
}