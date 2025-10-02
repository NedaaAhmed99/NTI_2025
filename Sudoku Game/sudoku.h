#include <stdio.h>
#include <stdlib.h>
#define SIZE 9
#define Max_Mistakes 3
typedef  unsigned char  u8;
typedef  signed char  s8;

typedef  unsigned int  u32;
typedef  signed int  s32;

typedef  unsigned long long u64;
typedef  signed long long  s64;

typedef unsigned char*  u8p;
typedef signed char*  s8p;

typedef  unsigned int*  u32p;
typedef  signed int*  s32p;

typedef  unsigned long long* u64p;
typedef  signed long long*  s64p;

void draw_Sudoku();
void drow_YouWin();
void draw_GameOver();

void setColor(u32 textColor, u32 bgColor);
void fillArea(u32 width, u32 height, u32 textColor, u32 bgColor);
void setFullScreen();
void setCursorPosition(int x, int y);



void refresh();
void Sudokuo_ifwin();
void sudoku_print(u32 Sudoku[SIZE][SIZE]);
u8  Sudoku_isSolved(u32 arr[SIZE][SIZE]);
u8  Sudoku_RowSearch(u32 row,u32 item);
u8  Sudoku_ColSearch(u32 col,u32 item);
u8  Sudoku_BoxSearch(u32 row,u32 col,u32 item);

