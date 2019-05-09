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
#include "eTexture.h"
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
ERL_NIF_TERM sfCircleShapeGetRadius(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enif_make_double(env, res.mObj->getRadius());
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
ERL_NIF_TERM sfCircleShapeGetPoint(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeGetOutlineThickness(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeSetOutlineThickness(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeSetTexture(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeSetTextureRect(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeGetTextureRect(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeGetOrigin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeSetOrigin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f position(0.0, 0.0);
    if (!enifGetVector2f(env, argv[1], position)) {
        return enif_make_badarg(env);
    }

    res.mObj->setOrigin(position);

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
ERL_NIF_TERM sfCircleShapeGetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeSetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeGetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeSetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeGetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeSetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeGetOutlineColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeSetOutlineColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeGetFillColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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

/***  Module Header  ******************************************************}}}*/
/**
* <タイトル記入>
* @par 解説
*   <<解説記入>>
*
* @retval <<戻り値記入>> <<戻り値説明記入>>
**/
/**************************************************************************{{{*/
ERL_NIF_TERM sfCircleShapeMove(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeRotate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeFlip(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeFlop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
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
ERL_NIF_TERM sfCircleShapeGetGlobalBounds(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResCircleShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::FloatRect rect = res.mObj->getGlobalBounds();

    return enifMakeRectf(env, rect);
}

/***  End of eCircleShape.cpp  *************************************************}}}*/
