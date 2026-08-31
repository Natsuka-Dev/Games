#include <stdio.h>

int main()
{
    char tab[42]; // 6 * 7 = 42 --> Ecole 42 Quel hasard?
    tab[0] = '_'; tab[1] = '_'; tab[2] = '_'; tab[3] = '_'; tab[4] = '_'; tab[5] = '_'; tab[6] = '_'; tab[7] = '_'; tab[8] = '_'; tab[9] = '_'; tab[10] = '_'; tab[11] = '_';
    tab[12] = '_'; tab[13] = '_'; tab[14] = '_'; tab[15] = '_'; tab[16] = '_'; tab[17] = '_'; tab[18] = '_'; tab[19] = '_'; tab[20] = '_'; tab[21] = '_'; tab[22] = '_';
    tab[23] = '_'; tab[24] = '_'; tab[25] = '_'; tab[26] = '_'; tab[27] = '_'; tab[28] = '_'; tab[29] = '_'; tab[30] = '_'; tab[31] = '_'; tab[32] = '_'; tab[33] = '_';
    tab[34] = '_'; tab[35] = '_'; tab[36] = '_'; tab[37] = '_'; tab[38] = '_'; tab[39] = '_'; tab[40] = '_'; tab[41] = '_';
    int c; // ChatGPT
    int colonne = 0;
    int un = -1;
    int deux = 5;
    int trois = 11;
    int quatre = 17;
    int cinq = 23;
    int six = 29;
    int sept = 35;
    int coups = 0;
    int victory = 0;
    int horizontal_1 = 0;
    int diagonale_1 = 0;
    int diagonale_2 = 0;
    int case_jouée = 0;
    int diagonale_droite = 7;
    int diagonale_gauche = 5;
    int horizontal = 6;
    char joueur1[50];
    char joueur2[50];

    printf("\nJoueur 1 quel est votre nom? ");
    scanf("%s", joueur1);
    printf("Joueur 2 quel est votre nom? ");
    scanf("%s", joueur2);

    printf("\n|%d|%d|%d|%d|%d|%d|%d|\n", 1, 2, 3, 4, 5, 6, 7);
    printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[5], tab[11], tab[17], tab[23], tab[29], tab[35], tab[41]);
    printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[4], tab[10], tab[16], tab[22], tab[28], tab[34], tab[40]);
    printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[3], tab[9], tab[15], tab[21], tab[27], tab[33], tab[39]);
    printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[2], tab[8], tab[14], tab[20], tab[26], tab[32], tab[38]);
    printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[1], tab[7], tab[13], tab[19], tab[25], tab[31], tab[37]);
    printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[0], tab[6], tab[12], tab[18], tab[24], tab[30], tab[36]);

    while (1)
    {
        if (coups % 2 == 0) {
            printf("\nEn quelle colonne allez vous jouer le 'X' %s? ", joueur1);
        }
        else {
            printf("\nEn quelle colonne allez vous jouer le 'O' %s? ", joueur2);
        }

        while ((c = getchar()) != '\n' && c != EOF); // ChatGPT
        scanf("%d", &colonne);
        if (colonne != 1 && colonne != 2 && colonne != 3 && colonne != 4 && colonne != 5 && colonne != 6 && colonne != 7) {
            printf("Cette colonne n'existe pas\n\n");
            continue;
        }

        if (colonne == 1 && un < 5) { // 1
            un++;
            if (coups % 2 == 0) {
                tab[un] = 'X';
            }
            else {
                tab[un] = 'O';
            }
            case_jouée = un;
        }
        else if (colonne == 2 && deux < 11) { // 2
            deux++;
            if (coups % 2 == 0) {
                tab[deux] = 'X';
            }
            else {
                tab[deux] = 'O';
            }
            case_jouée = deux;
        }
        else if (colonne == 3 && trois < 17) { // 3
            trois++;
            if (coups % 2 == 0) {
                tab[trois] = 'X';
            }
            else {
                tab[trois] = 'O';
            }
            case_jouée = trois;
        }
        else if (colonne == 4 && quatre < 23) { // 4
            quatre++;
            if (coups % 2 == 0) {
                tab[quatre] = 'X';
            }
            else {
                tab[quatre] = 'O';
            }
            case_jouée = quatre;
        }
        else if (colonne == 5 && cinq < 29) { // 5
            cinq++;
            if (coups % 2 == 0) {
                tab[cinq] = 'X';
            }
            else {
                tab[cinq] = 'O';
            }
            case_jouée = cinq;
        }
        else if (colonne == 6 && six < 35) { // 6
            six++;
            if (coups % 2 == 0) {
                tab[six] = 'X';
            }
            else {
                tab[six] = 'O';
            }
            case_jouée = six;
        }
        else if (colonne == 7 && sept < 41) { // 7
            sept++;
            if (coups % 2 == 0) {
                tab[sept] = 'X';
            }
            else {
                tab[sept] = 'O';
            }
            case_jouée = sept;
        }
        else {
            printf("Cette colonne est déjà remplie!\n");
            continue;
        }

        printf("\n|%d|%d|%d|%d|%d|%d|%d|\n", 1, 2, 3, 4, 5, 6, 7);
        printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[5], tab[11], tab[17], tab[23], tab[29], tab[35], tab[41]);
        printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[4], tab[10], tab[16], tab[22], tab[28], tab[34], tab[40]);
        printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[3], tab[9], tab[15], tab[21], tab[27], tab[33], tab[39]);
        printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[2], tab[8], tab[14], tab[20], tab[26], tab[32], tab[38]);
        printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[1], tab[7], tab[13], tab[19], tab[25], tab[31], tab[37]);
        printf("|%c|%c|%c|%c|%c|%c|%c| \n", tab[0], tab[6], tab[12], tab[18], tab[24], tab[30], tab[36]);

        if (case_jouée != 0 && case_jouée != 1 && case_jouée != 2 && case_jouée != 6 && case_jouée != 7 && case_jouée != 8 && case_jouée != 12 && case_jouée != 13 && case_jouée != 14 && case_jouée != 18 &&
            case_jouée != 19 && case_jouée != 20 && case_jouée != 24 && case_jouée != 25 && case_jouée != 25 && case_jouée != 30 && case_jouée != 31 && case_jouée != 32 && case_jouée != 36 && case_jouée != 37 && case_jouée != 38) {
            if (tab[case_jouée] == tab[case_jouée - 1] && tab[case_jouée] == tab[case_jouée - 2] && tab[case_jouée] == tab[case_jouée - 3]) {
                victory = 42; // Vertical +1
            }
        }

        while (tab[case_jouée] == tab[case_jouée + horizontal] && case_jouée + horizontal <= 41)
        {
            horizontal_1++;
            if (case_jouée + horizontal == 36 || case_jouée + horizontal == 37 || case_jouée + horizontal == 38 || case_jouée + horizontal == 39 || case_jouée + horizontal == 40 || case_jouée + horizontal == 41) {
                break;
            }
            horizontal += 6; // horizontal +6
        }

        horizontal = 6;

        while (tab[case_jouée] == tab[case_jouée - horizontal] && case_jouée - horizontal >= 0)
        {
            horizontal_1++;
            if (case_jouée - horizontal == 0 || case_jouée - horizontal == 1 || case_jouée - horizontal == 2 || case_jouée - horizontal == 3 || case_jouée - horizontal == 4 || case_jouée - horizontal == 5) {
                break;
            }
            horizontal += 6; // horizontal -6
        }

        if (tab[case_jouée] != 5 && tab[case_jouée] != 11 && tab[case_jouée] != 17 && tab[case_jouée] != 23 && tab[case_jouée] != 29 && tab[case_jouée] != 35 && tab[case_jouée] != 41) {
            while (tab[case_jouée] == tab[case_jouée + diagonale_droite] && case_jouée + diagonale_droite <= 41) {
                diagonale_1++;
                if (case_jouée + diagonale_droite == 11 || case_jouée + diagonale_droite == 17 || case_jouée + diagonale_droite == 23 || case_jouée + diagonale_droite == 29 || case_jouée + diagonale_droite == 35 || case_jouée + diagonale_droite == 41) {
                    break;
                }
                diagonale_droite += 7; // Diagonale +7
            }
        }
        if (tab[case_jouée] != 0 && tab[case_jouée] != 6 && tab[case_jouée] != 12 && tab[case_jouée] != 18 && tab[case_jouée] != 24 && tab[case_jouée] != 30 && tab[case_jouée] != 36) {
            while (tab[case_jouée] == tab[case_jouée + diagonale_gauche] && case_jouée + diagonale_gauche <= 41) {
                diagonale_2++;
                if (case_jouée + diagonale_gauche == 6 || case_jouée + diagonale_gauche == 12 || case_jouée + diagonale_gauche == 18 || case_jouée + diagonale_gauche == 24 || case_jouée + diagonale_gauche == 30 || case_jouée + diagonale_gauche == 36) {
                    break;
                }
                diagonale_gauche += 5; // Diagonale +5
            }
        }

        diagonale_gauche = 5;
        diagonale_droite = 7;

        if (tab[case_jouée] != 5 && tab[case_jouée] != 11 && tab[case_jouée] != 17 && tab[case_jouée] != 23 && tab[case_jouée] != 29 && tab[case_jouée] != 35 && tab[case_jouée] != 41) {
            while (tab[case_jouée] == tab[case_jouée - diagonale_droite] && case_jouée - diagonale_droite >= 0) {
                diagonale_1++;
                if (case_jouée - diagonale_droite == 5 || case_jouée - diagonale_droite == 11 || case_jouée - diagonale_droite == 17 || case_jouée - diagonale_droite == 23 || case_jouée - diagonale_droite == 29 || case_jouée - diagonale_droite == 35) {
                    break;
                }
                diagonale_droite += 7; // Diagonale -7
            }
        }
        if (tab[case_jouée] != 0 && tab[case_jouée] != 6 && tab[case_jouée] != 12 && tab[case_jouée] != 18 && tab[case_jouée] != 24 && tab[case_jouée] != 30 && tab[case_jouée] != 36) {
            while (tab[case_jouée] == tab[case_jouée - diagonale_gauche] && case_jouée - diagonale_gauche >= 0) {
                diagonale_2++;
                if (case_jouée - diagonale_droite == 0 || case_jouée - diagonale_gauche == 6 || case_jouée - diagonale_gauche == 12 || case_jouée - diagonale_gauche == 18 || case_jouée - diagonale_gauche == 24 || case_jouée - diagonale_gauche == 30) {
                    break;
                }
                diagonale_gauche += 5; // Diagonale -5
            }
        }

        if (horizontal_1 >= 3 || diagonale_1 >= 3 || diagonale_2 >= 3) { // Victoire
            victory = 42;
        }

        coups++;
        diagonale_gauche = 5;
        diagonale_droite = 7;
        horizontal = 6;
        diagonale_2 = 0;
        diagonale_1 = 0;
        horizontal_1 = 0;

        if (victory == 42) {
            if (coups % 2 != 0) {
                printf("\nFélicitations %s! Tu as gagné 🏆\n", joueur1);
                break;
            }
            printf("\nFélicitations %s! Tu as gagné 🏆\n", joueur2);
            break;
        }
        if (coups == 42) {
            printf("\nÉgalité! Désolé %s et %s mais la partie est terminée.\n", joueur1, joueur2);
            break;
        }
    }
    return 0;
}