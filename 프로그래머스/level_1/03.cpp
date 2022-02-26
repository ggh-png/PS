#include <iostream>
#include <string>
#include <vector>

using namespace std;



int answer_size(vector<int> arr)
{   
    int count = 0;
    for(int i=0; i < arr.size(); i++)
    {
        if((arr[i] == arr[i+1]) ? false : true) // 311331
        {
            count++;
        }
    }
    //cout << count << endl;
    return count;
}



void print_arr (vector<int> arr)
{
    cout << "[ ";
    for(int i=0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}




vector<int> solution (vector<int> arr)
{

    int size = answer_size(arr);
    vector<int> answer(size);
    int temp_arr=0;


    for(int i=0; i < arr.size(); i++)/// 133133 -- 6 arr size
    {                               // 1313 --   4 size

        if((arr[i] == arr[i+1]) ? false : true)                 // 앞 뒤가  같으면 
        {
            if(i+2  > arr.size())
            {
                answer[size-1] = arr[arr.size()-1];
               // cout << "test  : " << answer[size] << endl;
                
                break;
            }
            temp_arr = arr[i];// 새로운 배열에 순서대로 초기화 // 1 31333
            

            for(int j=i; j <= size; j++)  
            {
                answer[j] = temp_arr;            
            }     
        }
        else
        {
            temp_arr = arr[i+2];
            for(int j=i; j <= size; j++)
            {
                answer[j] = temp_arr; 
            }
        }   
    } 
    print_arr (answer);
    return answer;
}




int main() 
{
    
    vector<int> arr = {1, 1, 3, 3, 0, 1, 1}; // 151
    int arr_size = sizeof(arr) / sizeof(int);
    solution(arr);
    
	return 0;
}