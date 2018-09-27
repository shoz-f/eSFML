/***  File Header  ************************************************************/
/**
* @file ErlNifEx.h
*
* Helper templates for handling NIFs resource object
* @author	Shozo Fukuda
* @date		Create: <%= $date; %>
* @date		Modify: $Date:$
* System	Window<br>
*
* Copyright (C) Shozo Fukuda
*
**/
/**************************************************************************{{{*/
#ifndef _ERLNIFEX_H
#define _ERLNIFEX_H

/***** INCLUDE *****/
#include <SFML/Graphics.hpp>
#include <erl_nif.h>
#include "NifRes.h"

/***** CONSTANT *****/

/***** TYPE *****/

/***** MACRO *****/
#define NIL(env) enif_make_atom(env, "nil")

/***** EXPORT VARIABLE *****/

/***** EXPORT FUNCTION *****/

/***  Module Header  ******************************************************}}}*/
/**
* <タイトル記入>
* @par 解説
*   <<解説記入>>
*
* @retval <<戻り値記入>> <<戻り値説明記入>>
**/
/**************************************************************************{{{*/
inline ERL_NIF_TERM enifMakeBoolean(ErlNifEnv* env, bool cond)
{
    return enif_make_atom(env, (cond) ? "true" : "false");
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
inline bool enifGetVector2f(ErlNifEnv* env, ERL_NIF_TERM list, sf::Vector2f& v)
{
    unsigned int len;
    if (!enif_is_list(env, list)
        || !enif_get_list_length(env, list, &len)
        || len != 2) {
        return false;
    }

    ERL_NIF_TERM item;
    double val;
    enif_get_list_cell(env, list, &item, &list);
    enif_get_double(env, item, &val);
    v.x = val;

    enif_get_list_cell(env, list, &item, &list);
    enif_get_double(env, item, &val);
    v.y = val;

    return true;
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
inline ERL_NIF_TERM enifMakeVector2f(ErlNifEnv* env, sf::Vector2f& v)
{
    ERL_NIF_TERM x = enif_make_double(env, v.x);
    ERL_NIF_TERM y = enif_make_double(env, v.y);
    return enif_make_list2(env, x, y);
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
inline ERL_NIF_TERM enifMakeVector2u(ErlNifEnv* env, sf::Vector2u& v)
{
    ERL_NIF_TERM x = enif_make_uint(env, v.x);
    ERL_NIF_TERM y = enif_make_uint(env, v.y);
    return enif_make_list2(env, x, y);
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
inline ERL_NIF_TERM enifGetRecti(ErlNifEnv* env, ERL_NIF_TERM list, sf::IntRect& r)
{
    unsigned int len;
    if (!enif_is_list(env, list)
        || !enif_get_list_length(env, list, &len)
        || len != 4) {
        return false;
    }

    ERL_NIF_TERM item;
    int val;
    enif_get_list_cell(env, list, &item, &list);
    enif_get_int(env, item, &val);
    r.left = val;

    enif_get_list_cell(env, list, &item, &list);
    enif_get_int(env, item, &val);
    r.top = val;

    enif_get_list_cell(env, list, &item, &list);
    enif_get_int(env, item, &val);
    r.width = val;

    enif_get_list_cell(env, list, &item, &list);
    enif_get_int(env, item, &val);
    r.height = val;

    return true;
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
inline ERL_NIF_TERM enifMakeRecti(ErlNifEnv* env, sf::IntRect& r)
{
    return enif_make_list4(env,
        enif_make_int(env, r.left),
        enif_make_int(env, r.top),
        enif_make_int(env, r.width),
        enif_make_int(env, r.height));
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
inline ERL_NIF_TERM enifGetRectf(ErlNifEnv* env, ERL_NIF_TERM list, sf::FloatRect& r)
{
    unsigned int len;
    if (!enif_is_list(env, list)
        || !enif_get_list_length(env, list, &len)
        || len != 4) {
        return false;
    }

    ERL_NIF_TERM item;
    double val;
    enif_get_list_cell(env, list, &item, &list);
    enif_get_double(env, item, &val);
    r.left = val;

    enif_get_list_cell(env, list, &item, &list);
    enif_get_double(env, item, &val);
    r.top = val;

    enif_get_list_cell(env, list, &item, &list);
    enif_get_double(env, item, &val);
    r.width = val;

    enif_get_list_cell(env, list, &item, &list);
    enif_get_double(env, item, &val);
    r.height = val;

    return true;
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
inline ERL_NIF_TERM enifMakeRectf(ErlNifEnv* env, sf::FloatRect& r)
{
    return enif_make_list4(env,
        enif_make_double(env, r.left),
        enif_make_double(env, r.top),
        enif_make_double(env, r.width),
        enif_make_double(env, r.height));
}

#endif
/*** End of ErlNifEx.h *************************************************}}}*/
