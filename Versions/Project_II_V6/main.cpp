/* 
 * File:   main.cpp
 * Author: Jazmyne Patlan
 * Created on February 11th, 2023, 6:24 PM
 * Purpose:  Game of Left Center Right
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <string>    //String Objects
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time Library
#include <iomanip>   //Format Library
#include <fstream>   //Read and Write to a File
#include <cmath>     //Math Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void p1turn(int &, int &, int &, int &, string &);  //Increase/decrease tokens for player 1's turn
void p2turn(int &, int &, int &, int &, string &);  //Increase/decrease tokens for player 2's turn
void p3turn(int &, int &, int &, int &, string &);  //Increase/decrease tokens for player 3's turn
void p4turn(int &, int &, int &, int &, string &);  //Increase/decrease tokens for player 4's turn
float intrst(float, int=3, int=10);  //Calculate interest
void statTbl(float, int [], int [], float [], int , int, int, int);  //Set arrays for table with token sums, sets, and averages
void statTbl(float, int [], int [], float [], string, string, string, string);  //Display table of token sums, sets, and averages
void bublSrt(float []);  //Sort average tokens array
void p1ary(int, int []); //Array for tokens player 1 had each set
void selSrt(int [],int); //Sort array of tokens player 1 had each set
int linSrch(int, int[], int);  //Search for max value of tokens player 1 had in a single set
void end();    //End program 

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    string  player1;        //Player 1's name
    string  player2;        //Player 2's name
    string  player3;        //Player 3's name
    string  player4;        //Player 4's name
    string  dieFace;        //What each side of the die reads
    const int SIZE=500;     //Constant max size for arrays
    int     p1Tkns,         //Player 1's tokens
            p2Tkns,         //Player 2's tokens
            p3Tkns,         //Player 3's tokens
            p4Tkns,         //Player 4's tokens
            die123,         //Random value for each die roll
            pot,            //Pot where tokens go if a Star is rolled
            loop,           //Determines where while loop stops
            count,          //Counts how many sets of tokens there are
            max,            //Max value in player 1 token array
            indx,           //Index marks position in array where a value is
            sumTkns[SIZE],  //Array for individual sum of tokens for each player
            plrTkns[SIZE],  //Array for looped sum of tokens for each player
            p1array[SIZE];  //Array for tokens player 1 had each set
    char    roll;           //Determines if a calculation of a roll should occur
    float   i,              //Interest in percent form
            p1avg,          //Average tokens player 1 had
            p2avg,          //Average tokens player 2 had
            p3avg,          //Average tokens player 3 had
            p4avg,          //Average tokens player 4 had
            avgTkns[SIZE];  //Array for average tokens players had
    fstream in,             //Read in initialization for variables
            out;            //Write out results of game and winnings
    
    //Initialize Variables
    i=6;      //Percent interest 
    indx=0;   //Position where max is found
    p1array[0]=3;  //First value in player 1 tokens array
    
    //Intro message
    cout<<"Game of Left Center Right"<<endl;
    cout<<"This program requires four players"<<endl;
    cout<<"Players are arranged in a circle facing the Pot, as displayed";
    cout<<" below:"<<endl<<endl;
    
    //Display player orientation that program works for
    cout<<"               Player 3               "<<endl;
    cout<<"Player 2         Pot          Player 4"<<endl;
    cout<<"               Player 1               "<<endl<<endl;
    
    in.open("input7.dat",ios::in);               //Input and output files
    out.open("LCRoutput7.dat",ios::out);
    in>>p1Tkns>>p2Tkns>>p3Tkns>>p4Tkns>>pot>>loop>>p1avg>>p2avg>>p3avg>>p4avg>>count;
    
    //Input prompt for player names
    cout<<"Enter four names"<<endl;
    cin>>player1>>player2>>player3>>player4;
    cout<<endl;
    
    //Map/Process the Inputs -> Outputs
    cout<<"Each player starts with three tokens and the Pot starts empty"<<endl;
    cout<<player1<<setw(3)<<p1Tkns<<endl;     //Output player and tokens
    cout<<player2<<setw(3)<<p2Tkns<<endl;
    cout<<player3<<setw(3)<<p3Tkns<<endl;
    cout<<player4<<setw(3)<<p4Tkns<<endl;
    cout<<"Pot"<<setw(3)<<pot<<endl<<endl;    //Output pot tokens
    
    //For Player 1's turn
    cout<<player1<<"'s turn"<<endl;
    cout<<"To roll press Y or y"<<endl;
    cin>>roll;
    do{                    //Continues program as long as roll=='Y' or roll=='y'
        if (roll=='Y'||roll=='y'){
            if (p1Tkns>=3){       //If player has over 3 tokens, roll three dice
                cout<<"Roll: ";
                for (int i=1; i<=3; i++){
                    die123=rand()%6+1;      //Sets random number between 1-6
                    dieFace = (die123==1)? "Left":   //Find what each die reads
                              (die123==2)? "Right":
                              (die123==3)? "Star":
                              (die123==4)? "Dot":
                              (die123==5)? "Dot": "Dot";
                              
                              //Increase/decrease tokens for player 1 turn
                              p1turn(p1Tkns, p2Tkns, p4Tkns, pot, dieFace);  

                    cout<<dieFace<<"   ";   //Display dice results
                }
            }else if (p1Tkns==2){
                cout<<"Roll: ";
                while (loop<=2){   //If player has 2 tokens, loop die roll twice
                    die123=rand()%6+1; //Sets random number between 1-6
                    if (die123==1){
                        dieFace="Left";}  //Die reads left if random number is 1
                    if (die123==2){
                        dieFace="Right";}//Die reads right if random number is 2
                    if (die123==3){
                        dieFace="Star";} //Die reads star if random number is 3
                    if (die123==4){
                        dieFace="Dot";} //Die reads dot for other random numbers
                    if (die123==5){
                        dieFace="Dot";}
                    if (die123==6){
                        dieFace="Dot";}

                    //Increase/decrease tokens for player 1 turn
                    p1turn(p1Tkns, p2Tkns, p4Tkns, pot, dieFace);  

                    cout<<dieFace<<"   ";  //Display dice results
                    loop++;                //Increment loop until at 2
                }
                loop=1;                //Set loop back to 1 so can be used again
            }else if (p1Tkns==1){      //If player has 1 token, roll die once
                cout<<"Roll: ";
                die123=rand()%6+1;     //Sets random number between 1-6
                switch(die123){
                    case 1: dieFace="Left";break;  //Die reads left if 1
                    case 2: dieFace="Right";break; //Die reads right if 2
                    case 3: dieFace="Star";break;  //Die reads star if 1
                    case 4:                        //Die reads dot if 4, 5, or 6
                    case 5: 
                    case 6: dieFace="Dot";break;   
                    default:cout<<"Error"<<endl;  //If any other number, error
                }
            
                //Increase/decrease tokens for player 1 turn
                p1turn(p1Tkns, p2Tkns, p4Tkns, pot, dieFace);  
                
                cout<<dieFace<<"   ";     //Display dice results
            }else{                        //If zero tokens, skip turn
                cout<<"Skip turn, same amount of tokens remain";
            }  
            cout<<endl;
            cout<<player1<<setw(3)<<p1Tkns<<endl;  //Display each players tokens
            cout<<player2<<setw(3)<<p2Tkns<<endl;
            cout<<player3<<setw(3)<<p3Tkns<<endl;
            cout<<player4<<setw(3)<<p4Tkns<<endl;
            if (pot>9){                       //Set width based on tokens in pot
                cout<<"Pot"<<setw(4)<<pot<<endl<<endl;
            }else{
                cout<<"Pot"<<setw(3)<<pot<<endl<<endl;
            }
            
            
            p1ary(p1Tkns,p1array); //Put player 1's tokens in an array
            
            
            p1avg+=p1Tkns; //Add players tokens together for average calculation
            p2avg+=p2Tkns;
            p3avg+=p3Tkns;
            p4avg+=p4Tkns; 
            count++;       //Count each set of tokens
            
            
            bool winner=false;
            if (p2Tkns==0&&p3Tkns==0&&p4Tkns==0){      //If one player has...
                winner=true;                          //tokens they win
                out<<"GAME OVER - "<<player1<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p3Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player2<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player3<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p3Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player4<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }
            if (!winner){             //If no players won, display input message
            cout<<player2<<"'s turn"<<endl;
            cout<<"To roll press Y or y"<<endl;
            cin>>roll;
            }
        }
        
    
    //For Player 2's turn
        if (roll=='Y'||roll=='y'){
            if (p2Tkns>=3){       //If player has over 3 tokens, roll three dice
                cout<<"Roll: ";
                for (int i=1; i<=3; i++){
                    die123=rand()%6+1;      //Sets random number between 1-6
                    dieFace = (die123==1)? "Left":   //Find what each die reads
                              (die123==2)? "Right":
                              (die123==3)? "Star":
                              (die123==4)? "Dot":
                              (die123==5)? "Dot": "Dot";

                    //Increase/decrease tokens for player 2 turn
                    p2turn(p1Tkns, p2Tkns, p3Tkns, pot, dieFace);  

                    cout<<dieFace<<"   ";   //Display dice results
                }
            }else if (p2Tkns==2){        //If player has 2 tokens, roll two dice
                cout<<"Roll: ";
                do{                   //Set one die result before test
                    die123=rand()%6+1;
                    if (die123==1){
                        dieFace="Left";}//Die reads left if random number is 1
                    if (die123==2){
                        dieFace="Right";}//Die reads right if random number is 2
                    if (die123==3){
                        dieFace="Star";}//Die reads star if random number is 3
                    if (die123==4){
                        dieFace="Dot";} //Die reads dot for other random numbers
                    if (die123==5){
                        dieFace="Dot";}
                    if (die123==6){
                        dieFace="Dot";}

                    //Increase/decrease tokens for player 2 turn
                    p2turn(p1Tkns, p2Tkns, p3Tkns, pot, dieFace);  

                    cout<<dieFace<<"   ";  //Display dice results
                    loop++;                //Increment loop until at 2
                }while (loop<=2);
                loop=1;                //Set loop back to 1 so can be used again

            }else if (p2Tkns==1){      //If player has 1 token, roll die once
                cout<<"Roll: ";
                die123=rand()%6+1;     //Sets random number between 1-6
                switch(die123){
                    case 1: dieFace="Left";break;  //Die reads left if 1
                    case 2: dieFace="Right";break; //Die reads right if 2
                    case 3: dieFace="Star";break;  //Die reads star if 1
                    case 4:                        //Die reads dot if 4, 5, or 6
                    case 5: 
                    case 6: dieFace="Dot";break;   
                    default:cout<<"Error"<<endl;  //If any other number, error
                }
            
                //Increase/decrease tokens for player 2 turn
                p2turn(p1Tkns, p2Tkns, p3Tkns, pot, dieFace);  
                
                cout<<dieFace<<"   ";     //Display dice results
            }else{                        //If zero tokens, skip turn
                cout<<"Skip turn, same amount of tokens remain";
            }  
            cout<<endl;
            cout<<player1<<setw(3)<<p1Tkns<<endl;  //Display each players tokens
            cout<<player2<<setw(3)<<p2Tkns<<endl;
            cout<<player3<<setw(3)<<p3Tkns<<endl;
            cout<<player4<<setw(3)<<p4Tkns<<endl;
            if (pot>9){                       //Set width based on tokens in pot
                cout<<"Pot"<<setw(4)<<pot<<endl<<endl;
            }else{
                cout<<"Pot"<<setw(3)<<pot<<endl<<endl;
            }
            
            
            p1ary(p1Tkns,p1array);  //Put player 1's tokens in an array
            
            
            p1avg+=p1Tkns; //Add players tokens together for average calculation
            p2avg+=p2Tkns;
            p3avg+=p3Tkns;
            p4avg+=p4Tkns; 
            count++;       //Count each set of tokens
            
            
            bool winner=false;
            if (p2Tkns==0&&p3Tkns==0&&p4Tkns==0){      //If one player has...
                winner=true;                          //tokens they win
                out<<"GAME OVER - "<<player1<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p3Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player2<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player3<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p3Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player4<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }
            if (!winner){             //If no players won, display input message
            cout<<player3<<"'s turn"<<endl;
            cout<<"To roll press Y or y"<<endl;
            cin>>roll;
            }
        }
   
    
    //For Player 3's turn
        if (roll=='Y'||roll=='y'){
            if (p3Tkns>=3){       //If player has over 3 tokens, roll three dice
                cout<<"Roll: ";
                for (int i=1; i<=3; i++){
                    die123=rand()%6+1;      //Sets random number between 1-6
                    dieFace = (die123==1)? "Left":   //Find what each die reads
                              (die123==2)? "Right":
                              (die123==3)? "Star":
                              (die123==4)? "Dot":
                              (die123==5)? "Dot": "Dot";

                    //Increase/decrease tokens for player 3 turn
                    p3turn(p2Tkns,p3Tkns,p4Tkns,pot,dieFace);  

                    cout<<dieFace<<"   ";   //Display dice results
                }
            }else if (p3Tkns==2){
                cout<<"Roll: ";
                while (loop<=2){   //If player has 2 tokens, loop die roll twice
                    die123=rand()%6+1; //Sets random number between 1-6
                    if (die123==1){
                        dieFace="Left";}  //Die reads left if random number is 1
                    if (die123==2){
                        dieFace="Right";}//Die reads right if random number is 2
                    if (die123==3){
                        dieFace="Star";} //Die reads star if random number is 3
                    if (die123==4){
                        dieFace="Dot";} //Die reads dot for other random numbers
                    if (die123==5){
                        dieFace="Dot";}
                    if (die123==6){
                        dieFace="Dot";}

                    //Increase/decrease tokens for player 3 turn
                    p3turn(p2Tkns,p3Tkns,p4Tkns,pot,dieFace);  

                    cout<<dieFace<<"   ";  //Display dice results
                    loop++;                //Increment loop until at 2
                }
                loop=1;                //Set loop back to 1 so can be used again
            }else if (p3Tkns==1){      //If player has 1 token, roll die once
                cout<<"Roll: ";
                die123=rand()%6+1;     //Sets random number between 1-6
                switch(die123){
                    case 1: dieFace="Left";break;  //Die reads left if 1
                    case 2: dieFace="Right";break; //Die reads right if 2
                    case 3: dieFace="Star";break;  //Die reads star if 1
                    case 4:                        //Die reads dot if 4, 5, or 6
                    case 5: 
                    case 6: dieFace="Dot";break;   
                    default:cout<<"Error"<<endl;  //If any other number, error
                }
            
                //Increase/decrease tokens for player 3 turn
                p3turn(p2Tkns, p3Tkns,p4Tkns,pot,dieFace);  
                
                cout<<dieFace<<"   ";     //Display dice results
            }else{                        //If zero tokens, skip turn
                cout<<"Skip turn, same amount of tokens remain";
            }  
            cout<<endl;
            cout<<player1<<setw(3)<<p1Tkns<<endl;  //Display each players tokens
            cout<<player2<<setw(3)<<p2Tkns<<endl;
            cout<<player3<<setw(3)<<p3Tkns<<endl;
            cout<<player4<<setw(3)<<p4Tkns<<endl;
            if (pot>9){                       //Set width based on tokens in pot
                cout<<"Pot"<<setw(4)<<pot<<endl<<endl;
            }else{
                cout<<"Pot"<<setw(3)<<pot<<endl<<endl;
            }
            
            
            p1ary(p1Tkns,p1array);  //Put player 1's tokens in an array
            
            
            p1avg+=p1Tkns; //Add players tokens together for average calculation
            p2avg+=p2Tkns;
            p3avg+=p3Tkns;
            p4avg+=p4Tkns; 
            count++;       //Count each set of tokens
            
            
            bool winner=false;
            if (p2Tkns==0&&p3Tkns==0&&p4Tkns==0){      //If one player has...
                winner=true;                          //tokens they win
                out<<"GAME OVER - "<<player1<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p3Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player2<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player3<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p3Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player4<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }
            if (!winner){             //If no players won, display input message
            cout<<player4<<"'s turn"<<endl;
            cout<<"To roll press Y or y"<<endl;
            cin>>roll;
            }
        }
    
    
    //For Player 4's turn
        if (roll=='Y'||roll=='y'){
            if (p4Tkns>=3){       //If player has over 3 tokens, roll three dice
                cout<<"Roll: ";
                for (int i=1; i<=3; i++){
                    die123=rand()%6+1;      //Sets random number between 1-6
                    dieFace = (die123==1)? "Left":   //Find what each die reads
                              (die123==2)? "Right":
                              (die123==3)? "Star":
                              (die123==4)? "Dot":
                              (die123==5)? "Dot": "Dot";

                    //Increase/decrease tokens for player 4 turn
                    p4turn(p1Tkns,p3Tkns,p4Tkns,pot,dieFace);  

                    cout<<dieFace<<"   ";   //Display dice results
                }
            }else if (p4Tkns==2){
                cout<<"Roll: ";
                while (loop<=2){   //If player has 2 tokens, loop die roll twice
                    die123=rand()%6+1; //Sets random number between 1-6
                    if (die123==1){
                        dieFace="Left";}  //Die reads left if random number is 1
                    if (die123==2){
                        dieFace="Right";}//Die reads right if random number is 2
                    if (die123==3){
                        dieFace="Star";} //Die reads star if random number is 3
                    if (die123==4){
                        dieFace="Dot";} //Die reads dot for other random numbers
                    if (die123==5){
                        dieFace="Dot";}
                    if (die123==6){
                        dieFace="Dot";}

                    //Increase/decrease tokens for player 4 turn
                    p4turn(p1Tkns,p3Tkns,p4Tkns,pot,dieFace);  

                    cout<<dieFace<<"   ";  //Display dice results
                    loop++;                //Increment loop until at 2
                }
                loop=1;                //Set loop back to 1 so can be used again
            }else if (p4Tkns==1){      //If player has 1 token, roll die once
                cout<<"Roll: ";
                die123=rand()%6+1;     //Sets random number between 1-6
                switch(die123){
                    case 1: dieFace="Left";break;  //Die reads left if 1
                    case 2: dieFace="Right";break; //Die reads right if 2
                    case 3: dieFace="Star";break;  //Die reads star if 1
                    case 4:                        //Die reads dot if 4, 5, or 6
                    case 5: 
                    case 6: dieFace="Dot";break;   
                    default:cout<<"Error"<<endl;  //If any other number, error
                }
            
                //Increase/decrease tokens for player 4 turn
                p4turn(p1Tkns,p3Tkns,p4Tkns,pot,dieFace);  
                
                cout<<dieFace<<"   ";     //Display dice results
            }else{                        //If zero tokens, skip turn
                cout<<"Skip turn, same amount of tokens remain";
            }  
            cout<<endl;
            cout<<player1<<setw(3)<<p1Tkns<<endl;  //Display each players tokens
            cout<<player2<<setw(3)<<p2Tkns<<endl;
            cout<<player3<<setw(3)<<p3Tkns<<endl;
            cout<<player4<<setw(3)<<p4Tkns<<endl;
            if (pot>9){                       //Set width based on tokens in pot
                cout<<"Pot"<<setw(4)<<pot<<endl<<endl;
            }else{
                cout<<"Pot"<<setw(3)<<pot<<endl<<endl;
            }

          
            p1ary(p1Tkns,p1array);  //Put player 1's tokens in an array
            
            
            p1avg+=p1Tkns; //Add players tokens together for average calculation
            p2avg+=p2Tkns;
            p3avg+=p3Tkns;
            p4avg+=p4Tkns; 
            count++;       //Count each set of tokens
            
            bool winner=false;
            if (p2Tkns==0&&p3Tkns==0&&p4Tkns==0){      //If one player has...
                winner=true;                          //tokens they win
                out<<"GAME OVER - "<<player1<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p3Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player2<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player3<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p3Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player4<<" Wins"<<endl;
                roll='0';                        //Set roll to zero to exit loop
            }
            if (!winner){             //If no players won, display input message
            cout<<player1<<"'s turn"<<endl;
            cout<<"To roll press Y or y"<<endl;
            cin>>roll;
            }
        }
    }while (roll=='Y'||roll=='y');    //Loop back to player 1's turn
   
    //Display Inputs/Outputs
    //Output file messages
    out<<endl<<endl<<"One version of the game includes substituting the tokens";
    out<<" for quarters"<<endl;
    out<<"The winner is then entitled to all quarters, even the ones";
    out<<" in the Pot"<<endl;
    
    //Display potential wins
    out<<"If players were gambling with this program, the winner would be";
    out<<" entitled to $3"<<endl;

    //Output money after interest
    out<<"If the winner were to invest the $3 dollars with 6% interest";
    out<<", after 10 years the winner would have $";
    out<<setprecision(2)<<fixed<<intrst(i)<<endl;
    
    //Message directing to output file and statistic table
    cout<<"Go to output file to see results"<<endl<<endl<<endl;
    cout<<"Look below to see some bonus game statistics:"<<endl<<endl;
    
    //Initialize arrays and display table
    statTbl(static_cast<float>(count), plrTkns, sumTkns, avgTkns, p1avg, p2avg, 
            p3avg, p4avg);
    statTbl(static_cast<float>(count), plrTkns, sumTkns, avgTkns, player1,
            player2,player3,player4);
    
    //Sort function for token averages
    bublSrt(avgTkns);
    cout<<"The lowest token average was: "<<avgTkns[0]<<endl;
    
    selSrt(p1array,count);  //Sort functions for player 1 tokens each set
    max=p1array[count-1];   //Set max value
    
    indx=linSrch(count, p1array, max);  //Linear search function to find array position
    if (indx!=-1){  //If max value was found, display it and it's position
        cout<<"The max amount of tokens "<<player1<<" had during a round was: ";
        cout<<max<<", which was found at index = "<<indx<<endl<<endl;
    }
    
    //Clean up memory and files
    in.close();
    out.close();
    end();       //Function to display final message and exit
    
    //Exit the Program
    return 0;
}

//Increase/decrease tokens for player 1's turn
void p1turn(int &p1Tkns, int &p2Tkns, int &p4Tkns, int &pot, string &dieFace){
    if (dieFace=="Left"){   //Increase/decrease tokens for left
                        p2Tkns+=1;          
                        --p1Tkns;}
                    if (dieFace=="Right"){  //Increase/decrease tokens for right
                        p4Tkns+=1;
                        --p1Tkns;}
                    if (dieFace=="Star"){   //Increase/decrease tokens for star
                        pot+=1;
                        --p1Tkns;}
}

//Increase/decrease tokens for player 2's turn
void p2turn(int &p1Tkns, int &p2Tkns, int &p3Tkns, int &pot, string &dieFace){
    if (dieFace=="Left"){   //Increase/decrease tokens for left
                        p3Tkns+=1;          
                        --p2Tkns;}
                    if (dieFace=="Right"){  //Increase/decrease tokens for right
                        p1Tkns+=1;
                        --p2Tkns;}
                    if (dieFace=="Star"){   //Increase/decrease tokens for star
                        pot+=1;
                        --p2Tkns;}
}

//Increase/decrease tokens for player 3's turn
void p3turn(int &p2Tkns, int &p3Tkns, int &p4Tkns, int &pot, string &dieFace){
    if (dieFace=="Left"){   //Increase/decrease tokens for left
                        p4Tkns+=1;          
                        --p3Tkns;}
                    if (dieFace=="Right"){  //Increase/decrease tokens for right
                        p2Tkns+=1;
                        --p3Tkns;}
                    if (dieFace=="Star"){   //Increase/decrease tokens for star
                        pot+=1;
                        --p3Tkns;}
}

//Increase/decrease tokens for player 4's turn
void p4turn(int &p1Tkns, int &p3Tkns, int &p4Tkns, int &pot, string &dieFace){
    if (dieFace=="Left"){   //Increase/decrease tokens for left
                        p1Tkns+=1;          
                        --p4Tkns;}
                    if (dieFace=="Right"){  //Increase/decrease tokens for right
                        p3Tkns+=1;
                        --p4Tkns;}
                    if (dieFace=="Star"){   //Increase/decrease tokens for star
                        pot+=1;
                        --p4Tkns;}
}

//Calculate interest for winnings
float intrst(float i, int pv, int yrs){
    i/=100;
    return pv*pow(1+i,yrs); //Equation to find future value
}

//Set arrays for statistic table
void statTbl(float count, int plrTkns[], int sumTkns[], float avgTkns[], 
        int p1avg, int p2avg, int p3avg, int p4avg){

    plrTkns[0]=p1avg;  //Set tokens array positions to total sum of each players tokens
    plrTkns[1]=p2avg;
    plrTkns[2]=p3avg;
    plrTkns[3]=p4avg;
    
    for (int j=0; j<4; j++){
        sumTkns[j]= plrTkns[j];   //Set sum array to tokens array
        avgTkns[j]=plrTkns[j]/count;  //Set average array values from tokens array and count
    }
}
//Display statistic table
void statTbl(float count, int plrTkns[], int sumTkns[], float avgTkns[], 
        string player1, string player2, string player3, string player4){
    //Display table header
    cout<<"     Player   Total Tokens   # of Sets   Average Tokens"<<endl;
    for (int j=0; j<4; j++){
        if (j==0){
            cout<<setw(11)<<player1;  //Output player name based on array position
        }else if (j==1){
            cout<<setw(11)<<player2;
        }else if (j==2){
            cout<<setw(11)<<player3;
        }else if (j==3){              //For last position, display final name
            cout<<setw(11)<<player4;  
        }
        
        //Output sum of tokens, number of token sets, and average number of tokens per player
        cout<<setw(15)<<sumTkns[j]<<setw(12)<<static_cast<int>(count);
        cout<<setw(17)<<fixed<<setprecision(2)<<avgTkns[j]<<endl;
    }
    cout<<endl;
}

//Sort average tokens array
void bublSrt(float avgTkns[]){
    bool swap;
    do{
        swap=false;   //Initialize bool to false
        for(int i=0; i<3; i++){
            if (avgTkns[i]>avgTkns[i+1]){  //If the value of the following array position is smaller, swap
                float temp=avgTkns[i];     //Use temporary variable to complete swap
                avgTkns[i]=avgTkns[i+1];
                avgTkns[i+1]=temp;
                swap=true;   //Set swap to true if a swap occurred
            }
        }
    }while(swap);  //Swap as long as the swap bool is true
}

//Array for tokens player 1 had each set
void p1ary(int p1Tkns, int p1array[]){
    static int k=1;  
    p1array[k]=p1Tkns;  //Add token value into array
    k++;   //Increase array position every time function is called
}

//Sort array values for player 1 tokens
void selSrt(int p1array[],int count){
    for (int k=0; k<count-1; k++){  //Loop for original positions
        for (int j=k+1; j<count; j++){  //Loop for one position ahead 
            if(p1array[k]>p1array[j]){  //If position ahead is smaller, swap
                int temp=p1array[k];
                p1array[k]=p1array[j];
                p1array[j]=temp;        //Complete swap
            }
        }
    }
}

//Search for max amount of tokens player 1 had in a set
int linSrch(int count, int p1array[], int max){
    for (int k=0; k<count; k++){
        if (p1array[k]==max){  //If the array position matches max value, return position
            return k;
        }
    }
    return -1;   //If the value doesn't match any position, return -1
}

//Exit program
void end(){
    cout<<"Goodbye";  //Final message
    exit(0);
}