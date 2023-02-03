#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"

#define r 8
#define c 10
#define TB4 printf("\t\t\t\t");
#define FLUSH while(getchar()!='\n');
#define LOWER(ch) (ch > 64 && ch < 91) ? (ch + 32) : (ch - 16)
#define START(SMINE) set_board(mine,flag);set_exit(mine);set_mine(mine,SMINE);set_safe(mine);
#define SZERO score=posr=posc=0;
#define SEASY SZERO smine=sflag=6;
#define SHARD SZERO smine=sflag=16;

void menu_controls(void);
void menu_start(void);
void menu_move(void);
void menu_flag(void);
void menu_point(void);

void set_board(int mine[r][c],int flag[r][c]);
void set_mine(int mine[r][c],int count);
void set_safe(int mine[r][c]);
void set_exit(int mine[r][c]);

void message_clear(void);
void message_end(void);
void message_exit(void);
void message_set(int num);

int proxy(int mine[r][c],int i,int j);
void update_scores(int mine,int flag, int score);
void update_start(int mine[r][c],int flag[r][c],int postr, int posc);
void update_player (int mine[r][c],int flag[r][c],int postr, int posc);
void update_display(int mine[r][c],int flag[r][c],int postr,int posc,int player);

int is_mine(int mine[r][c],int i,int j);
int is_new(int mine[r][c],int i,int j);
int is_exit(int mine[r][c],int i,int j);
int is_valid_move(char ch,int posr,int posc);
void move(char ch,int mine[r][c],int *posr,int *posc,int *score);
void place_flag(char ch,int mine[r][c],int flag[r][c],int *sflag,int *smine,int posr,int posc,int *score);
void input(char ch,int mine[r][c],int flag[r][c],int *sflag,int *smine,int *posr,int *posc,int *score);
