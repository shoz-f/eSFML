/***  File Header  ************************************************************/
/**
* @file sfCircleShape.h
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
#ifndef _ECIRCLESHAPE_H
#define _ECIRCLESHAPE_H

/*** IMPORT ***/
#include "eDrawable.h"

/*** CONSTANT ***/

/*** TYPE DEF ***/
typedef NifResChild<sf::CircleShape, ResDrawable> ResCircleShape;

/*** MACRO ***/

/*** IMPORT FUNCTION ***/

/*** GLOBAL VARIABLE ***/

/*** EXPORT FUNCTION ***/

DECL_NIF(sfCircleShapeCreate);
DECL_NIF(sfCircleShapeDestroy);
DECL_NIF(sfCircleShapeSetRadius);
DECL_NIF(sfCircleShapeGetRasius);
DECL_NIF(sfCircleShapeGetPoint);
DECL_NIF(sfCircleShapeGetOutlineThickness);
DECL_NIF(sfCircleShapeSetOutlineThickness);
DECL_NIF(sfCircleShapeSetTexture);
DECL_NIF(sfCircleShapeSetTextureRect);
DECL_NIF(sfCircleShapeGetTextureRect);
DECL_NIF(sfCircleShapeGetOrigin);
DECL_NIF(sfCircleShapeSetOrigin);
DECL_NIF(sfCircleShapeGetPosition);
DECL_NIF(sfCircleShapeSetPosition);
DECL_NIF(sfCircleShapeGetRotation);
DECL_NIF(sfCircleShapeSetRotation);
DECL_NIF(sfCircleShapeGetScale);
DECL_NIF(sfCircleShapeSetScale);
DECL_NIF(sfCircleShapeGetOutlineColor);
DECL_NIF(sfCircleShapeSetOutlineColor);
DECL_NIF(sfCircleShapeGetFillColor);
DECL_NIF(sfCircleShapeSetFillColor);
DECL_NIF(sfCircleShapeMove);
DECL_NIF(sfCircleShapeRotate);
DECL_NIF(sfCircleShapeScale);
DECL_NIF(sfCircleShapeFlip);
DECL_NIF(sfCircleShapeFlop);
DECL_NIF(sfCircleShapeGetGlobalBounds);

#endif  // _ECIRCLESHAPE_H

#if 0
void 	setPointCount (std::size_t count)
virtual std::size_t 	getPointCount () const
const Texture * 	getTexture () const
FloatRect 	getLocalBounds () const
#endif