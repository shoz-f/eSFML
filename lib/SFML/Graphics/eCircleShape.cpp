/***  File Header  ************************************************************/
/**
* @file eCircleShape.cpp
*
* <<�^�C�g���L��>>
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
#include "eColor.h"
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
* <�^�C�g���L��>
* @par ���
*   <<����L��>>
*
* @retval <<�߂�l�L��>> <<�߂�l�����L��>>
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
* <�^�C�g���L��>
* @par ���
*   <<����L��>>
*
* @retval <<�߂�l�L��>> <<�߂�l�����L��>>
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
* <�^�C�g���L��>
* @par ���
*   <<����L��>>
*
* @retval <<�߂�l�L��>> <<�߂�l�����L��>>
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
* <�^�C�g���L��>
* @par ���
*   <<����L��>>
*
* @retval <<�߂�l�L��>> <<�߂�l�����L��>>
**/
/**************************************************************************{{{*/
ERL_NIF_TERM sfCircleShapeSetFillColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    char name[256];
    if (!enif_get_atom(env, argv[1], name, sizeof(name), ERL_NIF_LATIN1)) {
        return enif_make_badarg(env);
    }

    try {
        sf::Color color = cColorMap.at(name);
        res.mObj->setFillColor(color);
    }
    catch (std::out_of_range&) {
    }
    
    return argv[0];
}

/***  End of eSprite.cpp  *************************************************}}}*/
