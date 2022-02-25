#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num1 = n;
    int num2 = n;
    int temp_num; 
    bool flag = true;
    vector<int> temp;
    while (!(num1 <= 3))
    {
        num1 /=3;
        num2 = (num1)*3%3;

        //temp.push_back(num1);
        

        if(num2 == 0)
        {
            temp.push_back(0);
        }
        else if(num2 == 1) 
        {
            temp.push_back(1);
        }

        else if(num2 == 2) 
        {
            temp.push_back(2);
        }

        else if (num1 <= 3)
        {
            temp.push_back(num1);
            temp.push_back(num2);
            flag = false;
        }
        
    }
    for(auto el : temp)
    {
        cout << el << " ";
    }
    cout << endl;
    return answer;
}

int main()
{
    int n = 45;
    solution(n);
    return 0;
}