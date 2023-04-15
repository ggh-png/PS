#include <iostream>

using namespace std;


int main()
{
    int cnt=0;
    while(1)
    {
        cnt++;
        int n;
        cin >> n; 
        if(!n)
            break;
        else
        {
            if(n%2)
                cout << cnt << ". odd " << n/2 << endl;
            else
                cout << cnt << ". even " << n/2 << endl;
        }       
    }
    return 0;
}