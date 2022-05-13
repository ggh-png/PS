#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int N;
        string str;
        cin >> N >> str;
        
        for(auto &el : str)
            for(int i=0; i < N; i++)
                cout << el;
        cout << '\n';   
    }
    return 0;
}