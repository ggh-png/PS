#include <iostream>
#include <string>
using namespace std;
int n;
string k,ans;
int main() {
    cin >> n;
    while (n--)
    {
        ans = "";
        cin >> k;
        int ksize = k.size();
        for (int i = 0; i < ksize/2; i++)
        {
            if (k[i] == k[ksize - i - 1]) { ans = "Do-it";}
            else { ans = "Do-it-Not"; }
        }
        cout << ans << '\n';
    }
}
