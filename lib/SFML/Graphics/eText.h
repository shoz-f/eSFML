/***  File Header  ************************************************************/
/**
* @file eText.h
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
#ifndef _ETEXT_H
#define _ETEXT_H

/*** IMPORT ***/
#include "eDrawable.h"

/*** CONSTANT ***/

/*** TYPE DEF ***/
typedef NifResChild<sf::Text, ResDrawable> ResText;

/*** MACRO ***/

/*** IMPORT FUNCTION ***/

/*** GLOBAL VARIABLE ***/

/*** EXPORT FUNCTION ***/

DECL_NIF(sfTextCreate);
DECL_NIF(sfTextDestroy);
DECL_NIF(sfTextSetCharacterSize);
DECL_NIF(sfTextSetLetterSpacing);
DECL_NIF(sfTextSetLineSpacing);
DECL_NIF(sfTextSetStyle);
DECL_NIF(sfTextSetColor);
DECL_NIF(sfTextGetOutlineThickness);
DECL_NIF(sfTextSetOutlineThickness);
DECL_NIF(sfTextGetOrigin);
DECL_NIF(sfTextSetOrigin);
DECL_NIF(sfTextGetPosition);
DECL_NIF(sfTextSetPosition);
DECL_NIF(sfTextGetRotation);
DECL_NIF(sfTextSetRotation);
DECL_NIF(sfTextGetScale);
DECL_NIF(sfTextSetScale);
DECL_NIF(sfTextGetOutlineColor);
DECL_NIF(sfTextSetOutlineColor);
DECL_NIF(sfTextGetFillColor);
DECL_NIF(sfTextSetFillColor);
DECL_NIF(sfTextMove);
DECL_NIF(sfTextRotate);
DECL_NIF(sfTextScale);
DECL_NIF(sfTextGetGlobalBounds);

#endif  // _ETEXT_H

#if 0
Text ()
Text (const String &string, const Font &font, unsigned int characterSize=30)
const String & 	getString () const
const Font * 	getFont () const
unsigned int 	getCharacterSize () const
float 	getLetterSpacing () const
float 	getLineSpacing () const
Uint32 	getStyle () const
const Color & 	getColor () const

Vector2f 	findCharacterPos (std::size_t index) const

FloatRect 	getLocalBounds () const
#endif