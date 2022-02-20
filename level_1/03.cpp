#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution (int arr[], int arr_size);
void print_arr (int arr[], int arr_size);
int output_arr_size(int arr[], int arr_size);


int main() 
{
    
    int arr[] = {1,5,1,5,3}; // 151
    int arr_size = sizeof(arr) / sizeof(int);
    solution(arr, arr_size);
    
	return 0;
}

int solution (int arr[], int arr_size)
{

    int size = output_arr_size(arr, arr_size);
    int output_arr[size];
    int temp_arr=0;


    for(int i=0; i < arr_size; i++)/// 133133 -- 6 arr size
    {                               // 1313 --   4 size

        if((arr[i] == arr[i+1]) ? false : true)                 // 앞 뒤가  같으면 
        {
            if(i+2  > arr_size)
            {
                output_arr[size-1] = arr[arr_size-1];
               // cout << "test  : " << output_arr[size] << endl;
                
                break;
            }
            temp_arr = arr[i];// 새로운 배열에 순서대로 초기화 // 1 31333
            

            for(int j=i; j <= size; j++)  
            {
                output_arr[j] = temp_arr;            
            }     
        }
        else
        {
            temp_arr = arr[i+2];
            for(int j=i; j <= size; j++)
            {
                output_arr[j] = temp_arr; 
            }
        }   
    } 
    print_arr (output_arr, size);
    return 0;
}



int output_arr_size(int arr[], int arr_size)
{   
    int count = 0;
    for(int i=0; i < arr_size; i++)
    {
        if((arr[i] == arr[i+1]) ? false : true) // 311331
        {
            count++;
        }
    }
    //cout << count << endl;
    return count;
}



void print_arr (int arr[], int arr_size)
{
    cout << "[ ";
    for(int i=0; i < arr_size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}