#include "answers.h"
#include "DataStructures/MyString.h"

Answers::Answers(const char* _answer, const char* _command)
{
	Answer = new MyString;
	command = new MyString;
	*Answer = _answer;
	*command = _command;
}