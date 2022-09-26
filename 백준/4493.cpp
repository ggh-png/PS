#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int n;
        cin >> n;
        int a=0, b=0;
        for(int j=0; j < n; j++)
        {
            char A,B;
            cin >> A >> B;
            if(A == B)
            {
                a += 1;
                b += 1;
            }
            else if((A == 'R' && B == 'P') || (A == 'P' && B == 'S') || (A == 'S' && B == 'R'))
                b += 1;
            else
                a += 1;
        }
        if(a == b)
            cout << "TIE" << endl;
        else if(a > b)
            cout << "Player 1" << endl;
        else 
            cout << "Player 2" << endl; 
    }
    return 0;
}