#include <string>
#include <iostream>
using namespace std;


string solution(string phone_number) 
{
    
    for(int i=0; i<phone_number.size()-4; i++){
        phone_number[i] = '*';
    }
    cout << phone_number << endl;
    return phone_number;
}
int main()
{
    string phone_number{"123468"};
    
    solution(phone_number);
    return 0;
}