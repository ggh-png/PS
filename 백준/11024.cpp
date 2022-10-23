#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    getchar();
    for (int i = 0; i < T; i++) {
        int sum{ 0 };
        string text;
        getline(cin, text);
        string numstr;

        for (int c = 0; c < text.size(); c++) {
            if (text[c] != ' ') {
                numstr.push_back(text[c]);
            }
            else {
                sum += stoi(numstr);
                numstr.clear();
            }
        }
        sum += stoi(numstr);
        cout << sum << endl;
    }

    return 0;
}