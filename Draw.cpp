#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{
	//Erase the last frame
	m_Window.clear(Color::White);

	//Single screen
	if (!m_Splitscreen)
	{
		//Switch to the background view
		m_Window.setView(m_BGMainView);
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Set main view
		m_Window.setView(m_MainView);
		//TODO: Draw all the stuff

	}//End of single screen
	//Splitscreen
	else
	{
		//Draw thomas' side of the screen
		//Switch to the background view
		m_Window.setView(m_BGLeftView);
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Switch to the main view for left
		m_Window.setView(m_LeftView);
		//TODO: Draw all the stuff

		//Draw Bob's side of the screen
		//Switch to the background view
		m_Window.setView(m_BGRightView);
		//Draw the background
		m_Window.draw(m_BackgroundSprite);
		//Switch to the main view for left
		m_Window.setView(m_RightView);
		//TODO: Draw all the stuff

	}//End split screen

	// Draw HUD
	// Switch to HUD view
	m_Window.setView(m_HudView);
	//TODO draw hud

	//Show Everything we have just drawn
	m_Window.display();

} //End of draw function