/* Name: Madeline Whitton
Date: 2/22/2022
Section: 11
Assignment: 7
Due Date: 2/27/2022
About this project: A simple program which allows the user to
input data for the array, display the array on the screen,
and find the maximum value in the array.
Assumptions: N/A
All work below was performed by Madeline Whitton */

#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_AVENGERS = 173;
int getValidNumAppearances();
int getValidAvenger();
void displayNumAppearances(int[]);
void ChangeANumAppearances(int []);
void displayMaxNumAppearances (int []);
void DisplayMenuOption();
int getValidOptionInput(int num);


int main() {
    int option = 0;
    int numAppearances[NUM_AVENGERS] = {1269, 1165, 3068, 2089, 2402,
                                        612, 3458, 1456, 769, 1214,
                                        115, 741, 780, 1036, 482,
                                        1112, 160, 1886, 332, 557,
                                        197, 106, 692, 109, 100,
                                        132, 108, 100, 156, 254,
                                        935, 576, 141, 355, 933,
                                        348, 206, 533, 374, 2,
                                        2305, 83, 402, 352, 565,
                                        112, 218, 149, 168, 1561,
                                        217, 158, 86, 41, 68,
                                        70, 61, 2125, 1761, 293,
                                        36, 22, 31, 34, 33,
                                        4, 47, 7, 3, 16,
                                        575, 58, 237, 4333, 126,
                                        158, 355, 517, 202, 31,
                                        28, 50, 27, 18, 302,
                                        330, 101, 43, 126, 24,
                                        886, 159, 3130, 241, 67,
                                        23, 103, 123, 110, 160,
                                        132, 121, 59, 629, 1324,
                                        236, 663, 525, 205, 108,
                                        359, 299, 333, 88, 369,
                                        380, 545, 6, 126, 417,
                                        31, 310, 40, 26, 63,
                                        2, 73, 22, 153, 73,
                                        59, 66, 43, 55, 108,
                                        64, 62, 94, 18, 81,
                                        1598, 1375, 746, 561, 592,
                                        679, 491, 65, 55, 44,
                                        65, 877, 176, 24, 25,
                                        35, 44, 78, 22, 77,
                                        115, 77, 69, 173, 75,
                                        12, 14, 13, 198, 29,
                                        45, 49, 35};

    cout << "Welcome to the Avengers number program\n";
    DisplayMenuOption();
    cin >> option;
    getValidOptionInput(option);

    bool run = true;

    do {
        //do while loop which runs through until option 4 is entered
        while (option == 1) {
            cout << "Display Number of Appearances";
            displayNumAppearances(numAppearances);
            DisplayMenuOption();
            cin >> option;
            getValidOptionInput(option);
            break;
            //Will display the nuber of appearances and then the menu options so
            //the user can input a new option after
        }

        while (option == 2) {
            ChangeANumAppearances(numAppearances);
            DisplayMenuOption();
            cin >> option;
            getValidOptionInput(option);
            break;
            //calls the function to change a number within the array
            //then displays the menu option and allows the user to enter
            //a new option.
        }

        while (option == 3) {
            cout << "The maximum number of the Avengers was ";
            displayMaxNumAppearances(numAppearances);
            DisplayMenuOption();
            cin >> option;
            getValidOptionInput(option);
            break;
            //uses the function which finds the max number of appearances
            //then displays the menu and allows the user to enter a new
            //option.
        }

        if (option == 4) {
            run = false;
            break;
            //when run = false the program quits.
        }
    } while (run);
}

void DisplayMenuOption(){
    //a void that will simply display the menu options.
        cout << "\n1) Display the number of appearances\n"
                "2) Change the number of appearances for an Avenger\n"
                "3) Display the max number of appearances\n"
                "4) Quit\n"
                "Select an option (1..4)..";
    }

int getValidOptionInput(int num){
    //a function which makes sure the user enters in a valid option
    //and will continue looping until a propper option is entered.
    while(num < 1 || num > 4){
        DisplayMenuOption();
        cin >> num;
    }
    return num;
}

int getValidNumAppearances(int &n){
    //a simple function which checks to see if the integer entered for
    //NumAppearances is greater than 0, if not then it requests the user
    //to enter in an integer greater than 0.
    while (n <= 0){
        cout << "Please enter in a valid Number of Appearances (>=1)\n";
        cin >> n;
    }
    return n;
}

int getValidAvenger(int &num){
    //A function that makes sure the number of the avenger entered
    //exists and if so, the number is returned.
    while(num < 1 || num > NUM_AVENGERS){
        cout << "Please enter in a valid Avenger number...\n";
        cin >> num;
    }
    return num;
}

void displayNumAppearances(int numAppearances[NUM_AVENGERS]){
    //this function loops through the array by rows with 5
    //integers on each row.
    for (int count = 0; count < NUM_AVENGERS; count++){
        if(count % 5 == 0){
            cout << endl;
            //if the count is divisible by 5, print the next set
            //of integers on a new row.
        }
        //formatting:
        cout << numAppearances[count] << right << setw(5);
    }
}

void ChangeANumAppearances(int numAppearances[NUM_AVENGERS]){
    //a function which allows the user to change the number of appearances
    //for any given point of the array.
    int i;
    int j;
    cout << "Enter in the number of the Avenger...\n";
    cin >> i;
    getValidAvenger(i);
    i = i - 1;
    //i = i - 1, since the first int of the array is actually from 0 to 172.
    //therefore the user will always enter in an integer one space above
    //the intended integer.
    {
        cout << "Please enter in the Number of Appearances...\n";
        cin >> j;
        getValidNumAppearances(j);
    }
        numAppearances[i] = j;
    //the number of appearances of the first integer entered will be equal to
    //the second integer (j) requested.
    }

void displayMaxNumAppearances(int numAppearances[NUM_AVENGERS]){
    int max = numAppearances[0];
    //loop through avengers
    for (int i = 1; i < NUM_AVENGERS; i++){
     if(numAppearances[i] > max){
         max = numAppearances[i];
         //this is looping through each integer in the array and comparing
         //values, replacing the last max value identified with whatever newer
         //max value identified.
     }
    }
    cout << max << endl;
}