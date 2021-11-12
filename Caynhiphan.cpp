#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

struct NGAYTHANG{
	
	int Ngay;
	
	int Thang;
	
	int Nam;
	
};

struct DONHANG{
	
	char maDH[10];
	
	char diachinhan[255];
	
	char diachigiao[255];
	
	NGAYTHANG ngaynhan;
	
	NGAYTHANG ngaygiao;
	
	int trangthai;
	
};

struct Node {
	
	DONHANG data;//truong data cua du lieu.
	
	Node *left;//con trai. 
	
	Node *right;//con phai.
};

typedef Node  *TREE;//Cay

int soSanh(DONHANG x1, DONHANG x2)
{
	return strcmp(x1.maDH, x2.maDH);	
}

DONHANG dh (){//Nhap DonHang.
	DONHANG x ;
	
	char maDH[10];
	
	cout <<"Nhap ma don hang(nhap q de thoat!!): ";
	
	gets(x.maDH);
	
	if (strcmp(x.maDH, "q") == 0 || strcmp(x.maDH, "Q") == 0) {
		
        return x;
        
    }
    
    cout <<"Dia chi nhan: ";
    
    gets(x.diachinhan);
    
    cout <<"Dia chi giao: ";
    
    gets(x.diachigiao);
    
    cout <<"Nhap ngay/thang/nam nhan: ";
	cin >>x.ngaynhan.Ngay;
	cin.ignore();
  	cin >>x.ngaynhan.Thang;
    cin.ignore();
	cin >>x.ngaynhan.Nam;
	
	cout <<"\nNhap ngay/thang/nam giao: ";
	cin>>x.ngaygiao.Ngay;
    cin.ignore();
	cin >>x.ngaygiao.Thang;
    cin.ignore();
	cin >>x.ngaygiao.Nam;
    fflush(stdin); 
    cout <<"\nNhap trang thai don hang(nhap 1 neu don hang ton tai, 0 cho don hang khong ton tai: ";
    cin >>x.trangthai;
    cout<<endl; 
    fflush(stdin);
    
    return x;
}	

void tieuDe()
{
	for(int i=0; i<110; i++)
		cout<<"_";
	cout<<"\n\t\t\t\t====QUAN LI DON HANG=====\n";
	for(int i=0; i<110; i++)
		cout<<"-";
	cout<<"\n";
	cout<<"||"<<"Ma don hang"<<"|"<<"\tDia chi nhan\t"<<"|"<<"\tDia chi giao\t"<<"|"
			<<"\tNgay nhan\t"<<"|"<<"\tNgay giao\t"<<"|"<<"Trang thai"<<"||";
} 
void XuatDH(DONHANG x)
{
	cout<<x.maDH<<"|\t"<<x.diachinhan<<"\t|\t"<<x.diachigiao<<"\t|\t"<<x.ngaynhan.Ngay<<"/"<<x.ngaynhan.Thang<<"/"<<x.ngaynhan.Nam
		<<"\t|\t"<<x.ngaygiao.Ngay<<"/"<<x.ngaygiao.Thang<<"/"<<x.ngaygiao.Nam<<"\t|\t"<<x.trangthai<<"\t||"; 
}
void outItem(DONHANG x) {
	
    cout <<"| Ma don hang: " <<x.maDH<< "|  Dia chi nhan: " <<x.diachinhan<< "| Dia chi giao: " <<x.diachigiao<< "| Ngay nhan: " <<x.ngaynhan.Ngay<<"/"<<x.ngaynhan.Thang<<"/"<<x.ngaynhan.Nam<< "| Ngay giao: " <<x.ngaygiao.Ngay<<"/"<<x.ngaygiao.Thang<<"/"<<x.ngaygiao.Nam<< "| Trang thai: " <<x.trangthai<<" |"<<endl;
      
}

int insertNode(TREE &T, DONHANG x){
	
	if (T != NULL) {
		
        if (soSanh(T->data, x) == 0)
        
            return -1;  // Node nay da co
            
        if (soSanh(T->data, x) > 0)
        
            return insertNode(T->left, x); // chen vao Node trai
            
        else if (soSanh(T->data, x) < 0)
        
            return insertNode(T->right, x);   // chen vao Node phai
            
    }
   //T = (Node *) malloc(sizeof(Node)); 
	T = new Node;
    if (T == NULL)
    
        return 0;   
        
    T->data = x;
    
    T->left = T->right = NULL;
    
    return 1;   // ok	
}


bool KiemTraDH(TREE &T, DONHANG x)
{
    if (T == NULL)
    
        return false;
        
    if (soSanh(T->data, x)==0)
    
        return true;
        
    bool th1 = KiemTraDH(T->left, x);
    
    if(th1) return true;
    
    bool th2 = KiemTraDH(T->right, x);
    
    return th2;
}

int Insert(TREE &T, DONHANG x)
{	

    if(soSanh(T->data, x) == 0)
    
        return 1;
        
    else if (soSanh(T->data, x)>0)
    
        return insertNode(T->left, x);
        
    else if(soSanh(T->data, x)<0)
    
        return insertNode(T->right, x);
        
}
void Create(TREE &T){// nhap cay.

	
	DONHANG x;
	
	while(1) {
		
		cout <<"NHAP THONG TIN \(0 v 0)>"<< endl;
		
		x = dh();
		
		if (strcmp(x.maDH, "q") == 0 || strcmp(x.maDH, "Q") == 0)
		
            break;  // x = 0 thi thoat.
        
        int check1 = insertNode(T,x);
        
        if (check1 == -1)
        
            cout <<"Don hang nhap sai.";
            
        else if (check1 == 0)
        
            cout <<"Da day.";
        
        
            
	}
}

// Duyet theo LNR
void LNR(TREE T) {
	
    if (T != NULL) {
    	
        LNR(T->left);
        
        outItem(T->data);
        //XuatDH(T->data);
        
        LNR(T->right);
        
        
    }
}
int TimKiemX()
{
	TREE T;
	
	DONHANG x;
	
	char maDH;
	
	cout<<"Nhap Ma Don Hang Can Tim: ";
	
    cin>> maDH;
    
    if (x.maDH==T-> data.maDH)
	{	
	
    	cout<<"Don Hang Can Tim : "<< maDH;
    	
	}
	return 0;
	
    if(T==NULL) 
    
		return 1;
}


//xoa key
int Delete(TREE &T, DONHANG x)     // xoa nut co key x
        {
        	
    if (T == NULL)
    
        return 0;
        
    else if (soSanh(T->data, x) > 0)
    
        return Delete(T->left, x);
        
    else if (soSanh(T->data, x) < 0)
    
        return Delete(T->right, x);
        
    else // T->key == x
    {
        Node *P = T;
        
        if (T->left == NULL)
        
            T = T->right;    // Node chi co cay con phai
            
        else if (T->right == NULL)
        
            T = T->left;   // Node chi co cay con trai
            
        else // Node co ca 2 con
        {
            Node *S = T, *Q = S->left;
            
            // S la cha cua Q, Q la Node phai nhat cua cay con trai cua P
            
            while (Q->right != NULL) {
            	
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

int main(){
	
	TREE T;
	
	DONHANG x;
	
	int chon;
	
	T = NULL;//tao cay rong.
	do
	{	
		system("cls");
		
		cout << "=================MENU================\n";
		
		cout << "1. Nhap don hang\n";
		
		cout << "2. Xuat don hang\n";
		
		cout << "3. Bo sung don hang\n";
		
		cout << "4. Xoa nut trong cay\n";
		
		cout << "5. Tim kiem nut trong cay\n";
		
		cout << "99. Thoat!!!\n";
		
		cout << "=====================================\n";
	
		cout << "\n\nMoi chon menu: ";
		
		cin >> chon;	
		
		fflush(stdin);
		
		switch(chon)
		{
		case 1:		
			cout << "1. Nhap don hang\n";
			
			Create(T);
			
			break;
			
		case 2:
			cout << "2. Xuat don hang\n";
			
			cout<<"Xuat theo LNR:\n";
			
			//tieuDe();
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
				
					cout<<"\nDon hang co roi";
					
				else cout<<"\nDon hang khong co san\n\n";
			}
						
			NEXT:cout<<"\n\nBo sung don hang \n"; 
			
			x = dh();
			
			Insert(T, x);
			
			EXIT:break;
			
		case 4:
			
			cout << "4. Xoa nut trong cay\n";
			
			Delete(T,x);
			
			break;
			
		case 5:
			
			cout << "5. Tim kiem nut trong cay\n";
			
			TimKiemX();
				
			break;
		case 99:
			cout << "Thoat!!!\n";
			
			exit(1);
			
			break;
		}
	
		cout<<"\n\n===Ban co muon tiep tuc khong? (Nhap y/n)===";
		
		char c ;
		
		fflush(stdin);
		
		cin>>c;
		
		if(c == 'y'||c == 'Y')
		
			chon = -1; // gan chon khong phai la 1,2,3,0 thi chuong trinh se lap lai
		else
		
			cout<<"\n HAN HANH VA TAM BIET DMM";
			
		}
		
		while(chon != 1 && chon != 2 && chon !=3 && chon!=0);

	return 0;
}
