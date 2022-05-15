//
// Created by ASUS on 2022/5/15.
//

#include<stdio.h>

int High;
int Width;

void Users_Crete(){
    int a,b;
    printf("Enter the Width :");
    scanf("%d", &High);
    printf("Enter the High :");
    scanf("%d",&Width);
    int User_Cells[High][Width];
    for(a = 0;a <= High; a++){
        for(b = 0;b < Width;b++){
            User_Cells[a][b] = 1;
        }
    }
    int i,j;
    for(i = 1; i <= High ;i++) {
        for (j = 0; j < Width; j++) {
            if (User_Cells[i][j] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    int Choose_High, Choose_Width;
    printf("All the cells are alive\n");
    printf("Choose the cells that you want it die from (1-%d,1-%d)\n", High, Width);
    scanf("%d,%d", &Choose_High, &Choose_Width);
    if (Choose_High <= 0 || Choose_High > High || Choose_Width <= 0 || Choose_Width > Width) {
        printf("Warning: Illegal Input\n");
        return;
    }
    else {
        User_Cells[Choose_High][Choose_Width-1] = 0;
    }
    for (i = 1; i <= High; i++) {
        for (j = 0; j < Width; j++) {
            if (User_Cells[i][j] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
    Users_Crete();
}