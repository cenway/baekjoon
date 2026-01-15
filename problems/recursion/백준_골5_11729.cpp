//이 문제만 그런지 모르겠는데

//내가 어디쯤의 재귀고 어떻고 알 필요가 없음
#include <iostream>
#include <queue>

using namespace std;

void func(int a, int b, int n)
{
    if(n == 1)
    {
        cout << a << ' ' << b << '\n';
        return;
    }
    //n == k이면 k-1을 a와 b가 아닌 칸으로 옮기고
    //k를 b로, 다시 k-1을 b로
    func(a, 6-a-b, n-1);
    func(a, b, 1);
    func(6-a-b, b, n-1);
    return;
}

int main() {
    // 코드 작성
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >>n;
    cout << (1 << n) - 1 <<endl;
    func(1, 3, n);

    return 0;
}