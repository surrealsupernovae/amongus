#ifndef MAT_MAT_H
#define MAT_MAT_H
#include "vec.h"
#include <iostream>
using namespace std;

class mat {

public:

    int l, c;
    vec ** m;
    mat();
    mat(int l, int c);
    mat(const mat& m);
    ~mat();

    void moutput() const;
    void minput() const;

    // Special functions: ...
    mat transpose() const;

    // calculation operators: ...
    mat operator + (const mat& b) const;

    // index operators:
    vec operator [](int l) const;
    vec& operator[] (int l);

    // I/O operators:
    friend ostream& operator << (ostream& out, const mat& matrix);
    friend istream& operator >> (istream& inp, mat& matrix);
};
#endif //MAT_MAT_H
