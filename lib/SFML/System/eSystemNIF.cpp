// eSystemNIF.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

#include "eClock.h"

int load(ErlNifEnv *env, void **priv_data, ERL_NIF_TERM load_info)
{
    ResClock::Define(env, "sfml_clock");
    return 0;
}

// Let's define the array of ErlNifFunc beforehand: 
static ErlNifFunc nif_funcs[] = {
    // {erl_function_name, erl_function_arity, c_function} 
    { "clock_create",               0, sfClockCreate             },
    { "clock_release",              1, sfClockRelease            },
    { "clock_get_elapsed_time",     1, sfClockGetElapsedTime     },
    { "clock_restart",              1, sfClockRestart            },
//    { "clock_interval",             2, sfClockInterval           },
    { "gclock_get_elapsed_time",    0, sfGClockGetElapsedTime    },
    { "gclock_restart",             0, sfGClockRestart           },
};

ERL_NIF_INIT(Elixir.SFML.System.NIF, nif_funcs, load, NULL, NULL, NULL);
