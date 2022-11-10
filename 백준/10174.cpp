#include <iostream>
#include <string>

using namespace std;

 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string line;
        getline(cin, line);       
        int len = line.size();
        bool isPalindrome = true;
        for (size_t i = 0; i < len / 2; i++)
        {
            char left = tolower(line[i]);
            char right = tolower(line[len - 1 - i]);
            if (left != right)
            {
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}