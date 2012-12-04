#include <stdio.h>
#include <string.h>

#define FRAC_LEN 23
#define EXP_LEN  8  
#define SIG_LEN  1
#define BIAS 127
typedef unsigned char *byte_pointer;
typedef int Boolean;

Boolean debug = 1;

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
	int bit_num = 0;
	int x = 2222;
	printf("now, x is: 0x%x \t %d\n", x, x);
	int temp = x;
	
	/*得到指数e*/
	while (temp!=1)
	{
		temp = temp>>1;
		bit_num++;
		printf("%d\n",bit_num);
		printf("now, temp is: 0x%x \t %d\n", temp, temp);
	}
	
	int bit_float = sizeof(float)*8;
	int frac_width = bit_float-FRAC_LEN;
	
	/*获得小数域的值*/
    unsigned int frac_area = x;
    frac_area = frac_area<<(bit_float-bit_num);    /*左移32-bit_num位，取得小数位*/
    if (debug)
    {
        printf("after moved left 32-bitnum,frac_area is: 0x%x \t %d\n",frac_area,frac_area);
    }
    
    frac_area = frac_area>>frac_width;/*右移9位，将小数域的值存放在小数域中*/
   	if (debug)
   	{
   		printf("frac_area is: 0x%x \t %d\n",frac_area,frac_area);
   	}
   	/*获得指数域的值*/
   	int exp_area = BIAS + bit_num;
   	exp_area = exp_area<<FRAC_LEN;
   	
   	/*组装*/
   	
   	int result = 0;
   	result |= exp_area;
   	result |= frac_area;
   	
   	float fx = *(float*)&result;
   	
   	printf("int result: %x\t %d\n",result,result);
   	printf("fx is :%f\n",fx,fx);
   	show_bytes((byte_pointer)&fx,sizeof(float));
	return 0;
}
	
	
