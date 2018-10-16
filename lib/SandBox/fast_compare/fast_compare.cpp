// fast_compare.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include <map>
#include <string>
#include "erl_nif.h"
#include <stdio.h>

using namespace std;
typedef map<string, int> AtomMap;

const AtomMap gSelector = {
    {"style", 1},
    {"fq",    2},
};

static ERL_NIF_TERM fast_int_compare(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
	int a, b;
    if (!enif_get_int(env, argv[0], &a)) {
        return enif_make_badarg(env);
    }
    if (!enif_get_int(env, argv[1], &b)) {
        return enif_make_badarg(env);
    }

	int result = a == b ? 0 : (a > b ? 1 : -1);
	return enif_make_int(env, result);
}

static ERL_NIF_TERM kwlist(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    if (!enif_is_list(env, argv[0])) {
        return enif_make_badarg(env);
    }

    printf("selector:%d\n", gSelector.at("style"));

    ERL_NIF_TERM item, list = argv[0];
    while (enif_get_list_cell(env, list, &item, &list)) {
        int           len;
        const ERL_NIF_TERM* tuple;
        if (enif_get_tuple(env, item, &len, &tuple)) {
            printf("len=%d\n", len);
        }
    }
    return enif_make_uint(env, 0);
}

// Let's define the array of ErlNifFunc beforehand: 
static ErlNifFunc nif_funcs[] = {
	// {erl_function_name, erl_function_arity, c_function} 
	{ "fast_compare", 2, fast_int_compare    },
    { "kwlist",       1, kwlist              },
};

ERL_NIF_INIT(Elixir.SandBox.FastCompare, nif_funcs, NULL, NULL, NULL, NULL);
