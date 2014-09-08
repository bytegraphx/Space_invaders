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

const int iScreenWidth = 755; // screen size
const int iScreenHeight = 780; // screen size
const int iPlayerCannonWidth = 64; //plaper icon size
const int iPlayerCannonHeight = 32; // player icon size
const int marqueeWidth = 755;
const int marqueeHeight = 780;

const char* pInVadersFont = "./fonts/invaders.fnt";


char pkScore1[ 10 ] = "00000";
char pkHighScore [ 10 ] = "00000";
char pkScore2 [ 10 ] = "00000";
char pkCredit [ 10 ] = "99";


//..

enum GAMESTATES
{
    eMAIN_MENU,
    eGAMEPLAY,
    eEND,
};

GAMESTATES eCurrentState;


int main ( int argc, char* argv[]) // main
{
    eCurrentState = GAMESTATES::eMAIN_MENU;


	Initialise(iScreenWidth, iScreenHeight, false, "Space Invaders"); // open screen
    unsigned int iArcadeMarquee = CreateSprite ("./images/ispaceInvaderMarquee.png", marqueeWidth, marqueeHeight, true);
    unsigned int iPlayerCannon = CreateSprite("./images/cannon.png", iPlayerCannonWidth, iPlayerCannonHeight, true); // call player icon
	MoveSprite(iPlayerCannon, iScreenWidth * 0.5f, 40); //place icon
    
	
	float fPlayerX = iScreenWidth * 0.5f; // pos. float
	float fPlayerY = 80.f; // pos. float
	MoveSprite(iPlayerCannon, fPlayerX, fPlayerY); // int for call to move
	
    
    
    switch ( eCurrentState )
    
    {
        case GAMESTATES::eMAIN_MENU:
            DrawSprite(iArcadeMarquee); //add int and path for iArcadeMarquee
            //DrawString( pkInsertCoins, iScreenWidth * 0.37f, iScreenHeight * 0.5f, 0.75); //add int for pkInsertcoin
            DrawString( pkCredit, iScreenWidth * 0.25f, iScreenHeight *0.4f, 0.7f);
            if( IsKeyDown(KEY_ENTER))
          
            break;
            
            
        
        case GAMESTATES::eGAMEPLAY:
            
    //GAME LOOP
	
    do
	{
		ClearScreen(); // clear screen
        DrawSprite(iPlayerCannon); // draw player
		SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF)); // set background to blk
        DrawSprite(iArcadeMarquee); //add int and path for iArcadeMarquee

        DrawString( "SCORE1 <1>", iScreenWidth * 0.020f, iScreenHeight -2);
        DrawString( "HIGH SCORE <1>", iScreenWidth * 0.35f, iScreenHeight -2);
        DrawString( "SCORE2 <1>", iScreenWidth * 0.73f, iScreenHeight -2);
        DrawString( "CREDITS <1>", iScreenWidth * 0.72f, iScreenHeight -750);
        //AddFont(pInVadersFont); //these calls not found in Xcode AIEFramework tried to add from Other file but didn't work
        //SetFont(pInVadersFont); //lost a few hours on these.. thx guys
        
		MoveSprite(iPlayerCannon, fPlayerX, fPlayerY);
		DrawSprite( iPlayerCannon);
        
        DrawLine( 0, 40, iScreenWidth, 40, SColour( 0x00, 0xFC, 0x00, 0xFF));
        DrawString( pkScore1, iScreenWidth * 0.025f, iScreenHeight - 2 );
        DrawString( pkHighScore, iScreenWidth * 0.425f, iScreenHeight -2);
        DrawString( pkScore2, iScreenWidth * 0.8f, iScreenHeight -2);
        DrawString( pkCredit, iScreenWidth * 0.7f, 38);

		
		
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
		
        
        break;
        
    case GAMESTATES::eEND:
    
        {
            eCurrentState = eMAIN_MENU;
        }
        break;
    default:
        std::cout << "Default Case";
        break;
		
	} while
		
	(FrameworkUpdate() == false);
	
//	DestroySprite(iPlayerCannon);
	
//	Shutdown();
	
//	return 0;
  
	
   }
}