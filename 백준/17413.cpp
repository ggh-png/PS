#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    
    // < 이 등장하면 > 이 등장할 때 까지 삽입한다. 
    deque<char> dec;
    while(!str.empty())
    {
        // < > 일 경우 
        if(str.front() == '<')
        {
            string temp = "";
            while(!dec.empty())
            {
                temp += dec.back();
                dec.pop_back();
            }
            cout << temp;
            dec.push_back(str.front());
            str.erase(str.begin());
            while(str.front() != '>')
            {
                dec.push_back(str.front());
                str.erase(str.begin());
            }    
            dec.push_back(str.front());
            str.erase(str.begin());
            string tmp = "";
            while(!dec.empty())
            {
                tmp += dec.front();
                dec.pop_front();
            }
            cout << tmp;
        }
        else if(str.front() != ' ' && str.size() != 1)
        {
            dec.push_back(str.front());
            str.erase(str.begin());
        }
        else if(str.front() == ' ')
        {
            string tmp = "";
            while(!dec.empty())
            {
                tmp += dec.back();
                dec.pop_back();
            }
            str.erase(str.begin());
            cout << tmp << " ";
        }
        else if(str.size() == 1)
        {
            dec.push_back(str.front());
            str.erase(str.begin());
            string tmp = "";
            while(!dec.empty())
            {
                tmp += dec.back();
                dec.pop_back();
            }
            cout << tmp << endl;
            break;
        }
    }
    return 0;
}