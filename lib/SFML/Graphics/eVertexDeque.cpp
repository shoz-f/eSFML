/***  File Header  ************************************************************/
/**
* @file eVertexDeque.cpp
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
#include "eVertexDeque.h"

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
ERL_NIF_TERM sfVertexDequeCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResVertexDeque res(env);
    if (!res.Create()) {
        return enif_make_badarg(env);
    }

    unsigned int count;
    if (!enif_get_uint(env, argv[0], &count)) {
        return enif_make_badarg(env);
    }

    res.mObj->resize(count);

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
ERL_NIF_TERM sfVertexDequeDestroy(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResVertexDeque res(env);
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
ERL_NIF_TERM sfVertexDequeGetCount(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResVertexDeque res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enif_make_uint(env, res.mObj->getVertexCount());
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
ERL_NIF_TERM sfVertexDequeSetVertexPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResVertexDeque res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    unsigned int index;
    if (!enif_get_uint(env, argv[1], &index)) {
        return enif_make_badarg(env);
    }

    sf::Vector2f position;
    if (!enifGetVector2f(env, argv[2], position)) {
        return enif_make_badarg(env);
    }
    
    res.mObj->setVertexPosition(index, position);

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
ERL_NIF_TERM sfVertexDequeSetVertexColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResVertexDeque res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    unsigned int index;
    if (!enif_get_uint(env, argv[1], &index)) {
        return enif_make_badarg(env);
    }

    sf::Color color;
    if (!enifGetColor(env, argv[2], color)) {
        return enif_make_badarg(env);
    }
    
    res.mObj->setVertexColor(index, color);

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
ERL_NIF_TERM sfVertexDequeGetVertex(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResVertexDeque res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    unsigned int index;
    if (!enif_get_uint(env, argv[1], &index)) {
        return enif_make_badarg(env);
    }

    if (index < res.mObj->getVertexCount()) {
        sf::Vertex v = res.mObj->getVertex(index);
        return enifMakeVertex(env, v.position, v.color);
    }
    else {
        return NIL(env);
    }
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
ERL_NIF_TERM sfVertexDequeClear(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResVertexDeque res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    res.mObj->clear();

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
ERL_NIF_TERM sfVertexDequeResize(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResVertexDeque res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    unsigned int count;
    if (!enif_get_uint(env, argv[1], &count)) {
        return enif_make_badarg(env);
    }

    res.mObj->resize(count);

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
ERL_NIF_TERM sfVertexDequePush(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResVertexDeque res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f position(0.0, 0.0);
    if (!enifGetVector2f(env, argv[1], position)) {
        return enif_make_badarg(env);
    }

    res.mObj->push(sf::Vertex(position));

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
ERL_NIF_TERM sfVertexDequeSetPrimitiveType(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResVertexDeque res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::PrimitiveType type;
    if (!enifGetPrimitiveType(env, argv[1], type)) {
        return enif_make_badarg(env);
    }

    res.mObj->setPrimitiveType(type);

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
ERL_NIF_TERM sfVertexDequeGetPrimitiveType(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResVertexDeque res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enifMakePrimitiveType(env, res.mObj->getPrimitiveType());
}

/***  End of eVertexDeque.cpp  *************************************************}}}*/
