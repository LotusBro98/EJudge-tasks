#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool visokos(int year){
	return ((year%4 == 0)&&(year%100 != 0)) || (year%400 == 0);
}

void printWeekDay(int wd){
	switch (wd) {
		case 0: printf(" Mo"); break;
		case 1: printf(" Tu"); break;
		case 2: printf(" We"); break;
		case 3: printf(" Th"); break;
		case 4: printf(" Fr"); break;
		case 5: printf(" Sa"); break;
		case 6: printf(" Su"); break;
	}
}

///Возвращает день недели 1 января указанного года
int weekDay1Jan(int year){
	//день недели 1 января
	//0 - понедельник
	//1 января 1 года - понедельник
	int wd = 0;
	
	int i;
	for(i=1; i<year; i++){
		//Прошел i-тый год:
		if(visokos(i)){
			wd += 2;
			//2 = 366 % 7
		} else {
			wd += 1;
			//1 = 365 % 7
		}
		wd = wd % 7;
	}
	return wd;
}

int daysInMonth(int month, int year){
	switch (month) {
		case 2:  //Февраль
			if (visokos(year))
				{return 29;} else 
				{return 28;}
		case 4:  //Апрель
		case 6:  //Июнь
		case 9:  //Сентябрь
		case 11: //Ноябрь
			return 30;
		case 1:  //Январь
		case 3:  //Март
		case 5:  //Май
		case 7:  //Июль
		case 8:  //Август
		case 10: //Октябрь
		case 12: //Декабрь
			return 31;
	}
}

void printMonthName(int month){
	switch (month) {
		case 1:  printf("-------January-------"); break;
		case 2:  printf("-------February------"); break;
		case 3:  printf("--------March--------"); break;
		case 4:  printf("--------April--------"); break;
		case 5:  printf("---------May---------"); break;
		case 6:  printf("---------June--------"); break;
		case 7:  printf("---------July--------"); break;
		case 8:  printf("--------August-------"); break;
		case 9:  printf("------September------"); break;  //Paaiiaaa memi in September
		case 10: printf("-------October-------"); break;
		case 11: printf("-------November------"); break;
		case 12: printf("-------December------"); break;
	}
}


int weekDay1ThisMonth(int month, int year){
	int wd = weekDay1Jan(year);
	int m;
	for (m = 1; m < month; m++){
		wd = (wd + daysInMonth(m,year)) % 7;
	}
	return wd;
}

void printMonth(int month, int year){
	int i;
	int first = weekDay1ThisMonth(month,year);
	int days = daysInMonth(month,year);

	//Печать шапки
	printMonthName(month);
	printf("\n");
	for (i = 0; i < 7; i++) {
		printWeekDay(i);
	}
	printf("\n");

	//Печать пробелов перед днями
	for (i = 1; i <= first; i++) {
		printf("   ");
	}

	//Печать дней
	for (i = 1; i <= days; i++) {
		if (i > 0) {
			printf("%3d",i);
		}

		if (((i+first) % 7) == 0) printf("\n");
	}
	printf("\n\n");
}

void printYear(int year){
	int m;
	for (m = 1; m <= 12; m++) {
		printMonth(m,year);
	}
}

int main(){
	int year;
	scanf("%d", &year);
	printYear(year);
	return 0;
}
