#include "CodeWheel.h"
#include <iostream>
#include <cstring>

using namespace std;

CodeWheel::CodeWheel(int initialPosition, char _transformKey[26])
{ 
    rotationPosition = initialPosition;
	strcpy(transformKey,_transformKey);
    leftHandWheel = NULL;
	rightHandWheel = NULL;
}

void CodeWheel::rotate()
{
    rotationPosition++;
    if(rotationPosition > 25)
    {
        rotationPosition = 0;
    }
}

void CodeWheel::printTransformKey()
{
    for(int i = 0; i < 26; i++)
    {
        cout << transformKey[i] << endl;
    }
}

char CodeWheel::transformCharacter(char inputCharacter)
{
    int index = (inputCharacter - 'a' + rotationPosition)%26;
    char outputCharacter =  transformKey[index];
	return outputCharacter;
}

char CodeWheel::reverseTransformCharacter(char inputCharacter)
{
	int index = findIndexOfCharacter(inputCharacter);

	char outputCharacter = 'a' + index - rotationPosition;
	if(outputCharacter < 'a')
		outputCharacter += 26;

	return outputCharacter;
}

int CodeWheel::getRotationPosition(){
    return rotationPosition;
}

int CodeWheel::findIndexOfCharacter(char inputCharacter)
{
	for(int i = 0; i < 26; i++)
	{
		if(transformKey[i] == inputCharacter)
			return i;
	}
	cout << "No instance of " << inputCharacter << " found!" << endl;
	return -1;
}

void CodeWheel::setLeftHandWheel(CodeWheel* input)
{
    leftHandWheel = input;
}

CodeWheel* CodeWheel::getLeftHandWheel()
{
    return leftHandWheel;
}

void CodeWheel::setRightHandWheel(CodeWheel* input)
{
    rightHandWheel = input;
}

CodeWheel* CodeWheel::getRightHandWheel()
{
    return rightHandWheel;
}
