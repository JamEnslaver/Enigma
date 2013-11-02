#include "Reflector.h"
#include <iostream>

using namespace std;

Reflector::Reflector()
{
	cout << "Reflector constructor" << endl;
}

//Returns the character on the opposite side of the reflector
char Reflector::reflectCharacter(char inputCharacter)
{
	char outputCharacter = inputCharacter - 13;

	if(outputCharacter < 'a')
	{
		outputCharacter += 26;
	}

	return outputCharacter;
}
