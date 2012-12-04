#include <stdio.h>
#include <string.h>
#define MAXLEN 100

/*exc: 1-10*/
int main()
{
	char c = 0;
	char output_char[MAXLEN][MAXLEN];
	
	for (; (c=getchar()) != EOF; )
	{
		int i = 0;
		int j = 0;
		
		if (c == '\t')
		{	
		    strcpy(output_char[i],"\\t");

		}
		
		else if (c == '\b')
		{	
		    output_char[i++][j]='\\';
			output_char[i][j++]='b';
		}	
		else if (c == '\\')
			strcpy(output_char[i++], "\\");
		else
			output_char[i++][j++] = c;
			
	    int row = 0;
	    int col = 0;
	    for (row = 0; output_char[row][col] != '\0'; row++)
	    {
		    for (col = 0; output_char[row][col] != '\0'; col++)
			{
				printf("%c",output_char[row][col]);
			}
	    }   
	
	}
	
	return 0;
}
	










/*characters counting*/
/*
int main()
{
	long counter = 0;
	long line_counter = 0;
	char c;
	long blank_counter = 0;
	long tab_counter = 0;
	
	/*while (getchar() != EOF)
	{
		++counter;
	}
	*/
	/*
	for (counter = 0; (c = getchar()) != EOF; ++counter)
	{
	   if (c == '\n')
	  
	       ++line_counter;
	   else if (c == '\t')
	      ++tab_counter;
	   else if (c == ' ')
	   	  ++blank_counter;
	   else if (c == '')	   
	}
	
	
	printf("number of characters: %ld\n", counter);
	printf("number of lines: %ld\n", line_counter);
	printf("number of blanks: %ld\n", blank_counter);
	printf("number of tabs: %ld\n", tab_counter);
	return 0;
}
*/



/*read characters*/
/*int main()
{
	char input_char = getchar();

	while (input_char!=EOF)
	{
		putchar(input_char);
		input_char = getchar();
	}
    if (input_char == EOF)
    	printf("Oh! You just enter an EOF!\n");
    	
	return 0;

}
*/














/*#include <stdio.h>*/

/*int main()*/
/*{*/
	/*int a =  EOF;*/
/*	int a = getchar();*/
/*	printf("%d\n", a!=EOF);*/
/*	return 0;*/
/*}*/


/*	*/
