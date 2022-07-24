#include <iostream>
#include <map>

using namespace std;

int main()
{    
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;
    map<int, int> mapA, mapB;

    for(int i=0; i < a; i++)
    {
        int tmp;
        cin >> tmp;
        mapA[tmp] = 2;
    }
    int BA = 0;
    for(int i=0; i < b; i++)
    {
        int tmp;
        cin >> tmp;
        mapB[tmp] = 2;
        if(mapA[tmp] != 2)
            BA++;
    }
    int AB = 0;
    for(auto &el : mapA)
        if(mapB[el.first] != 2)
            AB++;
    cout << AB + BA << '\n';
    return 0;
}
