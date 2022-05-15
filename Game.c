//
// Created by ASUS on 2022/4/28.
//

/*#include<stdio.h>

int High;
int Width;
int Cells[High][Width];
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
                printf ("1 ");
            }
            else{
                printf ("0 ");
            }
        }
        printf("\n");
    }
}

void Change(){
    int i,j;
    int count;
    int temp[High][Width];
    for(i=1;i<High;i++)
    {
        for(j=1;j<Width;j++)
        {
            count=Cells[i-1][j-1]+Cells[i-1][j]+Cells[i-1][j+1]+Cells[i][j-1]+Cells[i][j+1]+Cells[i+1][j-1]
                    +Cells[i+1][j]+Cells[i+1][j+1];
            if(count == 3)
                temp[i][j]=1;
            else if(count == 2)
                    temp[i][j]=Cells[i][j];
            else
            temp[i][j]=0;
        }
    }
    for(i=1;i<High;i++)
        for(j=1;j<Width;j++)
            Cells[i][j]=temp[i][j];
}

int main(){
    ReadFile();
    Play();
    return 0;
}*/