#include"yeucau.h"
int main() {
	int k;
	Gh g1;
	int n;
	list *l=(list*)malloc(sizeof(list));
	node *p = (node*)malloc(sizeof(node));
	khoiTaoList(l);
	giocuatoi h1;
    do{
    printf("\n===== MENU =====");
	printf("\n 1. Tao gio hang");
	printf("\n 2. Chon hang");
	printf("\n 3. Xem chi tiet gio hang");
	printf("\n 4. Xoa 1 gio hang vao vi tri bat ki");
	printf("\n 5. Chen them 1 gio hang vao vi tri bat ki");
	printf("\n 6. Ghi gio hang vao tep nhi phan");
	printf("\n 7. Tinh tong tien cac san pham da tao");
	printf("\n 8. Kiem tra xem da co so tien nao do hay chua");
	printf("\n 9. Exit");
	printf(" \n Ban chon? ");
	scanf("%d",&n);
	switch(n) {
	case 1: taogiohang(	h1);
	break;
	case 2:	
	p=createNodegiohang(g1,h1);
	themCuoi(p,l);
	break;
	case 3:	
	xuat(l);
	break;
	case 4:	
	printf("Nhap vi tri muon xoa gio hang: ");
	scanf("%d",&k);
	xoadanhsachbatky(l,k);
	break;
	case 5: printf("Nhap vi tri ban muon chen them gio hang: ");
    scanf("%d",&k);
	p=createNodegiohang(g1,h1);
	them1sanphamvaovitribatki(l,p,k);
	break;
	case 6: tao1file(l,n,h1);
	break;
	case 7: tinhtongtiencacsp(l);
	break;
	case 8: Timgiatiendanhaphaychua(l);
		break;	
	      }
	}while(n!=9);
}

