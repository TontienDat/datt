#include<stdio.h>
#include<stdlib.h>
 void nhapmang(int *a, int n);
 void xuatmang(int *a, int n);
 int tinhtong(int *a, int n);
 int timgiatrilonnhat(int *a, int n);
 int demmax(int *a, int n);
 int demsoluongxuathien(int *a, int n, int x);
 void sapxeptangdan(int *a, int n);
 void locdanhsacham(int *a, int n);
  int main(){
  	int n, x, *a;
  	do{
  		printf(" nhap so phan tu (n < 50): ");
  	scanf("%d",&n);
  	}while(n <= 0 || n>= 50 );
  	// cap phat
  	a = (int*),alloc(n * sizeof(int));
  	
  	// goi ham a
  	nhapmang(a,n);
  	
  	// goi ham b
  	xuatmang(a,n);
  	
  	// goi ham c
  	printf("tong cac phantu:%d\n", tinhtong(a,n));
  	
  	// goi ham d
  	printf("gia tri lon:%d\n",timgiatrilonnhat(a,n));
  	
  	// goi ham cau e
  	demmax(a,n);
  	
  	// goi ham f
  	printf(" nhap gia tri can dem ");
  	scanf("%d", &x);
  	printf(" so lan xuat hien: %d", x,demsoluongxuathien(int *a, int n, int x));
  	
  	// goi ham cau h
  	sapxeptangdan(a,n);
  	printf("sau khi sap xep:\n");
  	xuat(a,n);
  	
  	// goi ham cau i
  	locdanhsacham(a,n);
  	printf("sau khi loc so am:\n");
  	xuat(a,n);
  	
  }
    // nhapmang
    void nhapmang(int * a, int n);{
    	for(int i=0;i<n;i++){
    		printf("nhap phan tu %d: ",i++);
    		scanf("%d", &a[i]);
    	}
	}
	// xuatmang
	void xuatmang(int * a, int n);{
		printf("cac phan tu trong mang: ");
		for(int i=0;i<n;i++){
			printf("%d",a[i]);
		}
		return("\n");
	}
	// tinhtong
	int tinhtong(int *a, int n);{
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum+=a[i];
		}
		return sum;
	}
	// tim gia tri lon nhat
	int timgiatrilonnhat(int *a, int n);{
		int max = a[0];
		for(int i = 1; i < n; i++){
			if(a[i]>max){
				max = a[i];
			}
		}
		return max;
	}
	// demmax
	int demmax(int *a, int n);{
		int max+timmax(a,n);
		int dem=0
		for(int i=0;i<n;i++){
			if(a[i]==max)
			{
				dem++
			}
		}
		return dem;
	}
	// dem so luomg xuat hien x
	int demsoluongxuathien(int *a, int n, int x);{
	int count = 0;
	for(int i = 0; i < n; i++){
		if(a[i]== x){
			count++;
		}
	  }
	  return count;
	}
