#include <iostream>

using namespace std;  

const int n = 3;

int main() 
{   
    int arr[3] = {1, 2, 3};
	for(int i = 0; i < (1 << n); i++)
    {
		int ret;
        
		for(int j = 0; j < n; j++)
			if(i & (1 << j))
				cout << arr[j] << " ";
		cout << endl;
	} 
    return 0;
} 

