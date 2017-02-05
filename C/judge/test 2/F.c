#include <stdio.h>
#include <stdlib.h>

struct Buy
{
	int timestamp;
	int id;
	int receipt_id;
};

struct Buy buyLog[1000];

void readBuy( struct Buy * buy)
{
	scanf( "%d %d %d", &(buy->timestamp), &(buy->id), &(buy->receipt_id) );
}

void printBuy( struct Buy * buy)
{
	printf( "%d %d %d\n", buy->timestamp, buy->id, buy->receipt_id );
}

int cmpBuy( const void * b1, const void * b2 )
{
	struct Buy * buy1 = (struct Buy *) b1;
	struct Buy * buy2 = (struct Buy *) b2;

	if (buy1->receipt_id == buy2->receipt_id)
	{
		if (buy1->timestamp == buy2->timestamp)
		{
			return buy1->id - buy2->id;
		}
		else 
			return buy1->timestamp - buy2->timestamp;
	} 
	else 
		return buy1->receipt_id - buy2->receipt_id;
}

int main()
{
	int n;
	int i;
	int j;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		readBuy( &buyLog[i] );
	}

	qsort( buyLog, n, sizeof(struct Buy), cmpBuy );

	for (i = 0; i < n - 1; i++)
	{
		if ( buyLog[i].receipt_id == buyLog[i+1].receipt_id ) 
		{
			for ( j = i; 
				(j < n) && (buyLog[j].receipt_id == buyLog[i].receipt_id); 
				j++ ) 
			{
				printBuy( &buyLog[j] );
			}
			i = j;
		}
	}

	return 0;
}
