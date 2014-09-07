/*
 *  space_one_rework.h
 *  AIE Basic Framework For Xcode
 *
 *  Created by MAXXIE on 9/3/14.
 *  Copyright 2014 AIE. All rights reserved.
 *
 */

#include "AIE.h"
#include <iostream>

const int iScreenWidth = 672;
const int iScreenHeight = 780;
const int iPlayerCannonWidth = 64;
const int iPlayerCannonHeight = 32;

const char*pInVadersFont = "./fonts/invaders.fnt";



int main ( int argc, char* argv[])

{
	Initialise(iScreenWidth, iScreenHeight, false, "Space Invaders");
	
	unsigned int iPlayerCannon = CreateSprite("./images/cannon.png", 64, 32, true);
	MoveSprite(iPlayerCannon, iScreenWidth * 0.5f, 40);
	
	float fPlayerX = iScreenWidth * 0.5f;
	float fPlayerY = 80.f;
	MoveSprite(iPlayerCannon, fPlayerX, fPlayerY);
	
	do 
	{
		ClearScreen();
		
		DrawSprite(iPlayerCannon);
		SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));
		
		
		
		if (IsKeyDown('D'))
		{
			
			fPlayerX += 2.f;
			
			if (fPlayerX > iScreenWidth - iPlayerCannonWidth / 2) //width of screen - player / 2
			{
				fPlayerX = iScreenWidth - iPlayerCannonWidth /2; //width of screen - player width /2
			}
		}
		
		if (IsKeyDown('A'))
		{
			fPlayerX -= 2.f; //move player by 2
			
			if (fPlayerX < iPlayerCannonWidth / 2) //screen starts at 0,0 so just need the player sprite /2 their code was 32.f sprite is 64
			{
				fPlayerX = iPlayerCannonWidth / 2;
			}
		}
		
		MoveSprite(iPlayerCannon, fPlayerX, fPlayerY);
		
		
	} while 
		
		(FrameworkUpdate() == false);
	
	DestroySprite(iPlayerCannon);
	
	Shutdown();
	
	return 0;
	
	
}