#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <stdbool.h>


#define PSIZE 20

int main()
{
	char *playlist[PSIZE] = {
		"Like a Rolling Stone", "Satisfaction", "Imagine",
		"What's Going On", "Respect", "Good Vibrations",
		"Johnny B. Goode", "Hey Jude", "What'd I Say",
		"Smells Like Teen Spirit", "My Generation",
		"Yesterday", "Blowin' in the Wind", "Purple Haze",
		"London Calling", "I Want to Hold Your Hand",
		"Maybellene", "Hound Dog", "Let It Be",
		"A Change Is Gonna Come"
	};
	//bool recent[PSIZE];
	int recent[PSIZE] ={0};
	int frequency[PSIZE];
	int x, r, count;

	/* initialize */
	srand( (unsigned)time(NULL) );
	for(x=0;x<PSIZE;x++)
		frequency[x] = 0;


	/* run through the playlist randomly */
	puts("Playlist:");
	count = 0;
	while(count<100)
	{
		/* does r appear in recent[]? */
		r = rand() % PSIZE;		/* random value */
		if (recent[r] == 0){
			printf("%3d: Now Playing '%s'\n",
				count+1,
				playlist[r]
			  );
				recent[r] = count + 1;
				frequency[r]++;
				count++;
		}
		else if ((count + 1) - recent[r] > 15)
		{
				printf("%3d: Now Playing '%s'\n",
							 count + 1,
							 playlist[r]);
				recent[r] = count + 1;
				frequency[r]++;
				count++;
		}
	}

	puts("Song frequency:");
	for(x=0;x<PSIZE;x++)
		printf("%s: %d\n",playlist[x],frequency[x]);

	return(0);
}
