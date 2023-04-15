#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; 
    cin >> n;
    for(int i=0; i < n; i++)
    {
        int num; 
        cin >> num;
        int n = 0, m = num;
        cout << "Pairs for " << num << ": ";
        vector<pair<int, int>> v;
        while(1)
        {
            n++;
            m--;
            
            if(m - n <= 0)
                break;
            else
                v.push_back({n, m});
        }
        for(int j=0; j < v.size(); j++)
        {
            if(j != v.size()-1)
                cout << v[j].first << " " << v[j].second << ", ";
            else
                cout << v[j].first << " " << v[j].second << endl;
        }
        if(v.size() == 0)
            cout << endl;
    }
    return 0;
}