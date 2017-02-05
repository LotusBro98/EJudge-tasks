#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

class Coord
{
	public:
		int x;
		int y;
};

class Triangle
{
	public:
		Coord p1, p2, p3;
};

Coord getPoint()
{
	Coord vec;
	cin >> vec.x >> vec.y;
	return vec;
}

void getTri(Triangle& tri)
{
	tri.p1 = getPoint();
	tri.p2 = getPoint();
	tri.p3 = getPoint();
}

Coord sub(Coord a, Coord b)
{
	Coord c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

int cmpLen(Coord a, Coord b)
{
	return (a.x*a.x + a.y*a.y) - (b.x*b.x + b.y*b.y);
}

int cmpLen(const void * pa, const void * pb)
{
	Coord a = *((Coord *)pa);
	Coord b = *((Coord *)pb);
	return cmpLen(a, b);
}

int cmp(Triangle a, Triangle b)
{
	Coord sa[3];
	Coord sb[3];
	Coord min, avg, max;

	sa[0] = sub(a.p1, a.p2);
	sa[1] = sub(a.p2, a.p3);
	sa[2] = sub(a.p3, a.p1);

	sb[0] = sub(b.p1, b.p2);
	sb[1] = sub(b.p2, b.p3);
	sb[2] = sub(b.p3, b.p1);

	qsort(sa, 3, sizeof(Coord), cmpLen);
	qsort(sb, 3, sizeof(Coord), cmpLen);

	return
		cmpLen(sa[0], sb[0]) == 0 &&
		cmpLen(sa[1], sb[1]) == 0 &&
		cmpLen(sa[2], sb[2]) == 0;  
}

int main()
{
	Triangle a, b;

	getTri(a);
	getTri(b);

	cout << cmp(a, b) << endl;

	return 0;
}
