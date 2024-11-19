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

int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10; 
        n /= 10;         
    }
    return sum;
}

int sumOddDigits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 != 0) {  
            sum += digit;
        }
        n /= 10;
    }
    return sum;
}


int sumPrimeDigits(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        if (isPrime(digit)) {  
            sum += digit;
        }
        n /= 10;
    }
    return sum;
}


int countZeroDigits(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 10 == 0) {
            count++;
        }
        n /= 10;
    }
    return count;
}


int countDivisibleByThreeDigits(int n) {
    int count = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 3 == 0) { 
            count++;
        }
        n /= 10;
    }
    return count;
}


int countDivisibleByFiveDigits(int n) {
    int count = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 5 == 0) {  
            count++;
        }
        n /= 10;
    }
    return count;
}

int main() {
    int n;

    
    printf("Nhap n (100 <= n < 10000): ");
    scanf("%d", &n);

    
    if (n < 100 || n >= 10000) {
        printf("n ph?i là m?t s? nguyên duong và th?a mãn 100 <= n < 10000.\n");
        return 1;
    }

   
    printf("Tong cac chu so cua n: %d\n", sumDigits(n));

    
    printf("Tong cac chu so le cua n: %d\n", sumOddDigits(n));

   
    printf("Tong cac chu so nguyen to cua n: %d\n", sumPrimeDigits(n));

   
    printf("So chu so 0 cua n: %d\n", countZeroDigits(n));

   
    printf("So chu so chia het cho 3 cua n: %d\n", countDivisibleByThreeDigits(n));

    
    printf("So chu so chia het cho 5 cua n: %d\n", countDivisibleByFiveDigits(n));

    return 0;
}

