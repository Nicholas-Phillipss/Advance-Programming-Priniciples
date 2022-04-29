/*

Created by Nicholas Phillips and Samantha Duffy on April 27th-29th.

The purpose of this assignment is for students to implement Object-Oriented concepts. In this assignment, 
our team used the concepts of objects, inheritance, and polymorphism. The goal of this assignment is to 
use each of the concepts above to create a working mastermind game. For our assignment we created both
public and private objects. For the private object, we place in the correct answer created by the computer 
and our function to verify if the color positions are correct and color. Next, the user has ten tries to guess 
the correct color sequence. The colors are red, blue, green, yellow, orange, and purple. To guess you enter the 
first letter of the color in a four letter sequence. After a guess, two numbers will be shown. The first number
 will say how many correct colors are in the right place. The second number says how many colors are correct in 
 the wrong position. Then, after each guess, the user will lose a turn until ten tries are up. Finally, at the end 
 of the game the correct sequence will be shown and the user will have the option to play again if they won or lost. 



*/


#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>  // For srand() and rand()
using namespace std;
void instructions (); //Function to display instructions
int codeChecker(); //Function to check codes 

class codeMaker {
    //public attribute
    public:
        int userGuess = 10; //Amount of times a user can guess
    //private attribute
    private:
        int nums[4] = {}; //Amount of user input per guess
        int codeChecker(); //Function
};

int main () {
    codeMaker code;
    int userGuess = 10; //Amount of times a user can guess
    instructions(); //function call back
    codeChecker(); //function call back
}

int codeChecker() {
    codeMaker code;
    stringstream stream; //Used to convert strings and the user interger
    string guess; //Used to convert strings and the user interger
    int i; //Loops control variables 
    int nums[4] = {}; //Amount of user input per guess

    //Samantha and Nick completed 
    //Generates 4 random numbers between 1 - 6
    srand( time(NULL) );
    nums[0] = rand() % 6 + 1; // 1 to 6
    nums[1] = rand() % 6 + 1;
    nums[2] = rand() % 6 + 1;
    nums[3] = rand() % 6 + 1;
    
    // Nick completed
    for(int i = 0; i < 4; ++i) {
        stream << nums[i]; //put each value into the string stream
    }
    string fullString = stream.str(); //Makes the value a string
    //Samantha and Nick completed
    //Validates the user input  
    for(i = 0; i < code.userGuess; ++i) {
        int correct = 0;
        cout << "Enter a 4 number code "<<"(Guess Number: "<<i<<")"<<endl;
        getline(cin, guess);
        if(guess.size() != 4) { // to only allow 4 characters.
            cout << "Please enter 4 numbers "<<"((Guess Number: "<<i<<")"<<endl;
            i--;
            continue; // so it does not count an invalid num
        }
        //Checks the users value with the string 
        if(guess[0] == fullString[0]) {
            cout << "First number correct" << endl;
            correct++;
        }
        if(guess[1] == fullString[1]) {
            cout << "Second number correct" << endl;
            correct++;
        }if(guess[2] == fullString[2]) {
            cout << "Third number correct" << endl;
            correct++;
        } if(guess[3] == fullString[3]) {
            cout << "Last number correct" << endl;
            correct++;
        }
        //You won
        if(correct == 4) {
            cout << "You win! Exiting." << endl;
            exit(0);

        }
        //No guesses were correct 
        if(correct == 0) cout << "NONE CORRECT!"<< endl;
    }
    //You lost
    cout<<"You lost, the correct code was: "<< fullString[0]<<" "<< fullString[1]<<" "<< fullString[2]<<" "<< fullString[3]<<endl;
    return 0;
}

//Samantha completed 
//Instructions for the game.
void instructions () {
    cout << "-----     Welcome to Mastermind     -----" << endl;
    cout << "The goal is to guess the correct four number combination before 10 turns." << endl;
    cout << "Everytime you guess, the program will let you know what number is correct." << endl;
    cout << "To guess, enter a number between 1 - 6." << endl;
    cout << "A sample guess would be look like this: 1236" << endl; 
}