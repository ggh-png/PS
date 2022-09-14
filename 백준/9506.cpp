#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int tmp;
    while(tmp != -1)
    {
        cin >> tmp;
        int sum = 0;
        vector<int> v;
        for(int i=1; i < tmp; i++)
        {
            if(tmp % i == 0)
            {
                v.push_back(i);
                sum += i;
            }
        }
        if(tmp != -1)
        {
            if(sum == tmp)
            {
                cout << tmp << " = ";
                for(int i=0; i < v.size()-1; i++)
                    cout << v[i] << " + ";
                cout << v.back() << endl;
            }
            else
                cout << tmp << " is NOT perfect." << endl;
        }
    }
}