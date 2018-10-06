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
ERL_NIF_TERM sfSpriteCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
DECL_NIF(sfSpriteClone);
ERL_NIF_TERM sfSpriteSetTexture(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetTextureRect(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
DECL_NIF(sfSpriteGetTextureRect);

ERL_NIF_TERM sfSpriteGetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

ERL_NIF_TERM sfSpriteGetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

ERL_NIF_TERM sfSpriteGetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

DECL_NIF(sfSpriteGetColor);
DECL_NIF(sfSpriteSetColor);

ERL_NIF_TERM sfSpriteMove(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteRotate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteFlip(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
DECL_NIF(sfSpriteFlop);

ERL_NIF_TERM sfSpriteGetGlobalBounds(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

#endif // _ESPRITE_H
