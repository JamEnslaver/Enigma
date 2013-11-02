#ifndef CODEWHEEL_H
#define CODEWHEEL_H

class CodeWheel
{
    public:
		CodeWheel(int,char[26] = "zyxwvutsrqponmlkjihgfedcba");
        void printTransformKey();
        char transformCharacter(char);
		char reverseTransformCharacter(char);
        int getRotationPosition();
		int findIndexOfCharacter(char);
		void setLeftHandWheel(CodeWheel*);
        void setRightHandWheel(CodeWheel*);
        CodeWheel* getLeftHandWheel();
        CodeWheel* getRightHandWheel();
        

    private:
		
		char transformKey[26];
        CodeWheel* leftHandWheel;
        CodeWheel* rightHandWheel;
        int rotationPosition;
        void rotate();

    friend class WheelManager;
};

#endif // CODEWHEEL_H


