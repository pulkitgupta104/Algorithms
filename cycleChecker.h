int checkCycle(int x, int y, int V)
{
	static int *sets[100], count[100] = {0};
	int s1, s2, flag1=0, flag2=0;

	if (x == -1)					//TO INITIALIZE AND CREATE SETS
	{
		for (int i = 0; i < V; ++i)
		{
			sets[i] = malloc(sizeof(int));
			sets[i][0] = i;
			count[i]++;
		}
		return 0;
	}

	for (int i = 0; i < V; ++i)
		for (int j = 0; j < count[i] && count[i] != -1 ; ++j)
			if (sets[i][j] == x)
			{
				flag1 = 1;
				s1 = i;	
				if (flag2 == 1)
					goto XX;
			}
			else if (sets[i][j] == y)
			{
				flag2 = 1;
				s2 = i;
				if (flag1 == 1)
					goto XX;
			}

	XX: 
		if (s1 == s2)
			return 1;				//CYCLE IS FORMING
		else 
		{
			sets[s1] = realloc(sets[s1], count[s1] + count[s2]);
				
			for (int i = 0; i < count[s2]; ++i)
				sets[s1][count[s1]++] = sets[s2][i];

			free(sets[s2]); 
			count[s2] = -1;
			return 0;
		}
	
}