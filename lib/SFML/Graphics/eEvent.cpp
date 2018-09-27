/***  File Header  ************************************************************/
/**
* @file eEvent.cpp
*
* <<�^�C�g���L��>>
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
* <�^�C�g���L��>
* @par ���
*   <<����L��>>
*
* @retval <<�߂�l�L��>> <<�߂�l�����L��>>
**/
/**************************************************************************{{{*/
ERL_NIF_TERM enifMakeNoEvent(ErlNifEnv* env)
{
    return enif_make_tuple2(env, enif_make_atom(env, "none"), NIL(env));
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
inline ERL_NIF_TERM enifMakeEventSub(ErlNifEnv* env, char* name, ERL_NIF_TERM val)
{
    return enif_make_tuple2(env, enif_make_atom(env, name), val);
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


