
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
void themCuoi(node *p, list *l);
void taoGioHang(giocuatoi &h );
void xoaDanhSachBatKy(list *l, int viTri);
void timGiaTienDaNhapHayChua( list *l);
void tinhTongTienCacSP( list *l);
void them1SanPhamVaoViTriBatKi(list *l, node *p,int k );
void tao1File(list *l,int n,giocuatoi h);
void xuat(list *l);

