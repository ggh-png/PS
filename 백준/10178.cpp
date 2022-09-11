#include <iostream>
using namespace std;


int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int n, m;
        cin >> n >> m;
        cout << "You get " << n / m << " piece(s) and your dad gets " << n % m << " piece(s)." << endl;
    }
    return 0;

}