#include<stdio.h>
#include<conio.h>
void Print_Value(char*);
int Input1(char *A,int choice)
{
   if(choice>9){
    printf("               Invalid Index.\n               Please Input Again...");
    getch();
    system("cls");
    printf(" #######################################\n");
    printf(" ####                               ####\n");
    printf(" ####  WELCOME TO TIC TAC TOE GAME  ####\n");
    printf(" ####                               ####\n");
    printf(" #######################################\n\n");
    Print_Value(A);
    return(1);
   }
   else if(A[choice-1]=='0'||A[choice-1]=='X'){
            printf("               Same Index.\n               Please Try Again with Different Index");
            getch();
            system("cls");
            printf(" #######################################\n");
            printf(" ####                               ####\n");
            printf(" ####  WELCOME TO TIC TAC TOE GAME  ####\n");
            printf(" ####                               ####\n");
            printf(" #######################################\n\n");
            Print_Value(A);
            return(1);
        }
        else
            A[choice-1]='0';
            return(0);
}
int Input2(char *A,int choice)
{
    if(choice>9){
        printf("               Invalid Index.\n               Please Input Again...");
        getch();
        system("cls");
        printf(" #######################################\n");
        printf(" ####                               ####\n");
        printf(" ####  WELCOME TO TIC TAC TOE GAME  ####\n");
        printf(" ####                               ####\n");
        printf(" #######################################\n\n");
        Print_Value(A);
        return(1);
    }
   else if(A[choice-1]=='X'||A[choice-1]=='0'){
            printf("               Same Index.\n               Please Try Again with Different Index");
            getch();
            system("cls");
            printf(" #######################################\n");
            printf(" ####                               ####\n");
            printf(" ####  WELCOME TO TIC TAC TOE GAME  ####\n");
            printf(" ####                               ####\n");
            printf(" #######################################\n\n");
            Print_Value(A);
            return(1);
        }
    else
        A[choice-1]='X';
        return(0);
}
int Win1(char *A)
{
    if(A[0]==A[1]&&A[1]==A[2]&&A[0]=='0')
        return(1);
    else if(A[3]==A[4]&&A[4]==A[5]&&A[3]=='0')
            return(1);
    else if(A[6]==A[7]&&A[7]==A[8]&&A[6]=='0')
            return(1);
    else if(A[0]==A[3]&&A[3]==A[6]&&A[0]=='0')
            return(1);
    else if(A[1]==A[4]&&A[4]==A[7]&&A[1]=='0')
            return(1);
    else if(A[2]==A[5]&&A[5]==A[8]&&A[2]=='0')
            return(1);
    else if(A[0]==A[4]&&A[4]==A[8]&&A[0]=='0')
            return(1);
    else if(A[2]==A[4]&&A[4]==A[6]&&A[2]=='0')
            return(1);
    else
        return(0);
}
int Win2(char *A)
{
    if(A[0]==A[1]&&A[1]==A[2]&&A[0]=='X')
        return(1);
    else if(A[3]==A[4]&&A[4]==A[5]&&A[3]=='X')
            return(1);
    else if(A[6]==A[7]&&A[7]==A[8]&&A[6]=='X')
            return(1);
    else if(A[0]==A[3]&&A[3]==A[6]&&A[0]=='X')
            return(1);
    else if(A[1]==A[4]&&A[4]==A[7]&&A[1]=='X')
            return(1);
    else if(A[2]==A[5]&&A[5]==A[8]&&A[2]=='X')
            return(1);
    else if(A[0]==A[4]&&A[4]==A[8]&&A[0]=='X')
            return(1);
    else if(A[2]==A[4]&&A[4]==A[6]&&A[2]=='X')
            return(1);
    else
        return(0);
}
int Draw(char *A)
{
    int i;
    for(i=0;i<9;i++)
        if(A[i]!='X')
            if(A[i]!='0')
                return(0);
    return(1);
}
int Exit()
{
    int choice;
    printf("\n\n            1.Play Again");
    printf("\n            2.Exit");
    printf("\n\n            Enter Your Choice: ");
    scanf("%d",&choice);
    return(choice);
}
void Print_Value(char *A)
{
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            if(j==0)
                printf("                %c |",A[i*3+j]);
            else if(j==1)
                     printf(" %c |",A[i*3+j]);
            else
                printf(" %c",A[i*3+j]);
        if(i<2)
            printf("\n               ---|---|---\n");
    }

}
main()
{
    int choice1,choice2,x1,x2,x3;
    char A[9]={'1','2','3','4','5','6','7','8','9'},P1[15],P2[15];
    printf(" #######################################\n");
    printf(" ####                               ####\n");
    printf(" ####  WELCOME TO TIC TAC TOE GAME  ####\n");
    printf(" ####                               ####\n");
    printf(" #######################################\n\n");
    printf("       Enter 1st Player Name: ");
    gets(P1);
    printf("       Enter 2nd Player Name: ");
    gets(P2);
    printf("\n       Hi %s And %s.",P1,P2);
    printf("\n       Press Enter To Start The GAME...");
    getch();
    while(1){
        while(1){
            x1=x2=1;
            choice1=choice2=10;
            system("cls");
            printf(" #######################################\n");
            printf(" ####                               ####\n");
            printf(" ####  WELCOME TO TIC TAC TOE GAME  ####\n");
            printf(" ####                               ####\n");
            printf(" #######################################\n\n");
            Print_Value(A);
            while(x1){
                printf("\n\n               %s[0]: ",P1);
                scanf("%d",&choice1);
                x1=Input1(A,choice1);
            }
            system("cls");
            printf(" #######################################\n");
            printf(" ####                               ####\n");
            printf(" ####  WELCOME TO TIC TAC TOE GAME  ####\n");
            printf(" ####                               ####\n");
            printf(" #######################################\n\n");
            Print_Value(A);
            if(Win1(A)==1||Win2(A)==1||Draw(A)==1)
                break;
            while(x2){
                printf("\n\n               %s[X]: ",P2);
                scanf("%d",&choice2);
                x2=Input2(A,choice2);
            }
            if(Win1(A)==1||Win2(A)==1||Draw(A)==1)
                break;
        }
        if(Draw(A)==1)
            printf("\n\n               Match Draw");
        else if(Win1(A)==1)
            printf("\n         Congo %s[0] You Win.",P1);
        else
            printf("\n         Congo %s[X] You Win.",P2);
        getch();
        x3=3;
        while(x3!=1){
            system("cls");
            printf(" #######################################\n");
            printf(" ####                               ####\n");
            printf(" ####  WELCOME TO TIC TAC TOE GAME  ####\n");
            printf(" ####                               ####\n");
            printf(" #######################################\n\n");
            x3=Exit();
            switch(x3)
            {
            case 1:
                break;
            case 2:
                printf("            \nThank You.\n            Press Any Key to Exit.");
                getch();
                exit(0);
            default:
                printf("            Invalid choice,Please Try Again.");
                getch();
            break;

        }
        }
    }
}
