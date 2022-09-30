#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


// tree
int num;
int n;
int arr[1040];
vector<int> bytree[1040];
// 이진트리  

// 2 1 3
// 1 
// 2 3 

void binarytree(int level, int r, int l)
{
    if(r > l)
        return;
    // 최 하단 노드일 경우 
    if(r == l)
    {
        bytree[level].push_back(arr[r]);
        return;
    }
    int m = (r + l) / 2;
    bytree[level].push_back(arr[m]);
    binarytree(level+1, r, m-1);
    binarytree(level+1, m+1, l);
}



int main()
{
    cin >> num;
    n = pow(2,num)-1;

    for(int i=1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }
  
    binarytree(0, 1, n);
    for(int i=0; i < n; i++)
    {
        for(auto &el : bytree[i])
            cout << el << " ";
        cout << endl;
    }
    return 0;
}