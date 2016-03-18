#include <iostream>
#include <vector>
using namespace std;

int insertionSort(vector<int> A)
{
    int i=0;
    for (int j=1; j<A.size(); j++){
        int key=A[j];
        i=j-1;
        while(i>-1 && A[i]>key){
            A[i+1] = A[i];
            i=i-1;
        }
        A[i+1]=key;
    }
    for(int k=0;k<A.size();k++)
        cout<<A[k]<<endl;
}

int main(){
    vector<int> A;
    /*A.push_back(5);
    A.push_back(2);
    A.push_back(4);
    A.push_back(6);
    A.push_back(1);
    A.push_back(3);*/
    A.push_back(31);
    A.push_back(41);
    A.push_back(5981239);
    A.push_back(26);
    A.push_back(41);
    A.push_back(8);
    insertionSort(A);
}
