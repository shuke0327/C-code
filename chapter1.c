#include <stdio.h>
int main()
{
	int blank_count = 0;
	int tab_count = 0;
	int ent_count = 0;
	
	char a = 0;
	while ((a=getchar())!=EOF)
	{
		switch (a)
		{
			case '\n':
				ent_count++;
			break;
			
			case '\t':
				tab_count++;
			break;
			
			case ' ':
				blank_count++;
			break;
			
			default:
			   
			break;
		}
	}
	
	printf("there is %d blank\t, %d tab, and %d enter\n",blank_count,tab_count, ent_count);
	
	return 0;
}	   	   











/*#include <stdio.h>*/

/*int main()*/
/*{*/
/*	char c = 0;*/
/*	char a = 0;*/
/*	/*while ((c=getchar()) != EOF)*/
/*	{*/
/*		putchar(c);*/
/*	}*/
/*	*/
/*	printf("EOF is : %d\n",EOF);*/
/*	while((a=getchar())!= EOF)*/
/*	{*/
/*		if (a=='\n')*/
/*		{*/
/*			c = 1;*/
/*			printf("getchar() != EOF is 1\n");*/
/*		}*/
/*	}*/
/*	if ((a = getchar())==EOF)*/
/*		c = 0;*/
/*		*/
/*	printf("getchar() != EOF is %d\n",c);*/
/*	return 0;*/
/*}*/

