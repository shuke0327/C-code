#include <string.h>
#include <stdio.h>
# define NAME_LENGTH 20 
int main()
{
	//char length[] = "this is the sample of name length";
	//int const NAME_LENGTH = strlen(length);
	
	char name[NAME_LENGTH + 1] = {0};
	
	int i = 0;
	
	for (i = 0; i < NAME_LENGTH; i++)
	{
		name[i] = 'a';
	}
	
	strncpy(name, "this is another nameseaga", NAME_LENGTH);
	printf("%d\n", NAME_LENGTH);
	
	printf("%s\n", name);
	printf("%s\n length: %d\n", name, strlen(name));
	name[NAME_LENGTH] = '!'; /*会出现段错误*/
	printf("%s\n", name);
	
	
	
	return 0;
}
