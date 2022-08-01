#include <iostream>
#include <map>

using namespace std;


int main()
{
    int num;
    
    cin >> num;

    
    for(int i=0; i < num; i++)
    {
        int n;
        cin >> n;
        map<string, int> mapSet;
        for(int j=0; j < n; j++)
        {
            string str1, str2;
            cin >> str1 >> str2;
            mapSet[str2]++;
        }
        int ans=1;
        for(auto &el : mapSet)
            ans *= (el.second+1);
        
        ans--;
        cout << ans << endl;
    }
    return 0;
}