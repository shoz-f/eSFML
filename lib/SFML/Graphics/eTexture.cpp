/***  File Header  ************************************************************/
/**
* @file eTexture.cpp
*
* <<�^�C�g���L��>>
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

/***** CONSTANT *****/

/***** TYPE *****/

/***** MACRO *****/

/***** EXPORT VARIABLE *****/

/***** EXPORT FUNCTION *****/

/***** PRIVATE VARIABLE *****/
ErlNifResourceType* ResTexture::_ResType;

/***** PRIVATE FUNCTION *****/

/***  Module Header  ******************************************************}}}*/
/**
* <�^�C�g���L��>
* @par ���
*   <<����L��>>
*
* @retval <<�߂�l�L��>> <<�߂�l�����L��>>
**/
/**************************************************************************{{{*/
ERL_NIF_TERM sfTextureLoadFromFile(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary bin;
    if (!enif_inspect_binary(env, argv[0], &bin)) {
        return enif_make_badarg(env);
    }
    std::string fname((const char*)bin.data, bin.size);

    ResTexture res(env);
    if (!res.Create()) {
        return enif_make_badarg(env);
    }

    if (!res.mObj->loadFromFile(fname)) {
        res.Release();
        return enif_make_badarg(env);
    }

    return res.MkTerm();
}

/***  Module Header  ******************************************************}}}*/
/**
* <�^�C�g���L��>
* @par ���
*   <<����L��>>
*
* @retval <<�߂�l�L��>> <<�߂�l�����L��>>
**/
/**************************************************************************{{{*/
ERL_NIF_TERM sfTextureGetSize(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResTexture res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Vector2u size = res.mObj->getSize();
    return enifMakeVector2u(env, size);
}

/***  End of eTexture.cpp  *************************************************}}}*/


