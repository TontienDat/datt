#include <stdio.h>
#define SIZE 100

void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int tongMang(int a[], int n);
int tongCacPhanTuDuong(int a[],int n);
int tongCacPhanTuViTriLe(int a[],int n);
int slam(int a[],int n);
int slle(int a[],int n);
int main() {
    int A[SIZE];
    int n;
    int kq1,kq2,kq3;
    do {
        printf("\nNhap vao so phan tu: ");
        scanf("%d", &n);
    } while(n <= 0 || n > SIZE);  // n hop le

    // Goi ham cau a
    nhapMang(A, n);

    // Goi ham cau b
    printf("\nMang vua nhap la: ");
    xuatMang(A, n);

    // Goi ham cau c
    kq1 = tongMang(A, n);
    printf("\nTong cac gia tri trong mang la %d\n", kq1);
    // goi ham cau d
    kq2 = tongCacPhanTuDuong(A,n);
    printf("\nTong cac gia tri duong trong mang la %d\n", kq2);
    // goi ham cau e
    kq3 = tongCacPhanTuViTriLe(A,n);
    printf("\nTong cac gia tri o vi tri le trong mang la %d\n",kq3);
    // goi ham cau f
    printf("\nSo luong so am: %d",slam(A,n));
    // goi ham cau g 
    printf("\nPhan tu le: %d",slle(A,n));
     
    return 0;
}

int tongMang(int a[], int n) {
    int tong = 0;
    int i = 0;
    while (i < n) {
        tong += a[i];  
        i++;
    }
    return tong;
}

void xuatMang(int a[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);  
    }
    printf("\n");  
}

void nhapMang(int a[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("\nNhap gia tri tai vi tri %d: ", i);
        scanf("%d", &a[i]);  
    }
}
int tongCacPhanTuDuong(int a[], int n){
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0){  
            tong += a[i];  
        }
    }
    return tong;
}
int tongCacPhanTuViTriLe(int a[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {  
            tong += a[i];  
        }
    }
    return tong;

}
int slam (int a[], int n){
	int dem=0;
	for ( int i=0; i < n; i++ ){
		if( a[i]<0){
			dem++;
		}
	}
	return dem;
}
	int slle ( int a[], int n){
		int dem=0;
		for ( int i=0;i < n; i++ ){
			if (a[i]%2 !=0){
			dem++;
       } 
	   return dem;   
   }
}




