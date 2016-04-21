#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void strassen(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam);
int nextPowerOfTwo(int n);
void strassenR(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam);
void sum(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam);
void subtract(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam);
void printMatrix(vector< vector<int> > matrix, int n);

int leafsize;

void ikjalgorithm(vector< vector<int> > A, vector< vector<int> > B, vector< vector<int> > &C, int n) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void strassenR(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam) {
    if (tam <= leafsize) {
        ikjalgorithm(A, B, C, tam);
        return;
    }
 
    else {
        int newTam = tam/2;
        vector<int> inner (newTam);
        vector< vector<int> > 
            a11(newTam,inner), a12(newTam,inner), a21(newTam,inner), a22(newTam,inner),
            b11(newTam,inner), b12(newTam,inner), b21(newTam,inner), b22(newTam,inner),
              c11(newTam,inner), c12(newTam,inner), c21(newTam,inner), c22(newTam,inner),
            p1(newTam,inner), p2(newTam,inner), p3(newTam,inner), p4(newTam,inner), 
            p5(newTam,inner), p6(newTam,inner), p7(newTam,inner),
            aResult(newTam,inner), bResult(newTam,inner);
 
        int i, j;
 
        for (i = 0; i < newTam; i++) {
            for (j = 0; j < newTam; j++) {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + newTam];
                a21[i][j] = A[i + newTam][j];
                a22[i][j] = A[i + newTam][j + newTam];
 
                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + newTam];
                b21[i][j] = B[i + newTam][j];
                b22[i][j] = B[i + newTam][j + newTam];
            }
        }
 
        sum(a11, a22, aResult, newTam); 
        sum(b11, b22, bResult, newTam); 
        strassenR(aResult, bResult, p1, newTam); 
 
        sum(a21, a22, aResult, newTam); 
        strassenR(aResult, b11, p2, newTam); 
 
        subtract(b12, b22, bResult, newTam); 
        strassenR(a11, bResult, p3, newTam); 
 
        subtract(b21, b11, bResult, newTam);
        strassenR(a22, bResult, p4, newTam); 
 
        sum(a11, a12, aResult, newTam); 
        strassenR(aResult, b22, p5, newTam);   
 
        subtract(a21, a11, aResult, newTam); 
        sum(b11, b12, bResult, newTam); 
        strassenR(aResult, bResult, p6, newTam); 
 
        subtract(a12, a22, aResult, newTam); 
        sum(b21, b22, bResult, newTam); 
        strassenR(aResult, bResult, p7, newTam); 
 
 
        sum(p3, p5, c12, newTam); 
        sum(p2, p4, c21, newTam); 

        sum(p1, p4, aResult, newTam); 
        sum(aResult, p7, bResult, newTam); 
        subtract(bResult, p5, c11, newTam); 
 
        sum(p1, p3, aResult, newTam); 
        sum(aResult, p6, bResult, newTam); 
        subtract(bResult, p2, c22, newTam); 
 
        for (i = 0; i < newTam ; i++) {
            for (j = 0 ; j < newTam ; j++) {
                C[i][j] = c11[i][j];
                C[i][j + newTam] = c12[i][j];
                C[i + newTam][j] = c21[i][j];
                C[i + newTam][j + newTam] = c22[i][j];
            }
        }
    }
}

int nextPowerOfTwo(int n) {
    return pow(2, int(ceil(log2(n))));
}

void strassen(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C,  int n) {
    
    int m = nextPowerOfTwo(n);
    vector<int> inner(m);
    vector< vector<int> > APrep(m, inner), BPrep(m, inner), CPrep(m, inner);

    for( int i=0; i<n; i++) {
        for ( int j=0; j<n; j++) {
            APrep[i][j] = A[i][j];
            BPrep[i][j] = B[i][j];
        }
    }

    strassenR(APrep, BPrep, CPrep, m);
    for( int i=0; i<n; i++) {
        for ( int j=0; j<n; j++) {
            C[i][j] = CPrep[i][j];
        }
    }
}

void sum(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam) {
    int i, j;
 
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int tam) {
    int i, j;
 
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }   
}



void printMatrix(vector< vector<int> > matrix, int n) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (j != 0) {
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

int main () {
    vector<int> A;
    A.push_back(5);
    A.push_back(2);
    A.push_back(4);
    A.push_back(6);
    A.push_back(1);
    
    vector<int> B;
    A.push_back(5);
    A.push_back(2);
    A.push_back(4);
    A.push_back(6);
    A.push_back(1);
    
    vector<int> C;
    A.push_back(5);
    A.push_back(2);
    A.push_back(4);
    A.push_back(6);
    A.push_back(1);
    
    int n = 25;
    vector<int> inner (n);
    vector< vector<int> > A(n, inner), B(n, inner), C(n, inner);
    
    strassen(A, B, C, n);
    printMatrix(C, n);
    return 0;
}