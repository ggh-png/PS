#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int y = 0;
        int k = 0;
        for(int j=0; j < 9; j++)
        {
            int a, b;
            cin >> a >> b;
            if(a)
                y++;
            if(b)
                k++;
        }
        if(y > k)
            cout << "Yonsei" << endl;
        else if(y < k)
            cout << "Korea" << endl;
        else
            cout << "Draw" << endl;
    }
    return 0;
}