#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    map<string, int> poketmon;
    int n, m; 
    cin >> n >> m;
    string dogam[n+1];
    for(int i=1; i <= n; i++)
    {
        string str;
        cin >> str;
        poketmon[str] = i;
        dogam[i] = str;
    }

    for(int i=0; i < m; i++)
    {
        string str;
        cin >> str;
        

        if(str[0] >= 65 && str[0] <= 90)
            cout << poketmon[str] << '\n';   
        else
        {
            int ii = stoi(str);
            cout << dogam[ii] << '\n';
        }
            
    }
    return 0;
}