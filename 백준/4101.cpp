#include <iostream>

using namespace std;

int main()
{
    int a, b;
    while(1)
    {
        cin >> a >> b;
        if(!(a || b))
            break;
        else
        {
            string answer = a > b ? "Yes" : "No";
            cout << answer << endl;
        }
    }
    return 0;
}