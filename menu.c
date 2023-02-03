#include "library.h"

void menu_controls(void)
{
        printf("\t\t1)\tto find how to move about\n");
        printf("\t\t2)\tto find how to plant flags\n");
        printf("\t\t3)\tto see how to earn points\n");
        printf("\t\t4)\tto start play\n");
}

void menu_start(void)
{
        TB4 printf("WELCOME\n\t\t\t\tto\n\t\t\tTimmy Finds The Exit\n\n");
        printf("\tYou are about to be placed in grave danger.  You wake up in a field full\n");
        printf("\tof mines.  Your mission is to find the secret exit without blowing yourself\n");
        printf("\tup, and map the field in the process. Your predecessors have already mapped\n");
        printf("\tpart of the field for you before meeting their untimely ends.  You\n");
        printf("\tdo have a few tools to help you.  Your proximity probe will\n");
        printf("\tdisplay how many mines are in your immediate area as you step into\n");
        printf("\teach grid on the field.  You also carry a set of flags you can\n");
        printf("\tplant to show grids where you suspect there might be a mine.  For\n");
        printf("\tmore information, or to begin, choose from the menu below:\n\n\n");

        menu_controls();
}

void menu_move(void)
{
        TB4 printf("Moving About\n\n");
        printf("\tYou can move about the field in any of eight directions from\n");
        printf("\tyour current position by using the keys centered around the 'j'\n");
        printf("\tkey:\n\n");

        TB4 printf("y | u | i\n");
        TB4 printf("--|---|--\n");
        TB4 printf("h |   | k\n");
        TB4 printf("--|---|--\n");
        TB4 printf("n | m | ,\n\n");

        printf("\tHowever, you will not be allowed to leave the field except from\n");
        printf("\tthe far right edge.\n\n\n");

        menu_controls();
}

void menu_flag(void)
{
        TB4 printf("Planting Flags\n\n");
        printf("\tYou can plant one of your flags in any of eight directions from\n");
        printf("\tyour current position by using the shifted keys centered around\n");
        printf("\tthe 'J' key:\n\n");

        TB4 printf("Y | U | I\n");
        TB4 printf("--|---|--\n");
        TB4 printf("H |   | K\n");
        TB4 printf("--|---|--\n");
        TB4 printf("N | M | <\n\n");

        printf("\tYou will receive 2 points if you plant a flag on a mine, but you\n");
        printf("\twill lose 1 point (and the flag) if you plant it in an empty grid.\n\n\n");

        menu_controls();
}

void menu_point(void)
{
        TB4 printf("Earning Points\n\n");
        printf("\tYou earn 1 point for each new 'SAFE' grid you identify by stepping\n");
        printf("\tthrough it.  You also get a bonus of 10 points for making it\n");
        printf("\tthrough the miensfeld by stepping out on the far right.  You also\n");
        printf("\tcan earn points for flags. You get 2 points for correctly flagging\n");
        printf("\ta mine, but you lose 1 point for incorrectly flagging a 'SAFE' grid.\n\n");
        printf("\tThe game ends when you either blow up or safely find the exit.\n");
        printf("\tThe game also ends if you successfully flag all mines.\n\n\n");

        menu_controls();
}
