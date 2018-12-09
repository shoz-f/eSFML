#ifndef _ERENDERWINDOW_H
#define _ERENDERWINDOW_H

#include <SFML/Graphics.hpp>
#include "EventFlag.hpp"
#include "ErlNifEx.h"

namespace sf {
    class eRenderWindow :public RenderWindow {

    typedef ERL_NIF_TERM (eRenderWindow::*NifFunc)(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

    public:
        eRenderWindow();

    public:
        void mainLoop();
        DECL_NIF(launchWin);

        ERL_NIF_TERM call(NifFunc func, ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
        DECL_NIF(fxDiscard);
        DECL_NIF(fxClear);
        DECL_NIF(fxDraw);
        DECL_NIF(fxDisplay);
        DECL_NIF(fxGetSize);
        DECL_NIF(fxIsOpen);
        DECL_NIF(fxPollEvent);
        DECL_NIF(fxRequestForcus);
        DECL_NIF(fxSetFramerateLimit);
        DECL_NIF(fxDrawVertexArray);

    protected:
        bool mRun;
        sf::Thread mThread;
        sf::EventFlag EfCall;
        sf::EventFlag EfAnswer;

        // IPC Data passing (** CRITICAL SECTION **)
        sf::Mutex           mCriticalSection;
        NifFunc             mFunc;
        ErlNifEnv*          mNifEnv;
        int                 mNifArgc;
        const ERL_NIF_TERM* mNifArgv;
        ERL_NIF_TERM        mRes;
    };
}

typedef NifRes<sf::eRenderWindow> ResRenderWindow;

ERL_NIF_TERM sfRenderWindowCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowDestroy(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowClear(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowDraw(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowDisplay(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowGetSize(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowIsOpen(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowPollEvent(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfRenderWindowRequestFocus(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
DECL_NIF(sfRenderWindowSetFramerateLimit);
DECL_NIF(sfRenderWindowDrawVertexArray);

#endif