#include <iostream>
using namespace std;

char lc[100];
char rc[100];
char p[100];


void forward(char f)
{
	cout << f;
	if(lc[f] != '.')
		forward(lc[f]);
	if(rc[f] != '.')
		forward(rc[f]);
}

void midward(char f)
{
	if(lc[f] != '.') midward(lc[f]);
	cout << f;
	if(rc[f] != '.') midward(rc[f]);
}

void backward(char f)
{
	if(lc[f] != '.') backward(lc[f]);
	if(rc[f] != '.') backward(rc[f]);
	cout << f;
}

int main() {
	// 코드 작성
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		lc[a] = b;
		rc[a] = c;
		p[b] = a;
		p[c] = a;
	}

	forward('A');
	cout << '\n';
	midward('A');
	cout << '\n';
	backward('A');


	return 0;
}