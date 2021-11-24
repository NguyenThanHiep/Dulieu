#include <iostream>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>

using namespace std;

struct NGAYTHANG
{	
  
	int Ngay;	
  
	int Thang;	
  
	int Nam;	
  
};

struct DONHANG
{	
	char maDH[10];	
  
	char diachinhan[255];	
  
	char diachigiao[255];	
  
	NGAYTHANG ngaynhan;	
  
	NGAYTHANG ngaygiao;	
  
	int trangthai;	
  
};

struct Node 
{
	
	DONHANG data;
  
	Node *left;
  
	Node *right;
  
};

typedef Node  *TREE;

int soSanh(DONHANG x1, DONHANG x2)
{
	return strcmp(x1.maDH, x2.maDH);// so sánh chuoi x1 và x2	
}
int TrangThai(DONHANG &x)
{
	if (x.trangthai == 0 || x.trangthai == 1)
		return x.trangthai;
	else
	{
		cout << "Moi nhap lai: ";
		cin >>x.trangthai;
		return TrangThai(x);
	}
}
DONHANG dh ()
{
	DONHANG x ;
	char maDH[10];
	cout <<"\n\tNhap ma don hang(nhap q de thoat!!): ";
	fflush(stdin);
	gets(x.maDH);
	if (strcmp(x.maDH, "q") == 0 || strcmp(x.maDH, "Q") == 0)
        return x;
  
    cout <<"\n\tDia chi nhan: ";
    fflush(stdin);
    gets(x.diachinhan);
  
    cout <<"\n\tDia chi giao: ";
	fflush(stdin);
	gets(x.diachigiao);
  
    cout <<"\n\tNhap ngay/thang/nam nhan: ";
	cin >>x.ngaynhan.Ngay;
	cin.ignore();
  	cin >>x.ngaynhan.Thang;
    cin.ignore();
	cin >>x.ngaynhan.Nam;
  
	cout <<"\n\tNhap ngay/thang/nam giao: ";
	cin>>x.ngaygiao.Ngay;
	cin.ignore();
	cin >>x.ngaygiao.Thang;
	cin.ignore();
	cin >>x.ngaygiao.Nam;
  
	cout <<"\n\tNhap trang thai don hang(1 don hang giao thanh cong, 0 don hang giao khong thanh cong): ";
	cin >>x.trangthai;
    TrangThai(x);
	if(TrangThai(x)==0)
	{	
		fflush(stdin);
		char a[255]="NULL";
		strcpy(x.diachinhan,a);
    
		x.ngaygiao.Ngay=0;
    
		x.ngaygiao.Thang=0;
    
		x.ngaygiao.Nam=0;
    
	}
    return x;
}
void outItem(DONHANG x) 
{	
	char tt[20];
	if(x.trangthai==1)
		strcpy(tt,"thanh cong");
	else
		strcpy(tt,"khong thanh cong");
  
    cout<<"| Ma don hang: " <<x.maDH<< "|  Dia chi nhan: " 
      
		<<x.diachinhan<< "| Dia chi giao: " <<x.diachigiao<< "| Ngay nhan: " 
      
		<<x.ngaynhan.Ngay<<"/"<<x.ngaynhan.Thang<<"/"<<x.ngaynhan.Nam<< "| Ngay giao: " 
      
		<<x.ngaygiao.Ngay<<"/"<<x.ngaygiao.Thang<<"/"<<x.ngaygiao.Nam<< "| Trang thai: " 
      
		<<tt<<" |"<<endl;     
}
int insertNode(TREE &T, DONHANG x)
{
	if (T != NULL) 
	{	
        if (soSanh(T->data, x) == 0) 
            return -1; 
    
        if (soSanh(T->data, x) > 0)
            return insertNode(T->left, x);  
    
        else if (soSanh(T->data, x) < 0)
            return insertNode(T->right, x);          
    } 
	T = new Node;
    if (T == NULL)    
        return 0;    
  
    T->data = x;    
  
    T->left = T->right = NULL; 
  
    return 1; 	
}
bool KiemTraDH(TREE &T, DONHANG x)
{
    if (T == NULL) 
        return false; 
    if (soSanh(T->data, x)==0) 
        return true;     
  
    bool th1 = KiemTraDH(T->left, x); 
  
    bool th2 = KiemTraDH(T->right, x);
  
    if(th1) 
		return th1;
    else 
		return th2;
}
int Insert(TREE &T, DONHANG x)
{		
    if(soSanh(T->data, x) == 0)   
        return -1;         
  
    else if (soSanh(T->data, x)>0)
        return insertNode(T->left, x);
  
    else if(soSanh(T->data, x)<0)
        return insertNode(T->right, x);
}
void Create(TREE &T)
{
	DONHANG x;
	while(1) 
	{		
		cout <<"NHAP THONG TIN \(0 v 0)>"<< endl;		
		x = dh();		
		if (strcmp(x.maDH, "q") == 0 || strcmp(x.maDH, "Q") == 0)		
             break;     
        int check1 = insertNode(T,x);       
        if (check1 == -1)
            cout <<"Don hang nhap sai.";
        else if (check1 == 0)
            cout <<"Da day.";      
	}
}
void LNR(TREE T) 
{
    if (T != NULL) 
	{	
        LNR(T->left);
        outItem(T->data);
        LNR(T->right);   
    }
}
int Delete(TREE &T, DONHANG x) 
{	
    if (T == NULL)
        return 0;
    else if (soSanh(T->data, x) > 0)
        return Delete(T->left, x);
    else if (soSanh(T->data, x) < 0)
        return Delete(T->right, x);
    else
    {
        Node *P = T;
        if (T->left == NULL)
            T = T->right;
        else if (T->right == NULL)  
            T = T->left; 
        else
        {
            Node *S = T, *Q = S->left;
            while (Q->right != NULL) 
			{
                S = Q;
                Q = Q->right;  
            }
            P->data = Q->data;
            S->right = Q->left;
            delete Q;
        }
    }
    return 1;
}

int main()
{
	TREE T;
	DONHANG x;
	DONHANG n;
	int chon;	
	T = NULL;
	do
	{	
		system("cls");
		cout << "=================MENU================\n";
		cout << "1. Nhap don hang\n";
		cout << "2. Xuat don hang\n";
		cout << "3. Bo sung don hang\n";
		cout << "4. Xoa nut trong cay\n";
		cout << "5. Tim kiem don hang\n";
		cout << "99. Thoat!!!\n";
		cout << "=====================================\n";
		cout << "\n\nMoi chon menu: ";
		fflush(stdin);
		cin >> chon;	
		switch(chon)
		{
		case 1:		
			cout << "1. Nhap don hang\n";
			Create(T);
			break;
		case 2:
			cout << "2. Xuat don hang\n";
			cout<<"Xuat theo LNR:\n";
			LNR(T);
			break;
		case 3:
			cout << "3. Bo sung don hang\n";
			while(1)
			{
				cout<<"\nNhap ma don hang de kiem tra(q de thoat chuc nang, n de chuyen qua bo sung don hang): ";	
				fflush(stdin);
				gets(x.maDH);
				if(strcmp(x.maDH, "q") == 0 || strcmp(x.maDH, "Q") == 0) 
			 		goto EXIT; 	
				else if (strcmp(x.maDH, "n")==0 || strcmp(x.maDH, "N") == 0) 
					goto NEXT; 	
				if(KiemTraDH(T, x))
					cout<<"\n\tDon hang co roi\n";	
				else cout<<"\n\tDon hang khong co san\n\n";
			}			
			NEXT:cout<<"\n\nBo sung don hang \n"; 
			x = dh();
			Insert(T, x);
			EXIT:break;
		case 4:
			cout << "4. Xoa nut trong cay\n";
			cout << "\nNhap ma don hang can xoa: ";
			fflush(stdin); 
		 	gets(n.maDH); 
			Delete(T,n);
			cout<< "\nDanh sach don hang sau khi xoa: \n";
			LNR(T); 
			break;	
		case 5:
			cout << "5. Tim kiem nut trong cay\n";
			cout << "\nNhap ma don hang can tim kiem: "; 
			fflush(stdin);
			gets(x.maDH);
			if(KiemTraDH(T, x))
			{
				cout<<"\n\tDon hang co roi\n";		
			}
			else cout<<"\n\t\tDon hang khong co san\n";	
			break;
		case 99:
			cout << "Thoat!!!\n";
			exit(1);
			break;
		}
		cout<<"\n\n===Ban co muon tiep tuc khong? (Nhap y/n)===";
		char c;
		fflush(stdin);
		cin>>c;
		if(c == 'y'||c == 'Y')
			chon = -1;
		else
			cout<<"\n\t\t\t========TAM BIET========";
	}while(chon != 1 && chon != 2 && chon !=3 && chon!=0);
	return 0;
}
