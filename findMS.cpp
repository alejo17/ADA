#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <utility> 
#include <tuple>
#include <functional>
#include <limits.h>
#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_comparison.hpp"
#include "boost/tuple/tuple_io.hpp"
using namespace std;

::boost::tuple<int, int, int> findMCS(vector<int> A, int low, int mid, int high){
	int leftS = INT_MIN, maxL, maxR;
	int sum = 0;
	for(int i = mid; i >= low; i--){
		sum = sum + A[i];
		if (sum > leftS){
			leftS = sum;
			maxL = i;
		}
	}
	int rightS = INT_MIN;
	sum = 0;
	for(int j = mid + 1; j <= high; j++){
		sum = sum + A[j];
		if (sum > rightS){
			rightS = sum;
			maxR = j;
		}
	}
	//cout<<"max-left = "<<maxL<<" max-right = "<<maxR<<endl;

	return boost::make_tuple(maxL,maxR,leftS + rightS);

}


::boost::tuple<int, int, int> findMS(vector<int> A, int low, int high){
	if (high==low)
		return boost::make_tuple(low,high,A[low]);

	int mid = (low + high)/2;
	int leftL, leftH, leftS;
	int rightL, rightH, rightS;
	int crossL, crossH, crossS;

	if (mid){
		boost::make_tuple(leftL,leftH,leftS)=findMS(A,low,mid);
		boost::make_tuple(rightL,rightH,rightS)=findMS(A,mid + 1,high);
		boost::make_tuple(crossL,crossH,crossS)=findMCS(A,low,mid,high);
		if ((leftS >= rightS) && (leftS >= crossS))
			return boost::make_tuple(leftL,leftH,leftS);
		if ((rightS >= leftS) && (rightS >= crossS))
			return boost::make_tuple(rightL,rightH,rightS);
		else
			return boost::make_tuple(crossL,crossH,crossS);
		
	}
	/*return findMS(A, low, mid),
              findMS(A, mid+1, high),
              findMCS(A, low, mid, high));*/

}

::boost::tuple<int, int, double> add_multiply_divide(int a, int b) {
  return ::boost::make_tuple(a+b, a*b, double(a)/double(b));
}

int main(){
	vector<int> A;
	A.push_back(21);
	A.push_back(14);
	A.push_back(2);
	A.push_back(1);
	A.push_back(4);
	A.push_back(5);
	A.push_back(7);
	A.push_back(3);

	//cout<<add_multiply_divide(2,5);
	cout<<findMS(A,0,A.size()-1)<<endl; // ***********g++ -std=c++11 findMS.cpp 


	return 0;	
}