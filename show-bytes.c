
#include <stdio.h>
#include <string.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%.2x", start[i]);
	}
	printf("\n");
}

void show_int(int x)
{
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main()
{
    /*int val = 12345;
    test_show_bytes(val);
    printf("\n");
    char *s = "ABCDEF";
    show_bytes(s,strlen(s));*/
    
    short int x = 12345;
    short int mx = -x;
    show_bytes((byte_pointer) &x, sizeof(short int));
    show_bytes((byte_pointer) &mx, sizeof(short int));
    return 0;
}
