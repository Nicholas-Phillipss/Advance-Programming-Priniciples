/*
Completed by Nicholas Phillips on Feburary 8th 2022.
Assignment 1 for CPSC 246 taught by Dr. Lee.
Purpose: The purpose of this assignment was to examine how to use functions, 
manipulate, and read through arrays. The goal of the assignment was to validate 
a user file and to display the lowest, highest, sum, and average of the list 
of numbers in their file. For the assignment, we had to create four functions. 
Each of them had to display either the lowest, highest, sum or average. In my program, 
I made one extra function to validate the user file and displayed the list of numbers from 
the user's file. 

*/
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
void displayFile(); //Function prototype for the function readFile
int getLowest(int values[], int size);//Function prototype to find the lowest number
int getHighest(int values[], int size);//Function prototype to find the largest number
int getSum(int values[], int size);//Function prototype to get the sum of the numbers
double getAverage(int values[], int size);//Function prototype to find the average of the numbers
int main() {
    const int size1 = 10; //size of the array
    int value1[size1];//array

    //Output of the functions.
    displayFile();
    cout<<"The smallest number in the array is: "<< getLowest(value1, size1)<<endl;
    cout<<"The highest number in the array is: "<< getHighest(value1, size1)<<endl;
    cout<<"The sum of the array is: "<< getSum(value1, size1)<<endl;
    cout<<"Ther average of the array is: "<<getAverage(value1, size1)<<endl;
    
    return 0;
}

//Checks to see if the user's file exists.
//Prints off the contents of the searched file.
void displayFile() {
    string fileName;
    ifstream myFile;
    cout<<"Enter in the file you want to view: "<<endl;
    cin>>fileName;

    //Checks to see if the file entered exists from the user.
    if (fileName == "array.txt") {
        cout<<"The file does exists, below are the values contained in the file are: "<<endl;
        myFile.open("array.txt");

        //Reads through the file line by line and prints out all the elements in the array.txt file.
        while (myFile.good()) {
            string line;
            getline(myFile, line, ',');
            cout<<line<<endl;
            myFile.close();
        }
    }
    //Will exit out of the program if the file does not exist.
    else {
        cout<<"The file is not real, try again"<<endl;
        exit(0);
    }
}

//Function to find the lowest number from the file
int getLowest(int values[], int size) {
  ifstream inFile;    
    //Open the file
    inFile.open("array.txt");

    int lowest;
    if(inFile.is_open())
    {
        //Reads through the file and checks if size is less than the variable lowest.
        while (inFile >> size)
        {
            if (size < lowest)
            {
                lowest = size;
            }

        }
        //Closes the file
        inFile.close();

    }
    //returns the variable lowest from the function
    return lowest;
}

//Function is used to find the largest number from the file
int getHighest(int values[], int size) {
    ifstream inFile;    
    //Opens the file
    inFile.open("array.txt");
    int largest = 0;
    int numbersInArray = 0;
    
    if(inFile.is_open())
    {
        
        //Reads through the file and checks if numbersInArray is greater than the variable highest.
        while (inFile >> numbersInArray)
        {
            if (numbersInArray > largest)
            {
                largest = numbersInArray;
            }

        }
        //Closes the file
        inFile.close();

    }
    //Returns the variable largest from the function.
    return largest;
}

//Finds the sum of the integers in the array.txt file
int getSum(int values[], int size) {
    int sum = 0;
    ifstream inFile;

    inFile.open("array.txt");
    //checks to see if the file exits
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    //Loops through the array.txt file until it reaches the last element.
    //Stores the sum of all the elements into the variable sum.
    while (inFile >> size) {
        sum = sum + size;
    }
    inFile.close();
    return sum;
}

//Function is used to find the average of the file
double getAverage(int values[], int size) {
    double avg;
    int size1 = 10;
    int value1[size1];
    //Takes in the sum from the function getSum and divides it by the variable size.
    //Casted the variable size1 to a double
    avg = getSum(value1, size1) / (double)size1;

    //returns the variable avg
    return avg;
}
