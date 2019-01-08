//  sudoku.cpp
//  Sudoku
//
//  Created by James Lawson on 12/4/18.
//  Copyright © 2018 James Lawson. All rights reserved.
//
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Games {
private:
    char puzzleNum; // store index of which number in the puzzle
public:
    char gameGrid[60][81]; // 60 rows (10 game of each of the 3 difficulties, solution below each game.
    void read_gameFile(){
        ifstream gameFile("/Users/jamesMacBook/Desktop/introToC++/Sudoku/games.txt"); //read this file
        if (!gameFile) {
            cout << "Game not found."; // troubleshoot if file is not found
        }
        else {
            // read games file and assign numbers into 2D Array
            for (int i=0;i<60;i++) { // nested for-loops begin 0 to account for array offset
                for (int j=0;j<=81;j++) {
                    gameFile.get(puzzleNum); // retrieve assigned puzzle number in requested difficulty
                    gameGrid[i][j]=puzzleNum;} } // assign numbers from txt into the array
            gameFile.close();
        }
    }
};
class Sudoku : public Games {
private:
    string difficulty; // easy, medium or hard. assigned by user.
    int userScore = 100; // begin score at 100 up here so it changes everytime an error is made.
    int selectedRow; // user selected row
    int selectedColumn; // followed by user selected column
    char selectedEntry; // user attempt at puzzle - entry must be declared as type char for user input
public:
    int startGame(){
        read_gameFile();
            cout << "Enter easy, medium or hard difficulty to begin Sudoku: " << endl;
            cin >> difficulty; // prompt user for difficulty
            int i=0; // start in easy, medium, or hard section of puzzle list
            if (difficulty=="easy") {
                cout << "easy puzzle: " << "\n" << endl;
                i=0;} // point to the easy 10
            if (difficulty=="medium") {
                cout << "medium puzzle: " << "\n" << endl;
                i=20;} // point to the medium 10
            if (difficulty=="hard") {
                cout << "hard puzzle:  " << "\n" << endl;
                i=40;} // point to the hard 10
            srand(time_t(NULL));// generate random # for puzzle selection of requested difficulty
            i = i + 2 * (rand() % 5 + 1);// the even denominations are the answers, loop through only odds to print ( "2 * rand() + 1 is always an odd integer" )
            while (difficulty == "easy" || difficulty == "medium" || difficulty == "hard") { // address of gameGrid will always evaluate to true while program is running
                cout << "-----------" << endl;
                for (int  j=0; j<3;  j++) {cout<<gameGrid[i][j];} cout<<"|"; // prints puzzle with pipe symbol every 3 char's
                for (int  j=3; j<6;  j++) {cout<<gameGrid[i][j];} cout<<"|" ;
                for (int  j=6; j<9;  j++) {cout<<gameGrid[i][j];} cout<<endl;//break line every 9 char's
                for (int  j=9; j<12; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=12; j<15; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=15; j<18; j++) {cout<<gameGrid[i][j];} cout<<endl;
                for (int j=18; j<21; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=21; j<24; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=24; j<27; j++) {cout<<gameGrid[i][j];} cout<<endl;
                cout << "..........." << endl;
                for (int j=27; j<30; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=30; j<33; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=33; j<36; j++) {cout<<gameGrid[i][j];} cout<<endl;
                for (int j=36; j<39; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=39; j<42; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=42; j<45; j++) {cout<<gameGrid[i][j];} cout<<endl;
                for (int j=45; j<48; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=48; j<51; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=51; j<54; j++) {cout<<gameGrid[i][j];} cout<<endl;
                cout << "..........." << endl;
                for (int j=54; j<57; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=57; j<60; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=60; j<63; j++) {cout<<gameGrid[i][j];} cout<<endl;
                for (int j=63; j<66; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=66; j<69; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=69; j<72; j++) {cout<<gameGrid[i][j];} cout<<endl;
                for (int j=72; j<75; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=75; j<78; j++) {cout<<gameGrid[i][j];} cout<<"|";
                for (int j=78; j<81; j++) {cout<<gameGrid[i][j];} cout<< endl;
                cout << "------------" << endl << endl;
                
                int k = 0; // k will be the column which the users input in entered into the gameGrid[][] in the condition below
                cout << "Select row, column, and value. Hit enter once after each selection." << endl;
                cout << " Enter 0 or type 'exit' to quit game." << endl;
                cin >>  selectedRow;
                cin >> selectedColumn;
                cin >> selectedEntry;
                if (selectedRow==0) {
                    cout << "Game Over" << endl;
                    cout << "Score: " << userScore << "/100" << endl;
                    return 0;} // End of program
                k = 9 *(selectedRow - 1) + (selectedColumn - 1); // subract 1 from each entry to account for array's offset 0.
                if (gameGrid[i][k]=='0'){
                    gameGrid[i][k]=selectedEntry;
                }
                else { userScore = userScore - 5; // subract 5 points for each mistake (began with 100 in definition above)
                    cout << "Incorrect. Try again." << endl;
                    cout << "Current score: " << userScore << endl;
//                } else if (i>0 & j>0){
//                    cout << "Complete! Score: " << userScore << "/100" << endl;
//                }
//                else  {
                    // reset or program will break after bad entry.
                    selectedRow=0;
                    selectedColumn=0;
                    selectedEntry='0';
                }
            } // end of while loop
        return 0;
    } // end of startGame function
};
