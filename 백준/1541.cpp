#include <iostream>
#include <vector>

using namespace std;

// 주어진 식에서 괄호를 치는 행위를 통해 최솟값을 구하여라 
// 1. 순서는 바뀔 수 없으며 오로지 괄호를 이용한다. 
// 2. (-)가 존재하면 (+)끼리 묶어 먼저 계산한다. 
// ex) 55 - 40 + 50 - 30 + 30 일때
//     55 -(90) - 30 



int main()
{
    // 식 입력 받기 
    string str;
    cin >> str;
    vector<int> iv;
    vector<char> ic;
    string temp = "";
    for(int i=0; i <= str.size(); i++)
    {

        if(str[i] == '-' || str[i] == '+' || i == str.size())
        {
            iv.push_back(stoi(temp));
            temp = "";
            ic.push_back(str[i]);
            
        }
        else
            temp += str[i];
    }
    // 양의 부호를 가지면 묶는다. 
    for(int i=0; i < ic.size(); i++)
    {
        if(ic[i] == '+')
        {
            iv[i] += iv[i+1];
            iv.erase(iv.begin() + i+1);
            ic.erase(ic.begin() + i);
            i--;
        }
    }
    // 이후 음의 부호를 가지는 것들을 해결한다.
    for(int i=0; i < ic.size(); i++)
    {
        if(ic[i] == '-')
        {
            iv[i] -= iv[i+1];
            iv.erase(iv.begin() + i+1);
            ic.erase(ic.begin() + i);
            i--;
        }
    }
    int answer = iv[0];
    cout << answer << endl;
    return 0;
}