/***  File Header  ************************************************************/
/**
* @file eCircleShape.cpp
*
* <<タイトル記入>>
* @author	Shozo Fukuda
* @date		create: Sat Sep 08 08:01:09 JST 2018
* @date		modify: $Date:$
* System	Windows <br>
*
* Copyright (C) Shozo Fukuda
*
**/
/**************************************************************************{{{*/

/***** INCLUDE *****/
#include "stdafx.h"
#include "eCircleShape.h"

/***** CONSTANT *****/

/***** TYPE *****/

/***** MACRO *****/

/***** EXPORT VARIABLE *****/

/***** EXPORT FUNCTION *****/

/***** PRIVATE VARIABLE *****/

/***** PRIVATE FUNCTION *****/

/***  Module Header  ******************************************************}}}*/
/**
* <タイトル記入>
* @par 解説
*   <<解説記入>>
*
* @retval <<戻り値記入>> <<戻り値説明記入>>
**/
/**************************************************************************{{{*/
ERL_NIF_TERM sfCircleShapeCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
    
    if (!res.Create()) {
        return enif_make_badarg(env);
    }
    
    return res.MkTerm();
}

/***  Module Header  ******************************************************}}}*/
/**
* <タイトル記入>
* @par 解説
*   <<解説記入>>
*
* @retval <<戻り値記入>> <<戻り値説明記入>>
**/
/**************************************************************************{{{*/
ERL_NIF_TERM sfCircleShapeDestroy(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
    
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }
    
    res.Release();
    
    return enif_make_int(env, 0);
}

/***  Module Header  ******************************************************}}}*/
/**
* <タイトル記入>
* @par 解説
*   <<解説記入>>
*
* @retval <<戻り値記入>> <<戻り値説明記入>>
**/
/**************************************************************************{{{*/
ERL_NIF_TERM sfCircleShapeSetRadius(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
    
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }
    
    double radius;
    if (!enif_get_double(env, argv[1], &radius)) {
        return enif_make_badarg(env);
    }
    
    res.mObj->setRadius((float)radius);
    
    return argv[0];
}

/***  Module Header  ******************************************************}}}*/
/**
* <タイトル記入>
* @par 解説
*   <<解説記入>>
*
* @retval <<戻り値記入>> <<戻り値説明記入>>
**/
/**************************************************************************{{{*/
ERL_NIF_TERM sfCircleShapeSetFillColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Color color;
    if (!enifGetColor(env, argv[1], color)) {
        return enif_make_badarg(env);
    }

    res.mObj->setFillColor(color);

    return argv[0];
}

/***  End of eSprite.cpp  *************************************************}}}*/
