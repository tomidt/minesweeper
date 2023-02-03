#include "library.h"

void set_board(int mine[r][c], int flag[r][c])
{
        for(int i = 0; i < r; i++)
        {
                for(int j = 0; j < c; j++)
                {
                        mine[i][j] = 0;
                        flag[i][j] = 0;
                }
        }
}

void set_mine(int mine[r][c], int count)
{
        for(int a = 0; a < count; a++)
        {
                int i, j;
                i = rand() % r;
                j = (rand() % 9) + 1;

                if(mine[i][j] <  1)
                        mine[i][j] = 1;
                else
                        a--;
        }
}

void set_safe(int mine[r][c])
{
        int s,a,rng;
        a = rng = 0;

        s = rand() % 13;

        for(int i = 0; i < r; i++)
        {
                mine[i][0] = -1;
        }
        for(int j = 1; j < 3; j++)
        {
                for(int i = 0; i < r; i++)
                {
                        rng = rand()%2;
                        if(a < s && rng == 1)
                        {
                                if(mine[i][j] < 1 && mine[i][j-1] == -1)
                                {
                                        mine[i][j] = -1;
                                        a++;
                                }
                        }
                }
        }
}

void set_exit(int mine[r][c])
{
        int i,j;
        while(1)
        {
                i = rand() % r;
                j = (rand() % 9) + 1;

                if(mine[i][j] != 1)
                {
                        mine[i][j] = 3;
                        break;
                }
        }


}
