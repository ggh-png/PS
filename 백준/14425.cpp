#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<string, int> mapSet;
    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        mapSet[str] += 1;
    }
    int answer = 0;
    for(int i=0; i < m; i++)
    {
        string str;
        cin >> str;
        if(mapSet[str] == 1)
            answer++; 
    }    
    cout << answer << endl;
    return 0;
}