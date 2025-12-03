#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int player = 1;            // 0 = left, 1 = mid, 2 = right
    int obstacleRow = 0;       // how far obstacle has fallen
    int obstacleLane = rand() % 3; // random lane
    int score = 0;             // score increases on each dodge
    int speed = 150;           // sleep time (decreases = faster)

    while (1) {

        // ---- INPUT ----
        if (_kbhit()) {
            char ch = getch();
            if (ch == 75 && player > 0) player--;   // Left arrow
            if (ch == 77 && player < 2) player++;   // Right arrow
        }

        // ---- CLEAR SCREEN ----
        system("cls");

        printf("Score: %d\n", score);
        printf("|--- --- ---|\n");

        // ---- DRAW OBSTACLE ----
        for (int r = 0; r < 10; r++) {

            if (r == obstacleRow) {
                // Print obstacle based on lane
                if (obstacleLane == 0)       printf("|  O       |\n");
                else if (obstacleLane == 1)  printf("|    O     |\n");
                else                         printf("|       O  |\n");
            } else {
                printf("|           |\n");
            }
        }

        // ---- DRAW PLAYER ----
        if (player == 0)       printf("|  A       |\n");
        else if (player == 1)  printf("|    A     |\n");
        else                   printf("|       A  |\n");

        // ---- COLLISION ----
        if (obstacleRow == 10 && player == obstacleLane) {
            printf("\nGAME OVER!\n");
            printf("Final Score: %d\n", score);
            break;
        }

        // ---- UPDATE POSITION ----
        Sleep(speed);
        obstacleRow++;

        // ---- RESET OBSTACLE ----
        if (obstacleRow > 10) {
            obstacleRow = 0;
            obstacleLane = rand() % 3;
            score++;

            // Make game faster
            if (speed > 60)
                speed -= 5;
        }
    }

    return 0;
}
