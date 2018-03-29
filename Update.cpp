#include "stdafx.h"
#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		loadLevel();
	}

	if (m_Playing)
	{
		// Update Thomas and Bob
		m_Thomas.update(dtAsSeconds);
		m_Bob.update(dtAsSeconds);

		// Detect collisions and see if the characters have reached the goal
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			// New level required
			m_NewLevelRequired = true;

			// Play sound for reaching goal
			m_SM.playReachGoal();
		}
		else
		{
			// Run bob collision detection
			detectCollisions(m_Bob);
		}

		// Let bob and thomas jump on each others heads
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}

		// Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		// Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}

	} // end of if playing

	// Check if a fire sound needs to be played
	// Iterate through the vector of vector2f objects
	for (auto it = m_FireEmitters.begin(); it != m_FireEmitters.end(); it++)
	{

		// Where is this emitter
		// Store the location in pos
		float posX = (*it).x;
		float posY = (*it).y;

		// is the emitter near the player
		// make a 500 pixel rectangle round the emitter
		FloatRect localRect(posX - 250, posY - 250, 500, 500);

		// Is the player inside the localRect
		if (m_Thomas.getPosition().intersects(localRect))
		{
			// Play the sound and pass in the locations
			m_SM.playFire(Vector2f(posX, posY), m_Thomas.getCenter());
		}

	} // End fire loop

	  // Set the view around the appropriate character
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		if (m_Character1) // if we should focus on thomas...
		{
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}

} // end of update function