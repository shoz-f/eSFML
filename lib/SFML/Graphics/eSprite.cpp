/***  File Header  ************************************************************/
/**
* @file eSprite.cpp
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
#include "eSprite.h"

/***** CONSTANT *****/

/***** TYPE *****/

/***** MACRO *****/

/***** EXPORT VARIABLE *****/

/***** EXPORT FUNCTION *****/

/***** PRIVATE VARIABLE *****/

/***** PRIVATE FUNCTION *****/

/***  Module Header  ******************************************************}}}*/
/**
* Constructor
* @par description
*   instantiate the object
**/
/*************************************************************************{{{*/
eSprite::eSprite()
:mTextrueRes(NULL)
{
    // empty
}

/***  Module Header  ******************************************************}}}*/
/**
* Destructor
* @par description
*   destroy the object
**/
/*************************************************************************{{{*/
eSprite::~eSprite()
{
    releaseTextureRes();
}

/***  Module Header  ******************************************************}}}*/
/**
* Keep Texture resource
* @par description
*   increment reference counter
**/
/*************************************************************************{{{*/
void eSprite::keepTextureRes(void* r)
{
    enif_keep_resource(r);
    mTextrueRes = r;
}

/***  Module Header  ******************************************************}}}*/
/**
* Release Texture resource
* @par description
*   decrement reference counter
**/
/*************************************************************************{{{*/
void eSprite::releaseTextureRes()
{
    enif_release_resource(mTextrueRes);
    mTextrueRes = NULL;
}

/***  Module Header  ******************************************************}}}*/
/**
* Return Texture resource
* @par description
*   return the texture resource
**/
/*************************************************************************{{{*/
void* eSprite::getTextureRes()
{
    return mTextrueRes;
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
ERL_NIF_TERM sfSpriteCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResTexture texture(env);
    if (!texture.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    ResSprite res(env);
    if (!res.Create()) {
        return enif_make_badarg(env);
    }

    res.mObj->keepTextureRes(texture.mRes);
    res.mObj->setTexture(*texture.mObj);

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
ERL_NIF_TERM sfSpriteClone(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite org(env);
    if (!org.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    ResSprite clone(env);
    if (!clone.Create()) {
        return enif_make_badarg(env);
    }

    clone.mObj->keepTextureRes(org.mObj->getTextureRes());
    clone.mObj->setTexture(*org.mObj->getTexture());
    clone.mObj->setTextureRect(org.mObj->getTextureRect());
    clone.mObj->setPosition(org.mObj->getPosition());
    clone.mObj->setColor(org.mObj->getColor());

    return clone.MkTerm();
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
ERL_NIF_TERM sfSpriteSetTexture(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    ResTexture texture(env);
    if (!texture.Open(argv[1])) {
        return enif_make_badarg(env);
    }

    res.mObj->setTexture(*texture.mObj);

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
ERL_NIF_TERM sfSpriteSetTextureRect(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteGetTextureRect(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteGetOrigin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteSetOrigin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteGetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteSetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteGetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteSetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    double angle;
    if (!enifGetDouble(env, argv[1], angle)) {
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
ERL_NIF_TERM sfSpriteGetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteSetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteGetColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Color color = res.mObj->getColor();
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
ERL_NIF_TERM sfSpriteSetColor(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteMove(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteRotate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    double angle;
    if (!enifGetDouble(env, argv[1], angle)) {
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
ERL_NIF_TERM sfSpriteScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteFlip(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteFlop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
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
ERL_NIF_TERM sfSpriteGetGlobalBounds(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSprite res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::FloatRect rect = res.mObj->getGlobalBounds();

    return enifMakeRectf(env, rect);
}

/***  End of eSprite.cpp  *************************************************}}}*/
