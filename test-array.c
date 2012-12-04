#include <stdio.h>
typedef char name;

void sayhello(name *);
int  sum(int x, int y);

int main()
{
	name FirstName[] = "jing kai";
	sayhello(FirstName);
	return 0;
}

void sayhello(name usr_name[])
{
	printf("hello, %s\n", usr_name);
}
int accum = 0;
int sum(int x, int y)
{
    
	int t = x + y;
	accum += t;
	return t;
}

