#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>



int main(){

    char words [10][10][15] = {{"convenient", "habit", "chore", "leisure", "notice", "postpone", "schedule", "appliance", "tidy", "occasional"}, 
                               {"colleague", "deadline", "promote", "negotiate", "applicant", "resign", "skill", "efficient", "supervise", "salary"}, 
                               {"device", "implement", "security", "access", "hardware", "automate", "compatible", "update", "transmit", "storage"}, 
                               {"assignment", "exam", "analyze", "comprehend", "pass", "evaluate", "curriculum", "improve", "research", "fundamental"}, 
                               {"polite", "anxious", "stubborn", "confident", "generous", "sincere", "jealous", "reliable", "enthusiastic", "lazy"}, 
                               {"pollution", "predict", "renewable", "disaster", "species", "climate", "conservation", "threaten", "protect", "phenomenon"}, 
                               {"argue", "clarify", "complain", "interrupt", "persuade", "mention", "explain", "emphasize", "describe", "convey"}, 
                               {"destination", "ticket", "commute", "delay", "accommodation", "urban", "explore", "crowded", "pedestrian", "reservation"}, 
                               {"afford", "price", "investment", "borrow", "debt", "budget", "fluctuate", "expense", "currency", "receipt"}, 
                               {"decision", "consequence", "opinion", "perspective", "solution", "justify", "doubt", "assume", "goal", "prioritize"}};


    srand(time(NULL)); //Produce for random number(every second)                           
    
    while(1){

        int category = sizeof(words) / sizeof(words[0]); 
        int word = sizeof(words) / (category * sizeof(words[0][0])); 

        int number = rand() % category; 
        int number2 = rand() % word; // 0-9 number in between
        char prefword[15];
        char hint[50] = "Daily Life";
        char space[15];

        strcpy(prefword, words[number][number2]);

        int stop = 0;
    
        for(int i = 0; isalpha(prefword[i]) != false; i++){

            stop += 1;
            space[i] = '_';
        }

        space[stop] = '\0';    

        if(number == 0) strcpy(hint, "Daily Life"); 
        else if(number == 1) strcpy(hint, "Work and Career"); 
        else if(number == 2) strcpy(hint, "Technology and Engineering");
        else if(number == 3) strcpy(hint, "Education and Academic Life");
        else if(number == 4) strcpy(hint, "Feeling and Personality");
        else if(number == 5) strcpy(hint, "Nature, Environment and Science");
        else if(number == 6) strcpy(hint, "Conversation and Social Interaction");
        else if(number == 7) strcpy(hint, "Travel and Transport");
        else if(number == 8) strcpy(hint, "Economy, Trade and Money");
        else strcpy(hint, "Thouth, Abstract Ideas and Decision");

        char guess[50];
    
        char falseGuess[27];
        char beforeLetter0[27] = {0};

        bool beforeLetter[27] = {false};

        int remaining = 6;
        int a = 0, b = 0, tmp = 0, tmp2 = 0;




    


    printf("********Welcome to Hangman********\n\n");


        while(1){

            bool value = 0;

            if(a != 0){//False Letters
                printf("False Letters: ");
                for(int i = 0; i < a; i++){
                printf("%c ", falseGuess[i]);
                }
                printf("\n\n");
            }


            printf("Category: %s\n", hint);
            printf("Guess Letter or Word: ");

            for(int i = 0; space[i] != '\0'; i++){ 
                printf("%c ", space[i]);
            }


            printf("\nGuess: ");
            fgets(guess, sizeof(guess), stdin);



            if(strlen(guess) > 2){
                printf("\nOnly one letter can be entered. Try again...\n");
                printf("\nRemaining attempts %d\n", remaining);
                continue;
            }


            if(isalpha(guess[0]) == false){ // 'isalpha()' is checks whether it is a letter.

                if(guess[0] == '\n'){ // if user nothing write push "enter" 
                    continue;
                }

                printf("\nPlease enter a letter. Try again...\n");
                printf("\nRemaining attempts %d\n", remaining);

                continue;
            }


            guess[0] = tolower(guess[0]);
            tmp = ('z' - guess[0]); 
            tmp2 = (int)guess[0];


            if(beforeLetter[tmp] == true){
                printf("This letter has already been entered. Please try again...\n\n");

            
                printf("Before Letters: ");

                for(int i = 0; i < b; i++){

                    printf("%c ", beforeLetter0[i]);
                }
                printf("\n");
                printf("\nRemaining attempts %d\n", remaining);
                continue;
            }


            else{
                beforeLetter0[b] = (char)tmp2;
                b += 1;
                beforeLetter[tmp] = true;
            }


            for(int i = 0; guess[i] != '\0'; i++){
                guess[i] = tolower(guess[i]);

                for(int j = 0; prefword[j] != '\0'; j++){

                    if(guess[i] == prefword[j] && prefword[j] != '\n'){
                        space[j] = prefword[j];

                        value = 1;
                    }

                }

            }  


            if(strcmp(prefword,space) == 0){
                printf("\nCongratulations! The word is '%s'\n\n", prefword);

                break;
            }

            else if(value == 1){

                printf("\nRemaining attempts %d\n", remaining);
                continue;

            }

            else{

                falseGuess[a] = guess[0];
                a += 1;

                remaining -= 1;

                if(remaining == 0){
                    printf("\nRemaining attempts %d Game Over! True Word %s\n\n", remaining, prefword);

                    break;
                }

                printf("\nRemaining attempts %d\n", remaining);

            }

        } 

    }
    
    return 0;
}