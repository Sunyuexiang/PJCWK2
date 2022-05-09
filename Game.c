//
// Created by ASUS on 2022/4/28.
//

#include<stdio.h>

int High;
int Width;

void ReadFile(){
    FILE *fp = fopen("Initialize.txt", "r");
    for(int a = 0;a < 1; a++){
        fscanf(fp,"%d",&High);
        printf("%d\n",High);
    }
    fscanf(fp,"%d",&Width);
    printf("%d\n",Width);
    fclose(fp);
}

void Play(){
    int a,b;
    int Cells[High][Width];
    for(a = 0;a < High; a++){
        for(b = 0; b < Width; b++){
            Cells[a][b]= 1;
        }
    } //初始化所有的都为生
    int i,j;
    for(i = 1; i < High ;i++){
        for(j = 0; j < Width;j++){
            if(Cells[i][j] == 1){
                printf ("*");
            }
            else{
                printf (" ");
            }
        }
        printf("\n");
    }
}


int main(){
    ReadFile();
    Play();
    return 0;
}