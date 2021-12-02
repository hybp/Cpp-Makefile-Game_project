
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>
#include <cstdlib>
#include "garden.h"
#include "universal.h"
using namespace std;
// play.day
//play.period ==> 1. morning 2. afternoon 3. evening
//play.location ==> 0. Library 1. Garden 2. Student Cafeteria  3. Lecture Room
// Iris = [0], Olivia = [1], Daisy = [2]
void garden(status* input_stat, int mood){
  char choose;
  int input;
  char name;
  double increment = 1;
  double decrement = -1;
  int sun;
  if (mood == 0){
    decrement = -1.5;
    increment = 0.8;
  }
  if (mood == 2) {
    increment = 2;
    decrement = -0.8;
  }
  int run = 1;
  while(run == 1){
      int sel;
      cout << " You selected to come to Garden." << endl;
      cout << " In Garden, there is a higher probability for Olivia to appear. Do you want to enter?" << endl;
      cout << " [1] Yes [2] No, I want to go back home [3]Badminton Club" << endl;
      cin >> sel;
      if(sel ==1){
        srand(time(0));
        int Olivia_Appear = rand() % 100;
        if(Olivia_Appear < 50){
          cout << "Olivia appears on the Garden" << endl;
          cout << " Hi, I'm Olivia. " << endl;
          getchar();
          cout << "Stressed out due to excessive amount of assignments and examinations," << endl;
          cout << "You went to Garden to chill. And you found Olivia crying on the bench. " << endl;
          getchar();
          cout << " You may choose between three options: "<< endl;
          cout << " 1. Ask why she is crying. " << endl;
          cout << " 2. Comfort her without saying any word. " << endl;
          cout << " 3. Didn't recognize Olivia crying and look around Garden. " << endl;
          cout << "please enter a number from 1 to 3" << endl;
          cin >> input;
          if(input == 1){
            cout << "Olivia: life is hard cuz of too much of tests and assignments..." << endl;
            input_stat->inti_level[1] += increment;
            input_stat->sun += 1;
          }
          else if(input == 2){
            cout << "Thank you for comforting me.." << endl;
            input_stat->affi_level[1] += increment;
            input_stat->sun += 1;
          }
          else{
            cout << "(Nothing happens)" << endl;
            input_stat->inti_level[1] += decrement;
            input_stat->affi_level[1] += decrement;
            input_stat->sun += 1;
          }
        }
        // random chances for Iris to appear
        else if(Olivia_Appear > 50 && Olivia_Appear < 69){
          cout<< "Iris appears on the Garden" << endl;
          cout << "Iris: Hi, I'm Iris!" << endl;
          getchar();
          cout << "Stressed out due to excessive amount of assignments and examinations," << endl;
          cout << "You went to Garden to chill. And you found Iris crying on the bench. " << endl;
          getchar();
          cout << " 1. Take the flower to give her " << endl;
          cout << " 2. Since you consider every living thing a precious one, you keep walking to the garden " << endl;
          cout << " 3. Buy an Oreo Ice cream to her and walk with her on the Garden " << endl;
          cout << "please enter a number from 1 to 3" << endl;
          cin >> input;
          if(input == 1){
            cout << " Iris: (With impression) I liked this kind of flower..Thank you!!" << endl;
            input_stat->affi_level[0] += increment;
            input_stat->sun += 1;
          }
          else if(input == 2){
            cout << " Iris: .... " << endl;
            input_stat->inti_level[0] += decrement;
            input_stat->affi_level[0] += decrement;
            input_stat->sun += 1;
          }
          else{
            cout << " It is really nice of you for this Oreo icecream! let's walk around!! " << endl;
            input_stat->inti_level[0] += increment;
            input_stat->sun += 1;
          }
        }
        else if(Olivia_Appear > 70 && Olivia_Appear < 90){
          cout << "Daisy appears on the Garden" << endl;
          cout << "Hi!! I'm Daisy~~~ " << endl;
          getchar();
          cout << " 1. Take the flower to give her " << endl;
          cout << " 2. Since you consider every living thing a precious one, you keep walking to the garden " << endl;
          cout << " 3. Buy an Oreo Ice cream to her and walk with her on the Garden " << endl;
          cout << "please enter a number from 1 to 3" << endl;
          cin >> input;
          if(input == 1){
            cout << " Daisy: (With impression) I liked this kind of flower..Thank you!!" << endl;
            input_stat->affi_level[2] += increment;
            input_stat->sun += 1;
          }
          else if(input == 2){
            cout << " Daisy: .... " << endl;
            input_stat->inti_level[2] += decrement;
            input_stat->affi_level[2] += decrement;
            input_stat->sun += 1;
          }
          else{
            cout << " It is really nice of you for this Oreo icecream! let's walk around!! " << endl;
            input_stat->inti_level[2] += increment;
            input_stat->sun += 1;
          }
        }
        else
        {
          cout << "Prof T.W. Chim appears on the Garden" << endl;
          getchar();
          cout << " Nice to see you guys in the Garden!! Hahaha " << endl;
          cout << " You wanna walk around with me?? HAHAHA " << endl;
          cout << " I will give you guys a question!" << endl;
          getchar();
          cout << " Guess if you do not know the answer. Which of the following is valid command or editor " << endl;
          cout << " that allow you to show the content of a file in Linux/Unix? " << endl;
          cout << "1.	vi" << endl;
          cout << "2. show" << endl;
          cout << "3.	get" << endl;
          cin >> input;
          if(input == 1)
          {
            cout << " Correct!!! You have gained 0.5 points. " << endl;
            input_stat->GPA += 0.5;
            input_stat->sun += 1;
          }
          else if(input ==2)
          {
            cout << " Wrong! You have lost 0.5 input_stat->GPA points. "   << endl;
            input_stat->GPA -= 0.5;
            input_stat->sun += 1;
          }
          else
          {
            cout << " Wrong! You have lost 0.5 input_stat->GPA points. " << endl;
            input_stat->GPA -= 0.5;
            input_stat->sun += 1;
          }
        }
          input_stat->hp -= 1;
          input_stat->GPA -= 0.3;
        }
      else if(sel == 2){
          cout << "Going back home. " << endl;
          input_stat->hp -= 1;
          input_stat->sun += 1;
          input_stat->GPA -= 0.1;
          }
      else if(sel == 3){
          cout << " You entered Badminton Club. " << endl;
          cout << " By playing badminton you can gain health point per match! " << endl;
          input_stat->hp += 1;
          input_stat->sun += 1;
          input_stat->GPA -= 0.1;
          }
      run = 0;
      }
    }
