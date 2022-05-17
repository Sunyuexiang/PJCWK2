//
// Created by ASUS on 2022/5/16.
//
#include<stdio.h>
#include"Game.h"
#include"User_input.h"
#include"Users.h"

int Interface(){
    int a;
    while(1){
        printf("**************************************\n");
        printf("**    Welcome to 'Game of Life'     **\n");
        printf("**    Here are 3 kinds of way       **\n");
        printf("**  1. Fixed module (8x8  5 round)  **\n");
        printf("**  2. Loop module (8x8 X round)    **\n");
        printf("**  3. Free Module (XxX X round)    **\n");
        printf("**  4. Exit                         **\n");
        printf("**  Mention:X is depend your enter  **\n");
        printf("**************************************\n");
        printf("Enter your choose:");
        scanf("%d",&a);
        if(a != 1 && a != 2 && a != 3 && a !=4){
            printf("Wrong number. Please Re-Enter:");
            scanf("%d",&a);
            return 1;
        }
        else if(a == 1){
            Play();
            printf("The results will be presented at: 'Result.txt'\n");
        }
        else if(a == 2){
            User_Play();
            printf("The results will be presented at: 'User_Result.txt'\n");
        }
        else if(a == 3){
            Users_Crete();
            printf("The results will be presented at: 'Show.txt'\n");
        }
        else if(a==4){
            return 0;
        }
        printf("\n");
    }

}

void main(){
    Interface();
}
