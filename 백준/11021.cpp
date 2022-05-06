#include <iostream>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int num, a, b;
    cin >> num;
    for(int i=1; i <= num; i++)
    {
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << '\n';
    }
    return 0;
}