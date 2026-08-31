#include <stdio.h>
#include <string.h>
#include <time.h>

#define WHO if (coups % 2 == 0) { tab[stack][colonne] = 'X';} \
            else {tab[stack][colonne] = 'O';}

void tableau(char tab[7][8]) {
    printf("\n %c|%d|%d|%d|%d|%d|%d|%d|\n", '_', 1, 2, 3, 4, 5, 6, 7);
    printf("|%d|%c|%c|%c|%c|%c|%c|%c| \n", 1, tab[1][1], tab[1][2], tab[1][3], tab[1][4], tab[1][5], tab[1][6], tab[1][7]);
    printf("|%d|%c|%c|%c|%c|%c|%c|%c| \n", 2, tab[2][1], tab[2][2], tab[2][3], tab[2][4], tab[2][5], tab[2][6], tab[2][7]);
    printf("|%d|%c|%c|%c|%c|%c|%c|%c| \n", 3, tab[3][1], tab[3][2], tab[3][3], tab[3][4], tab[3][5], tab[3][6], tab[3][7]);
    printf("|%d|%c|%c|%c|%c|%c|%c|%c| \n", 4, tab[4][1], tab[4][2], tab[4][3], tab[4][4], tab[4][5], tab[4][6], tab[4][7]);
    printf("|%d|%c|%c|%c|%c|%c|%c|%c| \n", 5, tab[5][1], tab[5][2], tab[5][3], tab[5][4], tab[5][5], tab[5][6], tab[5][7]);
    printf("|%d|%c|%c|%c|%c|%c|%c|%c| \n", 6, tab[6][1], tab[6][2], tab[6][3], tab[6][4], tab[6][5], tab[6][6], tab[6][7]);
}

int main()
{
    char tab[7][8];
    memset(tab, '_', sizeof(tab));
    int c;
    char* how;
    int coups = 0;
    int stack = 1;
    int digit = 0;
    int colonne = 0;
    int diagonal_victory_1 = 0;
    int diagonal_victory_2 = 0;
    int horizontal_victory = 0;
    int victory = 0;
    char joueur1[50];
    char joueur2[50];

    printf("\nJoueur 1 quel est votre nom? ");
    scanf("%s", joueur1);
    printf("Joueur 2 quel est votre nom? ");
    scanf("%s", joueur2);

    tableau(tab);

    while (1) // Partie commencée
    {
        if (coups % 2 == 0) {
            printf("\nEn quelle colonne allez vous jouer le 'X' %s? ", joueur1);
        }
        else {
            printf("\nEn quelle colonne allez vous jouer le 'O' %s? ", joueur2);
        }
        while ((c = getchar()) != '\n' && c != EOF); // ChatGPT --> Buffer vidé et enregistrement de la colonne
        scanf("%d", &colonne);
        if (colonne != 1 && colonne != 2 && colonne != 3 && colonne != 4 && colonne != 5 && colonne != 6 && colonne != 7) {
            printf("Cette colonne n'existe pas\n");
            continue;
        }

        if (tab[1][colonne] != '_') { // Colonne pleine?
            printf("La colonne est déjà pleine!");
            continue;
        }

        while (tab[stack][colonne] == '_' && stack != 7) // placement de la case avec nanosleep
        {
            WHO;
            struct timespec t = { 0, 150000000 }; // ChatGPT pour les nano car sleep est trop lent
            nanosleep(&t, NULL);
            tableau(tab);
            tab[stack][colonne] = '_';
            stack += 1;
        }
        stack -= 1;
        WHO;

        if (stack <= 3 && stack >= 1 && tab[stack][colonne] != '_') { // Victoire verticale
            if (tab[stack][colonne] == tab[stack + 1][colonne] && tab[stack][colonne] == tab[stack + 2][colonne] && tab[stack][colonne] == tab[stack + 3][colonne]) {
                victory = 42;
            }
        }

        digit = 1;
        while (tab[stack][colonne] != '_' && colonne >= 1 && colonne <= 7 && digit <= 4) // Victoire horizontale
        {
            if (tab[stack][colonne] == tab[stack][colonne + digit]) {
                horizontal_victory++;
            }
            else {
                break;
            }
            digit++;
        }
        digit = 1;
        while (tab[stack][colonne] != '_' && colonne >= 1 && colonne <= 7 && digit <= 4) // Victoire horizontale
        {
            if (tab[stack][colonne] == tab[stack][colonne - digit]) {
                horizontal_victory++;
            }
            else {
                break;
            }
            digit++;
        }
        if (horizontal_victory >= 3) {
            victory = 43;
        }

        digit = 1;
        while (tab[stack][colonne] != '_' && colonne > 0 && colonne <= 7 && stack <= 7 && stack > 0 && digit <= 4) // Victoire diagonale 1
        {
            if (tab[stack][colonne] == tab[stack - digit][colonne + digit]) {
                diagonal_victory_1++;
            }
            else {
                break;
            }
            digit++;
        }
        digit = 1;
        while (tab[stack][colonne] != '_' && colonne > 0 && colonne <= 7 && stack <= 7 && stack > 0 && digit <= 4) // Victoire diagonale 1
        {
            if (tab[stack][colonne] == tab[stack + digit][colonne - digit]) {
                diagonal_victory_1++;
            }
            else {
                break;
            }
            digit++;
        }
        digit = 1;

        while (tab[stack][colonne] != '_' && colonne > 0 && colonne <= 7 && stack <= 7 && stack > 0 && digit <= 4) // Victoire diagonale 2
        {
            if (tab[stack][colonne] == tab[stack + digit][colonne + digit]) {
                diagonal_victory_2++;
            }
            else {
                break;
            }
            digit++;
        }
        digit = 1;
        while (tab[stack][colonne] != '_' && colonne > 0 && colonne <= 7 && stack <= 7 && stack > 0 && digit <= 4) // Victoire diagonale 2
        {
            if (tab[stack][colonne] == tab[stack - digit][colonne - digit]) {
                diagonal_victory_2++;
            }
            else {
                break;
            }
            digit++;
        }

        if (diagonal_victory_1 >= 3 || diagonal_victory_2 >= 3) {
            victory = 44;
        }
        diagonal_victory_1 = 0;
        diagonal_victory_2 = 0;
        horizontal_victory = 0;
        stack = 1;
        coups++;

        if (victory == 42) {
            how = "verticalement";
        }
        else if (victory == 43)
        {
            how = "horizontalement";
        }
        else {
            how = "en diagonale";
        }

        if (victory >= 42) {
            if (coups % 2 != 0) {
                printf("\nFélicitations %s! Tu as gagné %s 🏆\n", joueur1, how);
                break;
            }
            printf("\nFélicitations %s! Tu as gagné %s 🏆\n", joueur2, how);
            break;
        }
        if (coups == 42) {
            printf("\nÉgalité! Désolé %s et %s mais la partie est terminée sur une égalité.\n", joueur1, joueur2);
            break;
        }
    }
    return 0;
}