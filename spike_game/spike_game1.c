# include <stdio.h>
# include <unistd.h>
# include <ncurses.h>

#include "display_spike.h"

int main()
{
    int moves = 0; // movements from X 23
    int deaths = 0;
    int X = 0;
    int Y = 9;
    int stop_gravity = 5;
    int you_died = 0;
    int pass = 0;
    int dollar = 0;
    int unlock = 0;
    int unlock2 = 0;

    initscr();
    while (1) // boucle infinie
    {
        char tab[10][135];
        for (int i = 0; i < 135; i++) {
            tab[9][i] = '_';
        }
        for (int x = 0; x < 9;x++) {
            for (int y = 0; y < 135;y++) {
                tab[x][y] = ' ';
                tab[x][134] = '\0';
            }
        }
        tab[9][124] = ' ';
        tab[9][134] = '\0';
        tab[9][14] = '|';
        tab[8][15] = '_';
        tab[8][16] = '|';
        tab[7][17] = '_';
        tab[7][18] = '|';
        tab[6][19] = '_';
        tab[6][23] = '_';
        tab[7][24] = '|';
        tab[7][25] = '_';
        tab[8][26] = '|';
        tab[8][27] = '_';
        tab[9][28] = '|';
        tab[4][59] = '$';

        if (moves >= 75) { // print wall
            tab[9][81] = '|';
            tab[8][81] = '|';
            tab[7][81] = '|';
            tab[6][81] = '|';
            tab[5][81] = '|';
            tab[4][81] = '|';
            tab[3][81] = '|';
            tab[2][81] = '|';
            tab[1][81] = '|';
            tab[0][81] = '|';
            tab[8][80] = '_';
            tab[7][76] = '_';
            tab[6][80] = '_';
            tab[5][76] = '_';
            tab[4][72] = '_';
            tab[4][80] = '_';
            tab[9][80] = '*';
        }
        if ((Y == 4 && X == 78) || unlock == 1) { // unlock = 1
            unlock = 1;
            tab[4][80] = ' ';
            tab[6][80] = ' ';
            tab[8][80] = ' ';
            tab[3][76] = '_';
            tab[2][72] = '_';
            tab[1][68] = '_';
            tab[1][67] = '_';
            tab[3][63] = '_';
        }

        if ((Y == 4 && X == 73) || unlock == 2) { // unlock = 2
            unlock = 2;
            tab[3][76] = '_';
            tab[2][72] = '_';
            tab[1][68] = '_';
            tab[1][67] = '_';
            tab[3][63] = '_';
            tab[9][82] = '*';
            tab[9][83] = '*';
        }

        if ((Y == 4 && X == 59) || dollar == 1) { // first dollar && save point
            dollar = 1;
            tab[4][59] = ' ';
            tab[8][59] = ' ';
            tab[1][81] = ' ';
            tab[0][81] = ' ';
            tab[2][80] = '_';
            tab[2][81] = '_';
            tab[3][83] = '|';
            tab[3][84] = '_';
            tab[4][85] = '|';
            tab[4][86] = '_';
            tab[5][87] = '|';
            tab[5][88] = '_';
            tab[6][89] = '|';
            tab[6][90] = '_';
            tab[7][91] = '|';
            tab[7][92] = '_';
            tab[8][93] = '|';
            tab[8][94] = '_';
            tab[9][95] = '|';
            tab[7][82] = '*';
        }

        if ((X == 86 && Y == 4) || unlock == 3) {
            unlock = 3;
            tab[3][76] = '_';
            tab[2][72] = '_';
            tab[1][68] = '_';
            tab[1][67] = '_';
            tab[3][63] = '_';
            tab[5][89] = '|';
            tab[5][86] = '|';
            tab[6][86] = '|';
            tab[5][88] = ' ';
            tab[5][87] = ' ';
            tab[9][88] = '*';
            tab[9][87] = '*';
            tab[9][90] = '*';
            tab[9][85] = '*';
            tab[9][82] = '*';
            tab[9][83] = '*';
            tab[8][118] = '?'; // second ?
            tab[8][119] = '|';
            tab[9][119] = '|';
            tab[7][119] = '_';
            tab[7][118] = '_';
            tab[7][117] = '_';
        }

        if ((X == 118 && Y == 8) || unlock == 4) { // second ?
            unlock = 4;
            tab[8][118] = ' ';
            tab[8][116] = '*';
            fourty_two(tab);
            tab[3][76] = '_';
            tab[2][72] = '_';
            tab[1][68] = '_';
            tab[1][67] = '_';
            tab[3][63] = '_';
            tab[5][89] = '|';
            tab[5][86] = '|';
            tab[6][86] = '|';
            tab[5][88] = ' ';
            tab[5][87] = ' ';
            tab[9][88] = '*';
            tab[9][87] = '*';
            tab[9][90] = '*';
            tab[9][85] = '*';
            tab[9][82] = '*';
            tab[9][83] = '*';
            tab[8][119] = '|';
            tab[9][119] = '|';
            tab[7][119] = '_';
            tab[7][118] = '_';
            tab[7][117] = '_';
            tab[4][86] = '|';
            tab[3][86] = '|';
            tab[2][86] = '|';
            tab[1][86] = '|';
            tab[0][86] = '|';
            tab[5][92] = '_';
            tab[6][93] = '|';
            tab[6][94] = '_';
            tab[7][95] = '|';
            tab[7][96] = '_';
            tab[8][97] = '|';
            tab[8][98] = '_';
            tab[9][99] = '|';
            tab[9][95] = '_';
            tab[8][82] = '?'; // trird ?
            tab[9][119] = '_';
            tab[8][122] = '_';
            tab[5][116] = '_';
            tab[6][113] = '_';
            tab[6][125] = '*';
        }

        if ((X == 82 && Y == 8) || unlock == 5) { // trird ?
            unlock = 5;
            tab[8][118] = ' ';
            tab[8][116] = '*';
            fourty_two(tab);
            tab[3][76] = '_';
            tab[2][72] = '_';
            tab[1][68] = '_';
            tab[1][67] = '_';
            tab[3][63] = '_';
            tab[5][89] = '|';
            tab[5][86] = '|';
            tab[6][86] = '|';
            tab[5][88] = ' ';
            tab[5][87] = ' ';
            tab[9][88] = '*';
            tab[9][87] = '*';
            tab[9][90] = '*';
            tab[9][85] = '*';
            tab[9][82] = '*';
            tab[9][83] = '*';
            tab[8][119] = '|';
            tab[7][119] = '_';
            tab[7][118] = '_';
            tab[7][117] = '_';
            tab[4][86] = '|';
            tab[3][86] = '|';
            tab[2][86] = '|';
            tab[1][86] = '|';
            tab[0][86] = '|';
            tab[5][92] = '_';
            tab[6][93] = '|';
            tab[6][94] = '_';
            tab[7][95] = '|';
            tab[7][96] = '_';
            tab[8][97] = '|';
            tab[8][98] = '_';
            tab[9][99] = '|';
            tab[9][95] = '_';
            // new
            tab[8][82] = ' ';
            tab[3][87] = '_';
            tab[2][91] = '_';
            tab[1][95] = '_';
            tab[4][99] = '?'; // fourth ?
            tab[9][119] = '_';
            tab[8][122] = '_';
            tab[5][116] = '_';
            tab[6][113] = '_';
            tab[6][125] = '*';
        }
        if ((X == 99 && Y == 4) || unlock2 == 1) {
            unlock2 = 1;
            tab[4][99] = ' ';
            tab[9][124] = '?';
        }
        if ((X == 124 && Y == 8) || unlock2 == 2) {
            unlock2 = 2;
            tab[4][99] = ' ';
            tab[9][124] = ' ';
        }

        char letter;
        refresh();
        letter = getch();

        if (letter == 'C') { // going right
            if (stop_gravity == 0 && tab[Y][X] != '_' && tab[Y + 1][X] != '|') { // stop gravity
                Y++;
                X--;
            }
            X++;
            if (tab[Y][X] == '|' || tab[Y][X] == '/') { // wall
                X--;
            }
            if (moves >= 1) {
                moves++;
            }
        }
        else if (letter == 'D' && X > 0) // going left
        {
            if (stop_gravity == 0 && tab[Y][X] != '_' && tab[Y + 1][X] != '|') { // stop gravity
                Y++;
                X++;
            }
            X--;
            if (tab[Y][X] == '|' || tab[Y][X] == '/') { // wall
                X++;
            }
            if (moves >= 1) {
                moves++;
            }
        }
        else if (letter == 'A' && (tab[Y - 1][X] != '_' && tab[Y - 1][X] != '|') && (tab[Y][X] == '_' || tab[Y + 1][X] == '|') && (tab[Y - 1][X] != '/')) // jump
        {
            if (moves >= 1) {
                moves++;
            }
            Y--;
            stop_gravity = 5;
        }
        else if (letter == 'B' && tab[Y][X] != '_' && tab[Y + 1][X] != '|') // going down
        {
            Y++;
            if (moves >= 1) {
                moves++;
            }
        }
        else // other key
        {
            continue;
        }

        if (stop_gravity > 0) {
            stop_gravity--;
        }

        display_first_pyramid(moves, tab);
        display_second_pyramid(moves, tab, dollar, &pass);


        if (Y == 9 && X == 9) { // trap 1
            tab[9][9] = '*';
            you_died = 1;
        }
        if ((Y == 6 && X == 20) || (Y == 6 && X == 21) || (Y == 6 && X == 22)) { // trap 2
            tab[6][20] = '*';
            tab[6][21] = '*';
            tab[6][22] = '*';
            deaths++;
            you_died = 1;
        }
        if (Y == 6 && X == 25 && moves >= 4) { // trap 3
            tab[6][25] = '*';
            deaths++;
            you_died = 1;
        }
        if (Y == 9 && X == 33) { // trap 4
            tab[9][33] = '*';
            deaths++;
            you_died = 1;
        }
        if (Y == 8 && X == 36) { // trap 5
            tab[8][36] = '*';
            deaths++;
            you_died = 1;
        }
        if (X == 23) { // trap 6.0
            moves = 1;
        }
        if (Y == 9 && X == 50) { // trap 6.1
            tab[9][50] = '*';
            deaths++;
            you_died = 1;
        }

        if (Y == 9 && X == 58 && moves >= 45 && pass == 0) { // trap 7.0
            tab[9][58] = '*';
            deaths++;
            you_died = 1;
        }
        if (X == 59 && moves >= 46 && pass == 0) { // trap 7.1
            tab[9][59] = '*';
            tab[8][59] = '*';
            deaths++;
            you_died = 1;
        }
        if (X == 60 && moves >= 47 && pass == 0) { // trap 7.2
            tab[9][60] = '*';
            tab[8][60] = '*';
            you_died = 1;
        }
        if (X == 61 && moves >= 48 && pass == 0) { // trap 7.3
            tab[9][61] = '*';
            tab[8][61] = '*';
            you_died = 1;
        }
        if (X == 62 && moves >= 49 && pass == 0) { // trap 7.4
            tab[9][62] = '*';
            tab[8][62] = '*';
            you_died = 1;
        }
        if (X == 63 && moves >= 50 && pass == 0) { // trap 7.5
            tab[9][63] = '*';
            tab[8][63] = '*';
            you_died = 1;
        }
        if (X == 64 && moves >= 51 && pass == 0) { // trap 7.6
            tab[9][64] = '*';
            tab[8][64] = '*';
            you_died = 1;
        }
        if (X == 65 && moves >= 52 && pass == 0) { // trap 7.7
            tab[9][65] = '*';
            tab[8][65] = '*';
            you_died = 1;
        }
        if ((X == 66 || X == 67) && pass == 0) { // trap 7.8
            tab[9][66] = '*';
            tab[8][66] = '*';
            tab[7][66] = '*';
            tab[6][66] = '*';
            tab[5][66] = '*';
            tab[4][66] = '*';
            tab[3][66] = '*';
            tab[2][66] = '*';
            tab[1][66] = '*';
            you_died = 1;
        }
        if (Y == 8 && X > 59 && X <= 73) { // trap 7.9
            you_died = 1;
        }
        if (X == 80 && Y == 9) { // trap 8
            tab[9][80] = '*';
            you_died = 1;
        }
        if ((X == 73 && Y == 8) || (X == 60 && Y == 7) || (X == 72 && Y == 7) || (X == 61 && Y == 6) || (X == 71 && Y == 6) || (X == 62 && Y == 5) || (X == 70 && Y == 5) || (X == 63 && Y == 4) || (X == 69 && Y == 4) || (X == 64 && Y == 3) || (X == 68 && Y == 3) || (X == 65 && Y == 2) || (X == 67 && Y == 2) || (X == 66 && Y == 1)) { // trap 9
            you_died = 1;
        }
        if ((X == 88 && Y == 9) || (X == 87 && Y == 9) || (X == 82 && Y == 7) || (X == 85 && Y == 9) || (X == 90 && Y == 9) || (X == 82 && Y == 9) || (X == 83 && Y == 9)) { // trap 10
            tab[9][88] = '*';
            tab[9][87] = '*';
            tab[9][85] = '*';
            tab[9][90] = '*';
            tab[7][82] = '*';
            tab[9][82] = '*';
            tab[9][83] = '*';
            you_died = 1;
        }

        if (X == 116 && Y == 8) { // trap 11
            tab[8][116] = '*';
            you_died = 1;
        }

        if (X == 125 && Y == 6) { // trap 11
            tab[6][125] = '*';
            you_died = 1;
        }


        if (X >= 9) { // printed traps
            tab[9][9] = '*';
            if (X >= 23) {
                tab[6][20] = '*';
                tab[6][21] = '*';
                tab[6][22] = '*';
                if (X >= 25) {
                    tab[6][25] = '*';
                    if (X >= 33) {
                        tab[9][33] = '*';
                        if (X >= 36) {
                            tab[8][36] = '*';
                            if (X >= 89) {
                                tab[9][88] = '*';
                                tab[9][87] = '*';
                                tab[9][85] = '*';
                                tab[9][90] = '*';
                            }
                        }
                    }
                }
            }
        }

        tab[Y][X] = 'O';
        if (unlock2 == 2) { // endgame
            endwin();
            break;
        }

        clear();
        printw("Deaths: %d\n", deaths);
        for (int i = 0; i < 10; i++) {
            printw("%s\n", tab[i]);
        }
        refresh();
        if (you_died == 1) {
            deaths++; // deaths + 1
            you_died = 0; // reset
            unlock = 0; // reset
            moves = 0; // reset
            X = 0; // reset
            Y = 9; //reset
            if (dollar == 1) { // save point 1
                moves = 77;
                X = 59;
                Y = 4;
                dollar = 1;
                stop_gravity = 0;
                unlock = 2;
            }
        }
        printw("\n\n\nDigit: %d", X);
        printw("\nLetter: %c\n", letter);
        printw("Gravity: %d\n", Y);
        printw("Stop Gravity: %d\n", stop_gravity);
        printw("Change: %d\n", moves);
        printw("Unlock: %d\n", unlock);
    }
    return 0;
}

// gccc spike_game1.c display_spike.c -o ppp -lncurses && ./ppp