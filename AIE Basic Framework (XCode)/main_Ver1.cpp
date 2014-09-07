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

const int iScreenWidth = 672; // screen size
const int iScreenHeight = 780; // screen size
const int iPlayerCannonWidth = 64; //plaper icon size
const int iPlayerCannonHeight = 32; // player icon size

const char* pInVadersFont = "./fonts/invaders.fnt";

char pkScore1[ 10 ] = "00000";
char pkHightScore [ 10 ] = "00000";
char pkScore2 [ 10 ] = "00000";
char pkCredit [ 10 ] = "99";


//..


int main ( int argc, char* argv[]) // main

{
	Initialise(iScreenWidth, iScreenHeight, false, "Space Invaders"); // open screen
    unsigned int iPlayerCannon = CreateSprite("./images/cannon.png", iPlayerCannonWidth, iPlayerCannonHeight, true); // call player icon
	MoveSprite(iPlayerCannon, iScreenWidth * 0.5f, 40); //place icon
    
	
	float fPlayerX = iScreenWidth * 0.5f; // pos. float
	float fPlayerY = 80.f; // pos. float
	MoveSprite(iPlayerCannon, fPlayerX, fPlayerY); // int for call to move
	
//GAME LOOP
	
    do
	{
		ClearScreen(); // clear screen
        DrawSprite(iPlayerCannon); // draw player
		SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF)); // set background to blk
        DrawString( "SCORE1 <1>", iScreenWidth * 0.020f, iScreenHeight -2);
        DrawString( "HIGH SCORE <1>", iScreenWidth * 0.35f, iScreenHeight -2);
        DrawString( "SCORE2 <1>", iScreenWidth * 0.73f, iScreenHeight -2);
        DrawString( "CREDITS <1>", iScreenWidth * 0.72f, iScreenHeight -750);
        //AddFont(pInVadersFont); //these calls not found in Xcode AIEFramework tried to add from Other file but didn't work
        //SetFont(pInVadersFont); //lost a few hours on these.. thx guys
        
		

		
		
		if (IsKeyDown('D')) // if you press d move right
		{
			
			fPlayerX += 2.f;
			
			if (fPlayerX > iScreenWidth - iPlayerCannonWidth / 2) //width of screen - player / 2
			{
				fPlayerX = iScreenWidth - iPlayerCannonWidth /2; //width of screen - player width /2
			}
		}
		
		if (IsKeyDown('A')) // if you press a move left
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