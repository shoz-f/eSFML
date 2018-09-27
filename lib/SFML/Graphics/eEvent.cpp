/***  File Header  ************************************************************/
/**
* @file eEvent.cpp
*
* <<タイトル記入>>
* @author	Shozo Fukuda
* @date		create: Sun Sep 09 22:49:45 JST 2018
* @date		modify: $Date:$
* System	Windows <br>
*
* Copyright (C) Shozo Fukuda
*
**/
/**************************************************************************{{{*/

/***** INCLUDE *****/
#include "stdafx.h"
#include "eEvent.h"

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
ERL_NIF_TERM enifMakeNoEvent(ErlNifEnv* env)
{
    return enif_make_tuple2(env, enif_make_atom(env, "none"), NIL(env));
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
inline ERL_NIF_TERM enifMakeEventSub(ErlNifEnv* env, char* name, ERL_NIF_TERM val)
{
    return enif_make_tuple2(env, enif_make_atom(env, name), val);
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
ERL_NIF_TERM enifMakeEvent(ErlNifEnv* env, sf::Event& event)
{
    ERL_NIF_TERM val;

    switch (event.type) {
    case sf::Event::Closed:
        return enifMakeEventSub(env, "closed", NIL(env));
    case sf::Event::KeyPressed:
        val = enif_make_int(env, event.key.code);
        return enifMakeEventSub(env, "keypressed", val);
    }
    return enifMakeNoEvent(env);
}

/***  End of eEvent.cpp  **************************************************}}}*/


