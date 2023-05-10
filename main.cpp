#include"yeucau.h"
void user_menu_input(Item item, list *shopping_list, node *p, giocuatoi customer_info) {
    int user_input;
    int vitri ;
    int tieptuc = 0;

    while (tieptuc != -1) {
        menu_show(1);
        scanf("%d", &user_input);
        switch (user_input) {
            case 1:
                tieptuc = -1;
                taogiohang(customer_info);
                printf("\nDa tao thanh cong gio hang!!!\n");
                break;
            case 2:
                printf("\n END!!!!!\n");
                return;
        }
    }
    tieptuc = 0;

    while (tieptuc != -1) {
        menu_show(2);
        scanf("%d", &user_input);
        xoaInputBuffer();
        switch (user_input) {

            case 1:
                p =  createNodeSanpham(item, customer_info);
                themCuoi(p, shopping_list);
                break;
            case 2:
                xuat(shopping_list);
                break;
            case 3:
                do {
                    menu_show(3);
                    scanf("%d", &user_input);
                    xoaInputBuffer();
                    switch (user_input) {
                        case 1:
                            printf("Nhap vi tri muon xoa gio hang: ");
                            scanf("%d", &vitri);
                            xoadanhsachbatky(shopping_list, vitri);
                            break;
                        case 2:

                            printf("Nhap vi tri ban muon chen them gio hang: ");
                            scanf("%d", &vitri);
                            p = createNodeSanpham(item,  customer_info);
                            them1sanphamvaovitribatki(shopping_list, p, vitri);
                            break;
                        case 3:
                            tao1file(shopping_list,customer_info);
                            break;
                        case 4:
                            tinhtongtiencacsp(shopping_list);
                            break;
                        case 5:
                            Timgiatiendanhaphaychua(shopping_list);
                            break;
                        case 6:
                            taogiohang(customer_info);
                            printf("\nThong Tin khach hang da sua thanh cong!!!\n");
                            break;
                        case 7:
                            tieptuc = 0;
                            break;
                        case 8:
                            tieptuc = -1;
                            printf("\n END!!!!!\n");
                            return;
                    }
                } while (tieptuc != 0);
                break;
            case 4:
                printf("\n END!!!!!\n");
                return;
        }
    }
}


int main() {
  
    Item item ; // data gio hang
    list *shopping_list=(list*)malloc(sizeof(list));
    node *p = (node*)malloc(sizeof(node));
    khoiTaoList(shopping_list);
    giocuatoi  customer_info ;
    customer_info.sosanpham = 30;
    user_menu_input(item, shopping_list, p, customer_info);

}


