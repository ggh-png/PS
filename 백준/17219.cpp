#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<string, string> mapSet;
    for(int i=0; i < n; i++)
    {
        string site, pw; 
        cin >> site >> pw;
        mapSet[site] = pw;
    } 
    for(int i=0; i < m; i++)
    {
        string str;
        cin >> str;
        cout << mapSet[str] << '\n';
    }
    return 0;
}