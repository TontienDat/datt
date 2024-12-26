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
void nhap_danh_sach(SINH_VIEN sinh_vien[], int n);
void xuat_danh_sach(SINH_VIEN sinh_vien[], int n);
SINH_VIEN *tim_sinh_vien_theo_mssv(SINH_VIEN sinh_vien[], int n, const char *mssv);
void tim_sinh_vien_theo_ten(SINH_VIEN sinh_vien[], int n, const char *ten);
void tim_sinh_vien_theo_thang_sinh(SINH_VIEN sinh_vien[], int n, int thang);
void tim_sinh_vien_theo_gioi_tinh(SINH_VIEN sinh_vien[], int n, const char *gioi_tinh);
void tim_sinh_vien_theo_dia_chi(SINH_VIEN sinh_vien[], int n, const char *dia_chi);

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    
    SINH_VIEN sinh_vien[n];
    nhap_danh_sach(sinh_vien, n);

    printf("\nDanh sach sinh vien:\n");
    xuat_danh_sach(sinh_vien, n);

    char mssv[15];
    printf("\nNhap ma so sinh vien can tim: ");
    fflush(stdin);
    fgets(mssv, sizeof(mssv), stdin);
    mssv[strcspn(mssv, "\n")] = 0;  
    SINH_VIEN *sv = tim_sinh_vien_theo_mssv(sinh_vien, n, mssv);
    if (sv != NULL) {
        printf("\nSinh vien tim duoc theo MSSV: ");
        xuat(*sv);
    } else {
        printf("\nKhong tim thay sinh vien voi MSSV: %s\n", mssv);
    }

    char ten[100];
    printf("\nNhap ten sinh vien can tim: ");
    fflush(stdin);
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = 0;
    printf("\nDanh sach sinh vien co ten '%s':\n", ten);
    tim_sinh_vien_theo_ten(sinh_vien, n, ten);

    int thang;
    printf("\nNhap thang sinh can tim: ");
    scanf("%d", &thang);
    printf("\nDanh sach sinh vien sinh vao thang %d:\n", thang);
    tim_sinh_vien_theo_thang_sinh(sinh_vien, n, thang);

    char gioi_tinh[10];
    printf("\nNhap gioi tinh can tim: ");
    fflush(stdin);
    fgets(gioi_tinh, sizeof(gioi_tinh), stdin);
    gioi_tinh[strcspn(gioi_tinh, "\n")] = 0;
    printf("\nDanh sach sinh vien co gioi tinh '%s':\n", gioi_tinh);
    tim_sinh_vien_theo_gioi_tinh(sinh_vien, n, gioi_tinh);

    char dia_chi[111];
    printf("\nNhap dia chi can tim: ");
    fflush(stdin);
    fgets(dia_chi, sizeof(dia_chi), stdin);
    dia_chi[strcspn(dia_chi, "\n")] = 0;
    printf("\nDanh sach sinh vien co dia chi '%s':\n", dia_chi);
    tim_sinh_vien_theo_dia_chi(sinh_vien, n, dia_chi);

    return 0;
}

void nhap(SINH_VIEN *a) {
    printf("\nNhap vao ho ten: ");
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
        printf("\nNhap ma mon hoc %d: ", i + 1);
        fflush(stdin);
        fgets(a->mon_hoc[i].ma_mon, sizeof(a->mon_hoc[i].ma_mon), stdin);
        a->mon_hoc[i].ma_mon[strcspn(a->mon_hoc[i].ma_mon, "\n")] = 0;

        printf("Nhap diem mon hoc %d: ", i + 1);
        scanf("%f", &a->mon_hoc[i].diem);
    }
}

void xuat(SINH_VIEN a) {
    printf("%s\t%s\t%s\t%s\t%d\n", a.mssv, a.hoten, a.gioi_tinh, a.dia_chi, a.somon);
    for (int i = 0; i < a.somon; i++) {
        printf("Mon hoc %d: Ma Mon: %s, Diem: %.2f\n", i + 1, a.mon_hoc[i].ma_mon, a.mon_hoc[i].diem);
    }
}

void nhap_danh_sach(SINH_VIEN sinh_vien[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien %d:\n", i + 1);
        nhap(&sinh_vien[i]);
    }
}

void xuat_danh_sach(SINH_VIEN sinh_vien[], int n) {
    for (int i = 0; i < n; i++) {
        xuat(sinh_vien[i]);
    }
}

SINH_VIEN *tim_sinh_vien_theo_mssv(SINH_VIEN sinh_vien[], int n, const char *mssv) {
    for (int i = 0; i < n; i++) {
        if (strcmp(sinh_vien[i].mssv, mssv) == 0) {
            return &sinh_vien[i];
        }
    }
    return NULL;
}

void tim_sinh_vien_theo_ten(SINH_VIEN sinh_vien[], int n, const char *ten) {
    for (int i = 0; i < n; i++) {
        if (strstr(sinh_vien[i].hoten, ten) != NULL) {
            xuat(sinh_vien[i]);
        }
    }
}

void tim_sinh_vien_theo_thang_sinh(SINH_VIEN sinh_vien[], int n, int thang) {
    for (int i = 0; i < n; i++) {
        if (sinh_vien[i].ngaysinh.thang == thang) {
            xuat(sinh_vien[i]);
        }
    }
}

void tim_sinh_vien_theo_gioi_tinh(SINH_VIEN sinh_vien[], int n, const char *gioi_tinh) {
    for (int i = 0; i < n; i++) {
        if (strstr(sinh_vien[i].gioi_tinh, gioi_tinh) != NULL) {
            xuat(sinh_vien[i]);
        }
    }
}

void tim_sinh_vien_theo_dia_chi(SINH_VIEN sinh_vien[], int n, const char *dia_chi) {
    for (int i = 0; i < n; i++) {
                if (strstr(sinh_vien[i].dia_chi, dia_chi) != NULL) {
            xuat(sinh_vien[i]);
        }
    }
}

