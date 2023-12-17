#include<stdio.h>
#include<conio.h>

void check(char p , char s);

char a[9]={'1','2','3','4','5','6','7','8','9'};

void gamename() {
    printf("\n\t\t     Tic Tac Toe Game:\n");
}

void show() {
    printf("\n\n\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c \n", a[0],a[1],a[2]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c \n", a[3],a[4],a[5]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c \n" , a[6],a[7],a[8]);
    printf("\t\t\t---|---|---\n");
}
void inputsymbol() {
    printf("\nPlayer 1: X \n");
    printf("Player 2: 0 \n");
}
void start() {
    char pa;
    printf("\nWho wants to start the game (X or 0):\n");
    scanf("%c", &pa);
}
int count = 0 ;
void playgame() {
    char p , s;
    printf("\nEnter position & symbol:\n");
    fflush(stdin);
    scanf("%c", &p);
    fflush(stdin);
    scanf("%c", &s);
    count++;
    check(p,s);
}
void check(char p , char s) {
    int i;
    for ( i = 0 ; i <= 8 ; i++ ) {
        if ( a[i] == p ) {
            a[i] = s;
        }
    }
}

int end() {
    if ( (a[0] == 'X' && a[1] == 'X' && a[2] == 'X') || (a[0] == 'X' && a[3] == 'X' && a[6] == 'X') || a[0] == 'X' && a[4] == 'X' && a[8] == 'X' ) {
        return (100);
    } else if ( (a[0] == '0' && a[1] == '0' && a[2] == '0') || (a[0] == '0' && a[3] == '0' && a[6] == '0') || a[0] == '0' && a[4] == '0' && a[8] == '0' ) {
        return (200);
    } else if ( a[1] == 'X' && a[4] == 'X' && a[7] == 'X' ) {
        return (100);
    } else if ( a[1] == '0' && a[4] == '0' && a[7] == '0' ) {
        return (200);
    } else if ( a[2] == 'X' && a[5] == 'X' && a[8] == 'X' ) {
        return (100);
    } else if ( a[2] == '0' && a[5] == '0' && a[8] == '0' ) {
        return (200);
    } else if ( a[3] == 'X' && a[4] == 'X' && a[5] == 'X' ) {
        return (100);
    } else if ( a[3] == '0' && a[4] == '0' && a[5] == '0' ) {
        return (200);
    } else if ( a[2] == 'X' && a[4] == 'X' && a[6] == 'X' ) {
        return (100);
    } else if ( a[2] == '0' && a[4] == '0' && a[6] == '0' ) {
        return (200);
    } else if ( a[6] == 'X' && a[7] == 'X' && a[8] == 'X' ) {
        return (100);
    } else if ( a[6] == '0' && a[7] == '0' && a[8] == '0' ) {
        return (200);
    }
    return (300);
}

void main() {
    int k;
    char ch;

    label2:
    system("cls");
    gamename();
    show();
    inputsymbol();
    start();
    playgame();

    label:
    system("cls");
    show();
    playgame();
    k = end();
    system("cls");
    show();
    if ( count < 9 ) {
        if ( k == 100 ) {
            printf("\nPlayer 1 won!");
            count = 0;
        } else if ( k == 200 ) {
            printf("\nPlayer 2 won!");
            count = 0;
        } else {
            goto label;
        }
    } else {
        printf("\nGame Tied!");
        count = 0;
    }
    printf("\nDo you want to play again? (Y/N): ");
    fflush(stdin);
    scanf("%c", &ch);
    if ( ch == 'Y' || ch == 'y' ) {
        a[0]='1';
        a[1]='2';
        a[2]='3';
        a[3]='4';
        a[4]='5';
        a[5]='6';
        a[6]='7';
        a[7]='8';
        a[8]='9';
        goto label2;
    }
    printf("\nPress any key to exit: ");
    getch();
}
