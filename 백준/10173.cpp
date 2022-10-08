#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

string check[] = {"NEMO", 
                  "NEMo", "NEmO", "NeMO", "nEMO",
                  "NEmo", "NemO", "NEmo",
                  "Nemo", "nEmo", "neMo", "nemO",
                  "nemo"};
int main()
{
    cin.ignore();
    while(1)
    {
        string str;
        getline(cin, str);
        bool flag = 0;
        if(str != "EOI")
        {
            for(auto &el : check)
                if(str.find(el) != std::string::npos)
                {
                    flag = 1;
                    break;
                }
            if(flag)
                v.push_back("Found");
            else
                v.push_back("Missing");
        }
        else 
            break;
    }
    for(auto &el : v)
        cout << el << endl;
    return 0;
}