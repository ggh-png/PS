#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main() {
	
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
	vector<string> v = {"c=","c-", "dz=", "d-", "lj", "nj", "s=", "z="};

	string str;
	cin >> str;
	int index;

	for (int i = 0; i < v.size(); i++) 
		while (1)
        {   // iterator 반환 
            // 찾지 못하면 -1 반환
			index = str.find(v[i]);
			if (index == string::npos)
				break;
			str.replace(index, v[i].length(), "#");
		}

	cout << str.size();
	return 0;
}
