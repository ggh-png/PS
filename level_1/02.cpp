#include <iostream>
#include <string>


using namespace std; 
 

string solution (string participant[], string completion[],int participant_size, int completion_size);

int main()
{
    string participant[] = {"kiki", "eden", "kiki"};           //참가자 
	string completion[] = { "kiki", "eden" };                   //완주자 

    int participant_size = sizeof(participant)/sizeof(string);  
    int completion_size = sizeof(completion)/sizeof(string);    //참가자 완주자 수 

    solution(participant, completion, participant_size, completion_size);
    return 0;
}



string solution (string participant[], string completion[],int participant_size, int completion_size)
{

    string str_check = "null";
    string answer;


    for(int i=0; i < participant_size; i++)// {"kiki", "eden", "kiki"}; 
    {
        for(int j=0; j < completion_size; j++) //{ "kiki", "eden" 
        {
            if (participant[i].compare(completion[j])==0)
            {
                participant[i] = str_check;
                completion[j] = str_check;               
            }           
        }
    }

    for(int k=0; k < participant_size; k++)
    {
        
        if(str_check.compare(participant[k]) != 0) 
        {
            answer = participant[k];
        }
    }
    cout << answer << endl;
    return answer;
}