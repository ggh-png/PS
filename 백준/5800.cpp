#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++) 
    {
        int n;
        int max, min, gap=0;
        cin >> n;
        vector<int> v(n);
        for(int j=0; j < n; j++)
            cin >> v[j];
        sort(v.rbegin(), v.rend());
        max = v.front();
        min = v.back();
        for(int j=0; j < v.size()-1; j++)
            if(gap < abs(v[j] - v[j+1]))
                gap = abs(v[j] - v[j+1]);
                
        cout << "Class " << i+1 << '\n';
        cout << "Max " << max << ", Min " << min << ", Largest gap " << gap << '\n';
    }
    return 0;
}