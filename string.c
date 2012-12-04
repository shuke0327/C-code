#include <stdio.h>
#include <string.h>

int main()
{
	printf("%s\n","this is a string constant");
	
	char *s = "this is a string constant";
	printf("%s is stored at: %p \n", s, s);
	printf("the address of s is: %p\n", &s);
	s = "this is another string ,hah";
	printf("now I have changed the s: \n");
	printf("%s is now stored at %p \n", s, s);
	printf("now, the address of s is: %p\n", &s);
	
	char t[] = "this is a character array";
	printf("\"%s\" is stored at address: %p", t, t);
	printf("I want to change the content in \"t\", how?\n");
	printf("sizeof t is: %d\n", sizeof(t));
	
	char *ref = "I have changed the t";
	strcpy(t, ref); /*how to change the content of t?*/
	printf("now, the content in t is \"%s\", at address: %p\n", t, t);
	printf("sizeof t is: %d\n", sizeof(t));
	/*strcpy(t,"I want to make it outflow waht will happend haha s?"); 
	printf("the content in t is \"%s\",address is: %p, sizeof t is: %d", t, t, sizeof(t));
    */
    
    /*practice: how to change the char in a char array*/
    char test[]="this is a test string";
    printf("%c",test[1]);
    putchar(test[1]);
    printf("\nnow, I will change the content in test:\n");
    test[0] = '0';
    test[2] = '2';
    test[4] = "whatisrunwithme"[4];
    putchar(test[4]);
    putchar('\n');
    printf("\n%s\n",test);
    putchar(*"\n");
    
    return 0;
}
	
	
	
	
	
	
