#include <iostream>
#include "vec.h"
#include "mat.h"
#include <cmath>
using namespace std;

vec vec::operator+ (const vec& b) const{

	if (dim!=b.dim) {
		cerr<<"Fatal error with +: Dimensions" << endl;
		abort();
	}

	vec erg(dim);

	for (int i = 0; i < dim; i++) {
		erg.v[i] = v[i] + b.v[i];
	}
	return erg;
}

vec vec::operator- (const vec& b) const {

	if (dim!=b.dim) {
		cerr<<"Fatal error with -: Dimensions" << endl;
		abort();
	}

	vec erg(dim);

	for (int i = 0; i < dim; i++) {
		erg.v[i] = v[i] - b.v[i];
	}
	return erg;
}

vec vec::operator* (const vec& b) const {

	if (dim!=b.dim) {
		cerr<<"Fatal error with *: Dimensions" << endl;
		abort();
	}

	vec erg(dim);

	for (int i = 0; i < dim; i++) {

		erg.v[i] = v[i] * b.v[i];

	}
	return erg;
}

vec vec::operator* (double b) const {


	vec erg(dim);

	for (int i = 0; i < dim; i++ ) {
		erg.v[i] = v[i] * b;
	}
	return erg;
}

vec vec::operator/ (double b) const {

 	vec erg(dim);

 	for ( int i = 0; i < dim; i++) {
 		erg.v[i] = v[i] / b;
 	}
 	return erg;
}

vec vec::operator+ () const {

	vec erg(dim);

	for (int i = 0; i < dim; i++) {
		 erg.v[i] = v[i] * 1;
	}
	return erg;
}

vec vec::operator- () const {

	vec erg(dim);

	for (int i = 0; i < dim; i++) {
		 erg.v[i] = v[i] * -1;
	}
	return erg;
}
vec vec::operator% (vec const& b) const {

	if (dim != 3 && b.dim != 3) {
		cerr << "error in dimension " << endl;
		abort();
	}

	vec erg(dim);

	erg.v[0] =  (v[1] * b.v[2]) - (v[2] * b.v[1]);
	erg.v[1] =  (v[2] * b.v[0]) - (v[0] * b.v[2]);
	erg.v[2] =  (v[0] * b.v[1]) - (v[1] * b.v[0]);

	return erg;
}

vec::vec() {

	dim = 3;
	v = new double [dim];
	if (!v) {
	 cerr << "err1" << endl;
	}
}

vec::vec(int dim1) {
	dim = dim1;
	v = new double [dim];

	if (!v) {
		cerr << "err2" << endl;
	}
}

double vec::abs () {

	double b = 0;

	cout << "Absolute value of vector: ";

 	for (int i = 0; i < dim; i++) {
 		b += v[i]*v[i];
 	}
return sqrt (b);
}

vec::vec(const vec& b) {

	dim = b.dim;
	v = new double[dim];

	if (!v) {
		cerr <<"...Memory...";
		abort();
	}

	for (int i = 0; i < dim; i++) {
		v[i] = b.v[i];
	}
}

vec::~vec() {

	delete[] v;
}

void vec::input (int j) {

	for (int i = 0; i <= dim - 1; i++){

		cout << "Enter variable " << i + 1<< "." << j + 1 << ": "; cin >> v[i]; cout << endl;
	}
}

void vec::output () {

	for (int i = 0; i <= dim - 1; i++){

		cout /*<< "var " << i + 1 <<  ": "*/ << v[i] << "  ";
	}
}

/*
ostream& operator << (ostream& outf, const vec& b){

	outf


}
double& vec::operator [](int index) const{
	if (index < 0 || index >= dim ) {
		cerr << "Error index" << endl;
		abort();
	}

	return v[index];
}
*/
