#include <iostream>
#include <climits>
using namespace std;

int cut_rod_rec(int p[], int n)
{
	if (n == 0)	
		return 0;

	int q = INT_MIN;

	for(int i=0; i<n; i++)
	{
		q = max(q, p[i] + cut_rod_rec(p, n-i-1));	
	}

	return q;
}

int cut_rod_mem_aux(int p[], int n, int r[])
{
	int q;
	if (r[n] >= 0)
	{
		return r[n];
	}

	if (n == 0)
	{
		q = 0;
	}
	else 
	{
		q = INT_MIN;
		for(int i=0; i<n; i++)
		{
			q = max(q, p[i] + cut_rod_mem_aux(p,n-i-1,r));
		}
	}

	r[n] = q;
	return q;
}

int cut_rod_mem(int p[], int n)
{
	int* r = new int[n + 1];

	for(int i=0; i<=n; i++)
	{
		r[i] = INT_MIN;
	}

	return cut_rod_mem_aux(p,n,r);
}

int cut_rod_BU(int p[], int n)
{
	int* r = new int[n+1];
	r[0] = 0;

	for(int i = 0; i <= n; i++)
    {
        r[i] = p[i-1];
    }

	for(int j=0; j<n; j++)
	{
		int q = INT_MIN;
		for(int i=0; i<j; i++)
			q = max(q, (p[i] + r[j - i]));
		r[j] = q;
	}

	return r[n];
}

void print(int p[], int n)
{
    while(n > 0)
    {
        cout<<p[n]<<"  ";
        n = n - p[n];
    }
}

void cut_rod_EBU(int p[], int n)
{
	int* r = new int[n+1];
	int* s = new int[n+1];
	r[0] = 0;

/*	for(int i = 0; i <= n; i++)
    {
        r[i] = p[i-1];
    }*/

	for(int j=0; j<=n; j++)
	{
		int q = INT_MIN;
		for(int i=0; i<=j; i++)
			if (q < (p[i] + r[j - i]))
			{
				q = (p[i] + r[j - i]);
				s[j] = i;
			}
		r[j] = q;
	}

	cout<<"R"<<endl;
	for(int i=0; i<=n; i++)
		cout<<r[i]<<"  ";
	//print(s,n);
	cout<<endl<<"S"<<endl;

	for(int i=0; i<=n; i++)
		cout<<s[i]<<"  ";
//	print(s,n);	
	cout<<endl;
}

int main()
{
	int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	
	//cout<<cut_rod_EBU(p,4);
	cut_rod_EBU(p,4);
}