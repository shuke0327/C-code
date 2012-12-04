


// 尝试使用函数指针，对下面函数进行优化 
// float (*ptr_convert)(float);
// 与： float (*ptr_convert)();
// 得到不同的结果。因为前者指向的是一个函数，动态调用；而后者则会将值固定死，而非调用函数。

#include <stdio.h>

float FahrToCels(float);
float CelsToFahr(float);

int main()
{
	float temp_input = 0.0;
	const float lower = 0.0;
	const float higher = 300.0;
    const float step = 20.0;
    float temp_output = 0.0;
    
	printf("%s", "Please enter the temperature format: F or C \t");
	char temFormat = getchar();
	char* input_temFormat;
	char* output_temFormat;
	
	input_temFormat = (temFormat == 'F') ? "Fahrenheit" : "Celsious";
	output_temFormat = (temFormat == 'F') ? "Celsious" : "Fahrenheit";
	printf("\n Temperature convertion from %s to %s \n", input_temFormat, output_temFormat);
	
	float (*ptr_convert)(float);
	ptr_convert = (temFormat == 'F') ? FahrToCels : CelsToFahr;
	
	for (temp_input = higher; temp_input >= lower; temp_input -= step)
	{
		
		temp_output = (*ptr_convert)(temp_input);
		printf("%4.1f \t %5.1f\n", temp_input, temp_output);
    }
    
    return 0;
}

float FahrToCels(float temp)
{
   float result;
   result = 5*(temp-32)/9;
   return result;
}

float CelsToFahr(float temp)
{
	float result;
	result = 32.0 + 9.0 * temp / 5.0;
	return result;
}







/*#include <stdio.h>*/
/*#include <string.h>*/
/*int main(void)*/
/*{*/
/*   string a = "hello";*/
/*   printf("hello, %s!\n", a);*/
/*   return 0;*/
/*}*/
/*#include <stdio.h>*/


/*int main(void)*/
/*{*/
/*    char s[] = "jing";*/
/*    printf("hello, %s!\n\c", s);*/
/*    return 0;*/
/*}*/


