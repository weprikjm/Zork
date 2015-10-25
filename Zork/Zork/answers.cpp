#include "answers.h"


Answers::Answers(const char* _answer, const char* _command)
{
	Answer = new p2SString;
	command = new p2SString;
	Answer->create(_answer);
	command->create(_command);
}