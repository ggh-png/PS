#include <iostream>
#include <string>
#include <list>

using namespace std; 


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    string str;
    list<char> L;
    int num;
    char temp;
    cin >> str >> num;
    // list에 삽입
    for(auto &el : str)
        L.push_back(el);
    // list<char>::iterator idx
    auto idx = L.end();
    for(int i=0; i < num; i++)
    {
        cin >> temp;
        if(idx != L.begin() && temp == 'L')
            idx--;
        else if(idx != L.end() && temp == 'D')
            idx++;
        else if(idx != L.begin() && temp == 'B')
        {
            idx = L.erase(--idx);  
        }
        else if(temp == 'P')
        {
            cin >> temp;
            L.insert(idx, temp);
        }

    }
    for(auto &el : L)
        cout << el;
    cout << '\n';
    return 0;
}