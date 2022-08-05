#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
         int a, b, c;
        cin >> a >> b >> c;
        int ans = b - a - c;
        if(ans > 0)
            cout << "advertise" << endl;
        else if(ans == 0)
            cout <<  "does not matter" << endl;
        else
            cout << "do not advertise" << endl;
    }
    return 0;
    
}
