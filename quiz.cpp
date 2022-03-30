#include<iostream>
#include<Windows.h>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include<random>
#include <conio.h>
#include <ctime> 
#include"question.h"
#include "quiz.h"

using namespace std;


quiz::quiz() {
    result=0;
    name="";
    id_num="";
}

//loading data from file quiz.txt
//1 line: Question num
//2 line: Question text
//3,4,5,6 lines: answer1,2,3,4
//7 line: Correct answer
void quiz::loadData() {
    quiz q1;
    Question q;
    string line;
    ifstream file("quiz.txt");
    if (file.is_open() == false) {

        cout << "Error: Cannot open file.";
        exit(0);

    }
    else {

        while (getline(file, line)) {

           
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
}


//shuffling the order of questions
void quiz::MIX() {
    random_device rd;
    mt19937 randomGenerator(rd());
    shuffle(questions.begin(), questions.end(), randomGenerator);
}


//starting quiz
void quiz::startQuiz()
{
    float score = 0;
    float base = 0;
    MIX();
    size_t quiz_size=0; 
    ifstream file1;
    file1.open("params.txt");
    file1 >> quiz_size;
    file1.close();
    
    if (quiz_size > questions.size())
    {
        quiz_size = questions.size();
    }
   
    for (size_t i = 0; i<quiz_size;i++) 
    {
        system("cls");
        questions[i].ask_Question();
        questions[i].check_Answer();
        score += questions[i].point;
        base++;
    }
    result = score / base * 100; //result in %
    
    //collecting the quiz end time
    SYSTEMTIME a;
    GetLocalTime(&a);
    system("cls");
    
    //print result
    cout << endl << "Quiz finished!" << endl << "Your score is : " << score << "/" << base <<"    "<<result << "%  " <<endl << endl;
    
    //saving data
    ofstream file;
    file.open("Results.txt", ios::app);
    if (file.is_open() == false) {

        cout << "Error: Cannot open file.";
        exit(0);

    }
    else {
       
        file << "Name:\t" << name << "\tIndex number:\t"<<id_num << "\tScore:\t" << score << "/" << base << "\t" << result << "%\tDate: " << a.wDay << "/" << a.wMonth << "/" << a.wYear << " | " << a.wHour << ":" << a.wMinute << ":" << a.wSecond << endl;
        file.close();
       
     
    }
    
    cout << "Press any key to continue" << endl;
    while (1)
    {
        if (_kbhit())
        {
            break;
        }
    }
    system("cls");
}

