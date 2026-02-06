#include <iostream>
#include <vector>
using namespace std;

int map[8][8];
bool visit[8][8];
int n, m, cnt;
vector<pair<int, int>> v[7];

int main() {
	// 코드 작성
	//입력 검증 완료
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if(map[i][j])
			{
				visit[i][j] = true;
				v[map[i][j]].push_back({i, j});
			} 
			else cnt++;
		}
	}
	

	return 0;
}

//일단 0들어올 때 마다 cnt++
//높은 숫자부터 해서 5번 하자
//visit칸을 체크하며 값이 더 높게 나오는 쪽으로
//그냥 q나 벡터에 입력 별 좌표를 저장할까
//