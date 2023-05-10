
#include"stdio.h"
#include"math.h"
#include"string.h"
#include"time.h"
#include"stdlib.h"
typedef struct Item{
  char tensp[40];
  int gia;
  int soluong;
}Item;


typedef struct Node{
	Item data;
	struct Node *next;
}node;

typedef struct List{
	node *head;
	node *tail;
	int n;
}list;

struct giohang_cua_khach {
char tenkhachhang[50];
char diachi[70];
int sosanpham;
Item giohang;
};
int menu_show(int mode);
typedef struct giohang_cua_khach giocuatoi;
void xoaInputBuffer();
void khoiTaoList(list *shopping_list);
void xoaXuongDong(char x[]);
node* createNodeSanpham(Item g, giocuatoi h);
void themDau(node *p, list *shopping_list);
void themCuoi(node *p, list *shopping_list);
void taogiohang(giocuatoi customer_info );
void xoaDau(list *shopping_list);
void xoaCuoi(list *shopping_list);
void xoadanhsachbatky(list *shopping_list, int viTri);
void Timgiatiendanhaphaychua( list *shopping_list);
void tinhtongtiencacsp( list *shopping_list);
void them1sanphamvaovitribatki(list *shopping_list, node *p,int k );
void tao1file(list *shopping_list,giocuatoi h);
void xuat(list *shopping_list);



