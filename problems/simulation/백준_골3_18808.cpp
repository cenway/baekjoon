//코드가 지저분하고 길어질 때를 대비해
//코드를 나눠 작성하고 각각을 테스트하자

//코드 구현력이 매우 낮음
//상황이 복잡해지면 겹치거나, 예외 상황 발생을 놓치는 경우가 많음
#include <iostream>

using namespace std;

bool map[40][40];

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	//입력받고
	//k번 입력에 대해
		//크기와 배열을 입력 받고
		//4방향에 대해
			//(n-r)*(m-c)의 시작 지점에 대해
				//r*c가 들어가는 지 확인
				//들어가면 집어넣고 칸 수 빼고 탈출
				//안 들어가면 돌리기
	//출력
	int n, m, k;
	cin >> n >> m >> k;
	int stick = 0;

	while(k--)
	{
		int r, c, cnt;
		cin >> r >> c;
		bool arr[10][10];

		cnt = 0;
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				cin >> arr[i][j];
				if(arr[i][j]) cnt++;
			}
		}
		
		int angle = 3;
		for(int a = 0; a < 4; a++)
		{
			//여기서 회전
			//나중에 깔끔하게 
			int nr = r;
			int nc = c;
			if(a%2)
			{
				nr = c;
				nc = r;
			}
			bool rot_arr[10][10];
			

			//원본을 유지하려 하지 말고 매번 90도씩 돌리면 됨
			//복사 과정이 있어서 좀 느려질 순 있긴 한데 
			if(a == 0)
			for(int i= 0; i < r; i++)
				for(int j= 0; j < c; j++)
					rot_arr[i][j] = arr[i][j];
			else if(a == 1)
			for(int i = 0; i < c; i++)
				for(int j = 0; j < r; j++)
					rot_arr[i][j] = arr[r-j-1][i];
			else if(a == 2)
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
					rot_arr[i][j] = arr[r-i-1][c-j-1];
			else if(a == 3)
			for(int i = 0; i < c; i++)
				for(int j = 0; j < r; j++)
					rot_arr[i][j] = arr[j][c-i-1];



			bool succ_flag = false;
			for(int i = 0; i < (n - nr+1); i++)
			{
				for(int j = 0; j < (m - nc+1); j++)
				{
					//가능하면 여기는 함수화
					//겹치는지 확인
					bool fail_flag = false;
					
					for(int p = 0; p < nr; p++)
					{
						for(int q = 0; q < nc; q++)
						{
							if(rot_arr[p][q] && map[p+i][q+j])
							{
								fail_flag = true;
								break;
							}
						}
						if(fail_flag) break;
					}
					if(fail_flag) continue;

					for(int p = 0; p < nr; p++)
						for(int q = 0; q < nc; q++)
						{
							if(!map[i+p][j+q])
								map[i+p][j+q] = rot_arr[p][q];
						}
					
					stick += cnt;
					succ_flag = true;
					break;
				}
				if(succ_flag) break;
			}
			if(succ_flag) break;
		}
	}

	cout << stick;
	return 0;
}

/*
1. 위
2. 왼
3. 없으면 시계 90도
받는 순서대로

그리해서 몇 칸이 남았는가
그래서

1. 공간이 되는지 어떻게 확인
2. 회전은 어떻게 구현
3. 시간 복잡도 안에 가능한가
*/