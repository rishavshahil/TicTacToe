#include<stdio.h>
#include<conio.h>
#include<windows.h>
void Print_Value(char*);
int Input(char*,int,char);
int Win(char*,char);
int Draw(char*);
void Set_value(char*);
int Exit();
void Print_Title();
void Same_Index(char*);
void point(char*,char*);
void Computer(char*);
int Computer_turn_G3(char*,char);
int match,point1,point2,x=1,level,turn=0;
char P1[15],P2[15];
void Same_Index(char *A)
{
    printf("\n           Invalid or Same Index.\n           Please Try Again with Different Index");
    getch();
    system("cls");
    Print_Title();
    Print_Value(A);
}
void Print_Title()
{
  HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
  if(x==0){
    SetConsoleTextAttribute(h,5 | FOREGROUND_INTENSITY);
  printf("#############################################\n");
  printf("##                                         ##\n");
  printf("##");
  SetConsoleTextAttribute(h,9 | FOREGROUND_INTENSITY);
  printf("  MATCH= 0%d    SCORE:         Esc:       ",match);
  SetConsoleTextAttribute(h,5 | FOREGROUND_INTENSITY);
  printf("##\n");
  printf("##");
  SetConsoleTextAttribute(h,9 | FOREGROUND_INTENSITY);
  printf("               %-8s=%2d    Quit Game  ",P1,point1);
  SetConsoleTextAttribute(h,5 | FOREGROUND_INTENSITY);
  printf("##\n");
  printf("##");
  SetConsoleTextAttribute(h,9 | FOREGROUND_INTENSITY);
  printf("               %-8s=%2d               ",P2,point2);
  SetConsoleTextAttribute(h,5 | FOREGROUND_INTENSITY);
  printf("##\n");
  printf("##                                         ##\n");
  printf("#############################################\n\n");}
  else{
        SetConsoleTextAttribute(h,5 | FOREGROUND_INTENSITY);
  printf("#############################################\n");
  printf("##                                         ##\n");
  printf("##");
  SetConsoleTextAttribute(h,9 | FOREGROUND_INTENSITY);
  printf("       WELCOME TO TIC TAC TOE GAME       ");
  SetConsoleTextAttribute(h,5 | FOREGROUND_INTENSITY);
  printf("##\n");
  printf("##");
  SetConsoleTextAttribute(h,9 | FOREGROUND_INTENSITY);
  printf("          [Developed by Rishav]          ");
  SetConsoleTextAttribute(h,5 | FOREGROUND_INTENSITY);
  printf("##\n");
  printf("##                                         ##\n");
  printf("#############################################\n\n");}
  SetConsoleTextAttribute(h,3 | FOREGROUND_INTENSITY);
}
int menu()
{
    int choice=0;
    while(choice>2||choice<=0){
        system("cls");
        Print_Title();
        printf("            1.Play with PC");
        printf("\n            2.Play with Two Player");
        printf("\n\n            Enter your choice: ");
        choice=getch();
        printf("%c",choice);
        for(int i=0;i<30000;i++)
            for(int j=7;j<5000;j++);
        if(choice-48>2||choice-48<0){
            printf("\n            Invalid choice. Try Again.");
            getch();
            }
        choice=choice-48;
    }
    return(choice);
}
int Exit()
{
    int choice;
    printf("\n\n            1.Play Again");
    printf("\n            2.Main Menu");
    printf("\n            3.Exit");
    printf("\n\n            Enter Your Choice: ");
    choice=getch();
    for(int i=0;i<30000;i++)
        for(int j=7;j<5000;j++);
    printf("%c",choice);
    return(choice-48);
}
void print_keypad()
{
    printf("      USE THIS PATTERN TO PLAY THE GAME\n\n");
    int i,j,A[9]={7,8,9,4,5,6,1,2,3};
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++)
            if(j==0)
                printf("               [%d] ",A[i*3+j]);
            else
                printf(" [%d] ",A[i*3+j]);
        printf("\n\n");
    }
    printf("          Press Any Key to continue.");
    getch();
}
void Print_Value(char *A)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int i,j;
    printf("           %s[",P1);
    SetConsoleTextAttribute(h,2 | FOREGROUND_INTENSITY);
    printf("O");
    SetConsoleTextAttribute(h,3 | FOREGROUND_INTENSITY);
    printf("] VS ");
    printf("%s[",P2);
    SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("X");
    SetConsoleTextAttribute(h,3 | FOREGROUND_INTENSITY);
    printf("]\n");
    if(level!=0){
        if(level==1)
        printf("               LEVEL-[EASY]\n\n",P1,P2);
        else if(level==2)
              printf("               LEVEL-[MODERATE]\n\n");
             else
                printf("                LEVEL-[HARD]\n\n");
            SetConsoleTextAttribute(h,6 | FOREGROUND_INTENSITY);

    }
    else{
        SetConsoleTextAttribute(h,6 | FOREGROUND_INTENSITY);
        printf("\n");
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            if(A[i*3+j]=='X'){
                SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
                if(j==0){
                    printf("                 %c ",A[i*3+j]);
                    SetConsoleTextAttribute(h,6 | FOREGROUND_INTENSITY);
                    printf("|");
                }
                else if(j==1){
                        printf(" %c ",A[i*3+j]);
                        SetConsoleTextAttribute(h,6 | FOREGROUND_INTENSITY);
                        printf("|");
                    }
                else
                    printf(" %c",A[i*3+j]);
                SetConsoleTextAttribute(h,6 | FOREGROUND_INTENSITY);
            }
            else if(A[i*3+j]=='O'){
                    SetConsoleTextAttribute(h,2 | FOREGROUND_INTENSITY);
                    if(j==0){
                        printf("                 %c ",A[i*3+j]);
                        SetConsoleTextAttribute(h,6 | FOREGROUND_INTENSITY);
                        printf("|");
                    }
                else if(j==1){
                        printf(" %c ",A[i*3+j]);
                        SetConsoleTextAttribute(h,6 | FOREGROUND_INTENSITY);
                        printf("|");
                    }
                else
                    printf(" %c",A[i*3+j]);
                    SetConsoleTextAttribute(h,6 | FOREGROUND_INTENSITY);
                }
            else{
                if(j==0)
                    printf("                 %c |",A[i*3+j]);
                else if(j==1)
                     printf(" %c |",A[i*3+j]);
                else
                    printf(" %c",A[i*3+j]);
            }
        if(i<2)
            printf("\n                ---|---|---\n");
    }
    SetConsoleTextAttribute(h,3 | FOREGROUND_INTENSITY);

}
int Input(char *A,int choice,char I)
{
    int x=0;
    if(choice<7&&choice>3)
        x=1;
    if(choice<1||choice>9){
        Same_Index(A);
    }
    else if(x>0&&A[choice-1]=='O'||x>0&&A[choice-1]=='X'){
            Same_Index(A);
            return(1);
        }
    else if(A[choice-7]=='O'||A[choice-7]=='X'){
            Same_Index(A);
            return(1);
    }
    else if(A[choice+5]=='O'||A[choice+5]=='X'){
            Same_Index(A);
            return(1);
        }
    else{
        if(choice<4)
            A[choice+5]=I;
        else if(choice>6)
                A[choice-7]=I;
             else
                A[choice-1]=I;
        return(0);
    }
}
int Win(char *A,char W)
{
    if((A[0]==A[1]&&A[1]==A[2]&&A[0]==W)||
       (A[3]==A[4]&&A[4]==A[5]&&A[3]==W)||
       (A[6]==A[7]&&A[7]==A[8]&&A[6]==W)||
       (A[0]==A[3]&&A[3]==A[6]&&A[0]==W)||
       (A[1]==A[4]&&A[4]==A[7]&&A[1]==W)||
       (A[2]==A[5]&&A[5]==A[8]&&A[2]==W)||
       (A[0]==A[4]&&A[4]==A[8]&&A[0]==W)||
       (A[2]==A[4]&&A[4]==A[6]&&A[2]==W))
        return(1);
    else
        return(0);
}
int Draw(char *A)
{
    int i;
    for(i=0;i<9;i++)
        if(A[i]!='X')
            if(A[i]!='O')
                return(0);
    return(1);
}
void Set_value(char *A)
{
  //char B[9]={'7','8','9','4','5','6','1','2','3'};
  //for(int i=0;i<=8;i++)
    //   A[i]=B[i];
  //For Blank TIC TAC TOE
  for(int i=0;i<=8;i++)
    A[i]=32;
}

//FOR COMPUTER CODE:
void Computer(char *A)
{
    int S,R=0;
    if(level==1)
        while(1){
            fflush(stdin);
            R=rand()%9;
            if(A[R]!='X')
                if(A[R]!='O'){
                    A[R]='X';
                    break;
                }
        }
    else if(level==2)
              if(Computer_turn_G3(A,'X')==1)
                 R=0;
              else{
                if(Computer_turn_G3(A,'O')==0)
                    while(1){
                        fflush(stdin);
                        R=rand()%9;
                        if(A[R]!='X')
                            if(A[R]!='O'){
                                A[R]='X';
                                break;
                        }
                    }
            }
    else{
        if(turn==1){
            if(A[4]!='O')
                A[4]='X';
            else
                A[0]='X';
        }
        else if(Computer_turn_G3(A,'X')==1)
                 R=0;
        else if(Computer_turn_G3(A,'O')==1)
                 R=0;
        else if(turn==2&&A[8]=='O'){
                if(A[4]=='X')
                    A[3]='X';
                else
                   A[6]='X';
            }
       // else if(turn==2&&A[3]!='O')
       //        A[3]='X';
        else {
            if(Computer_turn_G3(A,'O')==0)
                while(1){
                fflush(stdin);
                R=rand()%9;
                if(A[R]!='X')
                    if(A[R]!='O'){
                        A[R]='X';
                        break;
                    }
                }
            }
        }
}
int Computer_turn_G3(char *A,char C)//Here we Check if Opponent is in the win condition
{                                   //then computer's next move
    if(A[1]==C&&A[2]==C||A[3]==C&&A[6]==C||A[4]==C&&A[8]==C)
        if(A[0]!='X')
            if(A[0]!='O'){
                A[0]='X';
                return 1;
            }
    if(A[4]==C&&A[7]==C||A[0]==C&&A[2]==C)
            if(A[1]!='X')
                if(A[1]!='O'){
                    A[1]='X';
                    return 1;
                }
    if(A[0]==C&&A[1]==C||A[5]==C&&A[8]==C||A[4]==C&&A[6]==C)
            if(A[2]!='X')
                if(A[2]!='O'){
                    A[2]='X';
                    return 1;
                }

     if(A[4]==C&&A[5]==C||A[6]==C&&A[0]==C)
             if(A[3]!='X')
                if(A[3]!='O'){
                    A[3]='X';
                    return 1;
                }
    if(A[1]==C&&A[7]==C||A[3]==C&&A[5]==C||A[6]==C&&A[2]==C||A[0]==C&&A[8]==C)
            if(A[4]!='X')
                if(A[4]!='O'){
                    A[4]='X';
                    return 1;
                }
    if(A[2]==C&&A[8]==C||A[4]==C&&A[3]==C)
            if(A[5]!='X')
                if(A[5]!='O'){
                    A[5]='X';
                    return 1;
                }
    if(A[4]==C&&A[2]==C||A[8]==C&&A[7]==C||A[0]==C&&A[3]==C)
            if(A[6]!='X')
                if(A[6]!='O'){
                    A[6]='X';
                    return 1;
                }
    if(A[4]==C&&A[1]==C||A[6]==C&&A[8]==C)
            if(A[7]!='X')
                if(A[7]!='O'){
                    A[7]='X';
                    return 1;
                }
    if(A[6]==C&&A[7]==C||A[4]==C&&A[0]==C||A[2]==C&&A[8]==C)
            if(A[8]!='X')
                if(A[8]!='O'){
                    A[8]='X';
                    return 1;
                }
    return 0;
}
void Set_Level()
{
    while(level>3||level<=0){
    system("cls");
    Print_Title();
    printf("               1.EASY");
    printf("\n               2.MODERATE");
    printf("\n               3.HARD");
    printf("\n\n               Enter Level: ");
    level=getch();
    for(int i=0;i<30000;i++)
        for(int j=7;j<5000;j++);
    printf("%c",level);
    if(level-48>3||level-48<0){
        printf("\n               Invalid Level.Try Again");
    getch();}
    level=level-48;
    }
}
void main()
{
     HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,3 | FOREGROUND_INTENSITY);
    while(1){
        int x1,x2,x3,choice1,choice2,Comp;
        char A[9];
        system("cls");
        fflush(stdin);
        x=1;
        Comp=menu();
        level=0;
        if(Comp==1){
           Set_Level();
           system("cls");
           Print_Title();
           printf("          Enter Your Name: ");
           gets(P1);
           printf("\n          Hi %s.",P1);
           strcpy(P2,"COMPUTER");
        }
        else{
            system("cls");
            Print_Title();
            printf("          Enter 1st Player Name: ");
            gets(P1);
            printf("          Enter 2nd Player Name: ");
            gets(P2);
            printf("\n          Hi %s And %s.",P1,P2);
        }
        printf("\n          Press Enter To Start The GAME...");
        getch();
        system("cls");
        Print_Title();
        print_keypad();
        match=1;
        point1=point2=0;
        while(1){
            Set_value(A);
            x=0;
            turn=0;
            while(1){
                x1=x2=1;
                choice1=choice2=10;
                system("cls");
                Print_Title();
                Print_Value(A);
                while(x1){
                    SetConsoleTextAttribute(h,2 | FOREGROUND_INTENSITY);
                    printf("\n\n                 %s[O]: ",P1);
                    SetConsoleTextAttribute(h,3 | FOREGROUND_INTENSITY);
                    choice1=getch();
                    for(int i=0;i<30000;i++)
                           for(int j=7;j<5000;j++);
                    if(choice1==27)
                        break;
                    x1=Input(A,choice1-48,'O');
                }
                system("cls");
                Print_Title();
                Print_Value(A);
                if(choice1==27)
                        break;
                if(Win(A,'O')==1||Win(A,'X')==1||Draw(A)==1)
                    break;
                if(Comp==1){
                        for(int i=0;i<30000;i++)
                           for(int j=7;j<5000;j++);
                    turn++;
                    Computer(A);
                }
                else
                    while(x2){
                        SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
                        printf("\n\n                 %s[X]: ",P2);
                        SetConsoleTextAttribute(h,3 | FOREGROUND_INTENSITY);
                        choice2=getch();
                        if(choice2==27)
                            break;
                        x2=Input(A,choice2-48,'X');
                    }
                system("cls");
                Print_Title();
                Print_Value(A);
                if(choice2==27)
                        break;
                if(Win(A,'O')==1||Win(A,'X')==1||Draw(A)==1)
                    break;
            }
            if(choice1==27||choice2==27){
                if(Comp==1)
                        point2+=10;
                printf("\n\n                GAME OVER!!");
            }
            else if(Win(A,'O')==1){
                    point1+=10;
                    SetConsoleTextAttribute(h,2 | FOREGROUND_INTENSITY);
                    printf("\n\n           Congratulation %s[O]\n                  You Win!!",P1);
                    SetConsoleTextAttribute(h,3 | FOREGROUND_INTENSITY);
                }
            else if(Draw(A)==1){
                    point1+=5;
                    point2+=5;
                    printf("\n\n                Match Draw!!");
                }
            else {
                point2+=10;
                if(Comp==1)
                    printf("\n\n                 You Lose!!");
                else{
                    SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
                    printf("\n\n           Congratulation %s[X]\n                  You Win!!",P2);
                    SetConsoleTextAttribute(h,3 | FOREGROUND_INTENSITY);
                }
            }
            getch();
            while(1){
                system("cls");
                Print_Title();
                x3=Exit();
                switch(x3)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    printf("\n            Thank You.\n            Press Any Key to Exit.");
                    getch();
                    exit(0);
                default:
                    printf("\n            Invalid choice,Please Try Again.");
                    getch();
                    break;
                }
                if(x3==1||x3==2)
                    break;
            }
            if(x3==2)
                break;
            match+=1;
        }
    }
}
