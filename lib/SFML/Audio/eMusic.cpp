/***  File Header  ************************************************************/
/**
* @file eMusic.cpp
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
#include "eMusic.h"

/***** CONSTANT *****/

/***** TYPE *****/

/***** MACRO *****/

/***** EXPORT VARIABLE *****/

/***** EXPORT FUNCTION *****/

/***** PRIVATE VARIABLE *****/
template <>
ErlNifResourceType* ResMusic::_ResType;

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
ERL_NIF_TERM sfMusicCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
    if (!res.Create()) {
        return enif_make_badarg(env);
    }
    
    return res.MkTerm(true);
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
ERL_NIF_TERM sfMusicOpenFromFile(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
    if (!res.Create()) {
        return enif_make_badarg(env);
    }

    ErlNifBinary bin;
    if (!enif_inspect_binary(env, argv[0], &bin)) {
        return enif_make_badarg(env);
    }
    std::string fname((const char*)bin.data, bin.size);

    if (!res.mObj->openFromFile(fname)) {
        return enif_make_badarg(env);
    }

    return res.MkTerm(true);
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
ERL_NIF_TERM sfMusicDiscard(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicPlay(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicPause(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicStop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicGetChannelCount(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enif_make_uint(env, res.mObj->getChannelCount());
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
ERL_NIF_TERM sfMusicGetSampleRate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    return enif_make_uint(env, res.mObj->getSampleRate());
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
ERL_NIF_TERM sfMusicGetPlayingOffset(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicSetPlayingOffset(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicGetLoop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicSetLoop(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicGetVolume(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicSetVolume(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicGetPitch(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicSetPitch(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicGetAttenuation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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
ERL_NIF_TERM sfMusicSetAttenuation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResMusic res(env);
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

/***  End of eMusic.cpp  *************************************************}}}*/




#if 0
bool 	openFromMemory(const void *data, std::size_t sizeInBytes)
Open a music from an audio file in memory.More...

bool 	openFromStream(InputStream &stream)
Open a music from an audio file in a custom stream.More...

Time 	getDuration() const
Get the total duration of the music.More...

TimeSpan 	getLoopPoints() const
Get the positions of the of the sound's looping sequence. More...

void 	setLoopPoints(TimeSpan timePoints)
Sets the beginning and end of the sound's looping sequence using sf::Time. More...

Status 	getStatus() const
Get the current status of the stream(stopped, paused, playing) More...

void 	setPlayingOffset(Time timeOffset)
Change the current playing position of the stream.More...

Time 	getPlayingOffset() const
Get the current playing position of the stream.More...

void 	setPosition(float x, float y, float z)
Set the 3D position of the sound in the audio scene.More...

void 	setPosition(const Vector3f &position)
Set the 3D position of the sound in the audio scene.More...

void 	setRelativeToListener(bool relative)
Make the sound's position relative to the listener or absolute. More...

void 	setMinDistance(float distance)
Set the minimum distance of the sound.More...

Vector3f 	getPosition() const
Get the 3D position of the sound in the audio scene.More...

bool 	isRelativeToListener() const
Tell whether the sound's position is relative to the listener or is absolute. More...

float 	getMinDistance() const
Get the minimum distance of the sound.More...
#endif
