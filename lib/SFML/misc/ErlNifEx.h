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
#include <map>
#include <string>
#include <cstring>
#include <limits.h>
#include "NifRes.h"

/***** CONSTANT *****/
const std::map<std::string, sf::Color> cColorMap = {
    { "Black",       sf::Color::Black       },
    { "White",       sf::Color::White       },
    { "Red",         sf::Color::Red         },
    { "Green",       sf::Color::Green       },
    { "Blue",        sf::Color::Blue        },
    { "Yellow",      sf::Color::Yellow      },
    { "Magenta",     sf::Color::Magenta     },
    { "Cyan",        sf::Color::Cyan        },
    { "Transparent", sf::Color::Transparent },
};


const std::map<std::string, sf::PrimitiveType> cPrimitiveTypeMap = {
    { "Points",        sf::Points        },
    { "Lines",         sf::Lines         },
    { "LineStrip",     sf::LineStrip     },
    { "Triangles",     sf::Triangles     },
    { "TriangleStrip", sf::TriangleStrip },
    { "TriagnelFan",   sf::TriangleFan   },
    { "Quads",         sf::Quads         },
};

/***** TYPE *****/

/***** MACRO *****/
#define NIL(env) enif_make_atom(env, "nil")
#define OK(env)  enif_make_atom(env, "ok")

#define DECL_NIF(name)  ERL_NIF_TERM name(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])

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
inline bool enifGetBoolean(ErlNifEnv* env, ERL_NIF_TERM term, bool& cond)
{
    char atom[256];
    if (!enif_get_atom(env, term, atom, sizeof(atom), ERL_NIF_LATIN1)) {
        return false;
    }
    
    cond = std::strcmp(atom, "false") != 0 && std::strcmp(atom, "nil") != 0;
    
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
inline bool enifGetInt(ErlNifEnv* env, ERL_NIF_TERM term, int& val)
{
    if (enif_get_int(env, term, &val)) {
        return true;
    }

    double dval;
    if (enif_get_double(env, term, &dval) && dval >= INT_MIN && dval <= INT_MAX) {
        val = (int)dval;
        return true;
    }

    return false;
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
inline bool enifGetUint(ErlNifEnv* env, ERL_NIF_TERM term, unsigned int& val)
{
    if (enif_get_uint(env, term, &val)) {
        return true;
    }

    double dval;
    if (enif_get_double(env, term, &dval) && dval >= 0.0 && dval <= UINT_MAX) {
        val = (int)dval;
        return true;
    }
    return false;
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
inline bool enifGetDouble(ErlNifEnv* env, ERL_NIF_TERM term, double& val)
{
    if (enif_get_double(env, term, &val)) {
        return true;
    }

    int ival;
    if (enif_get_int(env, term, &ival)) {
        val = (double)ival;
        return true;
    }

    return false;
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
    enifGetDouble(env, item, val);
    v.x = val;

    enif_get_list_cell(env, list, &item, &list);
    enifGetDouble(env, item, val);
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
inline bool enifGetVector2u(ErlNifEnv* env, ERL_NIF_TERM list, sf::Vector2u& v)
{
    unsigned int len;
    if (!enif_is_list(env, list)
        || !enif_get_list_length(env, list, &len)
        || len != 2) {
        return false;
    }

    ERL_NIF_TERM item;
    unsigned int val;
    enif_get_list_cell(env, list, &item, &list);
    enif_get_uint(env, item, &val);
    v.x = val;

    enif_get_list_cell(env, list, &item, &list);
    enif_get_uint(env, item, &val);
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
inline bool enifGetRecti(ErlNifEnv* env, ERL_NIF_TERM list, sf::IntRect& r)
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
    enifGetInt(env, item, val);
    r.left = val;

    enif_get_list_cell(env, list, &item, &list);
    enifGetInt(env, item, val);
    r.top = val;

    enif_get_list_cell(env, list, &item, &list);
    enifGetInt(env, item, val);
    r.width = val;

    enif_get_list_cell(env, list, &item, &list);
    enifGetInt(env, item, val);
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
inline bool enifGetRectf(ErlNifEnv* env, ERL_NIF_TERM list, sf::FloatRect& r)
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
    enifGetDouble(env, item, val);
    r.left = val;

    enif_get_list_cell(env, list, &item, &list);
    enifGetDouble(env, item, val);
    r.top = val;

    enif_get_list_cell(env, list, &item, &list);
    enifGetDouble(env, item, val);
    r.width = val;

    enif_get_list_cell(env, list, &item, &list);
    enifGetDouble(env, item, val);
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

/***  Module Header  ******************************************************}}}*/
/**
* <タイトル記入>
* @par 解説
*   <<解説記入>>
*
* @retval <<戻り値記入>> <<戻り値説明記入>>
**/
/**************************************************************************{{{*/
inline bool enifGetColor(ErlNifEnv* env, ERL_NIF_TERM term, sf::Color& color)
{
    unsigned int len;

    if (enif_is_atom(env, term)) {
        char name[256];
        enif_get_atom(env, term, name, sizeof(name), ERL_NIF_LATIN1);
        try {
            color = cColorMap.at(name);
        }
        catch (std::out_of_range&) {
            return false;
        }
        return true;
    }
    else if (enif_is_list(env, term) && enif_get_list_length(env, term, &len) && (len == 3 || len == 4)) {
        unsigned int rgba[4] = { 0, 0, 0, 255 };
        for (int i = 0; i < len; i++) {
            ERL_NIF_TERM item;
            enif_get_list_cell(env, term, &item, &term);
            enif_get_uint(env, item, &rgba[i]);
            if (rgba[i] > 255) {
                return false;
            }
        }
        color.r = rgba[0];
        color.g = rgba[1];
        color.b = rgba[2];
        color.a = rgba[3];
        return true;
    }
    else {
        return false;
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
inline ERL_NIF_TERM enifMakeColor(ErlNifEnv* env, sf::Color& color)
{
    return enif_make_list4(env,
        enif_make_uint(env, color.r),
        enif_make_uint(env, color.g),
        enif_make_uint(env, color.b),
        enif_make_uint(env, color.a));
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
inline bool enifGetPrimitiveType(ErlNifEnv* env, ERL_NIF_TERM term, sf::PrimitiveType& type)
{
    unsigned int len;

    if (enif_is_atom(env, term)) {
        char name[256];
        enif_get_atom(env, term, name, sizeof(name), ERL_NIF_LATIN1);
        try {
            type = cPrimitiveTypeMap.at(name);
        }
        catch (std::out_of_range&) {
            return false;
        }
        return true;
    }
    else {
        return false;
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
inline ERL_NIF_TERM enifMakePrimitiveType(ErlNifEnv* env, sf::PrimitiveType type)
{
    switch (type) {
    case sf::Points       : return enif_make_atom(env, "Points");
    case sf::Lines        : return enif_make_atom(env, "Lines");
    case sf::LineStrip    : return enif_make_atom(env, "LineStrip");
    case sf::Triangles    : return enif_make_atom(env, "Triangles");
    case sf::TriangleStrip: return enif_make_atom(env, "TriangleStrip");
    case sf::TriangleFan  : return enif_make_atom(env, "TriagnelFan");
    case sf::Quads        : return enif_make_atom(env, "Quads");
    }
    return NIL(env);
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
inline ERL_NIF_TERM enifMakeVertex(ErlNifEnv* env, sf::Vector2f& v, sf::Color& color)
{
    return enif_make_list2(env,
        enifMakeVector2f(env, v),
        enifMakeColor(env, color));
}

#endif
/*** End of ErlNifEx.h *************************************************}}}*/
