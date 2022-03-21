/*
Completed by Nicholas Phillips on Marth 20th 2022.
Assignment 3 for CPSC 246 taught by Dr. Lee.

Purpose: The purpose of this assignment was to use advanced file operations and functions.
In this assignment, the user will have to search for the correct text file. If the text file can not be found it will end the program.
If the text file can be found, it will then create an HTML file by reading the text file. 
The HTML file will be created using the ofstream. After that, the program will then use ifstream
for the input file stream for the text file. Finally, it will then use an access flag to read the data
from the file.

*/

#include <iostream>
#include <fstream>
#include <sstream>//for getline
#include <string>
using namespace std;

void checksFile (); //Function prototype.
void read(); //Function prototype.

int main() {
    checksFile(); //Checks to see if the input file does exists.
    read(); //Reads in the input file and display the results in the outfile to create the html file. 
}

void checksFile () {
    string filename("input.txt"); //Text file that we will be reading from.

    cout<<"Enter in the txt file you want to view. Make sure to put .txt at the end: "<<endl;
    cin>>filename; //User input to see if they are reading the correct .txt file.

    //Checks to see if the file does exists. If it does, it will make the html file.
    //If it does not exists, it will exit out of the program. 
    if (filename == "input.txt") {
        cout<<"The file does exists. "<<endl;
        cout<<"An html file called Assignment3.html will now be created in your folder from reading the text file."<<endl;
    }
    else {
        cout<<"Incorrect, please try again."<<endl;
        exit(0);
    }
}

//Reads and opens up the outfile. It uses the input.txt file as a string to read the letters to search and create the tags for the html website. 
void read() {
    ofstream outfile;
    outfile.open("Assignment3.html");
    string filename("input.txt");

    ifstream input_file(filename, ios::in); //Access flag, tells C++ to open the file in input mode.


    char Start='S'; //Searches in the file for the letter 'S' in the input file.
    char Title='T'; //Searches in the file for the letter 'T' in the input file. 
    char Table ='T'; //Searches in the file for the letter 'T' in the input file.
    char Row1='R'; //Searches in the file for the letter 'R' in the input file.
    char Row2='R'; //Searches in the file for the letter 'R' in the input file.

    //Checks to see if the letters in the input file.
    //If the letter is correct, the if statement will get the index and print out the correct tags below.
    //This goes for all the if statements below.  
     if(input_file.get(Start)) {
        outfile << "<html>"; //Beginning of the html tag
        outfile << "<body>";
     }
        //Centers everything and makes a heading
     if(input_file.get(Title)) {
        outfile << "<center>"; //Centering the table and h1 tags
        outfile << "<h1>" << "<h1>CPSC-246 Assignment 3\n" <<"</h1>";

     }
        //Makes the table and border
      if(input_file.get(Table)) {
        outfile << "<table border = \"1\">\n"; 
     }
        //Makes the first row for the table
     if(input_file.get(Row1)){
        outfile <<"<tr>" <<"<td style=color:blue>" <<"Header 1" <<"</td>" <<"<td style=color:blue>"<<"Header 2"<<"</td>" <<"<td style=color:blue>"<<"Header 3"<<"</td>"<<"</tr>";
     }
      //Makes the second row for the table
     if(input_file.get(Row2)){
        outfile << "<tr>"<<"<td style=color:red>" <<"Test 1" <<"</td>" <<"<td style=color:red>"<<"Test 2"<<"</td>" <<"<td style=color:red>"<<"Test 3"<<"</td>"<<"</tr>";
     }
        //Prints out the ending tags for table, center, body, and html tag to the ofstream outfile. 
        outfile <<"</table>" <<"</center>" << "</body>" << "</html>";
}   