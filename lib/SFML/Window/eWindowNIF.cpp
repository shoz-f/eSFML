// Window.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

#include <SFML/Window.hpp>
#include "erl_nif.h" 

ERL_NIF_TERM sfWindowDisplay(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
    ErlNifUInt64 tmp;
    if (!enif_get_uint64(env, argv[0], &tmp)) {
        return enif_make_badarg(env);
    }
    sf::Window* win = reinterpret_cast<sf::Window*>(tmp);
    
    win->display();
    
    return enif_make_int(env, 0);
}

// Let's define the array of ErlNifFunc beforehand: 
static ErlNifFunc nif_funcs[] = {
    // {erl_function_name, erl_function_arity, c_function} 
    { "window_display", 1, sfWindowDisplay },
};

ERL_NIF_INIT(Elixir.SFML.Window.NIF, nif_funcs, NULL, NULL, NULL, NULL);
