#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int arr[26] = {0};
    for(int i=0; i < num; i++)
    {
        string str;
        cin >> str;
        arr[str[0] - 'a']++;
    }
    string answer = "PREDAJA";
    for(int i=0; i < 26; i++)
        if(arr[i] >= 5)
        {
            answer = "";
            char tmp = i + 97;
            cout << tmp;
        }
    cout << answer << '\n';

    return 0;
}