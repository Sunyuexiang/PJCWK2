//
// Created by ASUS on 2022/4/28.
//

#include<stdio.h>
#include<stdlib.h>

void Play(){
    //初始化
    int High;
    int Width;
    int Round;
    //读取文件
    FILE *fp = fopen("Initialize.txt", "r");
    if(fp == NULL){
        printf("No FILE\n");
        return;
    }
    fscanf(fp,"%d",&High);
    printf("%d\n",High);
    fscanf(fp,"%d",&Width);
    printf("%d\n",Width);
    fscanf(fp,"%d",&Round);
    printf("%d\n",Round);
    printf("\n");
    fclose(fp);
    //生成正常环境
    int i,j;
    int Cells[High][Width];
    for(i = 0; i < High ;i++){
        for(j = 0; j < Width;j++){
            int c = rand()%2;
            if(c == 1){
                printf ("1 ");
                Cells[i][j] = c;
            }
            else{
                printf ("0 ");
                Cells[i][j] = c;
            }
        }
        printf("\n");
    }
    printf("\n");
    //循环Round次
    int d;
    for(d = 0; d < Round;d++){
        //建一个外部全是0的新二维数组
        int New_Cells[High+2][Width+2];
        for(i  = 0;i < High+2;i++){
            for(j = 0; j < Width+2;j++){
                New_Cells[i][j] = 0;
            }
        }

        for(i = 1; i <= High; i++){
            for(j = 1; j <= Width; j++){
                New_Cells[i][j] = Cells[i-1][j-1];
            }
        }

        for(i = 0;i < High+2;i++) {
            for (j = 0; j < Width+2; j++) {
                if (New_Cells[i][j] == 1) {
                    printf("1 ");
                } else {
                    printf("0 ");
                }
            }
            printf("\n");
        }
        printf("\n");
        //改变生死
        int count;
        int temp[High][Width];
        for(i = 1;i <= High;i++){
            for(j = 1;j <= Width;j++){
                count=New_Cells[i-1][j-1]+New_Cells[i-1][j]+New_Cells[i-1][j+1]+New_Cells[i][j-1]+New_Cells[i][j+1]
                      +New_Cells[i+1][j-1]+New_Cells[i+1][j]+New_Cells[i+1][j+1];
                if(count == 3){
                    temp[i-1][j-1] = 1;
                }
                else if(count == 2){
                    temp[i-1][j-1] = New_Cells[i][j];
                }
                else{
                    temp[i-1][j-1] = 0;
                }
            }
        }
        for(i = 0;i < High;i++) {
            for (j = 0; j < Width; j++) {
                Cells[i][j] = temp[i][j];
            }
        }
        for(i = 0;i < High;i++) {
            for (j = 0; j < Width; j++) {
                if (Cells[i][j] == 1) {
                    printf("1 ");
                } else {
                    printf("0 ");
                }
            }
            printf("\n");
        }
    printf("\n");
    }
}

void main(){
    Play();
    return;
}