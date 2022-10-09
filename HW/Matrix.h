/*This program was created as a header file for matrices in order to perform operations
 *through the use of an abstract data type c++ interface
 * @author Gregory Wagonblast
 * @version 1.0
 * @since 21May2020
 */ 

//Make include guard and define MATRIX_H
#ifndef MATRIX_H
#define MATRIX_H

//Include the c standard library
#include <cstdlib>

//Make a class for matrix operations
class Matrix{

//Create private member variables for two input matrices, an output matrix
//and rows and columns 
//@param These input and output matrices are set to be 3x3 matrices
private:

int matrixIn1[3][3];
int matrixIn2[3][3];
int matrixOut[3][3];
int c1,r1,c2,r2,c3,r3;

//Create public member functions that are declared virtual
public:

/*
 * @param These matrix member functions do not take any parameters
 * @return These matrix member functions return void
 * All member functions are meant to perform matrix operations only
 */
virtual void readMatrix();

virtual void addMatrices();

virtual void multiplyMatrices();

virtual void scalar();

virtual void transpose();

virtual void printMatrix();

}

//End the include guard
#endif
