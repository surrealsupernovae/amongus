#include<iostream>
#include<fstream>
#include <cmath>
#include"mat.h"
#include "vec.h"
using namespace std;

int main (){

int lines = 3;
int columns = 3;


mat a;
cout << "Please input the variables for matrix 1 (3x3)" << endl;
a.minput();
cout << "Output of matrix 1 (3x3) : " << endl ;
a.moutput();


cout << "Please input the number of rows : "; cin >> lines; cout << endl;
cout << "Please input the number of columns : "; cin >> columns; cout << endl;

mat b (lines, columns);
b.minput();
ofstream intofile ("mat_b");
intofile << b;


cout << "Output of matrix 2 (rows x columns) : " << endl ;
ifstream outofile ("mat_b");
outofile >> b;
//b.moutput();

mat cope(a);

cout << endl << "Output of cope: (copy of a)" << endl ;
cope.moutput();

cout << endl << "Output of a + b " << endl;
(a + b).moutput();

cout << endl << "output of b transposed" << endl;
b.transpose().moutput();

return 0;
}


