#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    while(1)
    {
        vector<string> v;
        string A = "";
        string B = "";
        cin >> A >> B;
        if((A + B) == "")
            break;
        else
            cout << stoi(A) + stoi(B) << '\n';
    }
    return 0;
}