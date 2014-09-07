#include "AIE.h"
#include <iostream>

const int iScreenWidth = 672;
const int iScreenHeight = 780;
const int iPlayerCannonWidth = 64;
const int iPlayerCannonHeight = 32;


const char* pInVadersFont = "./fonts/invaders.fnt";
char pkScore1 [10] = "00000";
char pkHighScore [10] = "00000";
char pkScore2 [10] = "00000";
char pkCredit [10] = "99";

//....session two
enum GAMESTATES
{
	eMAIN_MENU,
	eGAMEPLAY,
	eEND,
};


int main( int argc, char* argv[] )

{	
	
	GAMESTATES eCurrentState = eMAIN_MENU;


	Initialise(iScreenWidth, iScreenHeight, false, "Space Invaders");
	AddFont(pInVadersFont); //needs to be after the Initialise line
	
	unsigned int iPlayerCannon = CreateSprite("./images/cannon.png", iPlayerCannonWidth, iPlayerCannonHeight, true);
	MoveSprite(iPlayerCannon, iScreenWidth * 0.5f, 40);

	float fPlayerX = iScreenWidth * 0.5f;
	float fPlayerY = 80.f;
	MoveSprite(iPlayerCannon, fPlayerX, fPlayerY);

	do
	{
		ClearScreen();
		SetFont(pInVadersFont);


		switch (eCurrentState
		{
		case eMAIN_MENU:
			DrawSprite(iArcadeMarquee);
			DrawString(pkInserCoins, iScreenWidth *0.37f, iScreenHeight * 0.5f, 0.75f);
			DrawString(pkCredits, iScreenWidth * 0.25f, iScreenHeight * 0.4f, 0.7f);

			if (IsKeyDown(KEY_ENTER))
			{
				eCurrentState = eGAMEPLAY;
			}
			break;
		case eGAMEPLAY:
			if (IsKeyDown('A'))
			{
				fPlayerX -=
			}
		
		})

		DrawSprite(iPlayerCannon);
		SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));
		DrawString("SCORE <1>", iScreenWidth * 0.025f, iScreenHeight - 2);
		DrawString("HIGH SCORE", iScreenWidth * 0.35f, iScreenHeight - 2);
		DrawString("SCORE <2>", iScreenWidth * 0.75f, iScreenHeight - 2);
		DrawString("CREDITS", iScreenWidth *0.75f, iScreenHeight - 725);

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


	} while (FrameworkUpdate() == false);

	DestroySprite(iPlayerCannon);

	Shutdown();

	return 0;
    

}
