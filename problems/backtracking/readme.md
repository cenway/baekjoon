백트래킹은 n이 작은 경우에
ㄴ시간복잡도나 n값에 너무 쫄지 말자

C++에서는 next_permutation이라는 개사기 함수가 존재
자동으로 다음 순열을 만들어 주는데

배열 int arr[3] = {1, 2, 3}; 했다면
next_pernutation(arr, arr+3);
arr[] = {1, 3, 2}로 바뀜
끝까지 가면 다시 {1, 2, 3}으로 돌아옴

이를 활용해서 조합을 만드는 방법 또한 존재하는데

4중 2개 짜리 조합이라고 하면
int arr[4] = {0, 0, 1, 1};
do {
    for(int i = 0; i < 4; i++){
        if(!arr[i]) cout << i + 1;
    }
    cout << '\n';
}while(next_permutation(arr, arr+4))
//12
//13
//14

특히 조합은 풀었던 문제들 다시 확인해보자
