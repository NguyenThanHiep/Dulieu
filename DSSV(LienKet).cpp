#include <iostream>
#include <stdlib.h>
#include <Time.h>
#include <string.h>
using namespace std;
struct Date {
	
	int ngay , thang, nam;
};
struct SV {
	char maSV[8];
	
	char hoTen[50];
	
	int gioiTinh;
	
	Date ngaySinh;
	
	char diaChi[100];
	
	char lop[12];
	
	char khoa [7];
	
};



struct Node {
	
	SV data;
	
	Node *link;
	
};

struct List {
	
	Node *first , *last;
	
};

Node *GetNode (SV x){
	
	Node *p;
	
	p = new Node;
	
	if (p == NULL)
		return NULL;
	
	p->data = x;
	
	p->link = NULL;
	
	return p;
}

void init (List &l){
	
	l.first = l.last = NULL;
}

void AddFirst (List &l, Node *new_ele)
{
	if (l.first == NULL)
	{
		
		l.first = new_ele;
		
		l.last = l.first;
		
	}else{
		
		new_ele->link = l.first;
		
		l.first = new_ele;
		
	}
}

void AddLast (List &l, Node *new_ele){
	
	if (l.first == NULL){
		
		l.first = l.last = new_ele;
	}
	else {
		
		l.last->link = new_ele;
		
		l.last = new_ele;
	}
}

void InsertFisrt(List &l, SV x)
{
	Node *new_ele = GetNode(x);
	
	if (new_ele == NULL)
	
		return;
		
	AddFirst(l, new_ele);
}

void InsertLast (List &l, SV x){
	
	Node *new_ele = GetNode(x);
	
	if (new_ele == NULL)
		
		return;
		
	AddLast(l , new_ele);
	
}
 


int NhapSinhVien (SV &x){
	
	cout <<"Ma so Sinh Vien: ";
	fflush(stdin);
	gets(x.maSV);
	
	if (strcmp (x.maSV, "0") == 0)
		return 0;
		
	cout <<"Ho ten Sinh Vien: ";
	fflush(stdin);
	gets(x.hoTen);
	
	cout <<"Gioi tinh : ";
	fflush(stdin);
	cin >> x.gioiTinh;
	
	cout <<"Ngay thang nam sinh: ";
	fflush(stdin);
	cin >>x.ngaySinh.ngay >>x.ngaySinh.thang >>x.ngaySinh.nam;
	
	cout <<"Dia chi: ";
	fflush(stdin);
	gets(x.diaChi);
	
	cout <<"Lop: ";
	fflush(stdin);
	gets(x.lop);
	
	cout <<"Khoa vien: ";
	fflush(stdin);
	gets(x.khoa);
	
	return 1;
	
}

void NhapDSSV (List &l){
	
	cout <<"\n Bat dau nhap danh sach sinh vien\n" << endl;
	
	cout <<"\n Nhap 0 de ket thuc.\n"<< endl;
	
	SV x;
	
	int flag = NhapSinhVien(x);
	
	while(flag) {
		
		InsertLast(l, x);
		
		flag = NhapSinhVien(x);
	}
	cout <<"\nHoan thanh nhap danh sach.";
}

void XuatSinhVien(SV s){
	
	char gt[4];
	
	if (s.gioiTinh == 0)
	
		strcpy(gt, "Nam");
		
	else
	
		strcpy(gt, "Nu");
		
	cout <<s.maSV <<" | "<<s.hoTen <<" | "<<s.ngaySinh.ngay<<"/"<<s.ngaySinh.thang<<"/"<<s.ngaySinh.nam<<" | "<<gt<<" | "<<s.diaChi<<" | "<<s.lop<<" | "<<s.khoa<<" |"<<endl;
	
}

void XuatDSSV (List l){
	
	int dem = 1;
	for (Node *p = l.first; p != NULL; p = p->link)
	{
		cout<<"\n sinh vien "<<dem++;
		
		XuatSinhVien(p->data);
	}
	
}


int main(){
	
	List l;
	
	init(l);
	
	NhapDSSV(l);
	
	XuatDSSV(l);
	
}
