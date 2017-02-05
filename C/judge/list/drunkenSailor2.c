#include <stdio.h>
#include <stdlib.h>

typedef int Data;
struct Node
{
	struct Node * next;
	struct Node * prev;
	Data data;
};

void list_init (struct Node * list);

void list_insert (struct Node * list, struct Node * t);
void list_insert_before (struct Node * list, struct Node * t);

void list_remove (struct Node * t);

struct Node * list_push_front (struct Node * list, Data d);
struct Node * list_push_back  (struct Node * list, Data d);

Data list_pop_front (struct Node * list);
Data list_pop_back  (struct Node * list);
Data list_delete    (struct Node * t);

void list_print (struct Node * list);
Data list_sum (struct Node * list);
void list_foreach (struct Node * list, void (*func)(Data d, void * param), void * param);

int list_is_empty (struct Node * list);
int list_clear (struct Node * list);




//Lists must be initialised
void dealTheCards (struct Node * first, struct Node * second);

//0 - ok
//1 - game over
int makeTurn (struct Node * first, struct Node * second);

void doAllTheStuff();

int main()
{
	doAllTheStuff();
	return 0;
}

void doAllTheStuff()
{
	struct Node * first = malloc  (sizeof (struct Node));
	struct Node * second = malloc (sizeof (struct Node));
	list_init (first);
	list_init (second);

	dealTheCards (first, second);

	int turn;
	for (turn = 1; turn <= 1000000; turn++)
	{
		if (makeTurn (first, second) == 1)
		{
			if (list_is_empty (first))
				printf ("second ");
			else
				printf ("first ");
			printf("%d\n", turn);

			list_clear (first);
			list_clear (second);
			free (first);
			free (second);
			return;
		}
	}
	printf ("botva\n");

	list_clear (first);
	list_clear (second);
	free (first);
	free (second);
	return;
}

int makeTurn (struct Node * first, struct Node * second)
{
	int firstCard, secondCard;
	struct Node * winner;
	struct Node * loser;

	firstCard  = list_pop_front (first);
	secondCard = list_pop_front (second);

	if ((firstCard > secondCard && !(firstCard == 9 && secondCard == 0)) || (firstCard == 0 && secondCard == 9))
	{
		winner = first;
		loser = second;
	}
	else
	{
		winner = second;
		loser = first;
	}

	list_push_back (winner, firstCard);
	list_push_back (winner, secondCard);

	if (list_is_empty (loser))
		return 1;
	else
		return 0;
}

void dealTheCards (struct Node * first, struct Node * second)
{
	int i;
	int level;
	struct Node * card;

	for (i = 0; i < 5; i++)
	{
		scanf ("%d", &level);
		list_push_back (first, level);
	}
	for (i = 0; i < 5; i++)
	{
		scanf ("%d", &level);
		list_push_back (second, level);
	}
}





void list_init (struct Node * list)
{
	list->prev = list;
	list->next = list;
}

void list_insert (struct Node * list, struct Node * t)
{
	t->next = list->next;
	t->prev = list;
	t->next->prev = t;
	t->prev->next = t;
}

void list_insert_before (struct Node * list, struct Node * t)
{
	t->next = list;
	t->prev = list->prev;
	t->next->prev = t;
	t->prev->next = t;
}

void list_remove (struct Node * t)
{
	t->prev->next = t->next;
	t->next->prev = t->prev;
}

struct Node * list_push_front (struct Node * list, Data d)
{
	struct Node * t = malloc (sizeof (struct Node));
	if (t)
	{
		t->data = d;
		list_insert (list, t);
		return list;
	}
	else return NULL;
}

struct Node * list_push_back (struct Node * list, Data d)
{
	struct Node * t = malloc (sizeof (struct Node));
	if (t)
	{
		t->data = d;
		list_insert_before (list, t);
		return list;
	}
	else return NULL;
}

Data list_delete (struct Node * t)
{
	Data data = t->data;
	list_remove (t);
	free (t);
	return data;
}

Data list_pop_front (struct Node * list)
{
	return list_delete (list->next);
}


Data list_pop_back (struct Node * list)
{
	return list_delete (list->prev);
}

void list_foreach (struct Node * list, void (*func)(Data d, void * param), void * param)
{
	struct Node * t = list->next;
	while (t != list)
	{
		(*func)(t->data, param);
		t = t->next;
	}
}

void print_elem (Data d, void * param)
{
	printf("%d ", d);
}
void list_print (struct Node * list)
{
	list_foreach (list, print_elem, NULL);
	printf("\n");
}

void add_elem (Data d, void * param)
{
	int * sum = param;
	*sum += d;
}
Data list_sum (struct Node * list)
{
	int sum = 0;
	list_foreach (list, add_elem, &sum);
	return sum;
}

int list_is_empty (struct Node * list)
{
	return list->next == list;
}

int list_clear (struct Node * list)
{
	if (list)
	{
		while (!list_is_empty(list))
		{
			list_pop_front(list);
		}
		return 0;
	}
	else return 1;
}
