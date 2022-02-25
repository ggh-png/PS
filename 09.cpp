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


void test()
{
    int num = 45;
    int num_1 = 45; // 몫 
    int num_2; // 나머지 
    bool flag = true;

    while (flag)
    {
        num_2 = (num_1 * 3) % 3;
        num_1 /= 3;
        cout << num_1 << " " << num_2 << " ";
        if(num_1 <=5)
        {
            cout << " asdasd | ";
            //num_1 /= 3;
            //num_2 = (num_1 * 3) % 3;
            cout << num_1/3 << " " << num_1%3 << " ";
            flag = false;
        }
    }
    cout << endl;

}

int main()
{
    int n = 45;
    //solution(n);
    test();
    return 0;
}