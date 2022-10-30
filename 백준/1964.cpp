#include <iostream>

using namespace std;

const int MAX = 45678;

int main()
{
	int n;
	int res = 5;
	int size = 1;

	cin >> n;

	for (int i = 1; i < n; i++)
		res = (res + (i + 2) + ((i + 1) * 2)) % MAX;

	cout << res;

	return 0;
}