#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void dfs(int n, int depth)
{
    if(depth == M)
    {
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = n; i <= N; i++)
    {
        v.push_back(i);
        dfs(i + 1, depth + 1);
        v.pop_back();
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    dfs(1, 0);

    return 0;
}
/* 
dfs로 돌리는데
재귀로
1. 뭘 넘겨줄 건지.
2. 뭘 리턴할 건지.
3. 언제 끝나는지.
*/