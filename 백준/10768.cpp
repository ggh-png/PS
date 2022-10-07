#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if(n == 2 && m == 18)
        cout << "Special" << endl;
    else if(n == 2 && m > 18)
        cout << "After" << endl;
    else if(n == 2 && m < 18)
        cout << "Before" << endl;
    else if(n > 2)
        cout << "After" << endl;
    else if(n < 2)
        cout << "Before" << endl;
    return 0;
}
