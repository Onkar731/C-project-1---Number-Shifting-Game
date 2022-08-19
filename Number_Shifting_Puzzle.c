#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


// to generate random numbers 1 to 15
void generateRandomValues(int[][4]);

// to display rules of the game
void displayRules();

// to display formatted matrix
void printMatrix(int[][4]);

// to shift numbers in matrix
int shiftNumber(char*, int[][4]);

// to check whether the matrix is sortted or not
int isMatrixSortted(int[][4]);

// to display content for game winning situation 
void youWonGame(char*, int[][4]);

// to display content for game loosing situation 
char youLooseGame();

// To display text in color - user define functions as per the color name
void red();
void green();
void yellow();
void white();



int main()
{
    int matrix[4][4];
    char name[20];
    char choice = 'y';

    while(choice == 'y')
    {
        /* First screen start */
           
            printf("\n\nEnter Your Name : ");
            fgets(name, 20, stdin);
            name[strlen(name) - 1] = '\0';
            system("cls");

        /* First screen end */

        /* Second screen start */

           displayRules();

        /* Second screen end */

        /* Third screen start */

            generateRandomValues(matrix);

            // shiftNumber() function - it is used to shift number to empty location, it accepts name and matrix and 
            // returns remaining number moves
            // returns 0 - if moves are finished 
            // returns a number other than 0 - if matrix is found in winning situation in given number of moves.

            if(shiftNumber(name, matrix) == 0){
                printMatrix(matrix);
                choice = youLooseGame();
            }
            else{
                youWonGame(name, matrix);
            }

        /* Third screen end */
    }

    return 0;
}

void generateRandomValues(int matrix[][4])
{
    // array is just for to store unique value in matrix or array
    int arr[15];
    int count = 0, col = 0;
    int lwr = 1, upr = 15;
    int r = 0, c = 0;

    while(1){
        // to get random value between 1 to 15
        int num = (rand() % (upr - lwr + 1)) + lwr;
        int j = 0;
        // to store value at (num - 1) index
        while(num != j){
            j++;
        }
        // storing value at (num - 1) index if (num-1) index value is not equal to num
        if(arr[j-1] != num){

            arr[j-1] = num;
            matrix[r][c] = num;
            c++;
            // counting number of values 
            count++;
            // counting number of columns in a row to change line after 4 column is filled
            col++;
        }
        // if 4 column is filled in a row, then change line and set col to 0 
        if(col == 4){
            col = 0;
            r++;
            c = 0;
        }
        // if count is equal to 15 that means we got 1 to 15 distinct numbers, so that break the loop
        if(count == 15){
            break;
        }
    }
    matrix[3][3] = 0;
}

void displayRules()
{
        printf("\t\t\t* MATRIX PUZZLE *");
        
        red(); // displaying in red color
        printf("\n\n\t\t\tRULES OF THIS GAME");

            // First rule
            printf("\n\n1. You can move only 1 step at a time by arrow key.\n");
                white(); // displaying in white color
                printf("\tMove Up\t  : by Up arrow key");
                printf("\n\tMove Down : by Down arrow key");
                printf("\n\tMove Left : by Left arrow key");
                printf("\n\tMove Right: by Right arrow key");
            
            // Second rule
            red(); // displaying in red color
            printf("\n\n2. You can move number at empty position only.\n");

            // Third rule
            printf("\n3. For each valid move : your total number of moves will decreased by 1.\n");

            // Fourth rule
            printf("\n4. Winning situation : Number in a 4*4 matrix should be in order from 1 to 15.\n");
                
                white(); // displaying in white color
                printf("\n\n\tWinning situation:");
                
                yellow(); // Printing pattern in yellow color
                printf("\n---------------------\n");
                    int k = 1;
                    for(int i = 1; i <= 4; i++)
                    {
                        for(int j = 1; j <= 4; j++)
                        {
                            printf("|");
                            if(k < 10){
                                printf("  %d ", k);
                            }
                            else{
                                if(k > 15){
                                    printf("    ");
                                    break;
                                }
                                printf(" %d ", k);
                            }
                            k++;
                        }
                        printf("|");
                        printf("\n");
                    }
                printf("---------------------\n");
            
            // Fifth rule
            red(); // displaying in red color
            printf("\n5. You can exit the game at any time by pressing \'E\' or \'e\'.\n");

            white(); // displaying in white color
            printf("\nSo try to win in minimum number of moves.");

            printf("\n\n\t\tHappy gaming, Good Luck!\n");
            printf("\nPress any key to start......");
            getche();
            system("cls");  
}

void printMatrix(int matrix[][4])
{
    printf("\n---------------------\n");
        
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                printf("|");

                if(matrix[i][j] == 0){
                    printf("    ");
                }
                else if(matrix[i][j] < 10){
                    printf("  %d ", matrix[i][j]);
                }
                else{
                    printf(" %d ", matrix[i][j]);
                }
            }

            printf("|\n");
        }
     
    printf("---------------------\n");
}

int shiftNumber(char *name, int matrix[][4])
{
            // i and j variable which are used to store the index of 'empty' or 'blank' location
            int i = 3, j = 3, temp; // temp variable for swapping
            int moves = 10;

            while(moves)
            {
                printf("\n\t\t\t\t\tHello %s, Moves remaining : %d\n", name, moves);
                printMatrix(matrix);

                int shift = getch();

                switch(shift)
                {
                    case 72:
                            if((i+1) <= 3){

                                temp = matrix[i][j];
                                matrix[i][j] = matrix[i+1][j];
                                matrix[i+1][j] = temp;

                                i++; // incrementing row index of empty or blank location
                                moves--; // decreasing moves by 1
                                
                                if(isMatrixSortted(matrix)){
                                    return moves;
                                }
                                system("cls"); // clearing screen
                            }
                            else{
                                system("cls");
                            }

                            break;
                    case 75:
                            if((j+1) <= 3){

                                temp = matrix[i][j];
                                matrix[i][j] = matrix[i][j+1];
                                matrix[i][j+1] = temp;

                                j++; // incrementing column index of empty or blank location
                                moves--; // decreasing moves by 1

                                if(isMatrixSortted(matrix)){
                                    return moves;
                                }

                                system("cls"); // clearing screen
                            }
                            else{
                                system("cls");
                            }

                            break;
                     case 77:
                            if((j-1) >= 0){

                                temp = matrix[i][j];
                                matrix[i][j] = matrix[i][j-1];
                                matrix[i][j-1] = temp;

                                j--; // decrementing column index of empty or blank location
                                moves--; // decreasing moves by 1
 
                                if(isMatrixSortted(matrix)){
                                    return moves;
                                }

                                system("cls"); // clearing screen
                            }
                            else{
                                system("cls");
                            }

                            break;
                    case 80:
                            if((i-1) >= 0){

                                temp = matrix[i][j];
                                matrix[i][j] = matrix[i-1][j];
                                matrix[i-1][j] = temp;

                                i--; // decrementing row index of empty or blank location
                                moves--; // decreasing moves by 1

                                if(isMatrixSortted(matrix)){
                                    return moves;
                                }
 
                                system("cls"); // clearing screen
                            }
                            else{
                                system("cls");
                            }

                            break;
                    case 101:
                    case 69: exit(0);
                    default:
                            system("cls");
                }
            }

            return moves;
}

int isMatrixSortted(int matrix[][4])
{
    int counter = 1;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(counter != matrix[i][j])
            {
                if(matrix[3][3] == 0)
                    return 1;
                
                return 0;
            }
            // if(counter == matrix[i][j]){
            //     counter++;
            // }else{
            //     return 0;
            // }
        }
    }
}

void youWonGame(char *name, int matrix[][4])
{
    green();
    printf("\n\t\t\t\t\tCongratulations! %s, You Won The Game\n", name);

    yellow();
    printMatrix(matrix);

    exit(0);
}

char youLooseGame()
{

    printf("\n\nYour moves are over!!!\n");
    printf("\nPress any key to continue....\n");
    getch();

    red();
    system("cls");
    printf("\n\n\t\tYOU LOSE THE GAME ! Nice Try !");

    green();
    printf("\n\n\t\tWant to play again?");

    white();
    printf("\n\nEnter \'y\' to play again otherwise \'n\' : ");
    char choice = getch();

    system("cls");
    return choice;
}

void red()
{
   printf("\033[0;31m");
}

void yellow()
{
   printf("\033[0;33m");
}

void green()
{
   printf("\033[0;32m");
}

void white()
{
    printf("\033[0;37m");
}