#include <iostream>
#include <algorithm>

using namespace std;

int n, m, idx;
int arr[8];
int ans[8];

void func(int depth, int before)
{
    if(depth== 0)
    {
        for(int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(i && arr[i] == arr[i-1]) continue;
        if(arr[i] < before) continue;
        ans[idx] = arr[i];
        idx++;
        func(depth-1, arr[i]);
        idx--;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    func(m, 0);

    return 0;
}

//일단 중복 선택이 가능하므로
//중복 값을 지우거나
//중복이면 피하거나(의미 없게 하거나)
//