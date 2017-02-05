#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//Типы токенов:
#define NUMBER 'n'
#define OPERATION 'o'
#define BRACKET 'b'
#define ERROR 'e'


//Токен
struct _Data
{
	char type;
	int num;
};

typedef struct _Data Data;

struct Stack
{
	int n;
	int size;
	Data * a;
};

struct Stack * stack_create(int size)
{
	struct Stack * s;

	if (size >= 0)
	{
		s = malloc(sizeof(struct Stack));
	
		if (s != NULL)
		{
			s->a = malloc(size * sizeof(Data));
			s->size = size;
			s->n = 0;
		}
		return s;
	} else exit(1);
}

void stack_push(struct Stack * s, Data x)
{
	int newSize;
	Data * newPlace;

	if (s->n >= s->size)
	{
		if (s->size == 0)
		{
			newSize = 1;
		} else {
			newSize = s->size * 2;
		}
		newPlace = realloc(s->a, sizeof(Data) * newSize);
		if (newPlace == NULL)
		{
			newSize = s->size + 1;
			newPlace = realloc(s->a, sizeof(Data) * newSize);
			if (newPlace == NULL) exit(1);
		}
		s->size = newSize;
		s->a = newPlace;
	}

	s->a[s->n] = x;
	s->n++;
}

Data stack_pop(struct Stack * s)
{
	s->n--;
	return s->a[s->n];
}

Data stack_get(struct Stack * s)
{
	return *(s->a + s->n - 1);
}

int stack_is_empty(struct Stack * s)
{
	return s->n == 0;
}

void printElem(Data x)
{

}

void stack_print(struct Stack * s)
{
	int i;

	if (stack_is_empty(s))
	{
		printf("Empty stack\n");
	} else {
		for (i = 0; i < s->n; i++)
		{
			Data x = s->a[i];
			if (x.type == NUMBER)
			{
				printf("%d ", x.num);
			} else {
				printf("%c ", x.num);
			}
		}
		printf("\n");
	}
}

int stack_size(struct Stack * s)
{
	return s->n;
}

void stack_clear(struct Stack * s)
{
	s->n = 0;
}

void stack_destroy(struct Stack * s)
{
	free(s->a);
	free(s);
}




//Вычисляет значение выражения в постфиксной форме
//Выражение записано в виде стека, элементами которого являются токены
//токен может быть числом, операцией или скобкой
//В этом стеке элементы идут по порядку, то есть, функция pop выдаст элемент, записанный последним
int calc_postfix(struct Stack * expr)
{
	//Стек, в котором храним промежуточные результаты
	struct Stack * res;

	int result;
	int arg1;
	int arg2;
	int i;
	Data x;

	res = stack_create(16);

	for (i = 0; i < expr->n; i++)
	{
		//Так как элементы во входном стеке идут по порядку,
		//то получать их будем именно таким способом 
		x = expr->a[i];

		if (x.type == NUMBER) 
		{
			stack_push(res, x);
		} else if (x.type == OPERATION) {
			if (x.num == '~') //Унарный минус
			{
				arg1 = stack_pop(res).num;
				result = -arg1;
			} else {
				arg2 = stack_pop(res).num;
				arg1 = stack_pop(res).num;
				switch (x.num)
				{
					case '+':
						result = arg1 + arg2;
						break;
					case '-':
						result = arg1 - arg2;
						break;
					case '*':
						result = arg1 * arg2;
						break;
					default:
						result = 0;
						break;
				}
			}
			x.type = NUMBER;
			x.num = result;
			stack_push(res, x);
		}
	}
	result = stack_pop(res).num;
	stack_destroy(expr);
	stack_destroy(res);
	return result;
}

Data readToken()
{
	Data token;
	char c;

	if (scanf("%c", &c) != 1)
	{
		token.type = ERROR;
		token.num = '#';
	} else if (c == '+' || c == '-' || c == '*')
	{
		token.type = OPERATION;
		token.num = c;
	} else if (c == '(' || c == ')' || c == ' ') 
	{
		token.type = BRACKET;
		token.num = c;
	} else if (isdigit(c)) 
	{
		token.type = NUMBER;
		ungetc(c, stdin);
		scanf("%d", &(token.num));
	} else
	{
		token.type = ERROR;
		token.num = c;
	}
	return token;
}

//Считывание выражения в инфиксной форме
//И запись его в виде стека из токенов
struct Stack * readStack()
{
	struct Stack * s = stack_create(16);
	Data token;

	while ((token = readToken()).type != ERROR)
	{
		if (!(token.type == BRACKET && token.num == ' '))
		{
			stack_push(s, token);
		}
	}
	return s;
}

//Добавим еще одну функцию, которая позволит получить какой-то элемент из середины стека
//и перейти к следующющему
//0-й элемент был добавлен в стек первым
Data stack_take(struct Stack * s, int * pos)
{
	Data x = s->a[*pos];
	*(pos) += 1;
	return x;
}

//Преобразует в постфиксную форму выражение в скобках (открывающая скобка уже считана)
//Выражение подается в виде стека infix и номера текущего элемента
//Результат записывается в стек postfix
void parseExprInBrackets(struct Stack * infix, int * pos, struct Stack * postfix)
{
	Data x;
	Data op;

	//Отдельно ситываем первый операнд в выражении в скобках
	x = stack_take(infix, pos);
	if (x.type == OPERATION && x.num == '-')
	{
		x = stack_take(infix, pos);

		if (x.type == BRACKET)
		{
			parseExprInBrackets(infix, pos, postfix);
			x.type = OPERATION;
			x.num = '~';
			stack_push(postfix, x);
		} else {
			stack_push(postfix, x);
			x.type = OPERATION;
			x.num = '~';
			stack_push(postfix, x);
		}
	} else if (x.type == BRACKET) // (
	{
		parseExprInBrackets(infix, pos, postfix);
	} else {
		stack_push(postfix, x);
	}

	//далее идет последовательность <операция> <операнд>  <операция> <операнд> ... <операция> <операнд> )
	while (*pos < infix->n)
	{
		if (infix->a[*pos].type == BRACKET) // )
		{
			*(pos) += 1;
			break;
		} else {
			op = stack_take(infix, pos);
			x = stack_take(infix, pos);
	
			if (x.type == BRACKET) // (
			{
				parseExprInBrackets(infix, pos, postfix);
				stack_push(postfix, op);
			} else {
				stack_push(postfix, x);
				stack_push(postfix, op);
			}
		}
	}
}

struct Stack * fromInfixToPostfix(struct Stack * infix)
{
	struct Stack * postfix = stack_create(16);
	int pos = 0;

	parseExprInBrackets(infix, &pos, postfix);
	stack_destroy(infix);

	return postfix;
}

int main()
{
	struct Stack * infix;
	struct Stack * postfix;

	infix = readStack();
	//stack_print(infix);

	postfix = fromInfixToPostfix(infix);
	//stack_print(postfix);

	printf("%d\n", calc_postfix(postfix));
	return 0;
}
