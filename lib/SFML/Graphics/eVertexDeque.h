/***  File Header  ************************************************************/
/**
* @file eVertexDeque.h
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
#ifndef _EVERTEXDEQUE_H
#define _EVERTEXDEQUE_H

/*** IMPORT ***/
#include "eDrawable.h"
#include "VertexDeque.h"

/*** CONSTANT ***/

/*** TYPE DEF ***/
typedef NifResChild<sf::VertexDeque, ResDrawable> ResVertexDeque;

/*** MACRO ***/

/*** IMPORT FUNCTION ***/

/*** GLOBAL VARIABLE ***/

/*** EXPORT FUNCTION ***/

DECL_NIF(sfVertexDequeCreate);
DECL_NIF(sfVertexDequeDestroy);

DECL_NIF(sfVertexDequeGetCount);
DECL_NIF(sfVertexDequeSetVertexPosition);
DECL_NIF(sfVertexDequeSetVertexColor);
DECL_NIF(sfVertexDequeGetVertex);
DECL_NIF(sfVertexDequeClear);
DECL_NIF(sfVertexDequeResize);
DECL_NIF(sfVertexDequePush);
DECL_NIF(sfVertexDequeSetPrimitiveType);
DECL_NIF(sfVertexDequeGetPrimitiveType);

#endif  // _EVERTEXDEQUE_H
