#include <iostream>

using namespace std;


int main()
{
    int num;
    cin >> num;
    while(1)
    {
        int tmp;
        cin >> tmp;
        if(tmp == 0)
            break;
        else
        {
            if(!(tmp % num))
                cout << tmp << " is a multiple of " << num << "." << endl;
            else
                cout << tmp << " is NOT a multiple of " << num << "." << endl;
        }
    }
    return 0;
}