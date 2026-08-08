#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int main()
{
    srand(time(0));
    printf("\n");
    printf("\033[1;36m");
    printf("=================================================================================\n");
    printf("                |----> WELCOME TO THE NUMBER GUESSING GAME! <----|\n");
    printf("=================================================================================\n");
    printf("\033[0m");
    printf("\n>>> Press [ENTER] to view Instructions...");
    getchar();
    printf("\n");
    printf("\033[1;33m");
    printf("|---------------------------- GAME INSTRUCTIONS -------------------------------|\n");
    printf("| 1. Computer will pick a secret random number between 1 and 100.              |\n");
    printf("| 2. Try to guess it in as few attempts as possible!                           |\n");
    printf("| 3. You will get hints like 'Higher' or 'Lower' after each guess.             |\n");
    printf("| 4. In Group Mode, whoever guesses in fewer tries wins!                       |\n");
    printf("| 5. In case of a tie in guess count, time is the tiebreaker.                  |\n");
    printf("|------------------------------------------------------------------------------|\n");
    printf("\033[0m");
    printf("\n>>> Press [ENTER] to choose Game Mode...");
    getchar();
    int mode;
    char player1[50] = "Player 1", player2[50] = "Player 2";
    int guess1 = 0, guess2 = 0;
    double time1 = 0, time2 = 0;      
    printf("\n Choose Game Mode: \n");
    printf(" 1. Solo Mode\n");
    printf(" 2. Group Mode (2 Players)\n");
    printf(" Enter choice (1 or 2): ");      
    if (scanf("%d", &mode) != 1 || (mode != 1 && mode != 2))
    {
        printf("Invalid input! Exiting...\n");
        return 1;
    }   
    if (mode == 2)
    {
        printf("\nEnter Player 1 Name: ");
        scanf("%49s", player1);

        printf("Enter Player 2 Name: ");
        scanf("%49s", player2);
    }
    else
    {
        printf("\nEnter Your Name: ");
        scanf("%49s", player1);
        printf("\nGood luck %s!\n", player1);
    }
    int randomNumber = (rand() % 100) + 1;
    int gussed = 0, no_of_guess = 0;
    time_t start_t, end_t;
    if (mode == 2) printf("\n--- %s's Turn ---\n", player1);         
    time(&start_t);
    do
    {
        printf("Guess the number (1-100): ");
        scanf("%d", &gussed);
        no_of_guess++;
        if (gussed > randomNumber)
            printf("Lower number please!\n");
        else if (gussed < randomNumber)
            printf("Higher number please!\n");
        else
            printf("Correct!\n");
    } while (gussed != randomNumber);    
    time(&end_t);
    guess1 = no_of_guess;
    time1 = difftime(end_t, start_t);
    if (mode == 1)
    {
        printf("\033[1;32m");
        printf("\n==========================================\n");
        printf("          --- SOLO GAME SUMMARY ---\n");
        printf("==========================================\n");
        printf(" Player Name  : %s\n", player1);
        printf(" Total Tries  : %d\n", guess1);
        printf(" Time Taken   : %.2f seconds\n", time1);
        printf(" Performance  : ");
        if (guess1 <= 5)
            printf(" Outstanding Genius!\n");
        else if (guess1 <= 10)
            printf("Great Job!\n");
        else
            printf("Keep Practicing!\n");
        printf("==========================================\n");
        printf("\033[0m");
    }
    if (mode == 2)
    {
        randomNumber = (rand() % 100) + 1;
        no_of_guess = 0;
        printf("\n--- %s's Turn ---\n", player2);
        time(&start_t);
        do
        {
            printf("Guess the number (1-100): ");
            scanf("%d", &gussed);
            no_of_guess++;
            if (gussed > randomNumber)
                printf("Lower number please!\n");
            else if (gussed < randomNumber)
                printf("Higher number please!\n");
            else
                printf("Good luck %s! You got it!\n", player2);
        } while (gussed != randomNumber);
        time(&end_t);
        guess2 = no_of_guess;
        time2 = difftime(end_t, start_t);
        printf("\033[1;32m");
        printf("\n==========================================\n");
        printf("           --- FINAL RESULT ---\n");
        printf("==========================================\n");
        printf(" %s -> Guesses: %d | Time: %.2f sec\n", player1, guess1, time1);
        printf(" %s -> Guesses: %d | Time: %.2f sec\n", player2, guess2, time2);        
        printf("------------------------------------------\n");
        if (guess1 < guess2)
            printf(" Winner: %s (fewer tries)!\n", player1);
        else if (guess2 < guess1)
            printf(" Winner: %s (fewer tries)!\n", player2);
        else
        {
            if (time1 < time2)
                printf(" Winner: %s! (Tied on guesses, but %.2f sec faster!)\n", player1, time2 - time1);
            else if (time2 < time1)
                printf(" Winner: %s! (Tied on guesses, but %.2f sec faster!)\n", player2, time1 - time2);
            else
                printf(" It's an exact tie in both tries and time!\n");
        }
        printf("==========================================\n");
        printf("\033[0m");
    }
    return 0;
}