#include "library.h"

void message_clear(void)
{
       for(int i = 23; i >= 0; i--)
               write_message(i,"");
}

void message_end(void)
{
        write_message(0,"Game Over!");
        write_message(1,"You have stepped");
        write_message(2,"on a mine.");
        write_message(4,"Press any key to");
        write_message(5,"continue.");
}

void message_exit(void)
{
        write_message(0,"You Win!");
        write_message(2,"Press any key to");
        write_message(3,"continue.");
}

void message_set(int num)
{
        switch(num)
        {
                case 0:message_clear();
                       break;

                case 1:write_message(0,"Would you like to start");
                       write_message(1,"y to start & n to exit:");
                       break;

                case 2:write_message(0,"Select Difficulty");
                       write_message(1,"('e' for Easy)");
                       write_message(2,"('h' for Hard)");
                       break;

                case 3:message_clear();
                       message_end();
                       break;

                case 4:message_clear();
                       message_exit();
                       break;
        }
}
