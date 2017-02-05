#include <stdio.h>
#include <stdlib.h>

//            ******    *    *    ****     *****      ****
//              **       *  *     ** **    **        **
//              **        **      ****     *****      ****
//              **        **      **       **            **
//              **        **      **       *****      ****

typedef int Data;

struct Node
{
	Data val;
	struct Node * next;
};

struct List
{
	struct Node * head;
	struct Node * tail;
};


//           ******   **   **   ******   ******   ****     ******     **        ***   ******
//             **     ***  **     **     **       ** **    **       **  **    **      **
//             **     ** * **     **     ******   ****     ******   *******   **      ******
//             **     **  ***     **     **       ** **    **       **   **   **      **
//           ******   **   **     **     ******   **  **   **       **   **     ***   ******


struct List * list_create ();

void list_add_first (struct List * list, Data x);
void list_add_last  (struct List * list, Data x);

Data list_remove_first (struct List * list);
//Data list_remove_last  (struct List * list);

//Data list_get_first (struct List * list);
//Data list_get_last  (struct List * list);

void list_print (struct List * list);

int list_size (struct List * list);

void list_clear (struct List * list);

void list_destroy (struct List * list);

//Input lists must be initialised
void dealTheCards (struct List * first, struct List * second);

//0 - ok
//1 - game over
int makeTurn (struct List * first, struct List * second);

void doAllTheStuff();

//            *** ***      **      ******   **   **
//           ** *** **   **  **      **     ***  **
//           **  *  **   ******      **     ** * **
//           **     **   **  **      **     **  ***
//           **     **   **  **    ******   **   **


int main()
{
	doAllTheStuff();
	return 0;
}


//           ******    *** ***    *****    **       ******   *** ***    ******   **   **   ******     **     ******   ******     ***     **   **
//             **     ** *** **   **  **   **       **      ** *** **   **       ***  **     **     **  **     **       **     **   **   ***  **
//             **     **  *  **   *****    **       *****   **  *  **   ******   ** * **     **     ******     **       **     **   **   ** * **
//             **     **     **   **       **       **      **     **   **       **  ***     **     **  **     **       **     **   **   **  ***
//           ******   **     **   **       ******   *****   **     **   ******   **   **     **     **  **     **       **       ***     **   **


void doAllTheStuff ()
{
	struct List * first = list_create();
	struct List * second = list_create();
	int turn = 0;

	dealTheCards (first, second);

	while (turn < 1000000)
	{
		turn++;
		if (makeTurn (first, second) == 1)
		{
			if (list_size (first) == 0)
				printf("second ");
			else
				printf("first ");
			printf("%d\n", turn);
			list_destroy(first);
			list_destroy(second);
			return;
		}
		//list_print (first);
		//list_print (second);
		//printf("\n");
	}
	printf ("botva\n");
	list_destroy(first);
	list_destroy(second);
	return;
}

int makeTurn (struct List * first, struct List * second)
{
	int firstCard, secondCard;
	struct List * winner;
	struct List * loser;

	firstCard  = list_remove_first (first);
	secondCard = list_remove_first (second);

	if (firstCard > secondCard && (firstCard != 9 && secondCard != 0) || (firstCard == 0 && secondCard == 9))
	{
		winner = first;
		loser = second;
	}
	else
	{
		winner = second;
		loser = first;
	}
	
	list_add_last (winner, firstCard);
	list_add_last (winner, secondCard);

	if (list_size (loser) == 0)
		return 1;
	else
		return 0;
}

void dealTheCards (struct List * first, struct List * second)
{
	int i;
	int level;

	for (i = 0; i < 5; i++) 
	{
		scanf("%d", &level);
		list_add_last (first, level);
	} 
	for (i = 0; i < 5; i++) 
	{
		scanf("%d", &level);
		list_add_last (second, level);
	}
}

struct List * list_create ()
{
	struct List * list = malloc (sizeof (struct List));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void list_add_first (struct List * list, Data x)
{
	struct Node * newHead = malloc (sizeof (struct Node));
	newHead->val = x;
	newHead->next = list->head;
    list->head = newHead;
	if (list->tail == NULL) list->tail = list->head;
}

void list_add_last (struct List * list, Data x)
{
	struct Node * newTail = malloc (sizeof (struct Node));
	newTail->val = x;
	newTail->next = NULL;
	if (list->tail != NULL) list->tail->next = newTail;
	list->tail = newTail;
	if (list->head == NULL) list->head = list->tail;
}

/*
void list_add_last  (struct List * list, Data x)
{
	if (list->head)
	{
		struct Node * current = list->head;
		while (current->next) current = current->next;
		current->next = malloc (sizeof (struct Node));
		current->next->val = x;
		current->next->next = NULL;
	}
	else
	{
		list_add_first (list, x);
	}
}*/


Data list_remove_first (struct List * list)
{
	if (list->head)
	{
		struct Node * almostDead = list->head;
		list->head = list->head->next;
		Data val = almostDead->val;
		if (almostDead->next == NULL) list->tail == NULL; 

		free (almostDead);
		return val;
	} 
	else exit(1);
}

/*
Data list_remove_last  (struct List * list)
{
	if (list->head)
	{
		if (list->head->next)
		{
			struct Node * current = list->head;
			while (current->next->next) current = current->next;
			struct Node * almostDead = current->next;
			current->next = NULL;
			Data val = almostDead->val;
			free (almostDead);
			return val;
		}
		else return list_remove_first (list);
	}
	else exit(1);
}
*/

/*
Data list_get_first (struct List * list)
{
	if (list->head)
		return list->head->val;
		else exit(1);
}

Data list_get_last  (struct List * list)
{
	if (list->head)
	{
		struct Node * current = list->head;
		while (current->next) current = current->next;
		return current->val;
	}
	else exit(1);
}
*/

void list_print (struct List * list)
{
	if (list->head)
	{
		struct Node * current = list->head;
		while (current)
		{
			printf("%d ", current->val);
			current = current->next;
		}
		printf("\n");
	}
	else printf("Empty list\n");
}

int list_size (struct List * list)
{
	int n = 0;
	struct Node * current = list->head;
	while (current)
	{
		current = current->next;
		n++;
	}
	return n;
}

void list_clear (struct List * list)
{
	struct Node * almostDead;
	struct Node * current = list->head;
	while (current)
	{
		almostDead = current;
		current = current->next;
		free (almostDead);
	}
	list->head = NULL;

}

void list_destroy (struct List * list)
{
	list_clear (list);
	free(list);
}


