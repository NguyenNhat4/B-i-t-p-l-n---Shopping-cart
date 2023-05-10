#include"yeucau.h"

typedef struct customer_info customer_info;

typedef struct customer_info customer_info;

void khoiTaoList(list *l){
	l->head=l->tail=NULL;
	l->n=0;
}

void xoaXuongDong(char x[]){
	size_t len = strlen(x);
	if(x[len-1]=='\n'){
	x[len-1]='\0';
	}
}
void xuat(list *l){
	int m=1;
	printf("\nSTT    Ten san pham      Gia      So luong\n");
	for(node *i=l->head;i!=NULL;i=i->next){
printf("%-7d%-18s%-9d%d\n", m++, i->data.tensp, i->data.gia, i->data.soluong);
	}
}


node* createNodeSanpham(Item g, giocuatoi h){
	if(h.sosanpham  == 0){
		printf("Gio hang da day!!!\n");
		return NULL;
	}
	node *p = (node*)malloc(sizeof(node));
	printf("\nTen san pham: ");
	fflush(stdin); // clear all input stream
	fgets(g.tensp, sizeof(g.tensp), stdin);  // doc khong qua 20 ki tu
	xoaXuongDong(g.tensp);
	printf("Gia: ");
	scanf("%d",&g.gia);
	printf("So luong: ");
	scanf("%d",&g.soluong);
	p->data=g;
	p->next=NULL;
	printf("Da luu gio hang!!!\n");
	h.sosanpham--;
	return p;
	}
	void themCuoi(node *p, list *l){
	if(l->head==NULL){
		l->head=p;
		l->tail=p;
}
	else{
		l->tail->next=p;
		l->tail = p;
	}
	l->n++;
}

void themDau(node *p, list *l){
	if(l->head==NULL){
	l->head=p;
	l->tail=p;
	}
	else{
	p->next=l->head;
		l->head=p;
	}
	l->n++;
}
void xoaInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
void taogiohang(giocuatoi customer_info ) {
    printf("Nhap ten khach hang: ");
    scanf("%s", customer_info.tenkhachhang);
    xoaInputBuffer(); // Clear enter input buffer , avoid misunderstand when user hits "enter" as a input

    printf("\nNhap dia chi: ");
    scanf("%s", customer_info.diachi);
    xoaInputBuffer();
}

void xoaDau(list *l){
	 node* p = NULL;
	if(l->head==NULL)
		printf("Danh sach chua co phan tu nao de xoa");
	else{
		p = l->head;
		l->head=l->head->next;
		free(p);
		(l->n)--;
    }
}


void xoaCuoi(list *l){
	if(l->head==NULL)
		printf("Danh sach chua co phan tu nao de xoa");
	else{
		node *i=l->head;
		int dem=1;
		int soluong=l->n;
		while(dem < (soluong-1)){
			i=i->next;
			dem++;
}
		l->tail=i;
		i->next=NULL;
		l->n--;
	}
}

void xoadanhsachbatky(list *l, int viTri){
	if(viTri < 1 || viTri > l->n){
        printf("Ban phai nhap thu tu dung voi danh sach");
        return;
    }

    if(viTri == 1){
        xoaDau(l);
        return;
    }
    if(viTri == l->n){
        xoaCuoi(l);
        return;
    }
//    truong hop con lai
    node *truoc = l->head;
    for(int i = 1; i < viTri-1; i++){
        truoc = truoc->next;
    }

    node *sau = truoc->next;
    truoc->next = sau->next;
    free(sau);
    l->n--;
}


 void Timgiatiendanhaphaychua( list *shopping_list) {
 	int q;
 	int z;
 	bool flag = false;
 	printf("nhap gia tien ban muon tim xem co hay chua: ");
 	scanf("%d",&q);
	for(node *i=shopping_list->head;i!=NULL;i=i->next) {
		if( q == i->data.gia) {
		flag = true;
		}
		
	}
	if(flag) {
			printf("da co so tien la %d\n",q);
		}
		else{
			printf("chua co so tien la %d \n",q);
		}
 }
void tinhtongtiencacsp( list *shopping_list) {
	int tong=0;
	for(node *i=shopping_list->head;i!=NULL;i=i->next){
		tong=tong+ i->data.gia;
	}
	printf("Tong tien cac san pham da tao: %d\n",tong);
}

void them1sanphamvaovitribatki(list *shopping_list, node *p,int k ) {
	if(k < 1 || k > shopping_list->n+1){
        printf("Vi tri them khong hop le");
        return;
    }
    if(k == shopping_list->n+1){

        themCuoi(p, shopping_list);
        return;
    }
    if(k == 1){
        themDau(p, shopping_list);
        return;
    }
    node *prev = shopping_list->head;
    for(int i = 1; i < k-1; i++){
        prev = prev->next;
    }
    p->next = prev->next;
    prev->next = p;
    shopping_list->n++;
}

void tao1file(list *l,giocuatoi h) {
	int m=1;
	FILE *f;
	f = fopen("cart.dat","wb");
    fprintf(f," \nKhach hang: %s ",h.tenkhachhang);
    fprintf(f," \nDia chi: %s ",h.diachi);
    fprintf(f," \nSTT    Ten san pham     Gia      So luong\n");
	for(node *i=l->head;i!=NULL;i=i->next){
	fprintf(f,"%-7d%-18s%-9d%d\n", m++, i->data.tensp, i->data.gia, i->data.soluong);
	}
	printf("Da luu du lieu!!!\n");
	fclose(f);
}
int menu_show(int mode){

	if(mode==1){
		printf("\n===== Menu =====");
        printf("\n 1.Tao gio hang cua ban.");
        printf("\n 2. Exit");
        printf(" \n Chon: ");

	}
	if(mode ==2 ){
		printf("\n===== Gio cua ban =====");
		printf("\n 1.Them vao gio hang");
        printf("\n 2.Xem chi tiet gio hang");
        printf("\n 3.Lua chon khac");
        printf("\n 4.Exit");
        printf(" \n Chon: ");

	}

	if(mode==3){
		printf("\n===== Lua chon khac =====");
	    printf("\n 1.Nhap vi tri muon xoa gio hang");
        printf("\n 2.Nhap vi tri ban muon chen them gio hang");
        printf("\n 3.ghi gio hang vao tep nhi phan");
        printf("\n 4.Tinh Tong tien :");
        printf("\n 5.Kiem tra co gia tien nao do hay chua");
         printf("\n 6.Chinh sua thong tin khach hang");
        printf("\n 7.Quay lai.");
        printf("\n 8. Exit");
         printf(" \n Chon: ");
	}
}


