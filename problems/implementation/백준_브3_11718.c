#include<stdio.h>
#include<unistd.h>

int main() 
{
    char buf[10000];
	int len = read(0,buf,10000);
	write(1,buf,len);
    return 0;
}
