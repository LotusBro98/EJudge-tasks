#include <stdio.h>
#include <stdlib.h>

struct _Athl {
	int m;
	int s;
};

typedef struct _Athl Athl;

int cmp_Athl(const void* p1, const void* p2) {
	Athl* a1 = (Athl*)p1;
	Athl* a2 = (Athl*)p2;
	return a1->s - a2-> s;
}

//Pleeeeeeeeeeease

int main() {
	int n;
	int i;
	Athl all[100000];
	int mass;
	int height;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &(all[i].m), &(all[i].s));
	}

	qsort(all, n, sizeof(Athl), cmp_Athl);

	mass = all[0].m;
	height = 1;
	for (i = 0; i < n; i++) {
		if (all[i].s >= mass) {
			mass += all[i].m;
			height++;
		}
	}
	printf("%d\n", height);
	return 0;
}
