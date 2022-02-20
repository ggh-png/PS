#include<iostream>
#include<cstring>


using namespace std;

void solution(string Input_Num);


int main() 
{

    string Input_Num = "1twofour3";

    solution(Input_Num);
    return 0;
}


void solution(string Input_Num)
{
    
    string output_num;
    string strList; 

    int Input_size = Input_Num.size();

    string str_num_arr[10] = {"zero", "one","two",
                                "three","four","five","six","seven","eight","nine"};

    string num_arr[] = {"0","1","2","3","4","5","6","7","8","9"};


    for (int i =0; i < Input_size; i++)
    {
       for(int j=0; j < 10; j++)
       { 
           if (((Input_Num.substr(i,1)).compare(num_arr[j])==0))
           {
               output_num += num_arr[j];
               continue;
               //cout << output_num << endl;
           }
       }

       for(int g=i; g < Input_size+1; ++g)
       {
                strList +=Input_Num.substr(g,1);
                for(int k=0; k < 10; k++)
                {     
                    if((strList.compare(str_num_arr[k])==0))
                    { 
                        output_num += num_arr[k];
                        cout << strList << endl;
                        strList.clear();
                    }
                }            
       }
            cout << output_num << endl;    
       }
}