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
#ifndef _ETRANSFORMABLE_H
#define _ETRANSFORMABLE_H

/*** IMPORT ***/
#include "eDrawable.h"

/*** CONSTANT ***/

/*** TYPE DEF ***/
class eTransformable :public sf::Drawable, public sf::Transformable {
    /* **DANGER**
     * to fit the memory layout in multiple inheritance classes
     *   sf::Shape, sf::Sprite, sf::Text
     */
};

typedef NifResMixIn<eTransformable, ResDrawable> ResTransformable;

/*** MACRO ***/

/*** IMPORT FUNCTION ***/

/*** GLOBAL VARIABLE ***/

/*** EXPORT FUNCTION ***/
DECL_NIF(sfTransformableGetOrigin);
DECL_NIF(sfTransformableSetOrigin);

DECL_NIF(sfTransformableGetPosition);
DECL_NIF(sfTransformableSetPosition);

DECL_NIF(sfTransformableGetRotation);
DECL_NIF(sfTransformableSetRotation);

DECL_NIF(sfTransformableGetScale);
DECL_NIF(sfTransformableSetScale);

DECL_NIF(sfTransformableMove);
DECL_NIF(sfTransformableRotate);
DECL_NIF(sfTransformableScale);

#endif // _ETRANSFORMABLE_H
