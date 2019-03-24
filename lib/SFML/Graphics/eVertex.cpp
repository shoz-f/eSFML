/***  File Header  ************************************************************/
/**
* @file eVertex.cpp
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
#include "eVertex.h"

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
ERL_NIF_TERM sfVertexCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary bin;
    if (!enif_inspect_binary(env, argv[0], &bin)) {
        return enif_make_badarg(env);
    }
    std::string text((const char*)bin.data, bin.size);

    ResText res(env);
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
ERL_NIF_TERM sfVertexDestroy(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfVertexSetColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Color color;
    if (!enifGetColor(env, argv[1], color)) {
        return enif_make_badarg(env);
    }

    res.mObj->color = color;

    return argv[0];
}

/***  End of eVertex.cpp  *************************************************}}}*/
