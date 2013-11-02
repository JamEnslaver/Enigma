#include "UIManager.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

UIManager::UIManager(WheelManager* _wheelManager)
{
	wheelManager = _wheelManager;
}

void UIManager::SetupCycle()
{
	cout << "Welcome to Enigma!" << endl;
	cout << "How many wheels do you want your Enigma to have? (Max 10)" << endl;

	int numberOfWheels = safeNumericInput();

	if(numberOfWheels > 10)
		numberOfWheels = 10;
	if(numberOfWheels < 1)
		numberOfWheels = 1;

	cout << "Your Enigma will have " << numberOfWheels << " wheel";
	if(numberOfWheels > 1)
		cout << "s";
	cout << endl;
	

	cout << "When entering wheel types, please enter numbers between 1 and 5." << endl;
	cout << "When entering wheel rotations, please enter numbers between 0 and 25." << endl;
	int wheelID = 1;
	while(wheelID <= numberOfWheels)
	{
		int wheelType;
		int wheelRotation;
		cout << "Wheel " << wheelID << " type: ";
		wheelType = safeNumericInput();
		cout << "Wheel " << wheelID << " rotation: ";
		wheelRotation = safeNumericInput();

		if(orderNewWheel(wheelType, wheelRotation))
			wheelID++;
	}
	
}

int UIManager::safeNumericInput()
{
	char inputString[5];

	cin >> inputString;
	cin.ignore(); //Used to remove the 'Enter' keystroke from the input buffer
	return atoi(inputString);
}

//Given a wheel type, orders that type of wheel from the WheelManager
//If the wheel type is not valid, returns false
bool UIManager::orderNewWheel(int wheelType, int wheelRotation)
{
	char* transformKey = new char[26];
	switch(wheelType)
	{
	case 1: 
		strcpy(transformKey,"zyxwvutsrqponmlkjihgfedcba"); 
		break;
	case 2: 
		strcpy(transformKey,"qwertyuiopasdfghjklzxcvbnm");
		break;
	case 3:
		strcpy(transformKey,"qazwsxedcrfvtgbyhnujmikolp");
		break;
	case 4:
		strcpy(transformKey,"lkjhgfdsapoiuytrewqmnbvcxz");
		break;
	case 5:
		strcpy(transformKey,"plokmijnuhbygvtfcrdxeszwaq");
		break;
	default:
		return false;
	}

	if(wheelRotation < 0 || wheelRotation > 25)
		return false;

	wheelManager->addNewCodeWheel(wheelRotation,transformKey);
	return true;
}

void UIManager::EncodeCycle()
{
	cout << "Type in letters and press Enter to see the encoded message" << endl;
	cout << "Press ENTER to stop." << endl;

	char* inputString = new char[100];
	while(true)
	{
		cin.getline(inputString,100);

		if(!strcmp(inputString,""))
		{
			break;
		}

		char* targetCharacter = inputString;
		while(*targetCharacter != '\0')
		{
			if(isNotLetter(*targetCharacter))
			{
				cout << *targetCharacter;
			}

			else
			{
				if(isCapital(*targetCharacter))
				{
					makeLowerCase(*targetCharacter);
				}
				cout << wheelManager->transformCharacter(*targetCharacter);
			}
			targetCharacter += 1;
		}
		cout << endl << endl;
	}
}

bool UIManager::isCapital(char inputChar)
{
	return (inputChar >= 'A' && inputChar <= 'Z');
}

bool UIManager::isLower(char inputChar)
{
	return (inputChar >= 'a' && inputChar <= 'z');
}

bool UIManager::isNotLetter(char inputChar)
{
	return (!isLower(inputChar) && !isCapital(inputChar));
}

void UIManager::makeLowerCase(char& inputChar)
{
	inputChar += 'a' - 'A';
}