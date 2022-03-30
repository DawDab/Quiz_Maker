#include<iostream>

using namespace std;



//class representing the single question object in the quiz
class Question {
public:
    string question_number;
    string question_Text;
    string answer_1;
    string answer_2;
    string answer_3;
    string answer_4;
    string correct_answer;
    string given_answer;
    int point;

    Question();
    void ask_Question(); //function for displaying questions
    void check_Answer(); //function that checks the correctness of the answer
    
};