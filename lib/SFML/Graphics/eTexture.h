/***  File Header  ************************************************************/
/**
* @file eTexture.h
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
#ifndef _ETEXTURE_H
#define _ETEXTURE_H

/*** IMPORT ***/
#include <SFML/Graphics.hpp>
#include "ErlNifEx.h"

/*** CONSTANT ***/

/*** TYPE DEF ***/
typedef NifRes<sf::Texture> ResTexture;

/*** MACRO ***/

/*** IMPORT FUNCTION ***/

/*** GLOBAL VARIABLE ***/

/*** EXPORT FUNCTION ***/

DECL_NIF(sfTextureLoadFromFile);
DECL_NIF(sfTextureGetSize);

#endif  // _ETEXT_H
