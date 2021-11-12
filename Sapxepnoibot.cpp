#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int slhv;
void nhapmang (int a[], int &n)
{
	srand(time(NULL));
	
	for (int i = 0 ; i < n ; i++)
	
		a[i] = rand();
}

void BubbleSort (int a[], int n)
{

	for (int i = 0 ; i < n - 2; i++)
	
		for (int j = n -1; j > i; j--)
		{
			if(a[j] < a[j - 1])
			
				swap(a[j] , a[j - 1]); slhv++;
		}
		
}
void swap (int &b , int &c)
{
	int x = b;
	
	b = c ;
	
	c = x ;
	
	
}
void xuatmang (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
int main ()
{
	int a[100000];
	int n;
	double t;
	cout <<"========================================================="<<endl;
	
	cout << "Nhap n : ";
	
	cin >> n;
	
	clock_t start, end;
	
	nhapmang(a, n);
	
	start = clock();
	
	BubbleSort(a,n);
	
	end = clock();
	
	xuatmang(a,n);
	
	t= (double)(end - start);
	cout <<"so lan hoan vi: "<< slhv << endl;
	
	cout <<"thoi gian thuc hien: "<< t<<endl;
	
	return 0;
}
