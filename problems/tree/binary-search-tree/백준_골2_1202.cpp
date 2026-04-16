#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> v;

	for(int i = 0; i < n; i++)
	{
		int m, val;
		cin >> m >> val;

		//pair의 sort를 위해 순서 바꿈
		v.push_back({val, m});
	}
	sort(v.begin(), v.end());

	multiset <int> ms;
	for(int i = 0; i < k; i++)
	{
		int bag;
		cin >> bag;
		ms.insert(bag);
	}


	unsigned long long ans = 0;
	for(int i = n-1; i >= 0; i--)
	{
		if(v[i].second > *prev(ms.end())) continue;

		if(*ms.lower_bound(v[i].second) == v[i].second)
			ms.erase(ms.lower_bound(v[i].second));
		else
			ms.erase(ms.upper_bound(v[i].second));
		ans += v[i].first;
		k--;
		if(k == 0) break;
	}
	
	cout << ans;
	return 0;
}
/*
가장 가치가 높은 거 우선해서 그 무게 upper bound에 담기?
각 가방이 담을 수 있는 가장 비싼 것들을 담으면 안되지
각 보석이 담길 수 있는 가장 작은 가방에 담기면
*/