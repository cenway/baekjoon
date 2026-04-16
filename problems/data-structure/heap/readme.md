priority_queue<int> ; <= 기본적으로 최대 힙
priority_queue<int, vector<int>, greater<int>> ; <=라고 써야 최소힙

절대값 비교 함수
class cmp {
public:
	bool operator() (int a, int b) {
		if(abs(a) != abs(b)) return abs(a) > abs(b);
		return a > b;
	}
};