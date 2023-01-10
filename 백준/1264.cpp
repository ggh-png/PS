#include <iostream>
#include <string>

using namespace std;

int main()
{
    string mo = "aeiouAEIOU";
    
    while(1)
    {
        string str;
        getline(cin, str);
        if(str == "#")
            break;
        
        int cnt = 0;
        for(auto &el : str)
            for(auto &e : mo)
                if(e == el)
                    cnt++;
                
        cout << cnt << endl;
    }
    return 0;
}