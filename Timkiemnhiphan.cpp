#include <bits/stdc++.h>
using namespace std;
void nhapmang (int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout <<"a"<<i<<":";
		cin >> a[i];
	}
}
void xuatmang (int a[], int n)
{
	cout << "Phan tu mang : "<< endl;
		for (int i = 0; i < n ; i++)
		{
		 cout << a[i] << endl ;
		}
}

int timkiemnhiphan(int a[], int left, int right, int m)
 {
    int middle;
 
    while(left <= right) {
        middle = (left + right) / 2;
 
        if (a[middle] == m)
            return middle;
 
        
        if (m > a[middle])
            left = middle + 1;
        else
        
            right = middle - 1;
    }
 
    return -1;
}
int ghifile(int a[], int n)
{
	
	fstream f;                      
	f.open("nhiphan.txt", ios::out);
	for(int i = 0 ; i < n ; i++)
    {
		f << a[i] << endl;  
    }
	                         
	f.close();
}
int docfile(int a[], int n)
{
	fstream f;
	f.open("input.txt", ios::in);
	for(int i = 0; i < n; i++ )
	{
		string a[1];

		string line;
		while (!f.eof())          
		{
			getline(f, line); 
			a[i] += line;
		}
	}
	f.close();

}
int main ()
{
	int a[1000], n,chon,m;

	int x;
	cout <<"Nhap n: ";
	cin >> n;
	
	nhapmang (a,n);
	
	xuatmang (a,n);
	
	ghifile(a , n);
	
	docfile(a ,n);
	
    cout << "Nhap so can tim = nhi phan: ";
    
    cin >> m;
    
    int c = sizeof(a) / sizeof(a[0]);

    int result = timkiemnhiphan(a, 0, n-1, m);
 
    cout <<"vi tri : " << result;

	return 0;
}
