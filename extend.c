
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
    
    /*short int x = 12345;
    short int mx = -x;
    show_bytes((byte_pointer) &x, sizeof(short int));
    show_bytes((byte_pointer) &mx, sizeof(short int));
    
    int val = -12345;
    short sx = val;
    unsigned short usx = sx;
    int x = sx;
    unsigned ux = usx;
    
    printf("sx=%d:\t", sx);
    show_bytes((byte_pointer) &sx, sizeof(short));
    printf("usx = %u:\t", usx);
    show_bytes((byte_pointer) &usx, sizeof(unsigned short));
    printf("x = %d:\t",x);
    show_bytes((byte_pointer) &x, sizeof(int));
    printf("ux = %u:\t", ux);
    show_bytes((byte_pointer) &ux, sizeof(unsigned));   
    */
    int fun1(unsigned word)
    {
     	return (int) ((word<<24)>>24);
    }
    
    int fun2(unsigned word)
    {
        return ((int) word << 24)>>24;
    }
    
    unsigned x[] = {127,128,255,256};
    int i = 0;
    for (i = 0; i < 4; i++)
    {
    	printf("fun1: %d\t",fun1(x[i]));
    	printf("fun2: %d\n",fun2(x[i]));
    }
    
    int origin = 53191;
    short sx = (short) origin;
    int y = sx;
    show_bytes((byte_pointer) &origin, sizeof(int));
    show_bytes((byte_pointer) &sx, sizeof(short int));
    show_bytes((byte_pointer) &y, sizeof(int));
    return 0;
}
