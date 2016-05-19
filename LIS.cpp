#include <iostream>
#include <vector>
using namespace std;

void LIS(vector<int> &a, vector<int> &b)
{
  vector<int> p(a.size());
  int u, v;

  if (a.empty()) return;

  b.push_back(0);

  for (int i = 1; i < a.size(); i++) {
      if (a[b.back()] < a[i]) {
          p[i] = b.back();
          b.push_back(i);
          continue;
      }

      for (u = 0, v = b.size()-1; u < v;) {
          int c = (u + v) / 2;
          if (a[b[c]] < a[i]) u=c+1; else v=c;
      }

      if (a[i] < a[b[u]]) {
          if (u > 0) p[i] = b[u-1];
          b[u] = i;
      }   
  }

  for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
}

int main()
{
  vector<int> a;
  a.push_back(0);
  a.push_back(8);
  a.push_back(4);
  a.push_back(12);
  a.push_back(2);
  a.push_back(10);
  a.push_back(6);
  a.push_back(14);
  a.push_back(1);
  a.push_back(9);
  a.push_back(5);
  a.push_back(13);
  a.push_back(3);
  a.push_back(11);
  a.push_back(7);
  a.push_back(15);
  vector<int> b;
  
  LIS(a, b);

  for (int i = 0; i < b.size(); i++)
    cout<<b[i]<<endl;

  return 0;
}