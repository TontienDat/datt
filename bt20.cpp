#include <stdio.h>
#define SIZE 10000
void nhapmang(float a[],int n),xuatmang(float a[], int n), invitrile(float a[], int n), vitricogiatrilakhong(float a[], int n), thututangdan(float a[], int n), incacvitrimax(float a[], int n);
float tong(float a[],int n),tbcvitrile(float a[], int n),max(float a[],int n);
int demduong(float a[],int n),viettoanam(float a[], int n);
void lonnhat(float a[], int n);
int main(){
	int n;
	do{
		printf("nhap n");
		scanf("%d",&n);
	}while(n>SIZE||n<=0);
	float a[n];
	/*goi ham cau a*/;nhapmang(a,n);printf("\n");
	/*goi ham cau b*/xuatmang(a,n);printf("\n");
	/*goi ham cau c*/printf("tong cac phan tu cua mang:  %.2f",tong(a,n));printf("\n");
	/*goi ham cau d*/printf("trung binh cong cac phan tu tai vi tri le:  %.2f",tbcvitrile(a,n));printf("\n");
	/*goi ham cau e*/printf("so phan tu duong trong mang la:  %d",demduong(a,n));printf("\n");
	/*goi ham cau f*/thututangdan(a,n);printf("\n");
	/*goi ham cau g*/invitrile(a,n);printf("\n");
	/*goi ham cau h*/vitricogiatrilakhong(a,n);printf("\n");
	/*goi ham cau i*/printf("gia tri lon nhat trong mang la: %.2f", max(a,n));printf("\n");
	/*goi ham cau j*/lonnhat(a,n);printf("\n");
	/*goi ham cau k*/incacvitrimax(a,n);printf("\n");
	//goi ham cau l;
	if (viettoanam(a,n)){
		printf("mang toan so am");
	}
	else{
		printf("mang khong toan la so am");
	}
	
	return 0;
}
//cau_a;
void nhapmang(float a[],int n){
	for (int i=0;i<n;i++){
		printf("A[%d]=",i);
		scanf("%f",&a[i]);
	}
}
//cau_b;
void xuatmang(float a[],int n){
	for (int i=0;i<n;i++){
		printf("A[%d]=%.2f\n",i,a[i]);
	}
}
//cau_c;
float tong(float a[], int n){
	float kq=0;
	for (int i=0;i<n;i++){
		kq+=a[i];
	}
	return kq;
}
//cau_d;
float tbcvitrile(float a[], int n){
	int dem=0;
	float tong=0;
	for (int i=0;i<n;i++){
		if (i%2!=0){
			dem++;
			tong+=a[i];
		}
	}
	return tong/dem;
}
//cau_e;
int demduong(float a[], int n){
	int dem=0;
	for (int i=0;i<n;i++){
		if (a[i]>0){
			dem++;
		}
	}
	return dem;
}
//cau_f;
void thututangdan(float a[], int n){
	for (int i=0;i<n-1;i++){
		for (int j=n-1;j>i;j--){
			if (a[j]<a[i]){
				float top=a[i];
				a[i]=a[j];
				a[j]=top;
			}
		}
	}
	printf("mang sau khi da sap xep tang dan: \n");
	
	for (int i=0;i<n;i++){
		printf("%.2f ",a[i]);
	}
}
//cau_g;
void invitrile(float a[], int n){
	printf("gia tri cua cac phan tu tai vi tri le:  ");
	for (int i=0;i<n;i++){
		if (i%2!=0){
			printf("%.2f  " ,a[i]);
		}
	}
}
//cau_h
void vitricogiatrilakhong(float a[], int n){
	printf("vi tri cua cac phan tu co gia tri la khong: ");
	for (int i=0;i<n;i++){
		if (a[i]==0){
			printf("%d ",i);
		}
	}
}
//cau_i;
float max(float a[], int n){
	int max=-1e9;
	for (int i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
}
//cau_j;
void lonnhat(float a[], int n){
	printf("vi tri dau tien co gia tri lon nhat trong mang la: ");
	for (int i=0;i<n;i++){
		if (a[i]==max(a,n)){
			printf("%d ",i);
			return;
		}
	}
}
//cau_k;
void incacvitrimax(float a[], int n){
	printf("vi tri cua cac phan tu co gia tri lon nhat: ");
	for (int i=0;i<n;i++){
		if (a[i]==max(a,n)){
			printf("%d ",i);
		}
	}
}
//cau_l;
int viettoanam(float a[], int n){
	for (int i=0;i<n;i++){
		if (a[i]>=0) return 0;
	}
	return 1;
}
