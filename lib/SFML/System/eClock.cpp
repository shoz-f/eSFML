/***  File Header  ************************************************************/
/**
* @file eClock.cpp
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
#include "eClock.h"

/***** CONSTANT *****/

/***** TYPE *****/

/***** MACRO *****/

/***** EXPORT VARIABLE *****/

/***** EXPORT FUNCTION *****/

/***** PRIVATE VARIABLE *****/
ErlNifResourceType* ResClock::_ResType;

sf::Clock gClock;

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
ERL_NIF_TERM sfClockCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResClock res(env);

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
ERL_NIF_TERM sfClockRelease(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResClock res(env);
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
ERL_NIF_TERM sfClockGetElapsedTime(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResClock res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Time t = res.mObj->getElapsedTime();

    return enif_make_int(env, t.asMilliseconds());
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
ERL_NIF_TERM sfClockRestart(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResClock res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Time t = res.mObj->restart();

    return enif_make_int(env, t.asMilliseconds());
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
ERL_NIF_TERM sfClockInterval(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResClock res(env);

    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    int wait;  // ms
    if (!enif_get_int(env, argv[1], &wait)) {
        return enif_make_badarg(env);
    }

    sf::Time start, lap;
    start = res.mObj->restart();
    do {
        lap = res.mObj->getElapsedTime() - start;
    } while (lap.asMilliseconds() < wait);

    return enif_make_int(env, lap.asMilliseconds());
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
ERL_NIF_TERM sfGClockGetElapsedTime(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    sf::Time t = gClock.getElapsedTime();
    return enif_make_int(env, t.asMilliseconds());
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
ERL_NIF_TERM sfGClockRestart(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    sf::Time t = gClock.restart();
    return enif_make_int(env, t.asMilliseconds());
}

/***  End of eClock.cpp  **************************************************}}}*/
