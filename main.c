#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

    int delay_speed;

    int xflag = 1;
    int yflag = -1;

    int y_ball = 12;
    int x_ball = 40;
    int jahat = 1;
    int y_next=0;

    int y1 = 0 ;   //player one y location
    int y2 = 0 ;   // player two y location

    int player1score = 0;
    int player2score = 0;


void PrintPlayers (void){


    mvprintw(10,0,"||");
    mvprintw(11,0,"||");
    mvprintw(12,0,"||");

    mvprintw(10,78,"||");
    mvprintw(11,78,"||");
    mvprintw(12,78,"||");

}


void print_ball(void)
{

    y_ball = y_ball + yflag ;
    x_ball = x_ball + xflag;
    y_next = y_ball + yflag;

    mvprintw(y_ball,x_ball,"o");
    refresh();

    delay_output(delay_speed);

    mvprintw(y_ball,x_ball," ");
    refresh();
}

void ball_cal(void){


    if (x_ball == 77){
    jahat = 0;// jahat bargasht chap

    }
    if (x_ball == 2){
   jahat = 1; // jahat raft rast

    }




    if(x_ball == 2 && jahat ==1 && y_next > y_ball && y1+9 < y_ball && y_ball < y1 +13 ){
    xflag = 1;
    yflag = 1;

    }

    if(x_ball == 2 && jahat ==1 && y_next < y_ball && y1+9 < y_ball && y_ball < y1 +13){

    xflag = 1;
    yflag = -1;

    }



    if(y_ball == 3 && jahat == 1){

    xflag = 1;
    yflag = 1;


    }

    if(y_ball == 23 && jahat == 1){

    xflag = 1;
    yflag = -1;


    }


    if(x_ball == 77 && jahat == 0 && y_next < y_ball && y2+9 < y_ball && y_ball < y2 +13   ){
    xflag = -1;
    yflag = -1;

    }


    if (x_ball == 77 && jahat == 0 && y_next > y_ball && y2+9 < y_ball && y_ball < y2 +13 ){
    xflag = -1;
    yflag = 1;

    }



    if(y_ball == 3 && jahat ==0){

    xflag = -1;
    yflag = 1;

    }
    if(y_ball == 23 && jahat == 0){

    xflag = -1;
    yflag = -1;

    }

    if( x_ball == 0){   // -1 barie in neveshte shode ke dar 0 bug chap top bud

    y_ball = 12;
    x_ball = 40;

     xflag = 1;
     yflag = -1;
    jahat = 1;
    }

    if ( x_ball == 80){

    y_ball = 12;
    x_ball = 40;

     xflag = -1;
     yflag = 1;
    jahat = 0;

    }

    mvprintw(10+y1,0,"||");
    mvprintw(11+y1,0,"||");
    mvprintw(12+y1,0,"||");

    mvprintw(10+y2,78,"||");
    mvprintw(11+y2,78,"||");
    mvprintw(12+y2,78,"||");

}

int platform(){
    mvprintw(1,5,"Player 1:");
    mvprintw(1,66,"Player 2:");

    mvprintw(3,0,"--------------------------------------------------------------------------------");
    mvprintw(4,40,"|");
    mvprintw(6,40,"|");
    mvprintw(8,40,"|");
    mvprintw(10,40,"|");
    mvprintw(12,40,"|");
    mvprintw(14,40,"|");
    mvprintw(16,40,"|");
    mvprintw(18,40,"|");
    mvprintw(20,40,"|");
    mvprintw(22,40,"|");
    mvprintw(23,0,"--------------------------------------------------------------------------------");
    refresh();
}

int score (){




    mvprintw(1,15,"%d", player1score);
    mvprintw(1,75,"%d", player2score);

    refresh();

    if(x_ball == 0){
    player2score = player2score + 1;
    }

    if(x_ball == 80){
    player1score = player1score + 1;
    }

    if(player1score == 8){
    while(1){
    clear();
    mvprintw(12,30,"PLAYER 1 IS WINNER");
    refresh();
    }

    }
    if(player2score == 8){
    while(1){
    clear();
    mvprintw(12,30,"PLAYER 2 IS WINNER");
    refresh();
}


    }

    //if(player1score >=7 && player2score >= 7 && player1score - player2score == 2){

    //}


}


int main(){

    initscr();
    noecho();
    curs_set(0);




    WINDOW* mywin = newwin(24,80,0,0);
    wrefresh(mywin);

    int ch1;
    start_color();
    init_pair(1,COLOR_RED,COLOR_BLACK);
    attron(COLOR_PAIR(1));

mvprintw(2,0,"\t           oooooooooo                                        \n"
               "\t           888    888  ooooooo    ooooooo    oooooooo8       \n"
               "\t           888oooo88 888     888 888   888  888    88o       \n"
               "\t           888       888     888 888   888   888oo888o       \n"
               "\t          o888o        88ooo88  o888o o888o 888     888      \n"
               "\t                                             888ooo888     \n\n");

               attroff(COLOR_PAIR(1));

    mvprintw(10,20,"PLEASE ENTER A OR B OR C FOR CHOOSE GAME LEVEL");
    mvprintw(12,20,"*A = EASY");
    mvprintw(13,20,"*B = MEDIUM");
    mvprintw(14,20,"*C = HARD");

    while(ch1 = getch()){

    if(ch1 == 'A'){

    delay_speed = 150;
    break;
    }

    if(ch1 == 'B'){

    delay_speed = 100;
        break;

    }
    if(ch1 == 'C'){

    delay_speed = 50;
        break;

    }
    }
clear();


    PrintPlayers();
    refresh();

    nodelay(mywin,true);



    char ch;


    while(1){


    ch = wgetch(mywin);

        switch(ch){

            case 'W' :
            if (y1 == -6){
            y1 = -5;
            }
            y1--;
            mvprintw(10+y1,0,"||");
            mvprintw(11+y1,0,"||");
            mvprintw(12+y1,0,"||");
            mvprintw(13+y1,0,"  ");
            refresh();

            break;

            case 'S':
            if (y1 == 10){
            y1 = 9;
            }
            y1++;
            mvprintw(9+y1,0,"  ");
            mvprintw(10+y1,0,"||");
            mvprintw(11+y1,0,"||");
            mvprintw(12+y1,0,"||");
            refresh();

            break;


            case '8':
            if (y2 == -6){
            y2 = -5;
            }
            y2--;
            mvprintw(10+y2,78,"||");
            mvprintw(11+y2,78,"||");
            mvprintw(12+y2,78,"||");
            mvprintw(13+y2,78,"  ");
            refresh();

            break;

            case '2':
            if (y2 == 10){
            y2 = 9;
            }
            y2++;
            mvprintw(9+y2,78,"  ");
            mvprintw(10+y2,78,"||");
            mvprintw(11+y2,78,"||");
            mvprintw(12+y2,78,"||");
            refresh();

            break;




        }


    ball_cal();

    print_ball();



    platform();
    score();


    if(player1score >=7 && player2score >= 7 && player1score - player2score == 2 || player2score - player1score ==2){
    break;

    }



}




getch();


}





