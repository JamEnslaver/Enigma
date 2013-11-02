#pragma once
#include "WheelManager.h"

class UIManager
{
	public:
		UIManager(WheelManager*);
		void SetupCycle();
		void EncodeCycle();

	private:
		WheelManager* wheelManager;
		int safeNumericInput();
		bool orderNewWheel(int,int);
		bool isNotLetter(char);
		bool isCapital(char);
		bool isLower(char);
		void makeLowerCase(char&);
};

