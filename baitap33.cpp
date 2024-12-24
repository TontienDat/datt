#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tu_so;
    int mau_so;
} PHAN_SO;

// khai bao
int UCLN(int a, int b);
void nhapPhanSo(PHAN_SO *ps);
void xuatPhanSo(PHAN_SO ps);
void rutGonPhanSo(PHAN_SO *ps);
PHAN_SO cong(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO tru(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO nhan(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO chia(PHAN_SO ps1, PHAN_SO ps2);
void ghiFile(PHAN_SO *ds, int n, const char *filename);
void docFile(PHAN_SO *ds, int *n, const char *filename);
void hienThi(PHAN_SO *ds, int n);
float tinhGiaTri(PHAN_SO ps);
PHAN_SO timMin(PHAN_SO *ds, int n);
int demMin(PHAN_SO *ds, int n);
void sapXep(PHAN_SO *ds, int n);

int main() {
    int n;
    PHAN_SO ds[100];
    const char *filename = "phanso.txt";

    // Nhap sp luong phan so
    printf("Nhap so luong phan so: ");
    scanf("%d", &n);

    // Nhap danh sach phan so
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so %d:\n", i + 1);
        nhapPhanSo(&ds[i]);
    }

    // Ghi phan so vao tep tin
    ghiFile(ds, n, filename);
    printf("Danh sach phan so da duoc ghi vao tep tin %s.\n", filename);

    // doc phan tu tep  tin
    docFile(ds, &n, filename);

    // Hien thi phan so
    hienThi(ds, n);

    // Tim phan so nho nhat
    PHAN_SO min = timMin(ds, n);
    printf("Phan so co gia tri nho nhat  là: ");
    xuatPhanSo(min);
    printf("\n");

    // dem phan so nho nhat
    int count = demMin(ds, n);
    printf("Co %d phan so co gia tri nho nhat.\n", count);

    // Sap xep phan so theo thu tu dam dan
    sapXep(ds, n);
    printf("Danh sach phan so sau khi sap xep theo thu tu giam dan:\n");
    hienThi(ds, n);

    // Cac phep toan 
    PHAN_SO ps1, ps2, result;

    printf("\nNhap phan so thu nhat:\n");
    nhapPhanSo(&ps1);
    printf("Nhap phan so thu hai:\n");
    nhapPhanSo(&ps2);

    // Cong hai phan so
    result = cong(ps1, ps2);
    printf("Cong hai phan so: ");
    xuatPhanSo(result);
    printf("\n");

    // Tru hai phan so
    result = tru(ps1, ps2);
    printf("Tru hai phan so: ");
    xuatPhanSo(result);
    printf("\n");

    // Nhan hi phan so
    result = nhan(ps1, ps2);
    printf("Nhan hai phan so: ");
    xuatPhanSo(result);
    printf("\n");

    // Chia hai phan so
    result = chia(ps1, ps2);
    printf("Chia hai phan so: ");
    xuatPhanSo(result);
    printf("\n");

    return 0;
}

// Ham nhap gia tri cho phan so
void nhapPhanSo(PHAN_SO *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu_so);
    do {
        printf("Nhap mau so (khác 0): ");
        scanf("%d", &ps->mau_so);
        if (ps->mau_so == 0) {
            printf("Mau so khong the bang 0, vui long nhap loi.\n");
        }
    } while (ps->mau_so == 0);
}

// Ham xuat gia tri cho phan so
void xuatPhanSo(PHAN_SO ps) {
    printf("%d/%d", ps.tu_so, ps.mau_so);
}

// Ham tinh uoc chung lon nhat
int UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Ham rut gon phan so
void rutGonPhanSo(PHAN_SO *ps) {
    int ucln_val = UCLN(ps->tu_so, ps->mau_so);
    ps->tu_so /= ucln_val;
    ps->mau_so /= ucln_val;
}

// Ham tinh gia tri
float tinhGiaTri(PHAN_SO ps) {
    return (float)ps.tu_so / ps.mau_so;
}

// Ham ghi gia tri vao trong tep tin
void ghiFile(PHAN_SO *ds, int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Khong the mo tep tin de ghi!\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d %d\n", ds[i].tu_so, ds[i].mau_so);
    }
    fclose(file);
}

// Ham doc phan so tu tep tin
void docFile(PHAN_SO *ds, int *n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo tep tin de ghi!\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(file, "%d %d", &ds[i].tu_so, &ds[i].mau_so) != EOF) {
        i++;
    }
    *n = i;
    fclose(file);
}

// Ham hien thi danh sach phan so
void hienThi(PHAN_SO *ds, int n) {
    printf("Danh sach phan so sau khi rut gon");
    for (int i = 0; i < n; i++) {
        rutGonPhanSo(&ds[i]);
        xuatPhanSo(ds[i]);
        printf("\n");
    }
}

// Ham tinh phan so nho nhat
PHAN_SO timMin(PHAN_SO *ds, int n) {
    PHAN_SO min = ds[0];
    for (int i = 1; i < n; i++) {
        if (tinhGiaTri(ds[i]) < tinhGiaTri(min)) {
            min = ds[i];
        }
    }
    return min;
}

// Ham dem so luong phan so nho nhat
int demMin(PHAN_SO *ds, int n) {
    PHAN_SO min = timMin(ds, n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (tinhGiaTri(ds[i]) == tinhGiaTri(min)) {
            count++;
        }
    }
    return count;
}

// Ham p xep danh sach theo thu tu giam dan
void sapXep(PHAN_SO *ds, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tinhGiaTri(ds[i]) < tinhGiaTri(ds[j])) {
                PHAN_SO temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

// Ham cong hai phan so
PHAN_SO cong(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tu_so = ps1.tu_so * ps2.mau_so + ps2.tu_so * ps1.mau_so;
    result.mau_so = ps1.mau_so * ps2.mau_so;
    rutGonPhanSo(&result);
    return result;
}

// Ham tru hai phan so
PHAN_SO tru(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tu_so = ps1.tu_so * ps2.mau_so - ps2.tu_so * ps1.mau_so;
    result.mau_so = ps1.mau_so * ps2.mau_so;
    rutGonPhanSo(&result);
    return result;
}

// Ham nhan hai phan so
PHAN_SO nhan(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tu_so = ps1.tu_so * ps2.tu_so;
    result.mau_so = ps1.mau_so * ps2.mau_so;
    rutGonPhanSo(&result);
    return result;
}

// Ham chia hai phan so
PHAN_SO chia(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tu_so = ps1.tu_so * ps2.mau_so;
    result.mau_so = ps1.mau_so * ps2.tu_so;
    rutGonPhanSo(&result);
    return result;
}

