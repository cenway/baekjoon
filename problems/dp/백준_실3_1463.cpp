//bfs로도 풀이 가능
#include <iostream>
using namespace std;

int arr[1000001];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	arr[0] = 10000000;
	arr[1] = 0;
	
	for(int i = 1; i < n; i++)
	{
		int cnt = arr[i]+1;

		if(((i+1) <= n) && (arr[i+1] == 0 || arr[i+1] > cnt)) arr[i+1] = cnt;
		if(((i*2) <= n) && (arr[i*2] == 0 || arr[i*2] > cnt)) arr[i*2] = cnt;
		if(((i*3) <= n) && (arr[i*3] == 0 || arr[i*3] > cnt)) arr[i*3] = cnt;
	}

	cout << arr[n];

	return 0;
}
//i가 1이 되기 위한 최소 횟수를 저장
//초기값을 넣고
//늘려나가기
//ㄴ근데 이 늘려나가는 걸 어떻게 할까
//늦게 온 놈이 더 빠를 수 있음
