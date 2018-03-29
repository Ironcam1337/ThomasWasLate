#include "stdafx.h"
#include "Engine.h"

using namespace sf;
using namespace std;

void Engine::populateEmitters(vector<Vector2f>& vSoundEmitter, int** arrayLevel)
{
	// Make sure the vector is empty
	vSoundEmitter.clear();

	// Keep track of the previous emitter
	// So we dont make too many
	FloatRect previousEmitter;

	// Search through the level array for fire
	for (int x = 0; x < m_LM.getLevelSize().x; x++)
	{
		for (int y = 0; y < m_LM.getLevelSize().y; y++)
		{
			if (arrayLevel[y][x] == 2)
			{
				// skip over any fire tiles too near the previous emitter
				FloatRect currentTile = FloatRect(x*TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE);
				if (!currentTile.intersects(previousEmitter))
				{
					// Add the coordinates of this block
					vSoundEmitter.push_back(Vector2f(x*TILE_SIZE, y*TILE_SIZE));

					// Make a rectangle 6 blocks x 6 blocks so we dont make any more emitters too close to this one
					previousEmitter.left = x*TILE_SIZE;
					previousEmitter.top = y*TILE_SIZE;
					previousEmitter.width = TILE_SIZE*6;
					previousEmitter.height = TILE_SIZE*6;
				} // end if not too close to other emitter
			} // end if fire
		} // end y loop
	} // end x loop


} // End of populateEmitters