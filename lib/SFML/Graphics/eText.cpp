/***  File Header  ************************************************************/
/**
* @file eText.cpp
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
#include "eFont.h"
#include "eText.h"

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
ERL_NIF_TERM sfTextCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary bin;
    if (!enif_inspect_binary(env, argv[0], &bin)) {
        return enif_make_badarg(env);
    }
    std::string text((const char*)bin.data, bin.size);

    ResFont font(env);
    if (!font.Open(argv[1])) {
        return enif_make_badarg(env);
    }
    
    ResText res(env);
    if (!res.Create()) {
        return enif_make_badarg(env);
    }
    
    res.mObj->setString(text);
    res.mObj->setFont(*font.mObj);

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
ERL_NIF_TERM sfTextDestroy(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
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
ERL_NIF_TERM sfTextSetCharacterSize(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    unsigned int size;
    if (!enifGetUint(env, argv[1], size)) {
        return enif_make_badarg(env);
    }

    res.mObj->setCharacterSize(size);

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
ERL_NIF_TERM sfTextSetLetterSpacing(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    double spacingFactor;
    if (!enifGetDouble(env, argv[1], spacingFactor)) {
        return enif_make_badarg(env);
    }

    res.mObj->setLetterSpacing(spacingFactor);

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
ERL_NIF_TERM sfTextSetLineSpacing(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    double spacingFactor;
    if (!enifGetDouble(env, argv[1], spacingFactor)) {
        return enif_make_badarg(env);
    }

    res.mObj->setLineSpacing(spacingFactor);

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
ERL_NIF_TERM sfTextSetStyle(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    unsigned int style;
    if (!enifGetUint(env, argv[1], style)) {
        return enif_make_badarg(env);
    }

    res.mObj->setStyle(style);

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
ERL_NIF_TERM sfTextSetColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Color color;
    if (!enifGetColor(env, argv[1], color)) {
        return enif_make_badarg(env);
    }

    res.mObj->setColor(color);

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
ERL_NIF_TERM sfTextGetOutlineThickness(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextSetOutlineThickness(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextGetOrigin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextSetOrigin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextGetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextSetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextGetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextSetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextGetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextSetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextGetOutlineColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextSetOutlineColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextGetFillColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextSetFillColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextMove(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextRotate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
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
ERL_NIF_TERM sfTextGetGlobalBounds(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResText res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::FloatRect rect = res.mObj->getGlobalBounds();

    return enifMakeRectf(env, rect);
}

/***  End of eText.cpp  *************************************************}}}*/
