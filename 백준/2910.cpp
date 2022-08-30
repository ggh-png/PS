#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class cl
{
public:
    // 숫자
    long long num;
    // 순서
    int number;
    // 빈도
    int bindo;
};


bool compare(cl &a, cl &b)
{
    if(a.bindo == b.bindo)
        return a.number < b.number;
    return a.bindo > b.bindo;
}

int main()
{
    int n, m;
    cin >> n >> m;
    // 숫자와 순서 
    map<long long, int> mp1;
    // 숫자와 빈도
    map<long long, int> mp2;
    // 숫자와 순서 빈도
    vector<cl> v;

    for(int i=1; i <= n; i++)
    {
        long long tmp;
        cin >> tmp;
        if(mp1[tmp] == 0)
            mp1[tmp] = i;
        mp2[tmp] += 1; 
    }

    for(auto &el : mp1)
    {   // 숫자 순서 빈도
        cl tmp;
        tmp.bindo = mp2[el.first];
        tmp.num = el.first;
        tmp.number = el.second;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), compare);

    for(auto &el : v)
        while(el.bindo)
        {
            cout << el.num << " ";
            el.bindo--;
        }
    cout << endl;

    return 0;
}

