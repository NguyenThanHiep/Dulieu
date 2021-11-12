#include <iostream>
#include <fstream>


using namespace std;

struct SV{
	int mssv;
	char ten[50];
	char gioitinh[10];
	int namsinh;
	int diem;
};

void nhapttsv (SV &sv){
	
		
		cout << "Nhap ten SV: ";
		
		fflush(stdin);
		
		gets(sv.ten);
		
		cout << "Nhap gioi tinh: ";
		
		gets(sv.gioitinh);
		
		cout <<"Nhap nam sinh: ";
		
		cin >> sv.namsinh;
		
		cout <<"Nhap diem : ";
		
		cin >> sv.diem;
	
}
void nhapN(SV a[], int n){
   
cout <<"_____________________________________________________"<<endl;	
    for(int i = 0; i< n; i++){
    	
       cout <<"Nhap Sv thu "<<i + 1<<":"<<endl;
       
       nhapttsv(a[i]);
    }
cout <<"_____________________________________________________"<<endl;
    
}
void xuatDS (SV sv)
{
	
	cout <<"Ho va Ten: "<< sv.ten << endl;
	
	cout <<"Gioi Tinh: "<< sv.gioitinh<< endl;
	
	cout <<"Nam Sinh: "<< sv.namsinh << endl;
	
	cout <<"Diem: "<< sv.diem << endl;
}
void xuatN(SV a[], int n){
	
   cout <<"__________________________________________________"<< endl;
    
    for(int i = 0 ; i < n;i++){
    	
        cout <<"Thong tin sinh vien thu " <<i + 1<< endl;
        
        	xuatDS(a[i]);
        
    }
    cout <<"__________________________________________________"<<endl;
}
int ghifile(SV a[], int n)
{
	
	fstream f;                      
	f.open("DSsv.txt", ios::out);

	for(int i = 0 ; i < n ; i++)
    {
		f << a[i].ten << endl;
		
		f << a[i].gioitinh<< endl;
		
		f << a[i].namsinh << endl;
		
		f << a[i].diem << endl;  
    }
	                         
	f.close();
}
void sapxepTB (SV a[], int n)
	{
		SV t;
		
		for (int i = 0; i < n; i++)
		
			for(int j = i + 1; j < n; j++)
			
				{
					if(a[i].diem > a[j].diem)
					{
						t = a[i];
						
						a[i] = a[j];
						
						a[j] = t;
					}
				}
	}
void sapXepTheoTen(SV a[], int n)
 {
    
    SV tmp;
    
    char tenSV1[30];
    
    char tenSV2[30];
    
    for(int i = 0;i < n; i++)
	 {
        (tenSV1, a[i].ten);
        
        for(int j = i+1; j < n; j++) 
		{
            (tenSV2, a[j].ten);
            
            if(((tenSV1), (tenSV2)) > 0)
			 {
                tmp = a[i];
                
                a[i] = a[j];
                
                a[j] = tmp;
            }
        }
    }
}
int main()
{
	SV sv;
	int chon;
		int n;
	  do {
		cout <<"Muon bao nhieu sinh vien : ";
		
		cin >> n;
		
		} while(n <= 0);
		
		SV a[n];
		
 	while(true)	
	{
		cout <<"DANH SACH SINH VIEN"<<endl;
		
		cout << "1.Nhap du lieu SV"<<endl;
	
		cout << "2.Xuat danh sach SV" << endl;
	
		cout << "3.In danh sach SV" << endl;
	
		cout <<"4.Sap xep SV theo diem TB" << endl;
	
		cout <<"5.Sap xep SV theo Ho va Ten" << endl;
		cout <<"Moi lua chon: "<<endl;
		cin >> chon;
		switch(chon) {
			case 1:
				cout <<"Du lieu cau ban:"<< endl;
				 
				nhapN(a, n);
				
				break;
			case 2:
				
				cout <<"Xuat danh sach"<< endl;
				
				xuatN(a, n)	;
				
				break;
			case 3:
				cout <<"__________________________________________________"<< endl;
				cout <<"Ghi danh sach vao file"<<endl;
				
				ghifile(a, n);
				cout <<"__________________________________________________"<< endl;
				break;
			case 4:
				cout <<"__________________________________________________"<< endl;
				cout <<"Sap xep SV theo diem TB"<< endl;
				
				sapxepTB (a, n);
				cout <<"__________________________________________________"<< endl;
				
				break;
			case 5:
				cout <<"__________________________________________________"<< endl;
				cout <<"Sap xep theo ten"<< endl;

				sapXepTheoTen(a,n);
				cout <<"__________________________________________________"<< endl;
			default:
				break;
		}
	}
}

