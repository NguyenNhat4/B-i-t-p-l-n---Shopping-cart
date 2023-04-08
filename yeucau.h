
#include"stdio.h"
#include"math.h"
#include"string.h"
#include"time.h"
#include"stdlib.h"
typedef struct gh{
  char tensp[30];
  int gia;
  int soluong;
}Gh;
typedef struct Node{
	Gh data;
	Node *next; 
}node;
typedef struct List{
	node *head;
	node *tail;
	int n;
}list;
  struct giohang_st {
 char tenkhachhang[30];
 char diachi[50] ;
 int sosanpham =40;
 Gh giohang;
};
typedef giohang_st giocuatoi;
void khoiTaoList(list *l);
void xoaXuongDong(char x[]);
node* createNodegiohang(Gh g, giocuatoi h);
void themDau(node *p, list *l);
void themCuoi(node *p, list *l);
void taogiohang(giocuatoi &h );
void xoaDau(list *l);
void xoaCuoi(list *l);
void xoadanhsachbatky(list *l, int viTri);
void Timgiatiendanhaphaychua( list *l);
void tinhtongtiencacsp( list *l);
void them1sanphamvaovitribatki(list *l, node *p,int k );
void tao1file(list *l,int n,giocuatoi h);
void xuat(list *l);

