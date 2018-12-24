#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LONGG unsigned long long int

LONGG fact(LONGG x)
{
	LONGG y = 1;
	for (LONGG i = x; i > 0; --i)
		y = y * i;
    return y;
}

LONGG comb_basic(LONGG n, LONGG r)
{
	return fact(n)/(fact(n-r)*fact(r));
}

LONGG comb_rec(LONGG n, LONGG r)
{
	if(r == 0 || r == n)
		return 1;
	else
		return comb_rec(n-1,r-1) + comb_rec(n-1,r);
}

LONGG comb_fact_array(LONGG *f, LONGG n, LONGG r)
{
	LONGG y = 1;
	f[1] = 1;
	for (LONGG i = 2; i <= n; i++)
		f[i] = f[i-1] * i;
    return (f[n]/(f[n-r] * f[r]));	
}

LONGG comb_rec_mat(LONGG n, LONGG r)
{
	LONGG mat[100][100] = {0}
	mat[0][0] = mat[1][0] = 0
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0 || i == j)
				mat[i][j] = 1;
			else
				mat[i][j]
		}
	}
}

int main(int argc, char const *argv[])
{
	clock_t t;
	LONGG x=0, c, n, r, *f;
	
	scanf("%llu %llu",&n,&r);	

	t = clock();
	printf("\ncomb_basic()= %llu\n", comb_basic(n,r));
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("comb_basic() took %f seconds to sort \n\n", time_taken);

	t = clock();
	printf("comb_rec()= %llu\n", comb_rec(n,r));
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("comb_rec() took %f seconds to sort \n\n", time_taken);

	free(f);
	f = malloc(sizeof(LONGG) * (n + 1));
	t = clock();
	printf("comb_fact_array()= %llu\n", comb_fact_array(f,n,r));
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("comb_fact_array() took %f seconds to sort \n\n", time_taken);

	t = clock();
	printf("comb_rec_mat()= %llu\n", comb_rec_mat(f,n,r));
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("comb_rec_mat() took %f seconds to sort \n\n", time_taken);

	printf("\n");

	return 0;
}