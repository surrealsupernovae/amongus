#ifndef VEC_VEC_H
#define VEC_VEC_H
#include <iostream>

class vec {

public:
        int dim;
        int j;
	double* v;

	vec();
	vec(int dim);
	vec(const vec& b);
	~vec();

	void input(int j);
	void output();
	double abs();
	vec operator+ (const vec& b) const;
	vec operator- (const vec& b) const;
	vec operator* (const vec& b) const;
	vec operator* (double b) const;
	vec operator/ (double b) const;
	vec operator+ () const;
	vec operator- () const;
	vec operator% (const vec& b) const;
	double& operator[] (int index) const;
 };
#endif
	
