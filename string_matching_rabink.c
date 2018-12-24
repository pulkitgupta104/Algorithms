#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int *power;

int main(int argc, char const *argv[])
{
	char str[1000000], p[1000000];
	// fgets(str,1000000,stdin);
	for (int i = 0; i < 10000; ++i)
		str[i] = (rand()%4) + 'a';
	fgets(p,1000000,stdin);

	clock_t t;
	t = clock();

	int count = 0, hash=0, hashP = 0, lenS = strlen(str) - 1, lenP = strlen(p) - 1;

	power = malloc(sizeof(int) * lenP);
	power[0] = 1;
	for (int i = 1; i < lenP; ++i)
		power[i] = power[i-1] * lenP;

	for (int i = lenP - 1; i >= 0; --i)
	{
		hash += (str[i] - 'a' + 1) * power[i];
		hashP += (p[i] - 'a' + 1) * power[i];
	}

	for (int i = 0; i <= lenS - lenP + 1; ++i)
	{
		if(hashP == hash)
		{
			for (int j = 0; j < lenP; ++j)
				if(str[i + j] != p[j])
					goto calcHASH;
			count++;
		}
		calcHASH :; 
		int X = hash - (str[i] - 'a' + 1);
		X = X / lenP;	
		hash = X + power[lenP - 1]*(str[i + lenP] - 'a' + 1);
	}

	printf("count = %d\n",count );
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Rabin karp took %f seconds to sort \n", time_taken);

	return 0;
}



/*
abcbababcbacbbabcacbbcaac
cba
count = 2

*/