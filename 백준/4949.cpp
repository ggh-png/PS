#include <iostream>
#include <vector>
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
        // stack init
        vector<char> VectorStack; 
        if(str[0] == '.') break;   
        // 판별 ()
        for(int i=0; i < str.size(); i++)   
        {   // 괄호를 입력 받으면 
			// 시작 괄호면 스택쌓기 
            if(str[i] == '(') VectorStack.push_back('(');
            if(str[i] == '[') VectorStack.push_back('[');
            if(str[i] == ')')
            {   // 스택이 비어있지 않고 스택의 최 상단에 시작괄호가 있다면 스택제거
                // () 인 경우 : 빈 스택으로 만듬 
                if(!VectorStack.empty() && *(VectorStack.end()-1) == '(') 
                    VectorStack.pop_back();
                // 빈 스택에 닫는괄호가 들어오면 no
                // ) 인 경우 : no 
                else{ answer.push_back("no"); break; }    
            }
            if(str[i] == ']')
            {   // 스택이 비어있지 않고 스택의 최 상단에 시작괄호가 있다면 스택제거
                // [] 인 경우 : 빈 스택으로 만듬 
                if(!VectorStack.empty() && *(VectorStack.end()-1) == '[') 
                    VectorStack.pop_back();
                // 빈 스택에 닫는괄호가 들어오면 no
                // ) 인 경우 : no  
                else{ answer.push_back("no"); break; } 
            }
            // 스택이 비어있고 .이 나오기 전까지 입력된 문자열을 확인했을 경우  
			if (VectorStack.empty() && i == str.length() - 2) 
                answer.push_back("yes"); 
			// 스택이 비어있지 않고 입력된 문자열을 확인했을 경우 
            else if (!VectorStack.empty() && i == str.length() - 2) 
                answer.push_back("no");
        }   
    }
    for(auto el : answer)
        cout << el << '\n'; 
}