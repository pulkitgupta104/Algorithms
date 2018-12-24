#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char X[1000],Y[1000];
	fgets(X,1000,stdin);
	fgets(Y,1000,stdin);
	int lenX = strlen(X);
	int lenY = strlen(Y);
	lenX--; lenY--;

	int L[lenX+1][lenY+1];
	for (int i  = 0; i < lenX + 1; ++i)
		L[i][0] = 0;
	for (int i  = 1; i < lenY + 1; ++i)
		L[0][i] = 0;

	for (int i = 1; i < lenX + 1; ++i)
		for (int j = 1; j < lenY + 1; ++j)
		{
			if( X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
			{	
				if (L[i - 1][j] > L[i][j - 1])
					L[i][j] = L[i - 1][j];
				else
					L[i][j] = L[i][j - 1];
			}
		}


	int lenLCS = L[lenX][lenY], r = lenX, c = lenY;
	int i = lenLCS;
	char LCS[lenLCS];
	while( r>0 && c>0 )
	{
		if(X[r-1] == Y[c-1])
		{
			LCS[i - 1] = X[r-1];
			i--; r--; c--;
		}
		else if(L[r-1][c] > L[r][c-1])
			r--;
		else
			c--;
	}	
	printf("%s\n",LCS);
	return 0;
}

/*
bshdsccsdkjcnd
scbhsskdc
shsskd
*/