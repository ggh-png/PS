#include<iostream>
 
using namespace std;
 
int divide(int &x, int &y)
{
    int tmp = x % y;
    // 나눠지면
    if (x % y == 0)
        return y;
    else
        return divide(y, tmp);
}
 
int main()
{
    int num;
    int A, B;
    cin >> num;
 
    for (int i = 0; i < num; i++)
    {
        cin >> A >> B;
        if (A >= B)
            cout << A * B / divide(A, B) << "\n";
        else
            cout << A * B / divide(B, A) << "\n"; 
    }
}
