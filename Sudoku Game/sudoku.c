
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"sudoku.h"

u8 Mistakes;
u32 Scores;
u32 Sudoku[SIZE][SIZE];
u32 original_Sudoku[SIZE][SIZE] = {
        {5, 3, 0,   0, 7, 0,   0, 0, 0},
        {6, 0, 0,   1, 9, 5,   0, 0, 0},
        {0, 9, 8,   0, 0, 0,   0, 6, 0},

        {8, 0, 0,   0, 6, 0,   0, 0, 3},
        {4, 0, 0,   8, 0, 3,   0, 0, 1},
        {7, 0, 0,   0, 2, 0,   0, 0, 6},

        {0, 6, 0,   0, 0, 0,   2, 8, 0},
        {0, 0, 0,   4, 1, 9,   0, 0, 5},
        {0, 0, 0,   0, 8, 0,   0, 7, 9}
};



void draw_Sudoku()
{
    printf("\n\n\n\n\n\n\n\n\n\n");
    setColor(11,0);
    printf("\t\t\t\t\t\t\t Welcome--->  SSSSS  UU   UU  DDDDDD     OOOOOO   KK    KK  UU   UU     \n");//  GGGGG        A         M    M    EEEEEE\n");
    setColor(7,0);
    printf("\t\t\t\t\t\t\t             SS      UU   UU  DD    DD  OO    OO  KK  KK    UU   UU     \n"); //GG          AA AA       MM   MM   EE   \n");
     setColor(11,0);
    printf("\t\t\t\t\t\t\t              SSSSS  UU   UU  DD    DD  OO    OO  KKK       UU   UU      \n");//GG  GGGGG  AAAAAAA     MM  M  MM  EEEEEE\n");
     setColor(7,0);
    printf("\t\t\t\t\t\t\t                  SS UU   UU  DD    DD  OO    OO  KK  KK    UU   UU     \n");// GG   GG    AA     AA   MM     MM  EE   \n");
    setColor(11,0);
    printf("\t\t\t\t\t\t\t              SSSSS    UUUU   DDDDDD     OOOOOO   KK    KK    UUU     <----game\n");// GGGGG     AA       AA  MM     MM  EEEEEE\n");
    setColor(15,0);
}


void draw_GameOver() {
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t        GGGGG    A    M     M  EEEEE       OOO   V     V  EEEEE  RRRR  \n");
    printf("\t\t\t\t\t\t\t       G        A A   MM   MM  E          O   O   V   V   E      R   R \n");
    printf("\t\t\t\t\t\t\t       G   GG  AAAAA  M M M M  EEEEE     O     O   V V    EEEEE  RRRR  \n");
    printf("\t\t\t\t\t\t\t       G    G  A   A  M  M  M  E          O   O     V     E      R  R  \n");
    printf("\t\t\t\t\t\t\t        GGGG   A   A  M     M  EEEEE       OOO      V     EEEEE  R   R \n");
}

void drow_YouWin()
{
    setColor(9,0);
    printf("\t\t\t\t\t\t\t                                                                        ###  \n");
    setColor(6,0);
    printf("\t\t\t\t\t\t\t                                                                       ##*## \n");
    setColor(6,0);
    printf("\t\t\t\t\t\t\t     EXCELLENT                                                        ##win##\n");
    setColor(9,0);
    printf("\t\t\t\t\t\t\t           YY    YY   OOOO   UU    UU    WW     WW IIIIII NN    NN     ##*##.\n");
    setColor(6,0);
    printf("\t\t\t\t\t\t\t            YY  YY  OO    OO UU    UU    WW     WW   II   NNN   NN    ..###..\n");
    setColor(9,0);
    printf("\t\t\t\t\t\t\t              YY    OO    OO UU    UU    WW  W  WW   II   NN NN NN    ...#...\n");
    setColor(6,0);
    printf("\t\t\t\t\t\t\t              YY    OO    OO UU    UU    WW W W WW   II   NN   NNN    ...#...\n");
    setColor(9,0);
    printf("\t\t\t\t\t\t\t              YY      OOOO     UUUU      W       W IIIIII NN    NN    ..###.. CONGRATULATION\n");

    setColor(15,4);
    printf("\n\n\t\t\t\t\t\t\t\t\t Your Mistakes:%d/3  ",Mistakes);
    setColor(15,2);
    printf(" Your Total Score:%d      ",Scores);
}

void Sudokuo_ifwin() {                 //if user win print
printf("\n\n\n\n\n\n");
int startX = 78;
int startY = 18;
drow_YouWin();
for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            setCursorPosition(startX + j * 4, startY + i * 2);
            if (original_Sudoku[i][j] != 0) {
                setColor(0, 2);
                printf(" %d ", Sudoku[i][j]);
            } else {
                setColor(7, 8);
                printf("   ");
            }
        }
        printf("\n");
    }


printf("\n");


}
void setFullScreen() {
    // الحصول على مقبض نافذة CMD
    HWND consoleWindow = GetConsoleWindow();

    // الحصول على حجم الشاشة
    RECT screenRect;
    GetWindowRect(GetDesktopWindow(), &screenRect);
    int screenWidth = screenRect.right;
    int screenHeight = screenRect.bottom;

    // تحريك وتغيير حجم نافذة CMD لتغطي الشاشة
    MoveWindow(consoleWindow, 0, 0, screenWidth, screenHeight, TRUE);
}
// دالة لتحريك المؤشر إلى موقع معين
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(hConsole, position);
}
void setColor(u32 textColor, u32  backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = textColor + (backgroundColor * 16);
    SetConsoleTextAttribute(hConsole, colorAttribute);
}

void refresh()
{

    Scores=0;
    Mistakes=0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            Sudoku[i][j] = original_Sudoku[i][j];
        }
    }
}
void sudoku_print(u32 Sudoku[SIZE][SIZE])
{
int startX = 80;
int startY = 18;
setCursorPosition(startX,startY );
    setColor(15,4);
    printf("  Mistakes:%d/3   ",Mistakes);
    setColor(15,2);
    printf("   Scores:%d   \n",Scores);

    setColor(0,0);

u8 row,col;

setCursorPosition(startX,++startY );
            setColor(15,8);
            printf("R/C| C0 C1 C2   C3 C4 C5   C6 C7 C8\n");
        setColor(0,11);
    for (row = 0; row<SIZE; row++)
    {
        setCursorPosition(startX,++startY );
        if (row%3==0&&row!=0) {
         setCursorPosition(startX,startY );
         setColor(15,8);
         printf("----");
         setColor(0,11);
            printf("-------------------------------\n");
            setCursorPosition(startX,++startY );
               setColor(15,8);
             printf("R%d |",row);
             setColor(0,11);
        }
        else
        {
            setColor(15,8);
            printf("R%d |",row);
            setColor(0,11);

        }
        for (col= 0; col<SIZE; col++)
        {

            if (col % 3 == 0 && col != 0) {
                printf("| ");
            }
            if(original_Sudoku[row][col] != 0) {
                setColor(0,9); // نص أسود وخلفية خضراء للخانات الثابتة
                printf(" %d ", Sudoku[row][col]);
                setColor(15,11);
            }
            else {
                setColor(0, 11); // نص أسود وخلفية بيضاء للخانات القابلة للتعديل
                printf(" %d ", Sudoku[row][col]);
                setColor(15,11);
            }

        }
        printf("\n");
    }
     setColor(15,0);
}
u8  Sudoku_RowSearch(u32 row,u32 item)
{
    u8 i;
    for(i=0; i<SIZE; i++)
    {
        if(Sudoku[row][i]==item)
        {   //printf("%d  %d ",row,i);
            return 1;
        }
    }
    return 0;
}

u8  Sudoku_ColSearch(u32 col,u32 item)
{
    u8 i;
    for(i=0; i<SIZE; i++)
    {
        if(Sudoku[i][col]==item)
        {
            //printf("%d  %d ",i,col);
            return 1;
        }
    }
    return 0;
}

u8  Sudoku_BoxSearch(u32 row,u32 col,u32 item)
{
    u8 i,j;
    if(row<3&&col<3)
    {
        for(i=0;i<3; i++)
        {
            for(j=0;j<3; j++)
            {
                if(Sudoku[i][j]==item)
                {
                   // printf("%d  %d ",i,j);
                    return 1;
                }
            }

        }

    }
    else if(row<3&&col>=3&&col<6)
    {
        for(i=0;i<3; i++)
        {
            for(j=3;j<6; j++)
            {
                if(Sudoku[i][j]==item)
                {
                    //printf("%d  %d ",i,j);
                    return 1;
                }
            }

        }

    }
    else if(row<3&&col>=6&&col<9)
    {
        for(i=0;i<3; i++)
        {
            for(j=6;j<9; j++)
            {
                if(Sudoku[i][j]==item)
                {
                    //printf("%d  %d ",i,j);
                    return 1;
                }
            }

        }

    }
    else if(row>=3&&row<6&&col<3)
    {
        for(i=3;i<6; i++)
        {
            for(j=0;j<3; j++)
            {
                if(Sudoku[i][j]==item)
                {
                    //printf("%d  %d ",i,j);
                    return 1;
                }
            }

        }

    }
    else if(row>=3&&row<6&&col>=3&&col<6)
    {
        for(i=3;i<6; i++)
        {
            for(j=3;j<6; j++)
            {
                if(Sudoku[i][j]==item)
                {
                    //printf("%d  %d ",i,j);
                    return 1;
                }
            }

        }

    }
    else if(row>=3&&row<6&&col>=6&&col<9)
    {
        for(i=3;i<6; i++)
        {
            for(j=6;j<9; j++)
            {
                if(Sudoku[i][j]==item)
                {
                   // printf("%d  %d ",i,j);
                    return 1;
                }
            }

        }

    }
    else if(row>=6&&row<9&&col<3)
    {
        for(i=6;i<9; i++)
        {
            for(j=0;j<3; j++)
            {
                if(Sudoku[i][j]==item)
                {
                    //printf("%d  %d ",i,j);
                    return 1;
                }
            }

        }

    }
    else if(row>=6&&row<9&&col>=3&&col<6)
    {
        for(i=6;i<9; i++)
        {
            for(j=3;j<6; j++)
            {
                if(Sudoku[i][j]==item)
                {
                    //printf("%d  %d ",i,j);
                    return 1;
                }
            }

        }

    }
    else if(row>=6&&row<9&&col>=6&&col<9)
    {
        for(i=6;i<9; i++)
        {
            for(j=6;j<9; j++)
            {
                if(Sudoku[i][j]==item)
                {
                   // printf("%d  %d ",i,j);
                    return 1;
                }
            }

        }

    }

    return 0;
}

u8 Sudoku_isSolved(u32 arr[][SIZE])
{
    u32 row,col;


    for (row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (arr[row][col] == 0)
            {
                return 0;
            }
        }
    }


    for (row = 0; row < SIZE; row++)
    {
        for (col = 0; col < SIZE; col++)
        {

            for (int i = 0; i < SIZE; i++)
            {
                if (i != col && arr[row][i] == arr[row][col])
                    return 0;
            }


            for (int j = 0; j < SIZE; j++)
            {
                if (j != row && arr[j][col] == arr[row][col])
                    return 0;
            }


            int startRow = row - row % 3, startCol = col - col % 3;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (i + startRow != row && j + startCol != col && arr[i + startRow][j + startCol] == arr[row][col])
                    {
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

