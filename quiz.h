#include<iostream>

using namespace std;

//class representing the quiz object 
class quiz
{
public:
	float result;
	string name;   //user identification variable
	string id_num; //user identification variables
	vector<Question>questions;
	quiz();
	void loadData(); //loading data from file quiz.txt
	void MIX();      //reorder questions
	void startQuiz();//starting quiz
};

