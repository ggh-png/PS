#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    else 
        return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num1, num2;
    cin >> num1 >> num2;

    int lcm  = (num1 * num2) / gcd(num1, num2);

    cout << gcd(num1, num2) << '\n' << lcm << '\n';

    return 0;

}