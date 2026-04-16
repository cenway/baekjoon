#include <iostream>
#include <algorithm>
using namespace std;

int heap[100001];
int sz = 0;

void push(int x)
{
	sz++;
	int idx = sz;
	heap[idx] = x;
	while(idx > 1)
	{
		if(heap[idx/2] <= x) return;
		swap(heap[idx/2], heap[idx]);
		idx /= 2;
	}
}

int top(void)
{
	if(sz == 0) return 0;
	return heap[1];
}

void pop(void)
{
	if(sz == 0) return;
	
	
	int idx = 1;
	heap[1] = heap[sz];
	heap[sz] = 0;
	if(sz > 0) sz--;
	while(idx*2 <= sz)
	{
		int min = idx*2;
		if(idx*2+1 <= sz && heap[min] > heap[idx*2+1]) min += 1;
		if(heap[idx] < heap[min]) break;
		swap(heap[idx], heap[min]);
		idx = min;
	}
	
}

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while(n--)
	{
		int k;
		cin >> k;
		if(k == 0) 
		{
			cout << top() << '\n';
			pop();
		}
		else 
		{
			push(k);
		}
		//for(int i = 1; i <= 4; i++) cout << heap[i] << ' ';
		//cout << '\n';
	}

	return 0;
}