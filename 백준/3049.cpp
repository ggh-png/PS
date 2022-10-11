#include <iostream>
using namespace std;

//N * (N - 1) * (N - 2) * (N - 3) / 24
int main()
{
    int num;
    cin >> num;
    cout << num*(num-1)*(num-2)*(num-3)/24 << endl;
    return 0;
}