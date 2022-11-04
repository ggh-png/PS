#include <iostream>

using namespace std;

int main()
{
    int num; 
    cin >> num;
    
    for(int i=0; i < num; i++)
    {
        string str;
        cin >> str;
        int sum = 0;
        string tmp = "";
         
        if(str != "P=NP")
        {
            for(auto &el : str)
                if(el == '+')
                {
                    sum += stoi(tmp); 
                    tmp = "";
                }
                else
                    tmp += el;
            sum += stoi(tmp);
            cout << sum << endl;
        }
        else
            cout << "skipped" << endl;
    }
    return 0;
}