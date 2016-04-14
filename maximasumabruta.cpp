#include <iostream>
#include <vector>
using namespace std;

int maxS(vector<int> A){
  int maximum = 0;
  for (int i=0; i<A.size();i++){
    int actual = 0;
    for (int j=0; j<A.size();j++){
       actual += A[j];
       if (actual > maximum)
         maximum = actual;
 	}
  }
  return maximum;
}

int main(){
	vector<int> A;
	A.push_back(21);
	A.push_back(44);
	A.push_back(2);

	cout<<maxS(A)<<endl;

}