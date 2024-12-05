#include <stdio.h>
#include <stdlib.h>

 
typedef struct {
    int tu; 
    int mau; 
} PHAN_SO;

// Khai bao
int UCLN(int a, int b);
void nhapPhanSo(PHAN_SO *ps);
void xuatPhanSo(PHAN_SO ps);
void rutGon(PHAN_SO *ps);
PHAN_SO cong(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO tru(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO nhan(PHAN_SO ps1, PHAN_SO ps2);
PHAN_SO chia(PHAN_SO ps1, PHAN_SO ps2);

int main() {
    PHAN_SO ps1, ps2, ketQua;
    
    // nhap phan so
    printf("Nhap phan so thu 1:\n");
    nhapPhanSo(&ps1);
    printf("Nhap phan so thu 2:\n");
    nhapPhanSo(&ps2);

    // xuat phan so
    printf("Phan so 1: ");
    xuatPhanSo(ps1);
    printf("Phan so 2: ");
    xuatPhanSo(ps2);

    // Cong hai phan so
    ketQua = cong(ps1, ps2);
    printf("Tong hai phan so: ");
    xuatPhanSo(ketQua);

    // tru hai phan so
    ketQua = tru(ps1, ps2);
    printf("Hieu hai phan so: ");
    xuatPhanSo(ketQua);

    // nhan hai phan so
    ketQua = nhan(ps1, ps2);
    printf("Tich hai phan so: ");
    xuatPhanSo(ketQua);

    // Chia hai phan so
    ketQua = chia(ps1, ps2);
    printf("Thuong hai phan so: ");
    xuatPhanSo(ketQua);

    return 0;
}

// tinh uoc chung
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// ham nhap phan so
void nhapPhanSo(PHAN_SO *ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
    } while (ps->mau == 0);
}

// ham xuat phan so
void xuatPhanSo(PHAN_SO ps) {
    if (ps.mau < 0) {
        ps.mau = -ps.mau;  
        ps.tu = -ps.tu;   
    }
    printf("%d/%d\n", ps.tu, ps.mau);
}

// ham rut gon phan so
void rutGon(PHAN_SO *ps) {
    int ucln = UCLN(abs(ps->tu), abs(ps->mau));
    ps->tu /= ucln;
    ps->mau /= ucln;
}

// ham cong hai phan so
PHAN_SO cong(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    result.mau = ps1.mau * ps2.mau;
    rutGon(&result);
    return result;
}

// ham tru hai phan so
PHAN_SO tru(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    result.mau = ps1.mau * ps2.mau;
    rutGon(&result);
    return result;
}

// ham nhan hai phan so
PHAN_SO nhan(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tu = ps1.tu * ps2.tu;
    result.mau = ps1.mau * ps2.mau;
    rutGon(&result);
    return result;
}

// Ham chia HAI phan so
PHAN_SO chia(PHAN_SO ps1, PHAN_SO ps2) {
    PHAN_SO result;
    result.tu = ps1.tu * ps2.mau;
    result.mau = ps1.mau * ps2.tu;
    rutGon(&result);
    return result;
}

