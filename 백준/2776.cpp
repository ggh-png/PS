#include <iostream>
#include <map> 

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num; 
    cin >> num;
    
    for(int i=0; i < num; i++)
    {
        map<int, bool> mapSet;
        int n;
        cin >> n;
        for(int j=0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            mapSet[tmp] = true;
        }

        int m;
        cin >> m;
        for(int j=0; j < m; j++)
        {
            int tmp; 
            cin >> tmp;
            if(mapSet[tmp])
                cout << 1 << '\n';
            else
                cout << 0 << '\n'; 
        }
    }
    return 0;
}