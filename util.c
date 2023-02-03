#include "library.h"

int is_mine(int mine[r][c], int i, int j)
{
        if(mine[i][j] == 1)
                return 1;
        else
                return 0;
}

int is_new(int mine[r][c], int i, int j)
{
        if(mine[i][j] == -1)
                return 0;
        else
                return 1;
}

int is_exit(int mine[r][c], int i, int j)
{
        if(mine[i][j] == 3)
                return 1;
        else
                return 0;
}

int is_valid_move(char ch, int posr, int posc)
{
        switch(ch)
        {
                case 'y': if(posr > 0 && posc > 0)
                                return 1;
                          else
                                return 0;

                case 'u': if(posr > 0)
                                  return 1;
                          else
                                  return 0;

                case 'i': if(posr > 0 && posc < (c-1))
                                  return 1;
                          else
                                  return 0;

                case 'h': if(posc > 0)
                                 return 1;
                         else
                                 return 0;

                case 'k': if(posc < (c-1))
                                 return 1;
                         else
                                 return 0;

                case 'n': if(posr < (r-1) && posc > 0)
                                 return 1;
                         else
                                 return 0;

                case 'm': if(posr < (r-1))
                                 return 1;
                         else
                                 return 0;

                case ',': if(posr < (r-1) && posc < (c-1))
                                 return 1;
                         else
                                 return 0;
                default:break;
        }
}

void move(char ch, int mine[r][c], int *posr, int *posc, int *score)
{
        if(is_valid_move(ch,*posr,*posc) == 1)
        {
                switch(ch)
                {
                        case 'y':(*posr)--;(*posc)--;
                                 break;

                        case 'u':(*posr)--;
                                 break;

                        case 'i':(*posr)--;(*posc)++;
                                 break;

                        case 'h':(*posc)--;
                                 break;

                        case 'k':(*posc)++;
                                 break;

                        case 'n':(*posr)++;(*posc)--;
                                 break;

                        case 'm':(*posr)++;
                                 break;

                        case ',':(*posr)++;(*posc)++;
                                 break;

                        default:break;
                }

                if(is_new(mine,*posr,*posc) == 1 && is_mine(mine,*posr,*posc) == 0 && is_exit(mine,*posr,*posc) == 0)
                {
                        mine[*posr][*posc] = -1;
                        (*score)++;
                }
        }
}

void place_flag(char ch, int mine[r][c], int flag[r][c], int *sflag, int *smine, int posr, int posc, int *score)
{
        if(is_valid_move(LOWER(ch),posr,posc) == 1 && *sflag > 0)
        {
                switch(LOWER(ch))
                {
                        case 'y':posr--;posc--;
                                 break;

                        case 'u':posr--;
                                 break;

                        case 'i':posr--;posc++;
                                 break;

                        case 'h':posc--;
                                 break;

                        case 'k':posc++;
                                 break;

                        case 'n':posr++;posc--;
                                 break;

                        case 'm':posr++;
                                 break;

                        case ',':posr++;posc++;
                                 break;

                        default:break;
                }

                if(flag[posr][posc] != 1)
                {
                        flag[posr][posc] = 1;
                        (*sflag)--;

                        if(is_mine(mine,posr,posc) == 1)
                        {
                                update_display(mine,flag,posr,posc,5);
                                (*score)+= 2;
                                (*smine)--;
                        }
                        else
                        {
                                update_display(mine,flag,posr,posc,2);
                                if((*score) > 0)
                                *score-= 1;
                        }
                        update_scores(*smine,*sflag,*score);
                }
        }
}

void input(char ch, int mine[r][c], int flag[r][c], int *sflag, int *smine, int *posr, int *posc, int *score)
{
        int pr = *posr;
        int pc = *posc;

        switch(ch)
        {
                case 'y':
                case 'u':
                case 'i':
                case 'h':
                case 'k':
                case 'n':
                case 'm':
                case ',':move(ch,mine,posr,posc,score);
                         break;

                case 'Y':
                case 'U':
                case 'I':
                case 'H':
                case 'K':
                case 'N':
                case 'M':
                case '<':place_flag(ch,mine,flag,sflag,smine,pr,pc,score);
                         break;

                default:break;

        }
}
