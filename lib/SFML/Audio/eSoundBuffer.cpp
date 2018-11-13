/***  File Header  ************************************************************/
/**
* @file eSoundBuffer.cpp
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
ERL_NIF_TERM sfSoundBufferLoadFromFile(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifBinary bin;
    if (!enif_inspect_binary(env, argv[0], &bin)) {
        return enif_make_badarg(env);
    }
    std::string fname((const char*)bin.data, bin.size);

    ResSoundBuffer res(env);
    if (!res.Create()) {
        return enif_make_badarg(env);
    }

    if (!res.mObj->loadFromFile(fname)) {
        res.Release();
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
ERL_NIF_TERM sfSoundBufferDiscard(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSoundBuffer res(env);
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
ERL_NIF_TERM sfSoundBufferSaveToFile(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResSoundBuffer res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }

    ErlNifBinary bin;
    if (!enif_inspect_binary(env, argv[1], &bin)) {
        return enif_make_badarg(env);
    }
    std::string fname((const char*)bin.data, bin.size);

    if (!res.mObj->saveToFile(fname)) {
        return enif_make_badarg(env);
    }

    return OK(env);
}

/***  End of eSoundBuffer.cpp  *************************************************}}}*/


#if 0
 	SoundBuffer (const SoundBuffer &copy)
 	Copy constructor. More...
 
bool 	loadFromMemory (const void *data, std::size_t sizeInBytes)
 	Load the sound buffer from a file in memory. More...
 
bool 	loadFromStream (InputStream &stream)
 	Load the sound buffer from a custom stream. More...
 
bool 	loadFromSamples (const Int16 *samples, Uint64 sampleCount, unsigned int channelCount, unsigned int sampleRate)
 	Load the sound buffer from an array of audio samples. More...
 
const Int16 * 	getSamples () const
 	Get the array of audio samples stored in the buffer. More...
 
Uint64 	getSampleCount () const
 	Get the number of samples stored in the buffer. More...
 
unsigned int 	getSampleRate () const
 	Get the sample rate of the sound. More...
 
unsigned int 	getChannelCount () const
 	Get the number of channels used by the sound. More...
 
Time 	getDuration () const
 	Get the total duration of the sound. More...
 
SoundBuffer & 	operator= (const SoundBuffer &right)
 	Overload of assignment operator. More...
#endif
