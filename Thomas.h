#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{

public:

	// Constructor
	Thomas();

	// This will implement the pure virtual function from PlayableCharacter
	bool virtual handleInput();

}; // end class Thomas
