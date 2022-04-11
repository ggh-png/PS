#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 입력 : 공백이 있는 문자열 ... 오로지 '.'만이 문자열의 끝을 알림. 
// (), []만이 존재함. 
// ( or [ 둘이 ([)] 인 경우 어떻게 처리할까..? 
// ()[ || ([) 를 어캐 구분할까 

int main()
{
    vector<string> answer;    // output
    string str;
    answer.clear();
    while (1)
    {
        // 문자열 입력
        getline(cin, str);
        vector<char> VectorStack; 
        if(str[0] == '.') break;   
        // 판별 ()
        for(int i=0; i < str.size(); i++)   // 괄호를 입력 받으면 
        {
            if(str[i] == '(') VectorStack.push_back('(');
            if(str[i] == '[') VectorStack.push_back('[');
            if(str[i] == ')')
            {
                if(!VectorStack.empty() && *(VectorStack.end()-1) == '(') 
                    VectorStack.pop_back();
                else{ answer.push_back("no"); break; }    
            }
            if(str[i] == ']')
            {
                if(!VectorStack.empty() && *(VectorStack.end()-1) == '[') 
                    VectorStack.pop_back();
                else{ answer.push_back("no"); break; } 
            }
			if (VectorStack.empty() && i == str.length() - 2) answer.push_back("yes"); 
			else if (!VectorStack.empty() && i == str.length() - 2) answer.push_back("no");
        }   
    }
    for(auto el : answer)
        cout << el << endl; 
}

