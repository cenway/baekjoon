#include <bits/stdc++.h>

using namespace std;

typedef struct 
{
    long long cnt;
    int height;
}p;

stack <p> stk;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ans = 0;
    cin >> n;

    while(n--)//확인 후 감소
    {
        int tmp;
        long long ncnt = 1;
        cin >> tmp;

        while(!stk.empty() && stk.top().height <= tmp)
        {
            ans += stk.top().cnt;
            if(stk.top().height == tmp) ncnt += stk.top().cnt;
            stk.pop();
        }
        if(!stk.empty())
            ans++;

        stk.push({ncnt, tmp});
    }
    cout << ans;
    return 0;
}

