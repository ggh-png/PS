#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b)
{
    if(a.size() == b.size())
    {
        int sizea = 0;
        int sizeb = 0;
        for(auto &el : a)
            if(el >= '0' && el <= '9')
                sizea += int(el) - 48;
        for(auto &el : b)
            if(el >= '0' && el <= '9')
                sizeb += int(el) - 48;
        if(sizea == sizeb)
            return a < b;
        return sizea < sizeb;  
    }
    return a.size() < b.size();
}


int main()
{
    vector<string> v;
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), compare);
    for(auto &el : v)
        cout << el << endl;
    return 0;
}