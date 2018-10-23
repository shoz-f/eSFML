/***  File Header  ************************************************************/
/**
* @file eConvexShape.cpp
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
#include "eTexture.h"
#include "eConvexShape.h"

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
ERL_NIF_TERM sfConvexShapeCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Create()) {
        return enif_make_badarg(env);
    }

    unsigned int len;
    if (enif_is_list(env, argv[0])
    &&  enif_get_list_length(env, argv[0], &len)
    &&  len > 0) {
      res.mObj->setPointCount(len);
    }
    else {
        return enif_make_badarg(env);
    }

    ERL_NIF_TERM list = argv[0];
    ERL_NIF_TERM item;
    sf::Vector2f p;
    for (int i = 0; i < len; i++) {
        if (enif_get_list_cell(env, list, &item, &list)
        &&  enifGetVector2f(env, item, p)) {
          res.mObj->setPoint(i, p);
        }
        else {
          return enif_make_badarg(env);
        }
    }

    res.mObj->setOutlineThickness(1.0);

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
ERL_NIF_TERM sfConvexShapeGetPointCount(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enif_make_uint(env, res.mObj->getPointCount());
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
ERL_NIF_TERM sfConvexShapeGetPoint(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    unsigned int count = res.mObj->getPointCount();

    ERL_NIF_TERM list = enif_make_list(env, 0);
    ERL_NIF_TERM item;
    sf::Vector2f point;
    while (count > 0) {
        point = res.mObj->getPoint(--count);
        item  = enifMakeVector2f(env, point);
        list  = enif_make_list_cell(env, item, list);
    }
    
    return list;
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
ERL_NIF_TERM sfConvexShapeGetOutlineThickness(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enif_make_double(env, res.mObj->getOutlineThickness());
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
ERL_NIF_TERM sfConvexShapeSetOutlineThickness(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    double thickness;
    if (!enif_get_double(env, argv[1], &thickness)) {
        return enif_make_badarg(env);
    }

    res.mObj->setOutlineThickness(thickness);

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
ERL_NIF_TERM sfConvexShapeSetTexture(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    ResTexture texture(env);
    if (!texture.Open(argv[1])) {
        return enif_make_badarg(env);
    }

    res.mObj->setTexture(texture.mObj);

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
ERL_NIF_TERM sfConvexShapeSetTextureRect(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::IntRect rect;
    if (!enifGetRecti(env, argv[1], rect)) {
        return enif_make_badarg(env);
    }

    res.mObj->setTextureRect(rect);

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
ERL_NIF_TERM sfConvexShapeGetTextureRect(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::IntRect rect = res.mObj->getTextureRect();

    return enifMakeRecti(env, rect);
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
ERL_NIF_TERM sfConvexShapeGetOrigin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f org = res.mObj->getOrigin();
    return enifMakeVector2f(env, org);
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
ERL_NIF_TERM sfConvexShapeSetOrigin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f org(0.0, 0.0);
    if (!enifGetVector2f(env, argv[1], org)) {
        return enif_make_badarg(env);
    }

    res.mObj->setOrigin(org);

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
ERL_NIF_TERM sfConvexShapeGetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f pos = res.mObj->getPosition();
    return enifMakeVector2f(env, pos);
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
ERL_NIF_TERM sfConvexShapeSetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f pos(0.0, 0.0);
    if (!enifGetVector2f(env, argv[1], pos)) {
        return enif_make_badarg(env);
    }

    res.mObj->setPosition(pos);

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
ERL_NIF_TERM sfConvexShapeGetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    float angle = res.mObj->getRotation();
    return enif_make_double(env, angle);
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
ERL_NIF_TERM sfConvexShapeSetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    double angle;
    if (!enif_get_double(env, argv[1], &angle)) {
        return enif_make_badarg(env);
    }

    res.mObj->setRotation(angle);

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
ERL_NIF_TERM sfConvexShapeGetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f factors = res.mObj->getScale();
    return enifMakeVector2f(env, factors);
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
ERL_NIF_TERM sfConvexShapeSetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f factors(1.0, 1.0);
    if (!enifGetVector2f(env, argv[1], factors)) {
        return enif_make_badarg(env);
    }

    res.mObj->setScale(factors);

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
ERL_NIF_TERM sfConvexShapeGetOutlineColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Color color = res.mObj->getOutlineColor();
    return enifMakeColor(env, color);
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
ERL_NIF_TERM sfConvexShapeSetOutlineColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Color color;
    if (!enifGetColor(env, argv[1], color)) {
        return enif_make_badarg(env);
    }

    res.mObj->setOutlineColor(color);

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
ERL_NIF_TERM sfConvexShapeGetFillColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Color color = res.mObj->getFillColor();
    return enifMakeColor(env, color);
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
ERL_NIF_TERM sfConvexShapeSetFillColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
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

/***  Module Header  ******************************************************}}}*/
/**
* <タイトル記入>
* @par 解説
*   <<解説記入>>
*
* @retval <<戻り値記入>> <<戻り値説明記入>>
**/
/**************************************************************************{{{*/
ERL_NIF_TERM sfConvexShapeMove(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f delta(0.0, 0.0);
    if (!enifGetVector2f(env, argv[1], delta)) {
        return enif_make_badarg(env);
    }

    res.mObj->move(delta);

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
ERL_NIF_TERM sfConvexShapeRotate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    double angle;
    if (!enif_get_double(env, argv[1], &angle)) {
        return enif_make_badarg(env);
    }

    res.mObj->rotate(angle);

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
ERL_NIF_TERM sfConvexShapeScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f factors(1.0, 1.0);
    if (!enifGetVector2f(env, argv[1], factors)) {
        return enif_make_badarg(env);
    }

    res.mObj->scale(factors);

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
ERL_NIF_TERM sfConvexShapeFlip(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::IntRect r = res.mObj->getTextureRect();
    r.left  += r.width;
    r.width *= -1;
    res.mObj->setTextureRect(r);

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
ERL_NIF_TERM sfConvexShapeFlop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::IntRect r = res.mObj->getTextureRect();
    r.top    += r.height;
    r.height *= -1;
    res.mObj->setTextureRect(r);

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
ERL_NIF_TERM sfConvexShapeGetGlobalBounds(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResConvexShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::FloatRect rect = res.mObj->getGlobalBounds();

    return enifMakeRectf(env, rect);
}

/***  End of eConvexShape.cpp  *************************************************}}}*/
