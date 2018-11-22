/***  File Header  ************************************************************/
/**
* @file eRectangleShape.h
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
#ifndef _ERECTANGLESHAPE_H
#define _ERECTANGLESHAPE_H

/*** IMPORT ***/
#include "eDrawable.h"

/*** CONSTANT ***/

/*** TYPE DEF ***/
typedef NifResChild<sf::RectangleShape, ResDrawable> ResRectangleShape;

/*** MACRO ***/

/*** IMPORT FUNCTION ***/

/*** GLOBAL VARIABLE ***/

/*** EXPORT FUNCTION ***/

DECL_NIF(sfRectangleShapeCreate);
DECL_NIF(sfRectangleShapeDestroy);
DECL_NIF(sfRectangleShapeSetSize);
DECL_NIF(sfRectangleShapeGetSize);
DECL_NIF(sfRectangleShapeGetPoint);
DECL_NIF(sfRectangleShapeGetOutlineThickness);
DECL_NIF(sfRectangleShapeSetOutlineThickness);
DECL_NIF(sfRectangleShapeSetTexture);
DECL_NIF(sfRectangleShapeSetTextureRect);
DECL_NIF(sfRectangleShapeGetTextureRect);
DECL_NIF(sfRectangleShapeGetOrigin);
DECL_NIF(sfRectangleShapeSetOrigin);
DECL_NIF(sfRectangleShapeGetPosition);
DECL_NIF(sfRectangleShapeSetPosition);
DECL_NIF(sfRectangleShapeGetRotation);
DECL_NIF(sfRectangleShapeSetRotation);
DECL_NIF(sfRectangleShapeGetScale);
DECL_NIF(sfRectangleShapeSetScale);
DECL_NIF(sfRectangleShapeGetOutlineColor);
DECL_NIF(sfRectangleShapeSetOutlineColor);
DECL_NIF(sfRectangleShapeGetFillColor);
DECL_NIF(sfRectangleShapeSetFillColor);
DECL_NIF(sfRectangleShapeMove);
DECL_NIF(sfRectangleShapeRotate);
DECL_NIF(sfRectangleShapeScale);
DECL_NIF(sfRectangleShapeFlip);
DECL_NIF(sfRectangleShapeFlop);
DECL_NIF(sfRectangleShapeGetGlobalBounds);

#endif  // _ERECTANGLESHAPE_H

#if 0
virtual std::size_t 	getPointCount () const
const Texture * 	getTexture () const
FloatRect 	getLocalBounds () const
#endif