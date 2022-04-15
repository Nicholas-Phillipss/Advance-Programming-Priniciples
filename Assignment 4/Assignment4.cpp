/*
The purpose of this assignment is for students to become familiar with 
strings, c-string, arrays, structure data, and conditional statements. For 
this assignment, we used structured data to hold data types of each of 
the six players (name, number, and points). Then, the program will loop 
through a for loop asking the user to input the name, number, and points 
scored by each of the six players. Once each player’s data is recorded, all 
the information will be presented in a table. Once the table is printed out, the 
program will then add up all the player's points to find the total points by the 
team using a for a loop. Lastly, the program will then find the player who scored 
the highest amount of points using a for loop and if statement. This information will then be 
printed out displaying the player's name and number. 


*/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>


using namespace std;

const int SIZE = 100;
const int VOLLEYBALL_PLAYERS = 6; //Number of players on the volleyball team. 

struct Players
{
       char name[SIZE];//Player's Name
       int number;//Player's Number
       int points;//Point's Scored
};

int main () {

    Players *players = new Players[VOLLEYBALL_PLAYERS]; //Array of structures
    int i; //Loop Control Variable
	int total=0; //Total number of points scored by the team.

    //Reference to slide 49 and 50 lecture 10
    //Loops through all the players and asks for their name, number, and points
    for (i = 0; i < VOLLEYBALL_PLAYERS; i++ ) {
        cout<<"PLAYER #"<<i+1<<endl; //Will add 1 to the players number.
        cout<<"---------"<<endl; //Divider
        cout<<"Player's name: ";
        cin.getline(players[i].name, 100);//Gets line, will read un to 100 characters for the user's name
        cout<<"Player's number: ";
        (cin >> players[i].number).get();//Gets the user's number.
        cout<<"Points scored: ";
        (cin >> players[i].points).get();
        cout<<" "<<endl;
    }

    //Displays for the name, number, and points for all the players
    cout << "Here is the players data:\n\n";
	cout << "    Name    Number    Points	\n";
	cout << "--------------------------------\n";
      
      for (i = 0; i < VOLLEYBALL_PLAYERS; i++)
	{
		cout << setw(8) << players[i].name; //set width
		cout << setw(8) << players[i].number; //set width
		cout << setw(8) << players[i].points << endl; //set width
	}

    cout << "--------------------------------\n";


    //Calculate the total points
	for (i = 0; i < VOLLEYBALL_PLAYERS; i++)
	{
		total += players[i].points;
		
	}

    //Display the results of the total points.
	cout << "\n\nThe total of points scored by the team are: ";
	cout << total << endl;

    
    int max=players[0].points;
    int maxIndex = 0;

    //Finds the player who scored the highest points
    for (i = 0; i < VOLLEYBALL_PLAYERS; i ++) {
        if (players[i].points > max) {
            max = players[i].points;
            maxIndex = i;

        }
    }
    //Displays the player with the highest points
    cout << "The highest scorer of the game is: " << players[maxIndex].name << " they are number: " << players[maxIndex].number <<" on the team."<<endl;

}