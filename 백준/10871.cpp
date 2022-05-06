#include <iostream>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num, n;
    cin >> num >> n;
    
    for(int i=0; i < num; i++)
    {
        int temp;
        cin >> temp;
        if(n > temp)
            cout << temp << " ";
    }
    return 0;
}