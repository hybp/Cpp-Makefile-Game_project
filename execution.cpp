#include <iostream>
#include <string>
#include <stdlib.h>
#include "universal.h"
#include "execution.h"
#include "library.h"
#include "garden.h"
#include "cafeteria.h"
#include "lecture.h"

using namespace std;

void decision (status pass_stat, int pass_mood, bool *qt) {
    cout << "What are you up to?" << endl;
    cout << "[1] Go to library [2] Go to garden [3] Go to cafeteria" << endl;
    cout << "[4] Go to lecture room [5] Save progress [6] Load save data" << endl;
    cout << "[7] Quit game" << endl;

    int input;
    bool correct_input = false;
    cin >> input;
    switch ( input )
    {
        case 1:
            library(&pass_stat, pass_mood);
            correct_input = true;
            break;
        case 2:
            garden(&pass_stat, pass_mood);
            correct_input = true;
            break;
        case 3:
            cafeteria(&pass_stat, pass_mood);
            correct_input = true;
            break;
        case 4:
            lect(&pass_stat, pass_mood);
            correct_input = true;
            break;
        case 5:
            correct_input = true;
            break;
        case 7:
            correct_input = true;
            cout << "See you again!";
            *qt = true;
            break;
        default:
            cout << "Wrong input!\n";
            while (cin.fail()) {
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
            decision(pass_stat, pass_mood, &*qt);
    }
}

void execution(status current_stat) {
    //Random variable "mood" which can have 3 possible integers.
    //mood 0 means bad atmosphere, mood 1 means moderate atmosphere, mood 2 means good atmosphere.
    int mood;
    bool qt_flag = false;

    while (current_stat.date != 10) {
        cout << endl;
        cout << "Day " << current_stat.date << " ";
        switch (current_stat.time)
        {
            case 0:
                cout << "Morning\n";
                break;
            case 1:
                cout << "Afternoon\n";
                break;
            default:
                cout << "Evening\n";
        }
        for (int j = 0; j != 3; j++) {
            cout << current_stat.names[j] << " Intimacy Level: [" << current_stat.inti_level[j] << "]";
            cout << endl;
        }
        cout << "Health Point : " << current_stat.hp << "   " << "GPA : " << current_stat.GPA << endl;
        if (current_stat.time == 0) {
            cout << "Good morning " << current_stat.name << "!" << endl;
        }
        else if (current_stat.time == 1) {
            cout << "Good afternoon " << current_stat.name << "!" << endl;
        }
        else {
            cout << "Good evening " << current_stat.name << "!" << endl;
        }
        
        if (current_stat.date != 5) {
            srand(time(0));
            mood = rand() % 3;
            decision(current_stat, mood, &qt_flag);
        }
        if (qt_flag == true) {
            break;
        }
        
    }
}