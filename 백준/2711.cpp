#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int n;
        string str;
        cin >> n >> str;
        for(int j=0; j < str.size(); j++)
        {
            if(n-1 == j)
                continue;
            else
                cout << str[j];
        }
        cout << endl;
    }
    return 0;
}