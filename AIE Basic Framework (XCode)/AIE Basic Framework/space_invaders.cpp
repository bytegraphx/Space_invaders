//
//  space_invaders.cpp
//  AIE Basic Framework
//
//  Created by MAXXIE on 9/5/14.
//  Copyright (c) 2014 AIE. All rights reserved.
//

#include "space_invaders.h"
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




int main( int argc, char* argv[] );




    
        unsigned int iPlayerCannon = CreateSprite ("./image.cannon.png", 64, 32, true); // call player sprite graphic and scale
    
        Initialise(iScreenWidth, iScreenHeight, false, "Space Invaders"); // set up screen size
        ClearScreen();
        DrawSprite(iPlayerCannon);
        SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));
        DrawString("SCORE <1>", iScreenWidth * 0.025f, iScreenHeight - 2);
        DrawString("HIGH SCORE", iScreenWidth * 0.35f, iScreenHeight - 2);
        DrawString("SCORE <2>", iScreenWidth * 0.75f, iScreenHeight - 2);
        DrawString("CREDITS", iScreenWidth *0.75f, iScreenHeight - 725);
        AddFont(pInVadersFont);//needs to be after the Initialise line
        SetFont( pInVadersFont);
{

        if (IsKeyDown('A')) // if pressing a then move left
                
            fPlayerX -= 2.f; //move player by 2
            
            
            if (fPlayerX < iPlayerCannonWidth / 2) //screen starts at 0,0 so just need the player sprite /2 their code was 32.f sprite is 64
                    
            fPlayerX = iPlayerCannonWidth / 2;
        
    

        if (IsKeyDown('D')) // if pressing d then move right

    
            fPlayerX += 2.f;
            if (fPlayerX > iScreenWidth - iPlayerCannonWidth / 2) //width of screen - player / 2
            
                fPlayerX = iScreenWidth - iPlayerCannonWidth /2; //width of screen - player width /2
        break;
        default:
            cout << "default";
        break;
    
    }
    
    {
    
        MoveSprite(iPlayerCannon, fPlayerX, fPlayerY);
    
        
    
    while (FrameworkUpdate() == false);
    DestroySprite(iPlayerCannon);
    Shutdown();
    return 0;
    }

