#include "library.h"

int main()
{
        srand(time(0));

        int mine[r][c],flag[r][c],posr,posc;
        int num;

        int score,smine,sflag;
        char ch;

        menu_start();
        do
        {
                scanf("%d",&num);
                switch(num)
                {
                        case 1:menu_move();break;
                        case 2:menu_flag();break;
                        case 3:menu_point();break;
                        case 4:num = 0;break;
                }
        }
        while(num != 0);

        while(1)
        {
                draw_board();
                message_set(1);
                ch = getchar();

                if(ch == 'y')
                {
                        message_set(2);
                        ch = getchar();


                        if(ch == 'e')
                        {
                                SEASY
                        }
                        else if(ch == 'h')
                        {
                                SHARD
                        }

                        START(smine)

                        message_set(0);
                        update_start(mine,flag,posr,posc);
                        update_scores(smine,sflag,score);

                        while(1)
                        {
                                ch = getchar();

                                update_player(mine,flag,posr,posc);
                                input(ch,mine,flag,&sflag,&smine,&posr,&posc,&score);
                                update_display(mine,flag,posr,posc,3);

                                if(is_mine(mine,posr,posc) == 1)
                                {
                                        update_display(mine,flag,posr,posc,6);
                                        message_set(3);
                                        getchar();
                                        break;
                                }
                                else if(is_exit(mine,posr,posc) == 1)
                                {
                                        message_set(4);
                                        score+= 10;
                                        getchar();
                                        break;
                                }
                                update_scores(smine,sflag,score);
                        }
                        message_set(0);
                }
                else if(ch == 'n')
                        break;
        }
        clear_screen();
}
