#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>

using namespace std;


int main()
{
    char input_arr[11] = { 0, };
    int arr[11] = { 0, };
    int out_arr[10] = { 0, };
    int num_len;
    int num;

    cin >> input_arr;
    num_len = strlen(input_arr);
    num = stoi(input_arr);

    for (int i = 0; i < num_len; i++)//순서 뒤집어서 int형 배열에 넣기
    {
        arr[i] = input_arr[num_len - i - 1] - '0';
    }
    
    for (int i = num_len; i > 0; i--)//높은 자릿수부터 구해서 내려오기
    {
        for (int j = 0; j < 10; j++)//1
        {
            out_arr[j] += int(num / pow(10, i)) * pow(10, i - 1);
        }

        for (int k = 0; k < arr[i - 1]; k++)//2
        {
            out_arr[k] += int(pow(10, i - 1));
        }
        if(i != 1)
            out_arr[arr[i - 1]] += int(num % int(pow(10, i - 1)))+1;//3
    }

    out_arr[arr[0]] += 1;
    for (int i = 0; i < num_len; i++)
    {
        out_arr[0] -= pow(10, i);
    }

    printf("%d %d %d %d %d %d %d %d %d %d ", out_arr[0], out_arr[1], out_arr[2], out_arr[3], out_arr[4], out_arr[5], out_arr[6], out_arr[7], out_arr[8], out_arr[9]);

    return 0;
}