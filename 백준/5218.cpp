#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    string a, b;
    for(int i=0; i < num; i++)
    {
        cin >> a >> b;
        cout << "Distances: ";
        for(int j=0; j < a.size(); j++)
        {
            int tmp = b[j] - a[j];
            if(tmp >= 0)
                cout << tmp << " ";
            else
                cout << 26 + tmp << " ";
        }
        cout << endl;
    }
    return 0;
}