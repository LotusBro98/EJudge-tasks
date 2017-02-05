#include <stdio.h>

struct _Vec3 {
	int x;
	int y;
	int z;
};
typedef struct _Vec3 Vec3;

Vec3 readVec() {
	Vec3 vec;
	scanf("%d%d%d", &(vec.x), &(vec.y), &(vec.z));
	return vec;
}

void printVec(Vec3 vec) {
	printf("%d %d %d\n", vec.x, vec.y, vec.z);
}

Vec3 sum(Vec3 a, Vec3 b) {
	Vec3 vec;
	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	vec.z = a.z + b.z;
	return vec;
}

Vec3 sub(Vec3 a, Vec3 b) {
	Vec3 vec;
	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	vec.z = a.z - b.z;
	return vec;
}

int main() {
	Vec3 r0;	Vec3 r1;	Vec3 r2;
				Vec3 r10;	Vec3 r20;

	Vec3 v0;	Vec3 v1;	Vec3 v2;
				Vec3 v10;	Vec3 v20;

	r0 = readVec();	v0 = readVec();
	r1 = readVec();	v1 = readVec();
	r2 = readVec();	v2 = readVec();

	r10 = sub(r1,r0);
	r20 = sub(r2,r0);

	v10 = sub(v1,v0);
	v20 = sub(v2,v0);

	return 0;
}
