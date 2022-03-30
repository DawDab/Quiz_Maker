#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"question.h"
#include <algorithm>



using namespace std;

Question::Question() {

    question_number = "";
    question_Text ="";
    answer_1="";
    answer_2="";
    answer_3="";
    answer_4="";
    correct_answer="";
    given_answer="";
    point=0;

}

void Question::ask_Question() {

    cout << endl << question_Text << endl;
    cout <<"A."<< answer_1 << endl;
    cout <<"B."<< answer_2 << endl;
    cout <<"C."<< answer_3 << endl;
    cout <<"D."<< answer_4 << endl;
    cout << "Your answer: ";
    cin >> given_answer;
    transform(given_answer.begin(), given_answer.end(), given_answer.begin(), ::toupper);
}
void Question::check_Answer() {

    if (given_answer == correct_answer) {
        point = 1;
    }
    else point = 0;

}
