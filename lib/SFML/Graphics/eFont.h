/***  File Header  ************************************************************/
/**
* @file eFont.h
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
#ifndef _EFONT_H
#define _EFONT_H

/*** IMPORT ***/
#include <SFML/Graphics.hpp>
#include "ErlNifEx.h"

/*** CONSTANT ***/

/*** TYPE DEF ***/
typedef NifRes<sf::Font> ResFont;

/*** MACRO ***/

/*** IMPORT FUNCTION ***/

/*** GLOBAL VARIABLE ***/

/*** EXPORT FUNCTION ***/

DECL_NIF(sfFontLoadFromFile);

#endif  // _ETEXT_H
