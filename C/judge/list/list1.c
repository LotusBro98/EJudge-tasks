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
Data list_remove_last  (struct List * list);

Data list_get_first (struct List * list);
Data list_get_last  (struct List * list);

void list_print (struct List * list);

int list_size (struct List * list);

void list_clear (struct List * list);

void list_destroy (struct List * list);


//            *** ***      **      ******   **   **
//           ** *** **   **  **      **     ***  **
//           **  *  **   ******      **     ** * **
//           **     **   **  **      **     **  ***
//           **     **   **  **    ******   **   **


int main()
{
	struct List * list = list_create();
	list_add_first(list, 5);
	list_add_first(list, 6);
	list_add_first(list, 7);
	list_add_last (list, 1);
	list_add_last (list, 2);
	list_add_last (list, 3);
	list_print(list);
	list_destroy(list);

	return 0;
}


//           ******    *** ***    *****    **       ******   *** ***    ******   **   **   ******     **     ******   ******     ***     **   **
//             **     ** *** **   **  **   **       **      ** *** **   **       ***  **     **     **  **     **       **     **   **   ***  **
//             **     **  *  **   *****    **       *****   **  *  **   ******   ** * **     **     ******     **       **     **   **   ** * **
//             **     **     **   **       **       **      **     **   **       **  ***     **     **  **     **       **     **   **   **  ***
//           ******   **     **   **       ******   *****   **     **   ******   **   **     **     **  **     **       **       ***     **   **



struct List * list_create ()
{
	struct List * list = malloc (sizeof (struct List));
	list->head = NULL;
	return list;
}

void list_add_first (struct List * list, Data x)
{
	struct Node * newHead = malloc (sizeof (struct Node));
	newHead->val = x;
	newHead->next = list->head;
    list->head = newHead;
}

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
}


Data list_remove_first (struct List * list)
{
	if (list->head)
	{
		struct Node * almostDead = list->head;
		list->head = list->head->next;
		Data val = almostDead->val;
		free (almostDead);
		return val;
	} 
	else exit(1);
}

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


