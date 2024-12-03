#include<stdio.h>

int main() {
    int n;
    printf("Nhap so thoi gian hoc tap trong tuan (7 ngay): ");
    scanf("%d", &n);

    // lua thoi gian
    float thoigian[7];

    // tong gio
    float tonggio = 0;

    // thoi gian hoc tap nhieu nhat và it nhat
    float max_hours = 0, min_hours = 1000;
    int max_day = 0, min_day = 0;

    // thoi gian cho moi ngay
    for(int i = 0; i < 7; i++) {
        printf("Nhap thoi gian hoc tap cho ngay thu %d: ", i + 1);
        scanf("%f", &thoigian[i]);
    }

    // thoi gian hoc
    printf("Thoi gian hoc tap trong tuan:\n");
    for(int i = 0; i < 7; i++) {
        printf("Ngay %d: %.2f gio\n", i + 1, thoigian[i]);
    }

    // Tinh tong
    for(int i = 0; i < 7; i++) {
        tonggio += thoigian[i];

        // ngay nhieu nhat
        if(thoigian[i] > max_hours) {
            max_hours = thoigian[i];
            max_day = i;
        }

        // ngay it nhat
        if(thoigian[i] < min_hours) {
            min_hours = thoigian[i];
            min_day = i;
        }
    }

    // Tb hoc
    float tbgio = tonggio / 7;
    // in ra
    printf("Tong so gio hoc trong tuan: %d gio\n", tbgio);
    printf("Trung binh so gio hoc moi ngay: %.2f gio\n", giomoingay);
    printf("Ngay hoc nhieu nhat  %d gio hoc\n", max_day + 1, max_hours);
    printf("Ngay hoc it nhat  %d gio hoc\n", min_day + 1, min_hours);

    return 0;
}


    
    

