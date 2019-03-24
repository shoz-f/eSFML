/***  File Header  ************************************************************/
/**
* @file eVertex.h
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
#ifndef _EVERTEX_H
#define _EVERTEX_H

/*** IMPORT ***/
#include "eDrawable.h"

/*** CONSTANT ***/

/*** TYPE DEF ***/
typedef NifResChild<sf::Vertex, ResDrawable> ResText;

/*** MACRO ***/

/*** IMPORT FUNCTION ***/

/*** GLOBAL VARIABLE ***/

/*** EXPORT FUNCTION ***/

DECL_NIF(sfVertexCreate);
DECL_NIF(sfVertexDestroy);

DECL_NIF(sfVertexSetColor);

#endif  // _EVERTEX_H
