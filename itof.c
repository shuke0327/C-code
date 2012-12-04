#include <stdio.h>
#define FRAC_LEN 23
#define EXP_LEN  8  
#define SIG_LEN  1
#define BIAS 127
#define BIT_FLOAT 32

float itof(int x);
void get_float(int x);

int main()
{   
    
    int input = 127;
    printf("input is: %d\n",input);
    int s[] = {-12,0,123};
    int i = 0;
    
    for (i = 0; i < 3; i++)
    {
        float output = 0.0;
        output = itof(s[i]);
        printf("input is: %d\t",s[i]);
        printf("changed to: %f\n",output);
    }
    return 0;
}

void get_float(int x)
{   
    printf("the value inputed is: %d\n",x); 
	/*初始化返回值浮点数fx*/
	float fx = 0.0;
		/*获得符号位*/
    int sig_area = 0;
	/*对x进行判断，如果为0，则直接返回结果；否则，进行判断*/
	/*if (x = 0)
		printf("%f\n",fx);
	
    else if (x < 0)
    {
        x = -x;
    	sig_area = 1;
    }
	*/	

    
    /*声明为无符号类型，右移使用逻辑右移*/
    unsigned int frac_area = x; 
    
    /*initial the digit num 初始化右移的位数*/
	unsigned int bit_num = 0;
    	
    /*获得右移至规范数据(小数点左侧只保留1)时候，所应该右移的位数*/  
		  
    while (x != 1)
    {
    	x = x>>1;
    	bit_num++;
    }
    
    int temp = x;
    printf("bit_num = : %d\n",bit_num);
          
    
    
    /*获得小数域的值*/
    int frac_width = BIT_FLOAT - FRAC_LEN;
                       
    frac_area = frac_area<<(BIT_FLOAT - bit_num);    /*左移32-bit_num位，取得小数位*/
    frac_area = frac_area>>frac_width;/*(sizeof(float)-FRAC_LEN); 右移9位，将小数域的值存放在小数域中*/
    
    /*获得指数域的值*/
    int exp_area = 0;
    exp_area = BIAS + bit_num;
    exp_area = exp_area<<FRAC_LEN;
    
    /*获得符号位*/
    sig_area = sig_area<<(BIT_FLOAT - SIG_LEN);
    
    /*组装获得需要的浮点数值*/
    int result = 0;
    result |= exp_area;
    result |= frac_area;
    result |= sig_area;
    
    fx = *(float*)&result;
    printf("fx is: %f\n",fx);
       
}


/*below is the buggy code*/
/*bug fixed: since a stencence: wrong write x = 0 instead of the right: x == 0*/
float itof(int x)
{
	/*初始化返回值浮点数fx*/
	float fx = 0.0;
		/*获得符号位*/
    int sig_area = 0;
	/*对x进行判断，如果为0，则直接返回结果；否则，进行判断*/
	if (x == 0)     /*新手错误：将比较==误写作赋值=*/
		return fx;
	
    else if (x < 0)
    {
        x = -x;
    	sig_area = 1;
    }    
      
    /*声明为无符号类型，右移使用逻辑右移*/
    unsigned int frac_area = x; 
    
    /*initial the digit num 初始化右移的位数*/
	unsigned int bit_num = 0;
    	
    /*获得右移至规范数据(小数点左侧只保留1)时候，所应该右移的位数*/  
		  
    while (x != 1)
    {
    	int temp = (unsigned int)x>>1;
    	x = temp;
    	bit_num++;
    }
    
    
    /*获得小数域的值*/
    int frac_width = BIT_FLOAT - FRAC_LEN;
                       
    frac_area = frac_area<<(BIT_FLOAT - bit_num);    /*左移32-bit_num位，取得小数位*/
    frac_area = frac_area>>frac_width;/*(sizeof(float)-FRAC_LEN); 右移9位，将小数域的值存放在小数域中*/
    
    /*获得指数域的值*/
    int exp_area = 0;
    exp_area = BIAS + bit_num;
    exp_area = exp_area<<FRAC_LEN;
    
    /*获得符号位*/
    sig_area = sig_area<<(BIT_FLOAT - SIG_LEN);
    
    /*组装获得需要的浮点数值*/
    int result = 0;
    result |= exp_area;
    result |= frac_area;
    result |= sig_area;
    
    fx = *(float*)&result;
  
    return fx;
    
}
    
    
    
        
    
    
    
    
    
    
    
    
     	
   	
	
	
	
	
	
	
	
	
	
	

