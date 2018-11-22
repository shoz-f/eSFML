/***  File Header  ************************************************************/
/**
* @file eFont.cpp
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
#include "eFont.h"

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
ERL_NIF_TERM sfFontLoadFromFile(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary bin;
    if (!enif_inspect_binary(env, argv[0], &bin)) {
        return enif_make_badarg(env);
    }
    std::string fname((const char*)bin.data, bin.size);

    ResFont res(env);
    if (!res.Create()) {
        return enif_make_badarg(env);
    }

    if (!res.mObj->loadFromFile(fname)) {
        res.Release();
        return enif_make_badarg(env);
    }

    return res.MkTerm();
}

/***  End of eFont.cpp  *************************************************}}}*/


