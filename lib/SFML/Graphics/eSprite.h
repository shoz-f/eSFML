/***  File Header  ************************************************************/
/**
* @file
*
* <<�^�C�g���L��>>
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
* <<�^�C�g���L��>>
* @par ���
*   <<����L��>>
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
    void keepTexture(void* r);
    void releaseTexture();

    //ACCESSOR:

    //INQUIRY:

    //ATTRIBUTE:
protected:
    void* mHaveTexture;
};

typedef NifResChild<eSprite, ResDrawable> ResSprite;

/*** MACRO ***/
#define DECL_NIF(name)  ERL_NIF_TERM name(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])

/*** IMPORT FUNCTION ***/

/*** GLOBAL VARIABLE ***/

/*** EXPORT FUNCTION ***/
ERL_NIF_TERM sfSpriteCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetTexture(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetTextureRect(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

ERL_NIF_TERM sfSpriteGetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

ERL_NIF_TERM sfSpriteGetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

ERL_NIF_TERM sfSpriteGetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

ERL_NIF_TERM sfSpriteMove(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteRotate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteFlip(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
DECL_NIF(sfSpriteFlop);

ERL_NIF_TERM sfSpriteGetGlobalBounds(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

#endif // _ESPRITE_H
