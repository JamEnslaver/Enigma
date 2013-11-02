// James Valner
#include "WheelManager.h"
#include <iostream>

using namespace std;

WheelManager::WheelManager()
{
    leftHandCodeWheel = NULL;
}

void WheelManager::addNewCodeWheel(int initialPosition, char transformKey[26])
{
	CodeWheel* newCodeWheel = new CodeWheel(initialPosition,transformKey);
	addCodeWheelToList(newCodeWheel);
}

void WheelManager::addCodeWheelToList(CodeWheel* newCodeWheel)
{
    if(leftHandCodeWheel == NULL)
    {
        leftHandCodeWheel = newCodeWheel;
        return;
    }

    CodeWheel* rightHandCodeWheel = findRightHandCodeWheel();
    rightHandCodeWheel->setRightHandWheel(newCodeWheel);
	newCodeWheel->setLeftHandWheel(rightHandCodeWheel);
}

//Finds the right-hand most codewheel
CodeWheel* WheelManager::findRightHandCodeWheel()
{
    CodeWheel* targetCodeWheel = leftHandCodeWheel;
    if(targetCodeWheel == NULL)
    {
        return NULL;
    }

    while(targetCodeWheel->getRightHandWheel() != NULL)
    {
        targetCodeWheel = targetCodeWheel->getRightHandWheel();
    }

    return targetCodeWheel;
}

void WheelManager::listAllCodeWheels()
{
    CodeWheel* targetCodeWheel = leftHandCodeWheel;
    while(targetCodeWheel != NULL)
    {
        cout << targetCodeWheel << endl;
        targetCodeWheel = targetCodeWheel->getRightHandWheel();
    }
}

char WheelManager::transformCharacter(char inputCharacter)
{
	CodeWheel* targetWheel = leftHandCodeWheel;

	//Go through all codewheels from left to right
	while(targetWheel != NULL)
	{
		inputCharacter = targetWheel->transformCharacter(inputCharacter);
		targetWheel = targetWheel->getRightHandWheel();
	}

	//Reflect character in the reflector
	inputCharacter = Reflector::reflectCharacter(inputCharacter);

	//Go back through all codewheels from right to left
	targetWheel = findRightHandCodeWheel();
	while(targetWheel != NULL)
	{
		inputCharacter = targetWheel->reverseTransformCharacter(inputCharacter);
		targetWheel = targetWheel->getLeftHandWheel();
	}

	rotateWheels();

	return inputCharacter;
}

void WheelManager::rotateWheels()
{
	if(leftHandCodeWheel == NULL)
		return;

	leftHandCodeWheel->rotate();
	CodeWheel* targetCodeWheel = leftHandCodeWheel->getRightHandWheel();
	while(targetCodeWheel != NULL)
	{
		if(targetCodeWheel->getLeftHandWheel()->getRotationPosition() == 0)
		{
			targetCodeWheel->rotate();
		}
		targetCodeWheel = targetCodeWheel->getRightHandWheel();
	}
	
}