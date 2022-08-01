#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num;
    cin >> num;
    string str;
    cin >> str;
    auto itr = str.find("*");

    string front = str.substr(0, itr);
    string back = str.substr(itr+1, str.size());


    for(int i=0; i < num; i++)
    {
        string tmp;
        cin >> tmp;
        if(front.size() + back.size() <= tmp.size())
        {
            auto itr1 = tmp.substr(0, itr);
            auto itr2 = tmp.substr(tmp.size() - back.size(), tmp.size());

            if(itr1 == front && itr2 == back  && itr1 != itr2)
                cout << "DA" << '\n';
            else
                cout << "NE" << '\n';
        }
        else
            cout << "NE" << '\n';
    }

    return 0;
}