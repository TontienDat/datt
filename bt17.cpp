#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void printValues(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void printEvenValues(int n) {
    for (int i = 2; i <= n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

void printMultiplesOfFive(int n) {
    for (int i = 5; i <= n; i += 5) {
        printf("%d ", i);
    }
    printf("\n");
}

void printPrimes(int n) {
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int sumValues(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}
int sumOddValues(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i += 2) {
        sum += i;
    }
    return sum;
}
int sumPrimes(int n) {
    int sum = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
float avgOddValues(int n) {
    int sum = 0;
    int count = 0;
    for (int i = 1; i <= n; i += 2) {
        sum += i;
        count++;
    }
    if (count == 0) return 0;
    return (float)sum / count;
}
float avgPrimes(int n) {
    int sum = 0;
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            sum += i;
            count++;
        }
    }
    if (count == 0) return 0;
    return (float)sum / count;
}

int main() {
    int n;
    printf("Nhap n (n < 100): ");
    scanf("%d", &n);
    if (n <= 0 || n >= 100) {
        printf("n phai là mot so nguyên duong và nho hon 100.\n");
        return 1;
    }

    printf("Gia tri tu 1 den n: ");
    printValues(n);
    printf("Gia tri chan tu 1 den n: ");
    printEvenValues(n);
    
    printf("Gia tri chia het cho 5 tu 1 den n: ");
    printMultiplesOfFive(n);

   
    printf("Cac so nguyen to nho hon n: ");
    printPrimes(n);

  
    printf("Tong cac gia tri tu 1 den n: %d\n", sumValues(n));

    
    printf("Tong cac so le tu 1 den n: %d\n", sumOddValues(n));

    
    printf("Tong cac so nguyen to nho hon n: %d\n", sumPrimes(n));

   
    printf("Trung binh cong cac so le tu 1 den n: %.2f\n", avgOddValues(n));

    
    printf("Trung binh cong cac so nguyen to nho hon n: %.2f\n", avgPrimes(n));

    return 0;
}

