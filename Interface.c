//
// Created by syx011020 on 22-5-20.
//

#include "Interface.h"
#include "Users_Create.h"
#include "User_Control.h"
#include <stdio.h>

int Interface(){
        printf("*********************************************\n");
        printf("**      Welcome to 'Game of Life'          **\n");
        printf("**      Here are 2 kinds of way            **\n");
        printf("**  1.   Random Generation(X*X Round X)    **\n");
        printf("**  2.   Click to Control(X*X Round X)     **\n");
        printf("**  3.   Exit                              **\n");
        printf("**      Mention:X is depend your enter     **\n");
        printf("*********************************************\n");
        printf("Enter your choose:");
}
int Choose(){
    int a;
    scanf("%d",&a);
    if(a != 1 && a != 2 && a != 3 && a !=4){
        printf("Wrong number,Restart\n");
        Interface();
        Choose();
    }
    else if(a == 1){
        User_Create();
        printf("The results will be presented at: 'Result.txt'\n");
        Interface();
        Choose();
    }
    else if(a == 2){
        Play_User_Control();
        printf("The results will be presented at: 'Show.txt.txt'\n");
        Interface();
        Choose();
    }
    else if(a == 3){
        printf("See You!");
        return 0;
    }
    printf("\n");
}


