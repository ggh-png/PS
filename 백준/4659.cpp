#include <iostream>
#include <vector>
using namespace std;
/*
모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
*/

int main()
{
    string str = "";
    string mo = "aeiou";

    while(str != "end")
    {
        cin >> str;
        vector<pair<char, int>> v;
        bool Mflag = 0;
        
        for(int i=0; i < str.size(); i++)
        {
            char c = 0;
            // 모음이면
            for(auto &el : mo)  
                if(el == str[i])
                {
                    Mflag = 1;
                    c = el;
                    v.push_back({c, 1});
                }
            if(c == 0)
            {
                c = str[i];
                v.push_back({c, 0});
            }
        }

        int M3stack = 0;
        int J3stack = 0;
        bool ans = 1;
        if(v[0].second) 
        {
            M3stack = 1;
            J3stack = 0;
        }
        else
        {
            M3stack = 0;
            J3stack = 1;
        }

        for(int i=1; i < v.size(); i++)
        {
            if(v[i].second) 
            {
                M3stack += 1;
                J3stack = 0;
            }
            else
            {
                M3stack = 0;
                J3stack += 1;
            }
            // 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
            if(!Mflag)
            {
                ans = 0;
                break;
            }
            // 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
            if(M3stack == 3 || J3stack == 3)
            {
                ans = 0;
                break;
            }
            // 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
            if(v[i-1] == v[i] && (v[i].first != 'e' && v[i].first != 'o'))
            {
                ans = 0;
                break;
            }
        }
        if(str != "end")
        {
            if(ans)
                cout << "<" << str << "> " << "is acceptable." << endl;
            else
                cout << "<" << str << "> " << "is not acceptable." << endl; 
        }
    }
    return 0;
}