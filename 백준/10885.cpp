#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int ans = 0;
    for(int i=0; i < num; i++)
    {
        bool tmp;
        cin >> tmp;
        if(tmp)
            ans++;
        else
            ans--;
    }
    if(ans > 0)
        cout << "Junhee is cute!" << endl;
    else
        cout << "Junhee is not cute!" << endl;
    return 0;
}