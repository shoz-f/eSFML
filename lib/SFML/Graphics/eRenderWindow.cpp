/***  File Header  ************************************************************/
/**
* @file eRenderWindow.cpp
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
#include <SFML/System/Vector2.hpp>
#include "eDrawable.h"
#include "eRenderWindow.h"
#include "eColor.h"

/***** CONSTANT *****/

/***** TYPE *****/

/***** MACRO *****/

/***** EXPORT VARIABLE *****/

/***** EXPORT FUNCTION *****/

/***** PRIVATE VARIABLE *****/
ErlNifResourceType* ResRenderWindow::_ResType;

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
ERL_NIF_TERM sfRenderWindowCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    int  w, h;
    char title[256];

    if (!enif_get_int(env, argv[0], &w)) {
        return enif_make_badarg(env);
    }
    if (!enif_get_int(env, argv[1], &h)) {
        return enif_make_badarg(env);
    }
    if (!enif_get_string(env, argv[2], title, sizeof(title), ERL_NIF_LATIN1)) {
        return enif_make_badarg(env);
    }

    ResRenderWindow res(env);

    if (!res.Create()) {
        return enif_make_badarg(env);
    }

    res.mObj->create(sf::VideoMode(w, h), title);

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
ERL_NIF_TERM sfRenderWindowDestroy(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    res.mObj->close();
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
ERL_NIF_TERM sfRenderWindowClear(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Color color;
    if (enif_is_atom(env, argv[1])) {
        char name[256];
        enif_get_atom(env, argv[1], name, sizeof(name), ERL_NIF_LATIN1);
        try {
            color = cColorMap.at(name);
        }
        catch (std::out_of_range&) {
            color = sf::Color::Black;
        }
    }

    res.mObj->clear(color);
    
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
ERL_NIF_TERM sfRenderWindowDraw(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    ResDrawable item(env);

    if (!item.Open(argv[1])) {
        return enif_make_badarg(env);
    }

    res.mObj->draw(*item.mObj);

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
ERL_NIF_TERM sfRenderWindowDisplay(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    res.mObj->display();
    
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
ERL_NIF_TERM sfRenderWindowGetSize(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2u size = res.mObj->getSize();

    return enif_make_list2(env, enif_make_uint(env, size.x), enif_make_uint(env, size.y));
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
ERL_NIF_TERM enifMakeBoolean(ErlNifEnv* env, bool cond)
{
    return enif_make_atom(env, (cond) ? "true" : "false");
}

ERL_NIF_TERM sfRenderWindowIsOpen(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enifMakeBoolean(env, res.mObj->isOpen());
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
#include "eEvent.h"

ERL_NIF_TERM sfRenderWindowPollEvent(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Event event;
    if (res.mObj->pollEvent(event)) {
        return enifMakeEvent(env, event);
    }
    else{
        return enifMakeNoEvent(env);
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
ERL_NIF_TERM sfRenderWindowRequestFocus(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    res.mObj->requestFocus();

    return argv[0];
}

/***  End of eRenderWindow.cpp  *******************************************}}}*/
