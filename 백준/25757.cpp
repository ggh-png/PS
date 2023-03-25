#include <iostream>
#include <map>

using namespace std;

int n;
char game;
int r;
int ans = 0;
int visited[100004];
map<string, bool> mp;

int main()
{
    cin >> n >> game;

    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        if(!mp[str])
            mp[str] = 1;
    }

    if(game == 'Y')
        r = 2;
    else if(game == 'F')
        r = 3;
    else if(game == 'O')
        r = 4;
    n = mp.size();
    ans = mp.size() / (r-1);
    cout << ans << endl;
    return 0;
}