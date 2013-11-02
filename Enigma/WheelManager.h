#ifndef WHEELMANAGER_H
#define WHEELMANAGER_H

#include "CodeWheel.h"
#include "Reflector.h"

class WheelManager
{
    public:
        WheelManager();
		void addNewCodeWheel(int,char[26]);
        void addCodeWheelToList(CodeWheel*);
        void listAllCodeWheels();
		char transformCharacter(char);

    private:
        CodeWheel* leftHandCodeWheel;
        CodeWheel* findRightHandCodeWheel();
		void rotateWheels();
};

#endif // WHEELMANAGER_H
