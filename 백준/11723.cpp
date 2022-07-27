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
    map<int, bool> mapSet;
    for(int i=0; i < num; i++)
    {
        string str;
        int tmp;
        cin >> str;
        if(str == "add")
        {
            cin >> tmp;
            if(!mapSet[tmp])
                mapSet[tmp] = true;
        }
        else if(str == "remove")
        {
            cin >> tmp;
            if(mapSet[tmp])
                mapSet[tmp] = false;
        }
        else if(str == "check")
        {
            cin >> tmp;
            if(mapSet[tmp])
                cout << true << '\n';
            else
                cout << false << '\n';
        }
        else if(str == "toggle")
        {
            cin >> tmp;
            if(mapSet[tmp])
                mapSet[tmp] = false;
            else
                mapSet[tmp] = true;
        }
        else if(str == "all")
        {
            for(int i=1; i <= 20; i++)
                if(!mapSet[i])
                    mapSet[i] = true;
        }
        else if(str == "empty")
        {
            for(int i=1; i <= 20; i++)
                if(mapSet[i])
                    mapSet[i] = false;
        }
    }
    return 0;
}