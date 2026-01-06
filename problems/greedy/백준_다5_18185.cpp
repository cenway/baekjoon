#include <iostream>
#include <algorithm>

int arr[10002] = {0,};
int coin= 0;

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int num;
    cin >> num;
    for(int i = 0; i < num; i++)
        cin >> arr[i];
    
    for(int i = 0; i < num; i++)
    {
        int arr_min;
        if(arr[i] == 0)
            continue;
        if((min({arr[i+1],arr[i+2],arr[i+3]}) != 0) && (arr[i] < arr[i+1]) &&(arr[i+2] < arr[i+1]))
        {
            arr_min = (arr[i] < (arr[i+1] - arr[i+2]))? arr[i]:(arr[i+1] - arr[i+2]);
            arr[i] -= arr_min;
            arr[i+1] -= arr_min;
            coin += 5 * arr_min;
        }
        arr_min = min({arr[i],arr[i+1],arr[i+2]});
        arr[i] -= arr_min;
        arr[i+1] -= arr_min;
        arr[i+2] -= arr_min;
        coin += 7 * arr_min;
        
        arr_min = min(arr[i],arr[i+1]);
        arr[i] -= arr_min;
        arr[i+1] -= arr_min;
        coin += 5 * arr_min;
        
        coin += 3 * arr[i];
        arr[i] = 0;
    }
    cout << coin;
    return 0;
}
