#include <stdio.h>
#define ROW 1000 // so dong n
#define COL 1000 // so cot m

void nhapMang(int a[ROW][COL], int n, int m);
void xuatMang(int a[ROW][COL], int n, int m);
int tongMang(int a[ROW][COL], int n, int m);
int tongdongk(int a[ROW][COL], int n, int k);
int tongcotk(int a[ROW][COL], int m, int k);
int kiemtraamdong(int a[ROW][COL], int m, int k);
int kiemtrasonguyento(int n);
void sapxepdonggiamdan(int a[ROW][COL], int n, int k);
int kiemTraCotLe(int a[ROW][COL], int m, int k);
void timViTriX(int a[ROW][COL], int m, int n, int x);
int timGiaTriX(int a[ROW][COL], int m, int n, int x);
int timGiaTriLonNhatDongK(int a[ROW][COL], int n, int k);
int timGiaTriNhoNhatDongK(int a[ROW][COL], int n, int k);
void inSoNguyenToDongK(int a[ROW][COL], int n, int k);
int laSoNguyenTo(int x); 

int main() {
    int a[ROW][COL];
    int n, m;

    printf("Nhap so dong: ");
    scanf("%d", &n);
    printf("Nhap so cot: ");
    scanf("%d", &m);

    nhapMang(a, n, m);
    xuatMang(a, n, m);

    printf("Tong mang: %d\n", tongMang(a, n, m));
    // cau c
	int tong=tongMang(a, m, n);
	printf("Tong cua mang la: %d\n", tong);
    return 0;
    
}

// goi ham cau a
void nhapMang(int a[ROW][COL], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap phan tu mang a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

// goi ham cau b
void xuatMang(int a[ROW][COL], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// goi ham cau c
int tongMang(int a[ROW][COL], int n, int m) {
    int Tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Tong += a[i][j];
        }
    }
    return Tong;
}

// goi ham cau d
int tongdongk(int a[ROW][COL], int n, int k) {
    int Tong = 0;
    for (int j = 0; j < n; j++) {
        Tong += a[k][j];
    }
    return Tong;
}

// goi ham cau e
int tongcotk(int a[ROW][COL], int m, int k) {
    int Tong = 0;
    for (int i = 0; i < m; i++) {
        Tong += a[i][k];
    }
    return Tong;
}

// goi ham cau f
int kiemtraamdong(int a[ROW][COL], int m, int k) {
    for (int i = 0; i < m; i++) {
        if (a[k][i] < 0) {
            return 1; // Dung
        }
    }
    return 0; // Sai
}

// goi ham cau g
int kiemtrasonguyento(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return 0;
    }
    return 1; // La so nguyen to
}

// goi ham cau h
void sapxepdonggiamdan(int a[ROW][COL], int n, int k) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[k][i] < a[k][j]) {
                int temp = a[k][i];
                a[k][i] = a[k][j];
                a[k][j] = temp;
            }
        }
    }
}

// goi ham cau i
int kiemTraCotLe(int a[ROW][COL], int m, int k) {
    for (int i = 0; i < m; i++) {
        if (a[i][k] % 2 == 0) return 0; // Cot khong toan so le
    }
    return 1; // Cot toan so le
}

// goi ham cau j
void timViTriX(int a[ROW][COL], int m, int n, int x) {
    int found = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                printf("Gia tri %d nam o vi tri dong %d, cot %d\n", x, i, j);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Gia tri %d khong ton tai trong mang.\n", x);
    }
}

// goi ham cau k 
int timGiaTriX(int a[ROW][COL], int m, int n, int x) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) return 1;
        }
    }
    return 0;
}

// goi ham cau l
int timGiaTriLonNhatDongK(int a[ROW][COL], int n, int k) {
    int max = a[k][0];
    for (int j = 1; j < n; j++) {
        if (a[k][j] > max) max = a[k][j];
    }
    return max;
}

// goi ham cau m
int timGiaTriNhoNhatDongK(int a[ROW][COL], int n, int k) {
    int min = a[k][0];
    for (int j = 1; j < n; j++) {
        if (a[k][j] < min) min = a[k][j];
    }
    return min;
}

// goi ham cau n
void inSoNguyenToDongK(int a[ROW][COL], int n, int k) {
    printf("Cac so nguyen to tren dong %d: ", k);
    for (int j = 0; j < n; j++) {
        if (kiemtrasonguyento(a[k][j])) {
            printf("%d ", a[k][j]);
        }
    }
    printf("\n");
}


