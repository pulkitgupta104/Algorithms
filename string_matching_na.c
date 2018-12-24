#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char str[1000000], p[1000000];

	fgets(str,1000000,stdin);
	fgets(p,1000000,stdin);
	
	clock_t t;
	t = clock();

	int count = 0, lenS = strlen(str), lenP = strlen(p);

	for (int i = 0; i <= lenS - lenP + 1; ++i)
		for (int j = 0; j < lenP; ++j)
		{
			if (str[i+j] != p[j])
				break;
			else if(j == lenP - 2)
				count++;
		}
	printf("count = %d\n",count );
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Naive approach took %f seconds to sort \n", time_taken);

	return 0;
}

/*
abcbababcbacbbabcacbbcaac
cba
count = 2

*/