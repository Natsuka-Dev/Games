#include <stdio.h> // printf
#include <string.h> // strcmp
#include <time.h> // nanosleep

void tableau(char* tab[6][7]) {
    printf("\n %c|%d|%d|%d|%d|%d|%d|%d|\n", '_', 1, 2, 3, 4, 5, 6, 7);
    printf("|%d|%s|%s|%s|%s|%s|%s|%s| \n", 1, tab[0][0], tab[0][1], tab[0][2], tab[0][3], tab[0][4], tab[0][5], tab[0][6]);
    printf("|%d|%s|%s|%s|%s|%s|%s|%s| \n", 2, tab[1][0], tab[1][1], tab[1][2], tab[1][3], tab[1][4], tab[1][5], tab[1][6]);
    printf("|%d|%s|%s|%s|%s|%s|%s|%s| \n", 3, tab[2][0], tab[2][1], tab[2][2], tab[2][3], tab[2][4], tab[2][5], tab[2][6]);
    printf("|%d|%s|%s|%s|%s|%s|%s|%s| \n", 4, tab[3][0], tab[3][1], tab[3][2], tab[3][3], tab[3][4], tab[3][5], tab[3][6]);
    printf("|%d|%s|%s|%s|%s|%s|%s|%s| \n", 5, tab[4][0], tab[4][1], tab[4][2], tab[4][3], tab[4][4], tab[4][5], tab[4][6]);
    printf("|%d|%s|%s|%s|%s|%s|%s|%s| \n", 6, tab[5][0], tab[5][1], tab[5][2], tab[5][3], tab[5][4], tab[5][5], tab[5][6]);
}

int main() {
    int c; // ChatGPT
    char* tab[6][7];
    char joueur1[50];
    char joueur2[50];
    int coups = 0;
    int colonne = 0;
    int ligne = 0;
    char* redBold_X = "\033[1;31mX\033[0m";
    char* yellowBold_O = "\033[1;33mO\033[0m";
    char* greenBold_X = "\033[1;32mX\033[0m";
    char* greenBold_O = "\033[1;32mO\033[0m";
    int victory = 0;
    int horizontal_victory = 0;
    int diagonal_victory_1 = 0;
    int diagonal_victory_2 = 0;

    while (colonne != 7)
    {
        tab[ligne][colonne] = "_";
        ligne++;
        if (ligne == 6)
        {
            ligne = 0;
            colonne++;
        }
    }

    printf("\nJoueur 1 quel est votre nom? ");
    scanf("%s", joueur1);
    while ((c = getchar()) != '\n' && c != EOF); // ChatGPT

    printf("\nJoueur 2 quel est votre nom?");
    scanf("%s", joueur2);
    while ((c = getchar()) != '\n' && c != EOF); // ChatGPT

    tableau(tab);

    while (1) // Partie commencée
    {
        if (coups % 2 == 0) {
            printf("\nEn quelle colonne allez vous jouer le 'X' %s?\n", joueur1);
        }
        else {
            printf("\nEn quelle colonne allez vous jouer le 'O' %s?\n", joueur2);
        }

        if (scanf("%d", &colonne) != 1) { // ChatGPT
            printf("Veuillez entrer un chiffre de 1 à 7\n");
            while ((c = getchar()) != '\n' && c != EOF); // ChatGPT
            continue;
        }
        colonne -= 1;
        if (colonne < 0 || colonne > 6) {
            printf("Cette colonne n'existe pas, veuillez entrer un chiffre de 1 à 7\n");
            continue;
        }
        if (tab[0][colonne] == yellowBold_O || tab[0][colonne] == redBold_X) {
            printf("Cette Colonne est déjà renmplie, veuillez en séléctionner une autre\n");
            continue;
        }

        while (ligne != 6 && strcmp(tab[ligne][colonne], "_") == 0) // slpeep(0.1)
        {
            if (coups % 2 == 0) {
                tab[ligne][colonne] = redBold_X;
            }
            else {
                tab[ligne][colonne] = yellowBold_O;
            }
            struct timespec t = { 0, 100000000 }; // ChatGPT pour les nano car sleep est trop lent
            nanosleep(&t, NULL);
            tableau(tab);
            tab[ligne][colonne] = "_";
            ligne++;
        }
        ligne -= 1;
        if (coups % 2 == 0) { tab[ligne][colonne] = redBold_X; } // print X ou O
        else { tab[ligne][colonne] = yellowBold_O; };

        if (ligne <= 2 && ligne >= 0 && strcmp(tab[ligne][colonne], "_") != 0) { // Victoire verticale
            if (strcmp(tab[ligne][colonne], tab[ligne + 1][colonne]) == 0 && strcmp(tab[ligne][colonne], tab[ligne + 2][colonne]) == 0 && strcmp(tab[ligne][colonne], tab[ligne + 3][colonne]) == 0) {
                if (coups % 2 == 0) {
                    tab[ligne][colonne] = greenBold_X;
                    tab[ligne + 1][colonne] = greenBold_X;
                    tab[ligne + 2][colonne] = greenBold_X;
                    tab[ligne + 3][colonne] = greenBold_X;
                }
                else {
                    tab[ligne][colonne] = greenBold_O;
                    tab[ligne + 1][colonne] = greenBold_O;
                    tab[ligne + 2][colonne] = greenBold_O;
                    tab[ligne + 3][colonne] = greenBold_O;
                }
                victory = 42;
            }
        }

        for (int i = 1; i < 4; i++) { // horizontal_victory ++
            if (colonne - i >= 0 && strcmp(tab[ligne][colonne], tab[ligne][colonne - i]) == 0) {
                horizontal_victory++;
            }
            else {
                break;
            }
        }
        for (int i = 1; i < 4; i++) { // horizontal_victory ++
            if (colonne + i <= 6 && strcmp(tab[ligne][colonne], tab[ligne][colonne + i]) == 0) {
                horizontal_victory++;
            }
            else {
                break;
            }
        }

        if (horizontal_victory >= 3) { // Victoire horizontale
            for (int i = 1; i < 7; i++) {
                if (colonne + i <= 6 && strcmp(tab[ligne][colonne], tab[ligne][colonne + i]) == 0) {
                    if (coups % 2 == 0) {
                        tab[ligne][colonne + i] = greenBold_X;
                    }
                    else {
                        tab[ligne][colonne + i] = greenBold_O;
                    }
                }
                if (colonne - i >= 0 && strcmp(tab[ligne][colonne], tab[ligne][colonne - i]) == 0) {
                    if (coups % 2 == 0) {
                        tab[ligne][colonne - i] = greenBold_X;
                    }
                    else {
                        tab[ligne][colonne - i] = greenBold_O;
                    }
                }
            }
        }

        for (int i = 1; i < 4; i++) { // diagonal_victory_1 ++
            if (ligne - i >= 0 && colonne + i <= 6 && strcmp(tab[ligne][colonne], tab[ligne - i][colonne + i]) == 0) {
                diagonal_victory_1++;
            }
            else {
                break;
            }
        }
        for (int i = 1; i < 4; i++) { // diagonal_victory_1 ++
            if (ligne + i <= 5 && colonne - i >= 0 && strcmp(tab[ligne][colonne], tab[ligne + i][colonne - i]) == 0) {
                diagonal_victory_1++;
            }
            else {
                break;
            }
        }

        if (diagonal_victory_1 >= 3) { // Victoire diagonale 1
            for (int i = 1; i < 7; i++) {
                if (ligne + i <= 5 && colonne - i >= 0 && strcmp(tab[ligne][colonne], tab[ligne + i][colonne - i]) == 0) {
                    if (coups % 2 == 0) {
                        tab[ligne + i][colonne - i] = greenBold_X;
                    }
                    else {
                        tab[ligne + i][colonne - i] = greenBold_O;
                    }
                }
                if (ligne - i >= 0 && colonne + i <= 5 && strcmp(tab[ligne][colonne], tab[ligne - i][colonne + i]) == 0) {
                    if (coups % 2 == 0) {
                        tab[ligne - i][colonne + i] = greenBold_X;
                    }
                    else {
                        tab[ligne - i][colonne + i] = greenBold_O;
                    }
                }
            }
        }

        for (int i = 1; i < 4; i++) { // diagonal_victory_2 ++
            if (ligne - i >= 0 && colonne - i >= 0 && strcmp(tab[ligne][colonne], tab[ligne - i][colonne - i]) == 0) {
                diagonal_victory_2++;
            }
            else {
                break;
            }
        }
        for (int i = 1; i < 4; i++) { // diagonal_victory_2 ++
            if (ligne + i <= 5 && colonne + i <= 6 && strcmp(tab[ligne][colonne], tab[ligne + i][colonne + i]) == 0) {
                diagonal_victory_2++;
            }
            else {
                break;
            }
        }

        if (diagonal_victory_2 >= 3) { // Victoire diagonale 2
            for (int i = 1; i < 7; i++) {
                if (ligne - i >= 0 && colonne - i >= 0 && strcmp(tab[ligne][colonne], tab[ligne - i][colonne - i]) == 0) {
                    if (coups % 2 == 0) {
                        tab[ligne - i][colonne - i] = greenBold_X;
                    }
                    else {
                        tab[ligne - i][colonne - i] = greenBold_O;
                    }
                }
                if (ligne + i <= 5 && colonne + i <= 6 && strcmp(tab[ligne][colonne], tab[ligne + i][colonne + i]) == 0) {
                    if (coups % 2 == 0) {
                        tab[ligne + i][colonne + i] = greenBold_X;
                    }
                    else {
                        tab[ligne + i][colonne + i] = greenBold_O;
                    }
                }
            }
        }

        if (victory == 42 || horizontal_victory >= 3 || diagonal_victory_1 >= 3 || diagonal_victory_2 >= 3) { // Victoire
            if (coups % 2 == 0) {
                tab[ligne][colonne] = greenBold_X;
                tableau(tab);
                printf("\nFélicitations %s! Tu as gagné 🏆\n", joueur1);
                break;
            }
            else {
                tab[ligne][colonne] = greenBold_O;
                tableau(tab);
                printf("\nFélicitations %s! Tu as gagné 🏆\n", joueur2);
                break;
            }
        }

        diagonal_victory_1 = 0; // reset
        diagonal_victory_2 = 0; // reset
        horizontal_victory = 0; // reset
        ligne = 0; // reset
        coups++;

        if (coups == 42) { // Égalité
            printf("\nÉgalité! Désolé %s et %s mais la partie est terminée sur une égalité.\n", joueur1, joueur2);
            break;
        }
    }
    return 0;
}