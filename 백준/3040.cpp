#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<int> v(9);
    int sum = 0;
    for(int i=0; i < 9; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    sum -= 100;
    bool flag = true;
    for(int i=0; i < 9; i++)
        if(flag)
        {
            for(int j=i; j < 9; j++)
                if(v[i] + v[j] == sum)
                {
                    v[i] = 0;
                    v[j] = 0;
                    flag = false;
                    break;
                }
        }
    for(int i=0; i < 9; i++)
        if(v[i] != 0)
            cout << v[i] << endl;
    return 0;
}