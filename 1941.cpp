#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

bool ans[1<<25];
char map[5][5];
bool visit[5][5];

void func(int x,int y, int select, int s, int ans_bit)
{
	//자기 좌표를 선택하고
	//자기 주변을 후보군으로 저장
	//ㄴ이 때 이미 후보군으로 저장되어 있는지 확인
	//후보군 중 하나를 선택하고
	//ㄴ선택을 위해서 q를 사용
	//7칸이 채워졌을 때 S가 4개 이상인가 확인해서 비트마스킹
	//ㄴ이 전에 미리 뺄 수도 있음(그냥 언제든 y가 4개면 = select - S가 4가 될 때)
	if(select == 7)
	{
		if(s >= 4)	ans[ans_bit] = true;
		return;
	}
	if(select - s >= 4) 
		return;
	
	
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			cin >> map[i][j];

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)


	return 0;
}

//내가 진행한 경로에 S가 4개 이상 있으면 되는 거
//경로 보다는 넓이, 인접한 7칸을 선택

//인근 칸들을 후보군으로 지정하고 이를 하나씩 채워가며 재귀
//그리고 결과적으로 7칸/S 4칸 이상 의 조건을 충족했을 때 중복인지 확인
//중복 확인은 5*5를 0~24번 비트로 지정해서 비트마스킹된 int들의 배열을 저장
//ㄴ의 경우 최악일 때 상당히 많은 횟수의 확인이 필요할 수 있음
//최악의 최악일 때 5*5에서 발생하는 모든 인접한 7칸이 다 답이 되며
//매번 배열에 없거나 마지막 인덱스에 중복되는 이전 결과가 있었다고 하면
//시간 복잡도가 많이 커질 수 있을 거 같아서
//그래서 비트마스킹할 모든 값에 대한 배열을 미리 만들어두고 1/0만 하자
//