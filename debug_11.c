#include <stdio.h>
#include <string.h>
typedef unsigned char* byte_pointer; 


void pass_val(int);
int  trans_val(int);
void show_bytes(byte_pointer start, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%.2x",start[i]);
	}
	printf("\n");
}
	

int main()
{
	/*pass_val(result);
	int get_int = trans_val(result);
	*/
	float fx = 0.0;
	int result = 1112;
	result = result|0x20E00000;
	fx = *(float *)&result;
	show_bytes((byte_pointer)&result,sizeof(int));
	show_bytes((byte_pointer)&fx,sizeof(float));
	printf("%f\n",fx);
	return 0;
}

void pass_val(int x)
{
	int temp = x;
	printf("I captured the input val: %d\n",x);
	printf("Stu, where is your mind?\n");
	int bit_num = 0;
	while (x!=1)
	{
		x = x>>1;
		bit_num++;
	}
	printf("we moved the x to right by %d bits\n",bit_num);
}

int trans_val(int x)
{   
    int bit_num = 0;
	while (x!=1)
	{
		x = x>>1;
		bit_num++;
	}
	printf("we moved the x to right by %d bits\n",bit_num);
	return x;
}







