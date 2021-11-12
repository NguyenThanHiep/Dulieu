#include <iostream>
#include <stdlib.h>
#include <string.h>
int MAXQUEUE = 10000;
using namespace std;

struct mathang{
	int mamh ;
	
	char tenmh[12];
	
};

struct queue{
	
	int front, rear ;
	
	mathang nodes[MAXQUEUE];
};

void initalize(struct queue *pq)
{
	pq->front = pq->rear = MAXQUEUE -1;
}

int empty(struct queue *pq){
	return ((pq->front == pq->rear) ? TRUE : FALSE);
}

int Insert(struct queue *pq, mathang x)
{
	if(pq->rear == MAXQUEUE -1)
		pq->rear = 0;
	else 
		(pq->rear)++;
		
	if (pq->rear == pq->front)
		cout <<"kho hang bi day";
	else
		pq->nodes[pq->rear] = x;
		
}

mathang Remove (struct queue *pq)
{
	
	if(empty(pq))
		cout <<"khong con hang";
	else {
		
		if ( pq->front == MAXQUEUE - 1)
			pq->front = 0;
			
		else 
			pq->front++;
			return(pq->nodes[pq->front]);
	}
}

void traverse(struct queue *pq){
	
	int i;
	
	if(empty(pq)){
		
		cout <<"\n kho khong con hang";
		
		return;
	}
	
	if (pq->front == MAXQUEUE - 1)
		i = 0;
	else 
		i = pq->front+1;
		
	while(i != pq->rear) {
		
		cout <<pq->nodes[i].mamh << pq->nodes[i].tenmh;
		
		if(i == MAXQUEUE - 1)
			i = 0;
		else 
			i++;
	}
	cout << pq->nodes[i].mamh << pq->nodes[i].tenmh; 
}
int main(){
	struct queue q;
	
	int chucnang, frontl;
	
	char c;
	
	mathang mh;
	
	initalize(&q);
	
	do {
		
		cout <<"CHUONG TRINH QUAN LY KHO" << endl;
		
		cout <<"(NHAP TRUOC  -  XUAT TRUOC)"<< endl;
		
		cout <<"Cac chua nang cua chuong trinh."<< endl;
		
		cout <<"1.Nhap mat hang."<< endl;
		
		cout <<"2.Xuat mat hang." << endl;
		
		cout <<"3.Xem mat hang chuan bi xuat" << endl;
		
		cout <<"4.Xem mat hang moi nhap" << endl;
		
		cout <<"5.Xem cac mat hang co trong kho" << endl;
		
		cout <<"6.Xuat toan bo kho hang" << endl;
		
		cout <<"0.Ket thuc chuong trinh" << endl;
		
		cout <<"Chuc nang ban chon: "<< endl;
		
		cin >> chucnang;
		
		switch(chucnang){
			case 1:{
				cout << "Mat hang : ";
				cin >> mh.mamh;
				
				cout <<"Ten mat hang : ";
				cin >> mh.tenmh;
				
				Insert(q, mh);
				break;
			}
			case 2:{
				if (!empty(&q))
				{
					mh = Remove(&q);
					cout <<Ma mat hang: <<mh.mamh << endl;
					cout <<Ten : <<mh.tenmh << endl;
				}
				else 
					cout << "khong con hang"<< endl;
				
				break;
			}
			case 3:{
				
				frontl = (q.front = MAXQUEUE - 1 ? 0 : q.front+1);
				
				cout <<"Mat hang chuan bi xuat: "<< q.nodes[frontl].mamh << endl;
				
				cout <<"Ten : " <<q.nodes[frontl].tenmh << endl;
				
				break;
			}
			case 4:{
				
				cout <<"Mat hang moi nhap: "<<q.nodes[q.rear].mamh << endl;
				
				cout <<"Ten : "<< q.nodes[q.rear].tenmh << endl;
				
				break;
			}
			case{
				
				cout <<"Cac mat hang co trong kho: " << endl;
				
				cout <<" Ma Mat Hang " << endl;
				
				cout <<"Ten mat hang " << endl;
				
				traverse(&q);
				
				break;
			}
			case 6:
				{
					cout <<"Ban co chac khong: " << endl;
					
					c = getche();
					
					if (c == 'c' || c == 'C')
						initalize(&q);
						
					break;
				}
		}
	} while( chucnang != 0);
	
	
}
