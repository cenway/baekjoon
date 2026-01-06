/*
구조체에 인덱스를 저장할 필요 없이 
닫는 괄호일 때 string의 직전 인덱스가 여는 괄호인지를 확인

현재까지의 곱셈 값을 저장해서  ()나 []를 만났을 때 바로 곱해주기
이전 방식에서 분배법칙을 적용하는 방식으로 바꿈
*/
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

    string s;
    cin >> s;

    long long ans = 0;
    int tmp = 1;
    bool error = false;
    stack<char> stk;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            stk.push('(');
            tmp *= 2;
        }
        else if(s[i] == '[')
        {
            stk.push('[');
            tmp *= 3;
        }
        else if (s[i] == ')') {
            // 1. 스택이 비었거나 짝이 안 맞으면 에러
            if (stk.empty() || stk.top() != '(') {
                error = true;
                break;
            }
            // 2. "바로 직전"이 여는 괄호였다면 값을 더함 (가장 깊은 곳)
            if (s[i - 1] == '(') {
                ans += tmp;
            }
            // 3. 닫았으니 스택 pop 및 곱셈 원상복구
            stk.pop();
            tmp /= 2;
        }
        else if(s[i] == ']')
        {
            if(stk.empty() || stk.top() != '[')
            {
                error = true;
                break;
            }
            if(s[i - 1] == '[') ans += tmp;
            stk.pop();
            tmp /= 3;
        }
    }
    if(error || !stk.empty())
        cout << 0;
    else
        cout << ans;
}