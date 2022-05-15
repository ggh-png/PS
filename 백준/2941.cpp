#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main() {
	
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
	vector <string> v = {"c=","c-", "dz=", "d-", "lj", "nj", "s=", "z="};

	string s;
	cin >> s;
	
	int index;

	for (int i = 0; i < v.size(); i++) {

		while (1){
			index = s.find(v[i]);
			if (index == string::npos)
				break;
			s.replace(index, v[i].length(), "#");
			
		}
	}
	
	cout << s.size();

	return 0;
}
