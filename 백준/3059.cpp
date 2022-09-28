#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int sum = 0;
        string str;
        bool ap[26] = {0};
        cin >> str;
        for(auto &el : str)
            ap[el-65] = 1;
        for(int i=0; i < 26; i++)
            if(!ap[i])
                sum += (i+65);
        cout << sum << endl;   
    }
    return 0;
}

