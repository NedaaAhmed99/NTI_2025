#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include"Sudoku.h"

extern u8 Mistakes;
extern  u32 Sudoku[SIZE][SIZE];
extern u32 Scores;
extern u32 original_Sudoku[SIZE][SIZE];

int main()
{

    refresh();
    u32 row,col,value,ret;
    u8 ch;
    sudoku_print(Sudoku);
    while(1)
    {
        setFullScreen();
        system("cls");
        draw_Sudoku();
        sudoku_print(Sudoku);
        printf("\n\n\t\t\t\t\t\t<=======*******************************************************************************======>");
        setColor(9, 0);
        printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter Row(0-8):");
        scanf(" %u",&row);
        printf("\t\t\t\t\t\t\t\t\t\tEnter Col(0-8):");
        scanf(" %u",&col);
        printf("\t\t\t\t\t\t\t\t\t\tEnter Value(1-9):");

        scanf(" %u",&value);
        if(row>=9||row<0||col>=9||col<0||value>9||value<=0)
        {
            printf("\t\t\t\t\t\t\t\t\t\tNot allowed Press 'y' to continue:");
            scanf(" %c",&ch);
            if(ch=='y'||ch=='Y')
            {
                continue;
            }
            else

                break;
        }

        if(Sudoku_isSolved(Sudoku))
        {
            system("cls");
            Sudokuo_ifwin();
            setColor(4, 0);
             printf("\n\n\t\t\t\t\t\t\t<=======*******************************************************************************======>");
             setColor(6, 0);
            printf("\n\n\t\t\t\t\t\t\t\t\t\tPress 'y' to Play again:\n");
            printf("\t\t\t\t\t\t\t\t\t\tPress 'q' to quit:\n\t\t\t\t\t\t\t\t\t\t====>");
            fflush(stdin);
            scanf("%c",&ch);
            setColor(15,0);
            if(ch=='y'||ch=='Y')
            {
                refresh();
                continue;
            }
            else

                break;
        }

        if(Sudoku_RowSearch(row,value)||Sudoku_ColSearch(col,value)||Sudoku_BoxSearch(row,col,value))
        {
            Mistakes++;
            if(original_Sudoku[row][col]==0)
            {
                Sudoku[row][col]=value;
            }
            else
             {
                printf("\t\t\t\t\t\t\t\t\t\tyou can not edit this cell Press 'y' to continue:");
                scanf(" %c",&ch);
                if(ch=='y'||ch=='Y')
                {
                continue;
               }
               else

                break;
            }

        }
        else
        {
            if(original_Sudoku[row][col]!=0)
            {
                printf("\t\t\t\t\t\t\t\t\t\tyou can not edit this cell Press 'y' to continue:");
                scanf(" %c",&ch);
                if(ch=='y'||ch=='Y')
                {
                continue;
               }
               else

                break;
            }

            Sudoku[row][col]=value;
            Scores+=20;
        }
        if(Mistakes==Max_Mistakes)
        {
            system("cls");
            setColor(4, 0);
            draw_GameOver();
            printf("\n\n\t\t\t\t\t\t<=======*******************************************************************************======>");
            setColor(6,0);
            printf("\n\n\n\t\t\t\t\t\t\t\t\t\tPress 'y' to Play again:\n");
            printf("\t\t\t\t\t\t\t\t\t\tPress 'q' to quit:\n\n\t\t\t\t\t\t\t\t\t\t====>");
            fflush(stdin);
            scanf("%c",&ch);
            if(ch=='y'||ch=='Y')
            {
                refresh();
                continue;
            }
            else

                break;
        }

    }
    return 0;
}

