#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main ()
{
	long long int T;
	int n, k;
	int* arr;
	long long int* cost;
	scanf("%ld", &T);
	while(T--)
	{
		scanf("%d %d", &n, &k);
		arr = (int*)malloc(sizeof(int)*(k+1));
		cost = (long long int*)malloc(sizeof(long long int)*(k+1));
		for (int i=1; i <= k; i++)
		{
			scanf("%d", &arr[i]);
			if (arr[i] == -1)
				arr[i] = INT_MAX;
		}

		cost[0] = 0;
		cost[1] = arr[1];
		for (int wt=2; wt <= k; wt++)
		{
			cost[wt] = INT_MAX;
			for (int i=1; i <= wt; i++)
				if ((arr[i] + cost[wt-i]) < cost[wt])
					cost[wt] = (arr[i] + cost[wt-i]);
		}
		if (cost[k] == INT_MAX)
			printf("-1\n");
		else
			printf("%ld\n", cost[k]);

		free(arr);
		free(cost);
	}
	return 0;
}