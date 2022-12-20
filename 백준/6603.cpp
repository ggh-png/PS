#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tmp;

int num=98765432;

void combi(vector<int> v, int idx)
{
    if(tmp.size() == 6)
    {
        for(auto &el : tmp)
            cout << el << " ";
        cout << '\n';
    }

    for(int i=idx+1; i < v.size(); i++)
    {
        tmp.push_back(v[i]);
        combi(v, i);
        tmp.pop_back();
    }
}



int main()
{
    while (1)
    {
        cin >> num;
        if(num)
        {
            vector<int> v;
            for(int i=0; i < num; i++)
            {
                int tmp;
                cin >> tmp;
                v.push_back(tmp);
            }
            sort(v.begin(), v.end());
            combi(v, -1);
            cout << '\n';
        }
        else
            break;
    }
      
    return 0;
}