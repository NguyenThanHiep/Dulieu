#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
struct Node{
	
	int data;
	
	Node *link;
	
};

struct stack{

	Node *top;	
};

void init (stack &s)
{
	
	s.top = NULL;
	
}

int Empty (stack s){
	
	return s.top == NULL ? 1 : 0;
}

void push (stack &s, float x){
	
	Node *p;
	
	p = new Node;
	
	if (p!= NULL){
		
		p->data = x;
		
		p->link = s.top;
		
		s.top = p;
	}
}

float pop (stack &s)
{
	float x;
	
	if (!Empty(s)){
		
		Node *p = s.top;
		
		s.top = p->link;
		
		x = p->data;
		
		delete(p);
		
		return x;
	}
}

void DocTu (char s[], char tu[], int &vt)
{
	
	for (int i = 0; i < strlen(tu); i++)
		tu[i] = ' ';
		
	int i = 0;
	
	while(s[vt] != ' ')
	{
		
		tu[i] = s[vt];
		
		vt++;
		
		i++;
	}
}

int LaToanTu (char s[]){
	
	char c = s[0];
	
	if ((c == '+')  || (c == '-') || (c == '*')|| (c == '/'))
	
			return 1;
			
	return 0;
}

float TinhToan (float toanHang1, float toanHang2, char toanTu){
	
	float kp;
	
	switch (toanTu)
	{
		case '+' : kp = toanHang1 + toanHang2; break;
		
		case '-' : kp = toanHang1 - toanHang2; break;
		
		case '*' : kp = toanHang1 * toanHang2; break;
		
		case '/' : kp = toanHang1 / toanHang2; break;
	}
	
	return kp;
}

float TinhBT (stack &s, char bieuThuc[]){
	
	float kp;
	
	char t[10];
	
	int i = 0;
	
	do{
		
		DocTu(bieuThuc, t, i);
		
		if (LaToanTu(t)){
			
			char toanTu = t[0];
			
			float toanHang1 = pop(s);
			
			float toanHang2 = pop(s);
			
			kp = TinhToan (toanHang2, toanHang1, toanTu);
			
			
			push(s,kp);
		}
		else{
			
			float toanHang = atof(t);
			
			push(s,toanHang);
		}
	}while (bieuThuc[i] != '#');
	
	
	return pop(s);
}
int main()
{
	stack s;
	
	init(s);
	
	char bieuThuc[100] = " ";
	
	cout <<"Nhap bieu thuc dang hau to\n";
	
	fflush(stdin);
	
	gets(bieuThuc);
	
	float kp;
	
	kp = TinhBT(s, bieuThuc);
	
	cout <<"Gia tri cua bieu thuc la: " << kp << endl;
	
}
