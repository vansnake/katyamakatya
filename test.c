#include <stdio.h>
#define WIDTH 25
#define LENGTH 80
#define XCORDERACKET1 10
#define XCORDERACKET2 70
int scoreGen(int coordinateBall, int scorePlayer1, int scorePlayer2);
int ballGen_1(int direction, int previousX, int previousY);
int ballGen_2(int direction, int previousX, int previousY);
void changeDirection(int *direction, int newDirection);
int racketGen1(int currentPositionRacket1, char inputSymbol);
int racketGen2(int currentPositionRacket2, char inputSymbol);
char inputGenPlayer1(void);
char inputGenPlayer2(void);
void fieldGenOnly(int coordinateBallX,int coordinateBallY, int coordinateRacket1Y, int coordinateRacket2Y) {
    system("clear");
    for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < LENGTH; j++) {
            if (i == 0 || i == WIDTH - 1) { printf("#");}
            else if (j == 0 || j == LENGTH - 1 ){ printf("#");
                
            } else if(j == XCORDERACKET1 && (i>= coordinateRacket1Y && i < coordinateRacket1Y + 4)) {
                printf("|");
            } else if (j ==XCORDERACKET2 && (i >= coordinateRacket2Y && i < coordinateRacket2Y + 4)) {
                printf("|");
            } else if (j == coordinateBallX && i == coordinateBallY) {printf("0");
            } else {printf(" "); }
        }printf("\n");
        }
    }


int main(void) {
    int start1 = WIDTH / 2;
    int start2 = WIDTH / 2;
    int direction = 2;
    int previousX = LENGTH / 2;
    int previousY = WIDTH / 2;
    int scorePlayer1 = 0;
    int scorePlayer2 = 0;
    int status = 0;
    size_t statusPlayer = 1;

    printf("PLAYER 1 MOVE\n");
    while (scorePlayer1 < 2 && scorePlayer2 < 2) {
        if (statusPlayer == 1) {
            char input = inputGenPlayer1();
            start1 = racketGen1(start1, input);
            statusPlayer = 2;
            printf("PLAYER 2 MOVE\n");
        } else {
            char input = inputGenPlayer2();
            start2 = racketGen2(start2, input);
            statusPlayer = 1;
            printf("PLAYER 1 MOVE\n");
        }

        previousX=ballGen_1(direction, previousX, previousY);
        previousY=ballGen_2(direction, previousX, previousY);
        status = scoreGen(previousX, scorePlayer1, scorePlayer2);

        if (status == 1) {
            start1 = WIDTH / 2;
            start2 = WIDTH / 2;
            previousX = LENGTH / 2;
            previousY = WIDTH / 2;
            status = 0;
        }

        fieldGenOnly(previousX, previousY, start1, start2);
        for (int i = 0; i < (LENGTH - 4) / 2; i++) {
            printf(" ");
        }
        printf("%d : %d\n", scorePlayer1, scorePlayer2);
    }

    if (scorePlayer1 > scorePlayer2) {
        for (int i = 0; i < (LENGTH - 16) / 2; i++) {
            printf(" ");
        }
        printf("VICTORY PLAYER 1 !!!\n");
    } else {
        for (int i = 0; i < (LENGTH - 16) / 2; i++) {
            printf(" ");
        }
        printf("VICTORY PLAYER 2 !!!\n");
    }

    return 0;
}

char inputGenPlayer1(void) {
    char result, tmp;
    if ((scanf("%c%c", &result, &tmp) != 2) || (tmp != '\n') || ((result != 'A') && (result != 'Z') && (result != ' '))) {
        result = 'e';
    }
    return result;
}

char inputGenPlayer2(void) {
    char tmp, result;
    if ((scanf("%c%c", &result, &tmp) != 2) || (tmp != '\n') || ((result != 'K') && (result != 'M') && (result != ' '))) {
        result = 'e';
    }
    return result;
}

int racketGen1(int currentPositionRacket1, char inputSymbol) {
    // focus on the top pixel of the racket
    int tmp = currentPositionRacket1;
    if (currentPositionRacket1 != 1) {
        if (inputSymbol == 'A') {
            currentPositionRacket1--;
        }
    }
    if (currentPositionRacket1 != WIDTH - 4) {
        if (inputSymbol == 'Z') {
            currentPositionRacket1++;
        }
    }
    if (inputSymbol == ' ') {
        currentPositionRacket1 = tmp;
    }
    return currentPositionRacket1;
}

int racketGen2(int currentPositionRacket2, char inputSymbol) {
    // focus on the top pixel of the racket
    int tmp = currentPositionRacket2;
    if (currentPositionRacket2 != 1) {
        if (inputSymbol == 'K') {
            currentPositionRacket2--;
        }
    }
    if (currentPositionRacket2 != WIDTH - 4) {
        if (inputSymbol == 'M') {
            currentPositionRacket2++;
        }
    }
    if (inputSymbol == ' ') {
        currentPositionRacket2 = tmp;
    }
    return currentPositionRacket2;
}

int scoreGen(int coordinateBallX, int scorePlayer1, int scorePlayer2) {
   
    if (coordinateBallX <= 0) {
        scorePlayer2++;
        return 1;
    } else if (coordinateBallX >= LENGTH - 1) {
        scorePlayer1++;
        return 1;
    }
    return 0;
}

int ballGen_1(int direction, int previousX, int previousY) {
    
    if (direction == 1) {
        previousX = previousX + 1;
    } else if (direction == 2) {
        previousX = previousX - 1;
        previousY = previousY - 1;
    } else if (direction == 3) {
        previousX = previousX - 1;
        previousY = previousY + 1;
    } else if (direction == 4) {
        previousX = previousX + 1;
        previousY = previousY + 1;
    }
    return previousX;
}

int ballGen_2(int direction, int previousX, int previousY) {
  
    if (direction == 1) {
       
        previousY = previousY - 1;
    } else if (direction == 2) {
        previousX = previousX - 1;
        previousY = previousY - 1;
    } else if (direction == 3) {
        previousX = previousX - 1;
        previousY = previousY + 1;
    } else if (direction == 4) {
        previousX = previousX + 1;
        previousY = previousY + 1;
    }
    return previousY;
}





