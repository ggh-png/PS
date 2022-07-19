#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        list<char> l;
        string str;
        cin >> str;
        list<char>::iterator iter = l.begin();

        for(auto &el : str)
        {
            if(el == '<')
            {
                if(iter != l.begin())
                    iter--;
            }
            else if(el == '>')
            {
                if(iter != l.end())
                    iter++;  
            }  
            else if(el == '-')
            {
                if(iter != l.begin())
                    iter = l.erase(--iter);
            }
            else{
                l.insert(iter, el);}
            
        }
        for(auto &el : l)
            cout << el;
        cout << '\n';

    }
    return 0;
}