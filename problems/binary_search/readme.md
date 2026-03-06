이분탐색은 정렬된 배열에서 한 원소를 탐색
binary_search, uppder/lower_bound 함수를 사용하자
!!!**stl의 이분탐색은 "오름차순" 기준**!!!

좌표 압축를 위한 정렬 후 중복 제거
sort(uni.begin(), uni.end());
uni.erase(unique(uni.begin(), uni.end()), uni.end());
lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin();

왜 lower_bound-begin를 쓰냐, binary_search는 반환값이 
있냐없냐 뿐이라, 인덱스는 저렇게

1920, 10816, 18870은 stl로 날먹 가능한 문제들

합으로 묶어서 쓰는 방법은 자주 나오는 테크닉이니 기억
(2295)

mid = (low+high+1)/2;
if(cable_cnt >= n) low = mid;
		else high = mid-1;

mid = (low+high)/2;
if(cable_cnt >= n) low = mid+1;
		else high = mid-1;

+1 은 위처럼 상황 따라 다름

값이 큰 문제들이 많으니 오버플로우 주의
