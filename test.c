#include <stdio.h>

int main()
{
    char c = getchar();
    
    while (c != EOF)
    {
        if (c == '\n')
        	printf("\\n");  
        else if (c == '\t')
        	printf("\\t");
        else if (c == '\\')
        	printf("\\\\");
        else
        	putchar(c);
        c = getchar();
    }
       
	return 0;
}

