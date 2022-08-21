#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int sum = 0;
        int min = 99999999;
        for(int j=0; j < 7; j++)
        {
            int tmp;
            cin >> tmp;
            if(tmp % 2 == 0)
            {
                if(min > tmp)
                    min = tmp;
                sum += tmp;
            }
        }
        cout << sum << " " << min << endl;
    }
    return 0;
}
