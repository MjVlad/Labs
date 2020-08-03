#pragma once
#include <iostream>

struct point {
	int x = 0;
	int y = 0;
	int z = 0;
	point() {
		x = 0;
		y = 0;
		z = 0;
	}
	point(int a) {
		x = a;
		y = a;
		z = a;
	}
	point(int x1, int y1, int z1) {
		x = x1;
		y = y1;
		z = z1;
	}
	point& operator=(const point& p) {
		x = p.x;
		y = p.y;
		z = p.z;
		return *this;
	}
	bool operator!=(point& pr) {
		if ((x == pr.x && y == pr.y) && (z == pr.z)) return false;
		return true;
	}
};

std::ostream& operator<<(std::ostream& out, point& p) {
	out << "(" << p.x << ";" << p.y << ";" << p.z << ")";
	return out;
}

//bool operator!=(point& pl, point& pr) {
//	if ((pl.x == pr.x && pl.y == pr.y) && (pl.z == pr.z)) return false;
//	return true;
//}