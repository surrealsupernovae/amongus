#include "mat.h"
#include "vec.h"
#include <iostream>
#include <string>

using namespace std;


mat::mat () {

	l = 3;
	c = 3;

	m = new vec* [l];

	for (int i = 0; i < l; i++) {

		m[i] = new vec (c);
	};
}

mat::mat (int lin, int col) {

	l = lin ;
	c = col;

	m = new vec* [l];

	for (int i = 0; i < l; i++) {

		m[i] = new vec (c);
	};
}

mat::mat (const mat& matrix) {

	l = matrix.l;
	c = matrix.c;
	m = new vec * [l];
	vec vector (c);


	for (int i = 0; i < l; i++ ){

		for (int j = 0; j < c; j++) {

			vector.v[j] = (*matrix.m[i]).v[j];

		};

		m[i] = new vec (vector);

	};

}

mat::~mat (){

 delete [] m;

}

void mat::minput () const {

	for (int i = 0; i < l; i++) {

		(*m[i]).input(i);

	};
}

void mat::moutput () const {

	for (int i = 0; i < l; i++) {

		(*m[i]).output();
		cout << endl;

	};
}


mat mat::transpose() const {

	mat ans (c,l);

	for (int i = 0; i < l; i++ ){

		for (int j = 0; j < c; j++) {

			(*ans.m[j]).v[i] = (*m[i]).v[j];

		}
	}
	return ans;
}

mat mat::operator+ (const mat& b) const {

	mat ans (l, c);

	for (int i = 0; i < l; i++ ){

		for (int j = 0; j < c; j++) {

			(*ans.m[i]).v[j] = (*m[i]).v[j] + (*b.m[i]).v[j];

		};
	};

	return ans;

}
ostream& operator << (ostream& out, const mat& matrix){


	for (int i = 0; i < matrix.l; i++ ){

		for (int j = 0; j < matrix.c; j++) {

			out << (*matrix.m[i]).v[j] << "  " ;
		}
		out << endl;
	}
	return out;
}
istream& operator >> (istream& inp, mat& matrix){

	string matrux;

	while (inp) {
		getline(inp, matrux);
		cout << matrux << endl;
	}

	return inp;
}

