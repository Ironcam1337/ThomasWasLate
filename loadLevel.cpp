#include "stdafx.h"
#include "Engine.h"

void Engine::loadLevel()
{

	m_Playing = false;

	// Delete the previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_Arraylevel[i];
	}
	delete[] m_Arraylevel;

	// Load the next 2D aray with the map for the level
	// And repopulate the vertex array as well
	m_Arraylevel = m_LM.nextLevel(m_VALevel);

	//prepare the sound emitters for the fire
	populateEmitters(m_FireEmitters, m_Arraylevel);

	// How long is the new time limit?
	m_TimeRemaining = m_LM.getTimeLimit();

	// Spawn Thomas and Bob
	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);

	// Make sure this isn't run twice
	m_NewLevelRequired = false;

} // end loadLevel()