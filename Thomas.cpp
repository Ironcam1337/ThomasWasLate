#include "stdafx.h"
#include "Thomas.h"
#include "TextureHolder.h"

Thomas::Thomas()
{

	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/thomas.png"));

	m_JumpDuration = 0.45f;

} // end functio Thomas()

  //========================================================================

bool Thomas::handleInput()
{
	// Always start assuming not jumping
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		// Start a jump if not already jumping
		// But only if standing on a block (not falling)
		if (!m_IsJumping && !m_IsFalling)
		{
			// Perform jump
			m_IsJumping = true;
			m_TimeThisJump = 0;
			m_JustJumped = true;
		} // end if not jumping or falling
	} // end if keyboard pressed w
	else
	{
		// Stop jump early if W not held down
		m_IsJumping = false;
		m_IsFalling = true;
	}// end w not pressed

	 // Check left
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	// Check right
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}

	// Return whether we just jumped or not
	return m_JustJumped;

} // end function handleInput()