//
// Created by ASUS on 2022/5/15.
//

#include<stdio.h>
#include <stdlib.h>

int High;
int Width;

void Users_Crete(){
    //输入环境大小
    printf("Enter the Width :");
    scanf("%d", &High);
    printf("Enter the High :");
    scanf("%d", &Width);

    //生成环境
    int i,j;
    int Cells[High][Width];
    for(i = 0; i < High ;i++){
        for(j = 0; j < Width;j++){
            int c = rand()%2;
            if(c == 1){
                Cells[i][j] = c;
            }
            else{
                Cells[i][j] = c;
            }
        }
    }

    //手动输入循环Round次
    int d;
    int Round;
    printf("Enter the number that you want to loop:");
    scanf("%d",&Round);
    for(d = 0; d < Round;d++) {
        //建一个外部全是0的新二维数组
        int New_Cells[High + 2][Width + 2];
        for (i = 0; i < High + 2; i++) {
            for (j = 0; j < Width + 2; j++) {
                New_Cells[i][j] = 0;
            }
        }

        for (i = 1; i <= High; i++) {
            for (j = 1; j <= Width; j++) {
                New_Cells[i][j] = Cells[i - 1][j - 1];
            }
        }

        //改变生死
        int count;
        int temp[High][Width];
        for (i = 1; i <= High; i++) {
            for (j = 1; j <= Width; j++) {
                count = New_Cells[i - 1][j - 1] + New_Cells[i - 1][j] + New_Cells[i - 1][j + 1] + New_Cells[i][j - 1] +
                        New_Cells[i][j + 1]
                        + New_Cells[i + 1][j - 1] + New_Cells[i + 1][j] + New_Cells[i + 1][j + 1];
                if (count == 3) {
                    temp[i - 1][j - 1] = 1;
                } else if (count == 2) {
                    temp[i - 1][j - 1] = New_Cells[i][j];
                } else {
                    temp[i - 1][j - 1] = 0;
                }
            }
        }
        for (i = 0; i < High; i++) {
            for (j = 0; j < Width; j++) {
                Cells[i][j] = temp[i][j];
            }
        }
        FILE *fp = fopen("Show.txt", "a+");
        fputs("\n",fp);
        for (i = 0; i < High; i++) {
            for (j = 0; j < Width; j++) {
                if (Cells[i][j] == 1) {
                    fputs("1 ", fp);
                } else {
                    fputs("0 ", fp);
                }
            }
            fputs("\n", fp);
        }
        fputs("\n", fp);
        fclose(fp);
    }
}