#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void optionOne(FILE *coinTextFile, char* txtFilePath, char inputName[20], int coins[2]){
    coinTextFile = fopen(txtFilePath, "r");                                                 // Read only

    if(coinTextFile == NULL) {
        printf("file error");
    }

    fscanf(coinTextFile, "%s", inputName);                                                  // scan name and store name into name array
    fscanf(coinTextFile, "%d", coins);                                                      // scan integer value and store into coins
    fclose(coinTextFile);
}

void calculate_Change(int coins[2], int fifty[1], int twenty[1], int ten[1], int five[1]){

    printf("\nYour change for the amount of %d cents is:\n\n", *coins);

    *fifty = *coins/50;
    *twenty = (*coins- *fifty * 50) / 20;
    *ten = (*coins - *fifty * 50 - *twenty * 20) / 10;
    *five = (*coins - *fifty * 50 - *twenty * 20 - *ten * 10) / 5;

    // TODO!!! ADJUST ACCORDINGLY!!! IF CENTS IS 0 DO NOT PRINT AND DISPLAY
    // ONLY DISPLAY WHERE THERE ARE CENTS NEEDED!!!!!
    // USE POINTER WHEN PRINTING OUT 
    // ALL THE BEST!
    printf("50 cent: %d\n", *fifty);
    printf("20 cent: %d\n", *twenty);
    printf("10 cent: %d\n", *ten);
    printf("5 cent: %d\n", *five);
}

void writeCSV(FILE *coinCSVFile, char* csvFilePath, char inputName[20], int coins[2], int fifty[1], int twenty[1], int ten[1], int five[1]){
    printf("Thank you for using this service");                                             // Exit statement

    coinCSVFile = fopen(csvFilePath, "w");                                                  // Write only
    fprintf(coinCSVFile,"Customer,Amount,50 cents,20 cents, 10 cents,5 cents \n");          // !!! CAN DELETE AS IT IS NOT REQUIRED !!!
    fprintf(coinCSVFile, "%s,%d,%d,%d,%d,%d", inputName, *coins, *fifty, *twenty, *ten, *five);
    fclose(coinCSVFile);
}

void consoleMenu(int option, char checkName[20], char inputName[20], int coins[2], int fifty[1], int twenty[1], int ten[1], int five[1]){
    printf("\n1. Enter name\n2. Exit\n");
    scanf("%d", &option);

    while (option != 2){
    printf("Customer:");                                                                    // Enter customer name
    scanf("%s", checkName);

    if(strcmp(inputName, checkName) != 0) {                                                 // Check and compare name
        printf("Not found");
    }else {
        printf("\nCustomer:\n%s %d cents", inputName, *coins);                              // Will printf the corresponding name
        calculate_Change(coins, fifty, twenty, ten, five);                                  // Function to calculate and printf change
    }
    printf("\n1. Enter name\n2. Exit\n");
    scanf("%d", &option);
    }                                                                                       // Exit the program
}

int main(){
    FILE *coinTextFile = NULL, *coinCSVFile = NULL;
    char* txtFilePath = "//Users//minzhan//Desktop//coin.txt";
    char* csvFilePath = "//Users//minzhan//Desktop//change.csv";
    char inputName[20], checkName[20];
    int coins[2], option = 0, fifty[1], twenty[1], ten[1], five[1];

    optionOne(coinTextFile, txtFilePath, inputName, coins);                                 // System will read the file, store data and close file
    consoleMenu(option, checkName, inputName, coins, fifty, twenty, ten, five);             // Console menu
    writeCSV(coinCSVFile, csvFilePath, inputName, coins, fifty, twenty, ten, five);         // Write to a CSV file
    return 0;
}
