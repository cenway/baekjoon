#include <bits/stdc++.h>
using namespace std;

int arr[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	for(char c:s1) arr[c-'a'] += 1;
	for(char c:s2) arr[c-'a'] -= 1;

	int ans = 0;
	for(int i = 0; i < 26; i++)
	{
		if(arr[i] != 0)
			ans += abs(arr[i]);
	}

	cout << ans;
	return 0;
}