#include <stdio.h>
#include <stdlib.h>

char *left(char *s,int len)
{
	int i = 0;
	char *r = malloc(sizeof(char) * (len + 1));
	if (r == NULL)
		exit(1);

	for (i = 0;i<=len-1;i++){
		r[i] = s[i];
	}
	return r;
}

char *right(char *s,int len)
{
	int i = 0;
	char *r = malloc(sizeof(char) * (len + 1));
	if (r == NULL)
		exit(1);

	for (i = 0; i <= len - 1; i++)
	{
		r[i] = s[len + i];
	}
	return r;
}

char *mid(char *s, int offset, int len)
{
	int i = 0;
	char *r = malloc(sizeof(char) * (len + 1));
	if (r == NULL)
		exit(1);
		
	for (i = 0; i <= len - 1; i++)
	{
		r[i] = s[offset -1 + i];
	}
	return r;
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n",string);
	printf("Left %d characters: %s\n",16,left(string,16));
	printf("Right %d characters: %s\n",18,right(string,18));
  printf("Middle %d characters: %s\n",11,mid(string,13,11));
	return(0);
}
