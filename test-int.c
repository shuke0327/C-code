#include <stdio.h>
float sum_elements(float a[], unsigned length);

int main()
{
	float a[] = {1.0,2.0,3.0,4.2,5.3,6.2};
	float get_sum = sum_elements(a, 0);
	printf("%f\n",get_sum);
	return 0;
}

/*buggy code*/
 float sum_elements(float a[], unsigned length) /*unsigned length:  */
 {
 	int i;
 	float result = 0;
 	
 	for (i = 0; i <= length-1; i++)
 
result += a[i];
 
 	
 	return result;
 }
 
