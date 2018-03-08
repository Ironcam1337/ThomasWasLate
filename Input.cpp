#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
	Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			// handle the player quiting
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				m_Window.close();
			}

			//Handle the player starting the game
			if (Keyboard::isKeyPressed(Keyboard::Return))
			{
				m_Playing = true;
			}

			//Switch between thomas and bob camera focus
			if (Keyboard::isKeyPressed(Keyboard::Q))
			{
				m_Character1 = !m_Character1;
			}

			//Switch between full and split screen
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				m_Splitscreen = !m_Splitscreen;
			}



		} //End if keypressed
	} //End While loop for event polling
} // End input