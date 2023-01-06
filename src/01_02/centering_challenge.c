#include <stdio.h>
#include <string.h>

void center_text(int width, char *text)
{
	/*
	   - write this function to complete the challenge
	   - this code won't run until the function is
	   written
	*/
int text_length = strlen(text);
int total_space = width - text_length;
int left = total_space/2;
int right = total_space - left;
int i = 0;
char str[width];
char delimiter = ' ';
if (left >= 0)
{
	while (i < left){
		str[i] = delimiter;
		i ++;
	}
	
	i = 0;
	while (i < text_length)
	{
		str[left+i] = text[i];
		i++;
	}
	i = 0;
	while (i < right)
	{
		str[left + text_length + i] = delimiter;
		i++;
	}

	str[width] = '\0';
	printf("%s\n", str);
}else{
	printf("%s\n", text);
}


}

int main()
{
	/* some sample text to center */
	char *title[] = {
	   "March Sales",
	   "My First Project",
	   "Centering output is so much fun!",
	   "This title is very long, just to see whether the code can handle such a long title"
	};
	int x;

	/* output each of the strings, centered */
	for( x=0; x<4; x++ )
	{
		/* assume the screen width to be 80 characters */
		center_text(80, title[x] );
	}

	return(0);
}
