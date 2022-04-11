#include <iostream>
#include <vector>
using namespace std;

// 입력 : 공백이 있는 문자열 ... 오로지 '.'만이 문자열의 끝을 알림. 
// (), []만이 존재함. 
// ( or [ 둘이 ([)] 인 경우 어떻게 처리할까..? 
// ()[ || ([) 를 어캐 구분할까 

int main()
{
    vector<string> OrderList; // input
    vector<string> answer;    // output
    bool flag = true;


    
    while (flag)
    {
        // 문자열 입력
        string str = "";
        getline(cin, str); 

            
        // 판별 ()
        int tmp1=0, tmp2=0;
        for(int i=0; i < str.size(); i++)
        {
            if(tmp1 < 0 || tmp2 < 0) break; 
            if(str[i] == '(') tmp1++;
            else if(str[i] == '[') tmp2++;
            else if(str[i] == ')') tmp1--;
            else if(str[i] == ']') tmp2--; 
            else if(tmp1==0 && tmp2 > 0) 
            {   
                tmp2++; 
                break;
            } 
            else if(tmp2==0 && tmp1 > 0)
            {
                tmp1++;
                break;
            } 
        }
        // tmp1, tmp2둘 다 0이여야만 함.
        string result;
        if(str == ".")
            break;
        else 
            result = (tmp1 == 0) && (tmp2 == 0) ? "yes" : "no";
        answer.push_back(result);
    }
    //answer.pop_back();
    
    for(auto el : answer)
        cout << el << endl; 
}