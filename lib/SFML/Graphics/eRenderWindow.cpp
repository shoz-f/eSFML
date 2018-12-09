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
#include <vector>
#include "eRenderWindow.h"

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
sf::eRenderWindow::eRenderWindow()
: mThread(&eRenderWindow::mainLoop, this), EfCall(false), EfAnswer(false), mRun(true)
{}

/***  Module Header  ******************************************************}}}*/
/**
* <タイトル記入>
* @par 解説
*   <<解説記入>>
*
* @retval <<戻り値記入>> <<戻り値説明記入>>
**/
/**************************************************************************{{{*/
void sf::eRenderWindow::mainLoop()
{
    // create
    sf::Vector2u size(0, 0);
    if (!enifGetVector2u(mNifEnv, mNifArgv[0], size)) {
        mRes = enif_make_badarg(mNifEnv);
    }

    ErlNifBinary bin;
    if (!enif_inspect_binary(mNifEnv, mNifArgv[1], &bin)) {
        mRes = enif_make_badarg(mNifEnv);
    }
    std::string title((const char*)bin.data, bin.size);

    create(sf::VideoMode(size.x, size.y), title);

    EfAnswer.signal();

    // main loop
    while (mRun) {
        EfCall.wait();

        mRes = (this->*mFunc)(mNifEnv, mNifArgc, mNifArgv);
        EfAnswer.signal();
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
ERL_NIF_TERM sf::eRenderWindow::call(NifFunc func, ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    sf::Lock lock(mCriticalSection);

    mFunc    = func;
    mNifEnv  = env;
    mNifArgc = argc;
    mNifArgv = argv;

    EfCall.signal();

    EfAnswer.wait();

    return mRes;
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
ERL_NIF_TERM sfRenderWindowCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);
    if (!res.Create()) {
        return enif_make_badarg(env);
    }
    sf::eRenderWindow* win = res.mObj;

    win->launchWin(env, argc, argv);

    return res.MkTerm();
}

ERL_NIF_TERM sf::eRenderWindow::launchWin(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    mNifEnv = env;
    mNifArgc = argc;
    mNifArgv = argv;

    mThread.launch();

    EfAnswer.wait();    // wait for window creation

    return mRes;
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
    sf::eRenderWindow* win = res.mObj;

    ERL_NIF_TERM ans = win->call(&sf::eRenderWindow::fxDiscard, env, argc, argv);
    res.Release();

    return ans;
}

ERL_NIF_TERM sf::eRenderWindow::fxDiscard(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    close();
    mRun = false;

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
    sf::eRenderWindow* win = res.mObj;

    return win->call(&sf::eRenderWindow::fxClear, env, argc, argv);
}

ERL_NIF_TERM sf::eRenderWindow::fxClear(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    sf::Color color;
    if (!enifGetColor(env, argv[1], color)) {
        return enif_make_badarg(env);
    }

    clear(color);

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
    sf::eRenderWindow* win = res.mObj;

    return win->call(&sf::eRenderWindow::fxDraw, env, argc, argv);
}

ERL_NIF_TERM sf::eRenderWindow::fxDraw(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResDrawable item(env);
    if (!item.Open(argv[1])) {
        return enif_make_badarg(env);
    }

    draw(*item.mObj);

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
ERL_NIF_TERM sfRenderWindowSetFramerateLimit(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }
    sf::eRenderWindow* win = res.mObj;

    return win->call(&sf::eRenderWindow::fxSetFramerateLimit, env, argc, argv);

}

ERL_NIF_TERM sf::eRenderWindow::fxSetFramerateLimit(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    unsigned int limit;
    if (!enif_get_uint(env, argv[1], &limit)) {
        return enif_make_badarg(env);
    }

    setFramerateLimit(limit);

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
    sf::eRenderWindow* win = res.mObj;

    return win->call(&sf::eRenderWindow::fxDisplay, env, argc, argv);
}

ERL_NIF_TERM sf::eRenderWindow::fxDisplay(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    display();

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
    sf::eRenderWindow* win = res.mObj;

    return win->call(&sf::eRenderWindow::fxGetSize, env, argc, argv);
}

ERL_NIF_TERM sf::eRenderWindow::fxGetSize(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    sf::Vector2u size = getSize();

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
ERL_NIF_TERM sfRenderWindowIsOpen(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }
    sf::eRenderWindow* win = res.mObj;

    return win->call(&sf::eRenderWindow::fxIsOpen, env, argc, argv);
}

ERL_NIF_TERM sf::eRenderWindow::fxIsOpen(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    return enifMakeBoolean(env, isOpen());
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
    sf::eRenderWindow* win = res.mObj;

    return win->call(&sf::eRenderWindow::fxPollEvent, env, argc, argv);
}

ERL_NIF_TERM sf::eRenderWindow::fxPollEvent(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    sf::Event event;
    if (pollEvent(event)) {
        return enifMakeEvent(env, event);
    }
    else {
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
    sf::eRenderWindow* win = res.mObj;

    return win->call(&sf::eRenderWindow::fxRequestForcus, env, argc, argv);
}

ERL_NIF_TERM sf::eRenderWindow::fxRequestForcus(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    requestFocus();

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
ERL_NIF_TERM sfRenderWindowDrawVertexArray(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ResRenderWindow res(env);
    if (!res.Open(argv[0])) {
        return enif_make_badarg(env);
    }
    sf::eRenderWindow* win = res.mObj;

    return win->call(&sf::eRenderWindow::fxDrawVertexArray, env, argc, argv);
}

bool _prepare_vertex_keys = false;
static ERL_NIF_TERM _keyPosition;
static ERL_NIF_TERM _keyColor;
static ERL_NIF_TERM _keyTexture;

inline void prepareVertexKeys(ErlNifEnv* env)
{
  if (!_prepare_vertex_keys) {
    // prepare key-Atoms for getting Vertex
    _keyPosition = enif_make_atom(env, "position");
    _keyColor    = enif_make_atom(env, "color");
    _keyTexture  = enif_make_atom(env, "texture");
    _prepare_vertex_keys = true;
  }
}

inline bool enifGetVertex(ErlNifEnv* env, const ERL_NIF_TERM map, sf::Vertex& vertex)
{
    ERL_NIF_TERM position;
    ERL_NIF_TERM color;
    ERL_NIF_TERM tex_coords;
    return enif_get_map_value(env, map, _keyPosition, &position)
         && enif_get_map_value(env, map, _keyColor, &color)
         && enif_get_map_value(env, map, _keyTexture, &tex_coords)
         && enifGetVector2f(env, position, vertex.position)
         && enifGetColor(env, color, vertex.color)
         && enifGetVector2f(env, tex_coords, vertex.texCoords);
}

bool enifGetVertexArray(ErlNifEnv* env, ERL_NIF_TERM list, unsigned int len, std::vector<sf::Vertex>& vertices)
{
    prepareVertexKeys(env);

    ERL_NIF_TERM map;
    sf::Vertex  vertex;
    for (int i = 0; i < len; i++) {
        if (enif_get_list_cell(env, list, &map, &list)
        &&  enifGetVertex(env, map, vertex)) {
          vertices.push_back(vertex);
        }
        else {
          return enif_make_badarg(env);
        }
    }
    return true;
}

ERL_NIF_TERM sf::eRenderWindow::fxDrawVertexArray(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    unsigned int len;
    std::vector<sf::Vertex> vertices;
    if (!enif_is_list(env, argv[1])
    ||  !enif_get_list_length(env, argv[1], &len)
    ||  len == 0
    ||  !enifGetVertexArray(env, argv[1], len, vertices)) {
        return enif_make_badarg(env);
    }

    sf::PrimitiveType type;
    if (!enifGetPrimitiveType(env, argv[2], type)) {
        return enif_make_badarg(env);
    }
    
    int n = vertices.size();

    draw(&vertices[0], vertices.size(), type);

    return argv[0];
}

/***  End of eRenderWindow.cpp  *******************************************}}}*/

