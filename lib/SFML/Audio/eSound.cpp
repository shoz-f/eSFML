/***  File Header  ************************************************************/
/**
* @file eSound.cpp
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
#include "eSoundBuffer.h"
#include "eSound.h"

/***** CONSTANT *****/

/***** TYPE *****/

/***** MACRO *****/

/***** EXPORT VARIABLE *****/

/***** EXPORT FUNCTION *****/

/***** PRIVATE VARIABLE *****/
ErlNifResourceType* ResSound::_ResType;

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
ERL_NIF_TERM sfSoundCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
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
ERL_NIF_TERM sfSoundSetBuffer(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    ErlNifBinary bin;
    if (!enif_inspect_binary(env, argv[0], &bin)) {
        return enif_make_badarg(env);
    }
    std::string fname((const char*)bin.data, bin.size);

    ResSoundBuffer sb(env);
    if (!res.Open(argv[1])) {
        return enif_make_badarg(env);
    }

    res.mObj->setBuffer(*sb.mObj);

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
ERL_NIF_TERM sfSoundDiscard(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    res.Release();

    return OK(env);
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
ERL_NIF_TERM sfSoundPlay(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    res.mObj->play();

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
ERL_NIF_TERM sfSoundPause(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    res.mObj->pause();

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
ERL_NIF_TERM sfSoundStop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    res.mObj->stop();

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
ERL_NIF_TERM sfSoundGetPlayingOffset(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    sf::Time t = res.mObj->getPlayingOffset();

    return enif_make_double(env, t.asSeconds());
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
ERL_NIF_TERM sfSoundSetPlayingOffset(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    double time;
    if (!enif_get_double(env, argv[1], &time)) {
        return enif_make_badarg(env);
    }

    sf::Time t = sf::seconds(time);
    res.mObj->setPlayingOffset(t);

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
ERL_NIF_TERM sfSoundGetLoop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enifMakeBoolean(env, res.mObj->getLoop());
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
ERL_NIF_TERM sfSoundSetLoop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    bool loop;
    if (!enifGetBoolean(env, argv[1], loop)) {
        return enif_make_badarg(env);
    }
    
    res.mObj->setLoop(loop);

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
ERL_NIF_TERM sfSoundGetVolume(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enif_make_double(env, res.mObj->getVolume());
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
ERL_NIF_TERM sfSoundSetVolume(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    double volume;
    if (!enif_get_double(env, argv[1], &volume)) {
        return enif_make_badarg(env);
    }

    res.mObj->setVolume(volume);

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
ERL_NIF_TERM sfSoundGetPitch(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enif_make_double(env, res.mObj->getPitch());
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
ERL_NIF_TERM sfSoundSetPitch(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    double pitch;
    if (!enif_get_double(env, argv[1], &pitch)) {
        return enif_make_badarg(env);
    }

    res.mObj->setPitch(pitch);

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
ERL_NIF_TERM sfSoundGetAttenuation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enif_make_double(env, res.mObj->getAttenuation());
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
ERL_NIF_TERM sfSoundSetAttenuation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSound res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    double attenuation;
    if (!enif_get_double(env, argv[1], &attenuation)) {
        return enif_make_badarg(env);
    }

    res.mObj->setAttenuation(attenuation);

    return argv[0];
}

/***  End of eSound.cpp  *************************************************}}}*/




#if 0
void 	setBuffer (const SoundBuffer &buffer)
 	Set the source buffer containing the audio data to play. More...
 
const SoundBuffer * 	getBuffer () const
 	Get the audio buffer attached to the sound. More...
 
Status 	getStatus () const
 	Get the current status of the sound (stopped, paused, playing) More...
 
Sound & 	operator= (const Sound &right)
 	Overload of assignment operator. More...
 
void 	resetBuffer ()
 	Reset the internal buffer of the sound. More...
 
void 	setPosition (float x, float y, float z)
 	Set the 3D position of the sound in the audio scene. More...
 
void 	setPosition (const Vector3f &position)
 	Set the 3D position of the sound in the audio scene. More...
 
void 	setRelativeToListener (bool relative)
 	Make the sound's position relative to the listener or absolute. More...
 
void 	setMinDistance (float distance)
 	Set the minimum distance of the sound. More...
 
Vector3f 	getPosition () const
 	Get the 3D position of the sound in the audio scene. More...
 
bool 	isRelativeToListener () const
 	Tell whether the sound's position is relative to the listener or is absolute. More...
 
float 	getMinDistance () const
 	Get the minimum distance of the sound. More...
#endif