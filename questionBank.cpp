#include<iostream>
#include<Windows.h>
#include<vector>
#include<fstream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<random>
#include"question.h"
#include <conio.h>
#include <ctime> 
#include"questionbank.h"

using namespace std;


void updateNumbers()
{
    /*
    Function updates the numbers of removed or added questions
    */
    
    string line;
    vector<Question>questions;
    Question q;
    ifstream file;
    ofstream file1;
    file.open("quiz.txt");
    file1.open("auxiliary_file.txt");
    
    int counter = 0;
    while (getline(file, line))
    {
        counter++;
        q.question_number = line;
        q.question_number = to_string(counter);
        getline(file, q.question_Text);
        getline(file, q.answer_1);
        getline(file, q.answer_2);
        getline(file, q.answer_3);
        getline(file, q.answer_4);
        getline(file, q.correct_answer);
        questions.push_back(q);

    }
   
    for (size_t i = 0; i < questions.size(); i++)
    {

        file1 << questions[i].question_number << endl;
        file1 << questions[i].question_Text << endl;
        file1 << questions[i].answer_1 << endl;
        file1 << questions[i].answer_2 << endl;
        file1 << questions[i].answer_3 << endl;
        file1 << questions[i].answer_4 << endl;
        file1 << questions[i].correct_answer << endl;
    }

    file.close();
    file1.close();
    remove("quiz.txt");
    if (!rename("auxiliary_file.txt", "quiz.txt")) {}
    else
    {
        cout << "Error can't modify file!";
    }

}
void addQuestion()
{
    /*
    Function adds new questions to the bank
    */

    ofstream file;
    file.open("quiz.txt", ios::app);

    if (file.is_open() == false) 
    {

        cout << "Error: Cannot open file.";
        exit(0);

    }
    else
    {
    
        system("cls");
        Question q;
        string s;
        cin.ignore();
        
        cout << "Adding new question to the bank: " << endl << endl;
        cout << "Question: ";
        getline(cin, q.question_Text);

        cout << "A. ";
        getline(cin, q.answer_1);

        cout << "B. ";
        getline(cin, q.answer_2);

        cout << "C. ";
        getline(cin, q.answer_3);

        cout << "D. ";
        getline(cin, q.answer_4);

        cout << "Correct answer: ";
        do {
            getline(cin, s);
            transform(s.begin(), s.end(), s.begin(), ::toupper);
            if(!(s=="A" || s=="B" || s=="C" || s=="D"))
            {
                system("cls");
                cout << "Adding new question to the bank: " << endl << endl;
                cout << "Question: ";
                cout<< q.question_Text;

                cout << endl << "A. ";
                cout << q.answer_1;

                cout << endl<< "B. ";
                cout << q.answer_2;

                cout << endl<<"C. ";
                cout << q.answer_3;

                cout << endl<< "D. ";
                cout <<q.answer_4;
                cout <<endl<<"Invalid option. Correct answer must be A,B,C,D "<<endl;
                
                                                                 
                cout << "Correct answer: ";

            }
        } while (!(s == "A" || s == "B" || s == "C" || s == "D"));
        q.correct_answer = s;
        file << "No" << endl;
        file << q.question_Text << endl;
        file << q.answer_1 << endl;
        file << q.answer_2 << endl;
        file << q.answer_3 << endl;
        file << q.answer_4 << endl;
        transform(q.correct_answer.begin(), q.correct_answer.end(), q.correct_answer.begin(), ::toupper);
        file << q.correct_answer;
        file.close();
        
        updateNumbers();
        cout << "Question added!";
        Sleep(1000);
    }
}
void modifyQuestion() {
    /*
    Function modifies questions from the bank
    */

    string line;
    vector<Question>questions;
    Question q;
    size_t number;
    ifstream file;
    file.open("quiz.txt");
   

    while (getline(file, line))
    {

        q.question_number = line;
        getline(file, q.question_Text);
        getline(file, q.answer_1);
        getline(file, q.answer_2);
        getline(file, q.answer_3);
        getline(file, q.answer_4);
        getline(file, q.correct_answer);
        questions.push_back(q);

    }
 
    system("cls");
    cout << "0.Back " << endl;
    cout << "Type number of question to edit: ";
  
    while (!(cin >> number))
    {
        system("cls");
        cout << "0.Back " << endl;
        cout << "Wrong input!" << endl;
        cout << "Type number of question to edit: ";
        cin.clear();
        cin.ignore();
    }

    
    if(number==0)
    {
        system("cls");
    }
    else if(questions.size()>=number)
    {
        string s;
        cout <<endl<< "OLD: ";
        cout << endl << "NUMBER: " << questions[number - 1].question_number << endl;
        cout << "QUESTION: " << questions[number - 1].question_Text << endl;
        cout << "A." << questions[number - 1].answer_1 << endl;
        cout << "B." << questions[number - 1].answer_2 << endl;
        cout << "C." << questions[number - 1].answer_3 << endl;
        cout << "D." << questions[number - 1].answer_4 << endl;
        cout << "CORRECT ANSWER: " << questions[number - 1].correct_answer << endl;

        ofstream file1;
        file1.open("auxiliary_file.txt");
        cin.ignore();
        
        cout << endl << "NEW: "<<endl;
        cout << "(ENTER == NO CHANGES)"<<endl;
        cout << "Question: ";
        getline(cin, s);
        if (!s.empty())
        {
            questions[number - 1].question_Text=s;
        }
        cout << "A. ";
        getline(cin, s);
        if (!s.empty())
        {
            questions[number - 1].answer_1 = s;
        }
        cout << "B. ";
        getline(cin, s);
        if (!s.empty())
        {
            questions[number - 1].answer_2 = s;
        }
        cout << "C. ";
        getline(cin, s);
        if (!s.empty())
        {
            questions[number - 1].answer_3 = s;
        }
        cout << "D. ";
        getline(cin, s);
        if (!s.empty())
        {
            questions[number - 1].answer_4 = s;
        }
        cout << "Correct answer: ";
        getline(cin, s);
        if (!s.empty())
        {
            questions[number - 1].correct_answer = s;
        }

       
        for (size_t i = 0; i < questions.size(); i++)
        {

            file1 << questions[i].question_number << endl;
            file1 << questions[i].question_Text << endl;
            file1 << questions[i].answer_1 << endl;
            file1 << questions[i].answer_2 << endl;
            file1 << questions[i].answer_3 << endl;
            file1 << questions[i].answer_4 << endl;
            file1 << questions[i].correct_answer << endl;
        
        }

        file.close();
        file1.close();
        remove("quiz.txt");
        if (!rename("auxiliary_file.txt", "quiz.txt")) {}
        else
        {
            cout << "Error can't modify file!";
        }
        cout << "Question modyfied!";
        Sleep(1000);
    
    }
    else 
    {

        file.close();
        cout << endl<< "Question doesnt exist!";
        Sleep(1000);
    
    }
  
    
}
void deleteQuestion() {
    /*
    Function removes questions from the bank
    */
   
    string line;
    vector<Question>questions;
    Question q;
    size_t number;
    ifstream file;
    file.open("quiz.txt");
    
    while (getline(file, line))
    {

        q.question_number = line;
        getline(file, q.question_Text);
        getline(file, q.answer_1);
        getline(file, q.answer_2);
        getline(file, q.answer_3);
        getline(file, q.answer_4);
        getline(file, q.correct_answer);
        questions.push_back(q);

    }

    system("cls");
    cout << "0.Back " << endl;
    cout << "Type number of question to delete: ";
    while (!(cin >> number))
    {
        system("cls");
        cout << "0.Back " << endl;
        cout << "Wrong input!" << endl;
        cout << "Type number of question to edit: ";
        cin.clear();
        cin.ignore();
    }

    
    if (number == 0)
    {
        system("cls");
    }
    else if (questions.size()>=number)
    {
    
        ofstream file1;
        file1.open("auxiliary_file.txt");
        
        for (size_t i = 0; i < questions.size(); i++)
        {
        
            if (i != number - 1)
            {
            
                file1 << questions[i].question_number << endl;
                file1 << questions[i].question_Text << endl;
                file1 << questions[i].answer_1 << endl;
                file1 << questions[i].answer_2 << endl;
                file1 << questions[i].answer_3 << endl;
                file1 << questions[i].answer_4 << endl;
                file1 << questions[i].correct_answer << endl;

            }
        
        }
        
        file.close();
        file1.close();
        remove("quiz.txt");

        if (!rename("auxiliary_file.txt", "quiz.txt")) {}
        else
        {
            cout << "Error can't modify file!";
        }
        updateNumbers();
        cout << "Question deleted!";
        Sleep(1000);
    }
    else
    {

        file.close();
        cout << "Question doesnt exist!";
        Sleep(1000);
    
    }

}
void searchQuestion() {
    /*
    Function displays a single question
    */
    string line;
    vector<Question>questions;
    Question q;
    size_t number;
    ifstream file;
    file.open("quiz.txt");

    while (getline(file, line)) 
    {

        q.question_number = line;
        getline(file, q.question_Text);
        getline(file, q.answer_1);
        getline(file, q.answer_2);
        getline(file, q.answer_3);
        getline(file, q.answer_4);
        getline(file, q.correct_answer);
        questions.push_back(q);
    
    }
    system("cls");
    cout << "0.Back " << endl;
    cout << "Type number of question: ";
    while (!(cin >> number))
    {
        system("cls");
        cout << "0.Back " << endl;
        cout << "Wrong input!" << endl;
        cout << "Type number of question to edit: ";
        cin.clear();
        cin.ignore();
    }

    if(number==0)
    {
        system("cls");
    }
    else if (questions.size()>=number) 
    {
    
        cout << endl << "NUMBER: " << questions[number - 1].question_number << endl;
        cout << "QUESTION: " << questions[number - 1].question_Text << endl;
        cout << "A." << questions[number - 1].answer_1 << endl;
        cout << "B." << questions[number - 1].answer_2 << endl;
        cout << "C." << questions[number - 1].answer_3 << endl;
        cout << "D." << questions[number - 1].answer_4 << endl;
        cout << "CORRECT ANSWER: >" << questions[number - 1].correct_answer << endl << endl;
        file.close();
        cout << "Press any key to go back" << endl;
        while (1)
        {
            if (_kbhit())
            {
                break;
            }
        }
    
        system("cls");
    
    }
    else
    {

        file.close();
        cout << "Question doesnt exist!";
        Sleep(1000);
    
    }
}
void displayBank()
{
    /*
    Function displays all question frome the bank
    */
    vector<Question>questions;
    Question q;
    string line;
    ifstream file("quiz.txt");
    if (file.is_open() == false)
    {

        cout << "Error: Cannot open file.";
        exit(0);

    }
    else
    {

        while (getline(file, line))
        {

            q.question_number = line;
            getline(file, q.question_Text);
            getline(file, q.answer_1);
            getline(file, q.answer_2);
            getline(file, q.answer_3);
            getline(file, q.answer_4);
            getline(file, q.correct_answer);

            questions.push_back(q);

        }

    }
    file.close();


    system("cls");
    cout << endl << endl << "__________________QUESTION BANK____________________" << endl << endl;

    for (size_t i = 0; i < questions.size(); i++)
    {

        cout << endl << "Number: " << questions[i].question_number << endl;
        cout << "Question: " << questions[i].question_Text << endl;
        cout << "A." << questions[i].answer_1 << endl;
        cout << "B." << questions[i].answer_2 << endl;
        cout << "C." << questions[i].answer_3 << endl;
        cout << "D." << questions[i].answer_4 << endl;
        cout << "Correct answer: " << questions[i].correct_answer << endl << endl;

    }

    cout << "___________________________________________________" << endl << endl;
    cout << "Press any key to go back" << endl;
    while (1)
    {
        if (_kbhit())
        {
            break;
        }
    }
    system("cls");

}
void showResults() {
    system("cls");
    string line;
    ifstream file("Results.txt");
    if (file.is_open() == false)
    {

        cout << "Error: Cannot open file.";
        exit(0);

    }
    else
    {

        while (getline(file, line))
        {

            cout << line << endl;

        }

    }
    file.close();
    cout << endl << "Press any key to go back" << endl;
    while (1)
    {
        if (_kbhit())
        {
            break;
        }
    }
    system("cls");

}
void setParams() {
    system("cls");
    ifstream file;
    file.open("params.txt");
    int quiz_size = 0;
    string choice;
    file >> quiz_size;
    file.close();
    cout << "Current quiz size: " << quiz_size << " question/s" << endl;
    cout << "Would you like to change it? type:yes (other exit): ";
    cin >> choice;
    transform(choice.begin(), choice.end(), choice.begin(), ::toupper);


    if(choice == "YES")
    {
        ofstream file;
        file.open("params.txt");
        cout << "New quiz size: ";
        while (!(cin >> quiz_size))
        {
            system("cls");
            cout << "Current quiz size: " << quiz_size << " question/s" << endl;
            cout << "Wrong input!" << endl;
            cout << "New quiz size: ";
            cin.clear();
            cin.ignore();
        }

        file << quiz_size;
        file.close();
        system("cls");
    }
    else
    {
        cout << "Parameters have not been changed ";
        Sleep(1000);
        system("cls");
    }
    
}
