/* 
 * File:   main.cpp
 * Author: Jazmyne Patlan
 * Created on February 10th, 2023, 3:58 PM
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
void p1turn(int &, int &, int &, int &, string &);
void p2turn(int &, int &, int &, int &, string &);
float average(float , int );
float average(float , unsigned char );
float intrst(float, int=3, int=10);
void end();
void statTbl(int, int [], int [], float [], int , int, int, int);
void dsplTbl(int, int [], int [], float [], string, string, string, string);

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    string  player1;   //Player 1's name
    string  player2;   //Player 2's name
    string  player3;   //Player 3's name
    string  player4;   //Player 4's name
    string  dieFace;   //What each side of the die reads
    int     p1Tkns,    //Player 1's tokens
            p2Tkns,    //Player 2's tokens
            p3Tkns,    //Player 3's tokens
            p4Tkns,    //Player 4's tokens
            die123,    //Random value for each die roll
            pot,       //Pot where tokens go if a Star is rolled
            loop,      //Determines where while loop stops
            count,     //Counts how many sets of tokens there are
            pv,        //Present value for interest calculation
            yrs;       //Compound years for interest calculation
    char    roll;      //Determines calculation of a roll
    float   fv,        //Future value for interest calculation
            i,         //Interest in percent form
            p1avg,     //Average tokens player 1 had
            p2avg,     //Average tokens player 1 had
            p3avg,     //Average tokens player 1 had
            p4avg;     //Average tokens player 1 had
    fstream in,        //Read in initialization for variables
            out;       //Write out results and player 1's average tokens
    
    //Initialize Variables
    cout<<"Game of Left Center Right"<<endl;
    cout<<"This program requires four players"<<endl;
    cout<<"Players are arranged in a circle facing the Pot, as displayed";
    cout<<" below:"<<endl<<endl;
    
    //Display player orientation that program works for
    cout<<"               Player 3               "<<endl;
    cout<<"Player 2         Pot          Player 4"<<endl;
    cout<<"               Player 1               "<<endl<<endl;
    
    in.open("input4.dat",ios::in);               //Input and output files
    out.open("LCRoutput4.dat",ios::out);
    in>>p1Tkns>>p2Tkns>>p3Tkns>>p4Tkns>>pot>>loop>>p1avg>>count;
    
    
    
    cout<<"Enter four names"<<endl;
    cin>>player1>>player2>>player3>>player4;
    cout<<endl;
    
    
    const int SIZE=500;
    int sumTkns[SIZE];
    float avgTkns[SIZE];
    int plrTkns[SIZE];
    
    
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
            
            
            
            p1avg+=p1Tkns; //Add players tokens together for average calculation
            p2avg+=p2Tkns;
            p3avg+=p3Tkns;
            p4avg+=p4Tkns; 
            count++;       //Count each set of tokens
            
            
            bool winner=false;
            if (p2Tkns==0&&p3Tkns==0&&p4Tkns==0){      //If one player has...
                winner=true;                          //tokens they win
                out<<"GAME OVER - "<<player1<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,count);
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p3Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player2<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,count);
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player3<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,count);
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p3Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player4<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,count);
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
            

            
            p1avg+=p1Tkns; //Add players tokens together for average calculation
            p2avg+=p2Tkns;
            p3avg+=p3Tkns;
            p4avg+=p4Tkns; 
            count++;       //Count each set of tokens
            
            
            bool winner=false;
            if (p2Tkns==0&&p3Tkns==0&&p4Tkns==0){      //If one player has...
                winner=true;                          //tokens they win
                out<<"GAME OVER - "<<player1<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,count);
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p3Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player2<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,count);
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player3<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,count);
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p3Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player4<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,count);
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

                    if (dieFace=="Left"){   //Increase/decrease tokens for left
                        p4Tkns+=1;          
                        --p3Tkns;}
                    if (dieFace=="Right"){  //Increase/decrease tokens for right
                        p2Tkns+=1;
                        --p3Tkns;}
                    if (dieFace=="Star"){   //Increase/decrease tokens for star
                        pot+=1;
                        --p3Tkns;}

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

                    if (dieFace=="Left"){  //Increase/decrease tokens for left
                        p4Tkns+=1;
                        --p3Tkns;}
                    if (dieFace=="Right"){ //Increase/decrease tokens for right
                        p2Tkns+=1;
                        --p3Tkns;}
                    if (dieFace=="Star"){  //Increase/decrease tokens for star
                        pot+=1;
                        --p3Tkns;}

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
            
                if (dieFace=="Left"){     //Increase/decrease tokens for left
                    p4Tkns+=1;
                    --p3Tkns;}
                if (dieFace=="Right"){    //Increase/decrease tokens for right
                    p2Tkns+=1;
                    --p3Tkns;}
                if (dieFace=="Star"){     //Increase/decrease tokens for star
                    pot+=1;
                    --p3Tkns;}
                
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
            
            
            p1avg+=p1Tkns; //Add players tokens together for average calculation
            p2avg+=p2Tkns;
            p3avg+=p3Tkns;
            p4avg+=p4Tkns; 
            count++;       //Count each set of tokens
            
            
            bool winner=false;
            if (p2Tkns==0&&p3Tkns==0&&p4Tkns==0){      //If one player has...
                winner=true;                          //tokens they win
                out<<"GAME OVER - "<<player1<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,static_cast<unsigned char>(count));
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p3Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player2<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,static_cast<unsigned char>(count));
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player3<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,static_cast<unsigned char>(count));
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p3Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player4<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,static_cast<unsigned char>(count));
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

                    if (dieFace=="Left"){   //Increase/decrease tokens for left
                        p1Tkns+=1;          
                        p4Tkns-=1;}
                    if (dieFace=="Right"){  //Increase/decrease tokens for right
                        p3Tkns+=1;
                        p4Tkns-=1;}
                    if (dieFace=="Star"){   //Increase/decrease tokens for star
                        pot+=1;
                        p4Tkns-=1;}

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

                    if (dieFace=="Left"){  //Increase/decrease tokens for left
                        p1Tkns+=1;
                        p4Tkns-=1;}
                    if (dieFace=="Right"){ //Increase/decrease tokens for right
                        p3Tkns+=1;
                        p4Tkns-=1;}
                    if (dieFace=="Star"){  //Increase/decrease tokens for star
                        pot+=1;
                        p4Tkns-=1;}

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
            
                if (dieFace=="Left"){     //Increase/decrease tokens for left
                    p1Tkns+=1;
                    --p4Tkns;}
                if (dieFace=="Right"){    //Increase/decrease tokens for right
                    p3Tkns+=1;
                    --p4Tkns;}
                if (dieFace=="Star"){     //Increase/decrease tokens for star
                    pot+=1;
                    --p4Tkns;}
                
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

          
            p1avg+=p1Tkns; //Add players tokens together for average calculation
            p2avg+=p2Tkns;
            p3avg+=p3Tkns;
            p4avg+=p4Tkns; 
            count++;       //Count each set of tokens
            
            
            bool winner=false;
            if (p2Tkns==0&&p3Tkns==0&&p4Tkns==0){      //If one player has...
                winner=true;                          //tokens they win
                out<<"GAME OVER - "<<player1<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,static_cast<unsigned char>(count));
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p3Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player2<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,static_cast<unsigned char>(count));
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p4Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player3<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,static_cast<unsigned char>(count));
                roll='0';                        //Set roll to zero to exit loop
            }else if (p1Tkns==0&&p2Tkns==0&&p3Tkns==0){ //If one player has...
                winner=true;                           //tokens they win
                out<<"GAME OVER - "<<player4<<" Wins"<<endl;
                out<<"Average tokens "<<player1<<" had: ";
                out<<average(p1avg,static_cast<unsigned char>(count));
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

    
    out<<endl<<endl<<"One version of the game includes substituting the tokens for ";
    out<<"quarters"<<endl;
    out<<"The winner is then entitled to all quarters, even the ones";
    out<<" in the Pot"<<endl;
    //Display potential wins
    out<<"If players were gambling with this program, the winner would be";
    out<<" entitled to $3"<<endl;

    i=6; 
    //Output future value
    out<<"If the winner were to invest the $3 dollars with 6% interest";
    out<<", after 10 years the winner would have $";
    out<<setprecision(2)<<fixed<<intrst(i)<<endl;
    
    statTbl(count, plrTkns, sumTkns, avgTkns, p1avg, p2avg, p3avg, p4avg);
    dsplTbl(count, plrTkns, sumTkns, avgTkns, player1,player2,player3,player4);
    
    //Clean up memory and files
    in.close();
    out.close();
    end();       //Function to display final message and exit
    
    //Exit the Program
    return 0;
}

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

float average(float pavg, int count){
    pavg/=count;                       //Calculate player 1 average
    return static_cast<int>(pavg);
}

float average(float pavg, unsigned char count){
    pavg/=count;                       //Calculate player 1 average
    return static_cast<int>(pavg);
}

float intrst(float i, int pv, int yrs){
    i/=100;
    return pv*pow(1+i,yrs); //Calculate future value
}

void end(){
    cout<<"Go to output file to see results";
    exit(0);
}

void statTbl(int count, int plrTkns[], int sumTkns[], float avgTkns[], 
        int p1avg, int p2avg, int p3avg, int p4avg){
 
    int numSets=count;
    
    plrTkns[0]=p1avg;
    plrTkns[1]=p2avg;
    plrTkns[2]=p3avg;
    plrTkns[3]=p4avg;
    
    avgTkns[0]=p1avg/count;
    avgTkns[1]=p2avg/count;
    avgTkns[2]=p3avg/count;
    avgTkns[3]=p4avg/count;
    
    for (int j=0; j<4; j++){
        sumTkns[j]= plrTkns[j];
    }
}

void dsplTbl(int count, int plrTkns[], int sumTkns[], float avgTkns[], string player1,
        string player2, string player3, string player4){
    cout<<"     Player   Total Tokens   # of Sets   Average Tokens"<<endl;
    for (int j=0; j<4; j++){
        if (j==0){
            cout<<setw(11)<<player1;
        }else if (j==1){
            cout<<setw(11)<<player2;
        }else if (j==2){
            cout<<setw(11)<<player3;
        }else if (j==3){
            cout<<setw(11)<<player4;
        }
        
        cout<<setw(15)<<sumTkns[j]<<setw(12)<<count<<setw(17)<<avgTkns[j]<<endl;
    }
    cout<<endl;
}

//single dimension array
//Play bonus mini game
//Enter 25 numbers (All between 1-6)
//In this program, those numbers in rolls would translate to...
//If put in order, it would take up until position () to roll a star
//or up until 
//Display as function argument

//2D array..interest up until 10 years

//Parallel array total player tokens, average player tokens?? could also sort 
//for person with lowest tokens