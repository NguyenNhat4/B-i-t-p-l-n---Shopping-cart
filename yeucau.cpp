#include"yeucau.h"
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
node* createNodegiohang(Gh g, giocuatoi h){
	 if (h.sosanpham>= 30) {
        printf("Chua tao gio hang.\n");
        return 0;
    }
	node *p = (node*)malloc(sizeof(node));
	printf("\nTen san pham: ");
	fflush(stdin); 
	fgets(g.tensp, sizeof(g.tensp), stdin); xoaXuongDong(g.tensp);
	printf("Gia: ");
	scanf("%d",&g.gia);
	printf("So luong: ");
	scanf("%d",&g.soluong);
	p->data=g;
	p->next=NULL;
	printf("Da luu gio hang!!!\n");
	return p;
}
void themCuoi(node *p, list *l){
	if(l->head==NULL){
		l->head=p;
		l->tail=p;
	}
	else{
		l->tail->next=p;
		l->tail=p;
	}
	l->n++;
}
void taoGioHang(giocuatoi &h ) {
	h.sosanpham=0;
	printf("Nhap ten khach hang: ");
	fflush(stdin);
	fgets(h.tenkhachhang, sizeof(h.tenkhachhang), stdin); xoaXuongDong(h.tenkhachhang);
	printf("\nNhap dia chi: ");
	fflush(stdin); 
	fgets(h.diachi, sizeof(h.diachi), stdin); xoaXuongDong(h.diachi);
}
void xoaDanhSachBatKy(list *l, int viTri){ 
	if(viTri < 1 || viTri > l->n){
        printf("Ban phai nhap thu tu dung voi danh sach");
        return;
    }
    if(viTri == 1){
      if(l->head==NULL)
		printf("Danh sach chua co phan tu nao de xoa");
	else{
		l->head=l->head->next;
	}
        return;
    }
    if(viTri == l->n){
       if(l->head==NULL)
		printf("Danh sach chua co phan tu nao de xoa");
	else{
		node *i=l->head;
		int dem=1;
		int sl=l->n;
		while(dem < (sl-1)){
			i=i->next;
			dem++;
		}
		l->tail=i;
		i->next=NULL;
		l->n--;
	}
        return;
    }
    node *prev = l->head;
    for(int i = 1; i < viTri-1; i++){
        prev = prev->next;
    }
    node *tmp = prev->next;
    prev->next = tmp->next;
    free(tmp);
    l->n--;
}
 void timGiaTienDaNhapHayChua( list *l) {
 	int q;
 	int z;
 	printf("nhap gia tien ban muon tim xem co hay chua: ");
 	scanf("%d",&q);
	for(node *i=l->head;i!=NULL;i=i->next) {
		if( q == i->data.gia) {
			printf("da co so tien la %d\n",q);
		}
		else{
			printf("chua co so tien la %d \n",q);
		}
	}
 }
void tinhTongTienCacSP( list *l) {
	int tong=0;
	for(node *i=l->head;i!=NULL;i=i->next){
		tong=tong+ i->data.gia;
	}
	printf("Tong tien cac san pham da tao: %d\n",tong);
}
void them1SanPhamVaoViTriBatKi(list *l, node *p,int k ) {
	if(k < 1 || k > l->n+1){
        printf("Vi tri them khong hop le");
        return;
    }
    if(k == l->n+1){
    	
        themCuoi(p, l);
        return;
    }
    if(k == 1){
       if(l->head==NULL){		
		l->head=p;
		l->tail=p;
	}
	else{
		p->next=l->head;
		l->head=p;
	}
	l->n++;
        return;
    }  
    node *prev = l->head;
    for(int i = 1; i < k-1; i++){
        prev = prev->next;
    }
    p->next = prev->next;
    prev->next = p;
    l->n++;
}
void tao1File(list *l,int n,giocuatoi h) {
	int m=1;		
	FILE *f;
	f = fopen("cart.dat","wb");
    fprintf(f," \nKhach hang: %s ",h.tenkhachhang);
    fprintf(f," \nDia chi: %s ",h.diachi);
    fprintf(f," \nSTT    Ten san pham      Gia      So luong\n");
	for(node *i=l->head;i!=NULL;i=i->next){
	fprintf(f,"%-7d%-18s%-9d%d\n", m++, i->data.tensp, i->data.gia, i->data.soluong);
	}
	printf("Da luu du lieu!!!\n");
	fclose(f);
}
void xuat(list *l){
	int m=1;
	printf("\nSTT    Ten san pham      Gia      So luong\n");
	for(node *i=l->head;i!=NULL;i=i->next){
printf("%-7d%-18s%-9d%d\n", m++, i->data.tensp, i->data.gia, i->data.soluong);
	}
}
