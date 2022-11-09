#include<iostream>

using namespace std;

int N;
int arr[9];
int check[9];

void dfs(int cnt) {
    
    if(cnt==N) {
        for(int i=0; i<N; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<=N; i++) {
        if(!check[i]) {
           arr[cnt] = i;
           check[i] = 1;
           dfs(cnt+1);
           check[i] = 0;
        }
    }
}
int main() {

    cin >> N;
    
    dfs(0);
    
    return 0;
}