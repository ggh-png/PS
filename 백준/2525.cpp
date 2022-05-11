#include <iostream>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int h, m, t;
    cin >> h >> m >> t;
    m += t % 60;
    h += t / 60; 

    if(m >= 60 && h < 24)
    {
        m -= 60;
        h++;
        if(h >= 24)
            h -= 24;      
    }
    else if(m < 60 && h >= 24)
        h -= 24;
    else if(m >= 60 && h >= 24)
    {
        m -= 60;
        h++;
        h -= 24;
    }


    cout << h << " " << m;
    return 0;
}