#include<iostream>
#include<vector>
#include<Windows.h>
#include<fstream>
#include<string>
#include<cstdlib>
#include"question.h"
#include"quiz.h"
#include"questionBank.h"

using namespace std;

//submenu executing function
void settings();
//menu executing function
void menu();


//main loop
int main() {
    
    menu();
    
    return 0;
}


void settings() {
    system("cls");
    cout << "SETTINGS:\n";
    int option;
    do
    {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1-Add question" << endl;
        cout << "2-Modify question" << endl;
        cout << "3-Delete question" << endl;
        cout << "4-Search question" << endl;
        cout << "5-Display question bank" << endl;
        cout << "6-Set quiz parameters" << endl;
        cout << "7-Show results" << endl;
        cout << "0-Back (MENU) " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Select option >> ";
        while (!(cin >> option))
        {
            system("cls");
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "1-Add question" << endl;
            cout << "2-Modify question" << endl;
            cout << "3-Delete question" << endl;
            cout << "4-Search question" << endl;
            cout << "5-Display question bank" << endl;
            cout << "6-Set quiz parameters" << endl;
            cout << "7-Show results" << endl;
            cout << "0-Back (MENU) " << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Wrong input!" << endl;
            cout << "Select option >> ";
            
            cin.clear();
            cin.ignore();
        }
        switch (option)
        {
        case 0: {
            //back to main menu
            system("cls");
            break;
        }
        case 1:
        {
            addQuestion();
            system("cls");
            break;
        }
        case 2:
        {
            modifyQuestion();
            system("cls");
            break;
        }
        case 3:
        {
            deleteQuestion();
            system("cls");
            break;
        }
        case 4:
        {
            searchQuestion();
            system("cls");
            break;
        }
        case 5:
        {
            displayBank();
            break;
        }
        case 6:
        {
            setParams();
            break;
        }
        case 7:
        {
            showResults();
            break;
        }
        default:
            cout << "Incorrect option!";
            Sleep(1000);
            system("cls");
            break;

        }

    } while (option != 0);
}

void menu(){

    int choice;
    string passwd;
    do
    {

        cout << "-----------QUIZMAKER-------------" << endl;
        cout << "| 1.Quiz                        |" << endl;
        cout << "| 2.Settings                    |" << endl;
        cout << "| 0.Quit                        |" << endl;
        cout << "---------------------------------" << endl;
        cout << "Select option >> ";
        while (!(cin >> choice))
        {
            system("cls");
            cout << "-----------QUIZMAKER-------------" << endl;
            cout << "| 1.Quiz                        |" << endl;
            cout << "| 2.Settings                    |" << endl;
            cout << "| 0.Quit                        |" << endl;
            cout << "---------------------------------" << endl;
            cout << "Wrong input!" << endl;
            cout << "Select option >> ";

            cin.clear();
            cin.ignore();
        }

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
        {
            //starting quiz
            system("cls");
            quiz* q = new quiz();
            cout << "Your name:";
            cin >> q->name;
            cout << "Your id number:";
            cin >> q->id_num;
            q->loadData();
            q->startQuiz();
            delete q;
        }
        break;
        case 2:
            //settings menu; needed password
            system("cls");
            cout << "PASSWORD:";
            cin >> passwd;
            if (passwd == "12345")
            {
                settings();
            }
            else
            {
                cout << "INCORRECT PASSWORD!" << endl;
                Sleep(1000);
                system("cls");
            }
            break;

        default:
            system("cls");
            cout << "Please type correct option!" << endl;
            break;


        }
    } while (choice != 0);

}