#include <iostream>
using namespace std;


int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int max = 0;
        string ans;
        int n;
        cin >> n;
        for(int j=0; j < n; j++)
        {
            int dosu;
            string nara;
            cin >> nara >> dosu;
            if(max < dosu)
            {
                max = dosu;
                ans = nara;
            }
        }
        cout << ans << endl; 
    }
    return 0;
}