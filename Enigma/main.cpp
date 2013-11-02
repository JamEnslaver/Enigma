// James Valner
#include <iostream>
#include "WheelManager.h"
#include "UIManager.h"

using namespace std;



int main()
{
    WheelManager* wheelManager = new WheelManager();
	UIManager* uiManager = new UIManager(wheelManager);
    
	uiManager->SetupCycle();

	uiManager->EncodeCycle();
}


