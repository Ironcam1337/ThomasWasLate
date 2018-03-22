#include "stdafx.h"
#include "Bob.h"
#include "TextureHolder.h"

Bob::Bob()
{

	// Associate a texture with the sprite
	m_Sprite = Sprite(TextureHolder::GetTexture("graphics/bob.png"));

	m_JumpDuration = 0.25f;

} // end functio Thomas()

  //========================================================================

bool Bob::handleInput()
{
	// Always start assuming not jumping
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::Up))
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
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	// Check right
	if (Keyboard::isKeyPressed(Keyboard::Right))
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