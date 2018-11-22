/***  File Header  ************************************************************/
/**
* @file eRectangleShape.cpp
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
#include "eRectangleShape.h"

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
ERL_NIF_TERM sfRectangleShapeCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
    
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
ERL_NIF_TERM sfRectangleShapeDestroy(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
    
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
ERL_NIF_TERM sfRectangleShapeSetSize(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
    
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f size(0.0, 0.0);
    if (!enifGetVector2f(env, argv[1], size)) {
        return enif_make_badarg(env);
    }

    res.mObj->setSize(size);
    
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
ERL_NIF_TERM sfRectangleShapeGetSize(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2f size = res.mObj->getSize();
    return enifMakeVector2f(env, size);
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
ERL_NIF_TERM sfRectangleShapeGetPoint(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeGetOutlineThickness(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeSetOutlineThickness(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeSetTexture(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeSetTextureRect(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeGetTextureRect(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeGetOrigin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeSetOrigin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeGetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeSetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeGetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeSetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeGetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeSetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeGetOutlineColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeSetOutlineColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeGetFillColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeSetFillColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeMove(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeRotate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeFlip(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeFlop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
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
ERL_NIF_TERM sfRectangleShapeGetGlobalBounds(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRectangleShape res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::FloatRect rect = res.mObj->getGlobalBounds();

    return enifMakeRectf(env, rect);
}

/***  End of eRectangleShape.cpp  *************************************************}}}*/
