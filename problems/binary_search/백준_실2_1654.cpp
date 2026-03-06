#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];


int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n;
	cin >> k >> n;
	for(int i = 0; i < k; i++) cin >> arr[i];
	sort(arr, arr+k);

	long long int low, high;
	int cable_cnt = 0;
	low = 1;
	high = arr[k-1];

	while(low < high)
	{
		long long int mid = (high+low+1)/2;
		int cable_cnt = 0;
		for(int i = 0; i < k; i++) cable_cnt += arr[i]/mid;
		if(cable_cnt >= n) low = mid;
		else high = mid-1;
	}
	
	cout << low;

	
	return 0;
}

//자를 길이가 인덱스
//그렇게 잘라서 나오는 랜선 수가 밸류
//그걸로 이분탐색을 진행하는데
//1. stl로 가능? <= 아마 불가능
//ㄴ오히려 그렇기에 오름차순 내림차순은 알아서 가능?
//2. 시작 범위는 어떻게?
//ㄴK<=N이라고 무조건 arr[0](원래 랜선 중 최소)는 아닌게 421이면 2골라도 
//k==N==3인지라
//최대 값을 높게 잡으면 문제는?
//ㄴ탐색 시간이 길어지고, 딱히 없다
//ㄴ조건 상 시작: 1 끝: arr[k-1];
//3. 결과적으로 찾고 싶은 것은?
//ㄴN보다 크거나 같은 가장 큰 인덱스(줄길이)
//bound를 구하는 느낌?

//이게 그니까 이분탐색을 보는 비전이 생기는 거 같아
//탐색이 값이 아닌 인덱스 기준으로