#include <bits/stdc++.h>

using namespace std;

vector<int> v[100000];
int arr[100000] = {1, 1,};

void dfs(int k)
{
	//수렴 조건
	//이 반복에 포함된 듯?

	//반복
	for(int x : v[k])
	{
		if(x != arr[k])
		{
			arr[x] = k;
			dfs(x);
		}
		
	}
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}

	dfs(1);

	for(int i = 2; i <= n; i++)
	{
		cout << arr[i] << "\n";
	}

	return 0;
}

/*
벡터로 연결된 노드을 표시(200,000Bytes)
1부터 시작해서 자식 노드로 타고 내려가며 부모 노드를 표시
dfs로 구현해도 될 거 같은데
재귀로?
*/