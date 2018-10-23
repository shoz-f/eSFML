/***  File Header  ************************************************************/
/**
* @file
*
* <<タイトル記入>>
* @author	Shozo Fukuda
* @date		create 
* @date		modify 
* System	Windows <br>
*
* Copyright (C) Shozo Fukuda
*
**/
/**************************************************************************{{{*/
#ifndef _ESPRITE_H
#define _ESPRITE_H

/*** IMPORT ***/
#include "eDrawable.h"

/*** CONSTANT ***/

/*** TYPE DEF ***/
/***  Class Header  *******************************************************}}}*/
/**
* <<タイトル記入>>
* @par 解説
*   <<解説記入>>
**/
/**************************************************************************{{{*/
class eSprite :public sf::Sprite {
    //CONSTANT:
public:

    //LIFECYCLE:
public:
    eSprite();
    virtual ~eSprite();

    //ACTION:
public:
    void keepTextureRes(void* r);
    void releaseTextureRes();

    //ACCESSOR:

    //INQUIRY:
    void* getTextureRes();

    //ATTRIBUTE:
protected:
    void* mTextrueRes;
};

typedef NifResChild<eSprite, ResDrawable> ResSprite;

/*** MACRO ***/

/*** IMPORT FUNCTION ***/

/*** GLOBAL VARIABLE ***/

/*** EXPORT FUNCTION ***/
DECL_NIF(sfSpriteCreate);
DECL_NIF(sfSpriteClone);
DECL_NIF(sfSpriteSetTexture);
DECL_NIF(sfSpriteSetTextureRect);
DECL_NIF(sfSpriteGetTextureRect);

DECL_NIF(sfSpriteGetOrigin);
DECL_NIF(sfSpriteSetOrigin);

DECL_NIF(sfSpriteGetPosition);
DECL_NIF(sfSpriteSetPosition);

DECL_NIF(sfSpriteGetRotation);
DECL_NIF(sfSpriteSetRotation);

DECL_NIF(sfSpriteGetScale);
DECL_NIF(sfSpriteSetScale);

DECL_NIF(sfSpriteGetColor);
DECL_NIF(sfSpriteSetColor);

DECL_NIF(sfSpriteMove);
DECL_NIF(sfSpriteRotate);
DECL_NIF(sfSpriteScale);
DECL_NIF(sfSpriteFlip);
DECL_NIF(sfSpriteFlop);

DECL_NIF(sfSpriteGetGlobalBounds);

#endif // _ESPRITE_H
