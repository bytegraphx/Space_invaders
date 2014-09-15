#include "AIE.h"
#include <iostream>

cont int iScreenWidth = 672;
cont int iScreenHeight = 780

int main( int argc, char* argv[] )
{	
	Initialise(iScreenWidth, iScreenHeight, false, "Space Invaders");

    
    

    //Game Loop
    do
    {
        MoveSprite(myTextureHandle, xPos, yPos);
        DrawSprite(myTextureHandle);

        ClearScreen();

    } while(!FrameworkUpdate());

    Shutdown();

    return 0;
}
