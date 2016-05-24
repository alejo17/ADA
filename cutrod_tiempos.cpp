#include <iostream>
#include <climits>
#include <time.h>
#include <stdlib.h>
using namespace std;

long long cut_rod_rec(long long p[], long long n)
{
	if (n == 0)	
		return 0;

	long long q = INT_MIN;

	for(long long i=0; i<=n; i++)
	{
		q = max(q, p[i] + cut_rod_rec(p, n-i-1));	
	}

	return q;
}

long long cut_rod_mem_aux(long long p[], long long n, long long r[])
{
	long long q;
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
		for(long long i=0; i<n; i++)
		{
			q = max(q, p[i] + cut_rod_mem_aux(p,n-i-1,r));
		}
	}

	r[n] = q;
	return q;
}

long long cut_rod_mem(long long p[], long long n)
{
	long long* r = new long long[n];

	for(long long i=0; i<=n; i++)
	{
		r[i] = INT_MIN;
	}

	return cut_rod_mem_aux(p,n,r);
}

void print(long long s[], long long n)
{
    while(n > 0)
    {
        cout<<s[n]<<endl;
        n = n - s[n];
    }
}

long long cut_rod_BU(long long rod[], long long n)
{
    long long r[n+1];
    long long s[n+1];
    r[0] = 0;
    for(long long i = 1; i <= n; ++i)
    {
        r[i] = rod[i-1];
    }
    for(long long i = 1; i <= n; ++i)
    {
        long long q = -1;
        for(long long j = 1; j <= i; ++j)
        {
            if(q < r[j] + r[i-j])
            {
                q = r[j] + r[i-j];
                s[i] = j;
            }
        }
        r[i] = q;
    }
    //print(s,n);
    return r[n];
}

void fill(long long max, long long p[]){
    srand (time(NULL));
    for (long long i=0; i <= max;i++){
        p[i] = rand()%100; 
    }
}

int main()
{
	//long long p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	long long tam = 1000000;
    long long p[tam];
    fill(tam,p);    
    
/*    for (long long i=0; i < tam ;i++){
        cout<<p[i] <<endl;
    }    */

    cout<<"   recursivo \n";
    int init = clock();
    cout<<cut_rod_rec(p,30);
    int end = clock();
	cout<<"\ntiempo: "<<(end-init)/(double)CLOCKS_PER_SEC<<endl;
	
	cout<<"\n   memoriza \n";
	int init_ = clock();
	cout<<cut_rod_mem(p,3950);
    int end_ = clock();
	cout<<"\ntiempo: "<<(end_-init_)/(double)CLOCKS_PER_SEC<<endl;
	
	cout<<"\n   bottom up \n";
	int init__ = clock();
	cout<<cut_rod_BU(p,3950);
    int end__ = clock();
	cout<<"\ntiempo: "<<(end__-init__)/(double)CLOCKS_PER_SEC<<endl;

	return 0;
}