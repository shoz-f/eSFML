/***  File Header  ************************************************************/
/**
* @file eConvexShape.h
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
#ifndef _ECONVEXSHAPE_H
#define _ECONVEXSHAPE_H

/*** IMPORT ***/
#include "eDrawable.h"

/*** CONSTANT ***/

/*** TYPE DEF ***/
typedef NifResChild<sf::ConvexShape, ResDrawable> ResConvexShape;

/*** MACRO ***/

/*** IMPORT FUNCTION ***/

/*** GLOBAL VARIABLE ***/

/*** EXPORT FUNCTION ***/
DECL_NIF(sfConvexShapeCreate);

DECL_NIF(sfConvexShapeGetPointCount);
DECL_NIF(sfConvexShapeGetPoint);

DECL_NIF(sfConvexShapeGetOutlineThickness);
DECL_NIF(sfConvexShapeSetOutlineThickness);

DECL_NIF(sfConvexShapeSetTexture);
DECL_NIF(sfConvexShapeSetTextureRect);
DECL_NIF(sfConvexShapeGetTextureRect);

DECL_NIF(sfConvexShapeGetOrigin);
DECL_NIF(sfConvexShapeSetOrigin);

DECL_NIF(sfConvexShapeGetPosition);
DECL_NIF(sfConvexShapeSetPosition);

DECL_NIF(sfConvexShapeGetRotation);
DECL_NIF(sfConvexShapeSetRotation);

DECL_NIF(sfConvexShapeGetScale);
DECL_NIF(sfConvexShapeSetScale);

DECL_NIF(sfConvexShapeGetOutlineColor);
DECL_NIF(sfConvexShapeSetOutlineColor);
DECL_NIF(sfConvexShapeGetFillColor);
DECL_NIF(sfConvexShapeSetFillColor);

DECL_NIF(sfConvexShapeMove);
DECL_NIF(sfConvexShapeRotate);
DECL_NIF(sfConvexShapeScale);
DECL_NIF(sfConvexShapeFlip);
DECL_NIF(sfConvexShapeFlop);

DECL_NIF(sfConvexShapeGetGlobalBounds);

#endif // _ECONVEXSHAPE_H
