#include <iostream>

using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;

    int q = a / b;
    int r = a % b * 10; 
    for(int i=0; i < n; i++)
    {
        q = r / b;
        r = (r % b) * 10;
    }
    cout << q << endl;
    return 0;
}