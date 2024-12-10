#include <stdio.h>
#include <string.h>


struct NGAY_THANG {
    int ngay;
    int thang;
    int nam;
};


struct MON_HOC {
    char ma_mon[10];
    float diem;
};


struct SINH_VIEN {
    char mssv[15];         
    char hoten[100];   
    struct NGAY_THANG ngaysinh;  
    char gioi_tinh[10];    
    char dia_chi[111]; 
    int somon;             
    struct MON_HOC mon_hoc[100];  
};

typedef struct SINH_VIEN SINH_VIEN;  


void nhap(SINH_VIEN *a);
void xuat(SINH_VIEN a);

int main() {
    SINH_VIEN a;
    
    nhap(&a);
    
    printf("\nThong tin vua nhap la: \n");
    xuat(a);
    
    return 0;
}


void xuat(SINH_VIEN a) {
    printf("%s\t%s\t%s\t%s\t%d\n", a.mssv, a.hoten, a.gioi_tinh, a.dia_chi, a.somon);
    
    
    for (int i = 0; i < a.somon; i++) {
        printf("Mon hoc %d: Ma Mon: %s, Diem: %.2f\n", i+1, a.mon_hoc[i].ma_mon, a.mon_hoc[i].diem);
    }
}


void nhap(SINH_VIEN *a) {
    
    printf("\nNhap vao hoten: ");
    fflush(stdin);
    fgets(a->hoten, sizeof(a->hoten), stdin);
    a->hoten[strcspn(a->hoten, "\n")] = 0;
    
    
    printf("\nNhap vao mssv: ");
    fflush(stdin);
    fgets(a->mssv, sizeof(a->mssv), stdin);
    a->mssv[strcspn(a->mssv, "\n")] = 0; 
    
    
    printf("\nNhap vao dia chi: ");
    fflush(stdin);
    fgets(a->dia_chi, sizeof(a->dia_chi), stdin);
    a->dia_chi[strcspn(a->dia_chi, "\n")] = 0; 
    
   
    printf("\nNhap gioi tinh: ");
    fflush(stdin);
    fgets(a->gioi_tinh, sizeof(a->gioi_tinh), stdin);
    a->gioi_tinh[strcspn(a->gioi_tinh, "\n")] = 0;  
    
    
    printf("\nNhap so mon hoc: ");
    scanf("%d", &a->somon);
    
    
    for (int i = 0; i < a->somon; i++) {
        printf("\nNhap ma mon hoc %d: ", i+1);
        fflush(stdin);
        fgets(a->mon_hoc[i].ma_mon, sizeof(a->mon_hoc[i].ma_mon), stdin);
        a->mon_hoc[i].ma_mon[strcspn(a->mon_hoc[i].ma_mon, "\n")] = 0; 
        
        printf("Nhap diem mon hoc %d: ", i+1);
        scanf("%f", &a->mon_hoc[i].diem);
    }
}

