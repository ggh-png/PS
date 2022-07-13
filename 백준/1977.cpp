#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main()
{
    double a, b;
    cin >> a >> b;
    vector<int> v;

    for(int i=a; i <= b; i++)
    {
        double tmp = sqrt(i);
        if(tmp == (int)tmp)
            v.push_back(i);
    }
    int sum = 0;
    if(!v.empty())
    {
        for(auto &el : v)
            sum += el;
        cout << sum << endl;
        cout << v[0] << endl;
    }
    else
        cout << -1 << endl;   



    return 0;
}