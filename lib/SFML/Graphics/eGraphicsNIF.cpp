// Graphics.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

#include "eDrawable.h"
#include "eRenderWindow.h"
#include "eCircleShape.h"
#include "eSprite.h"
#include "eTexture.h"

ErlNifResourceType* ResDrawable::_ResType;

int load(ErlNifEnv *env, void **priv_data, ERL_NIF_TERM load_info)
{
    ResDrawable::Define(env, "sfml_drawable");
    ResRenderWindow::Define(env, "sfml_renderwindow");
    ResSprite::Define(env, "sfml_sprite");
    ResTexture::Define(env, "sfml_texture");
    return 0;
}

// Let's define the array of ErlNifFunc beforehand: 
static ErlNifFunc nif_funcs[] = {
    // {erl_function_name, erl_function_arity, c_function} 
    { "render_window_create",       3, sfRenderWindowCreate      },
    { "render_window_destroy",      1, sfRenderWindowDestroy     },
    { "render_window_clear",        2, sfRenderWindowClear       },
    { "render_window_draw",         2, sfRenderWindowDraw        },
    { "render_window_display",      1, sfRenderWindowDisplay     },
    { "render_window_get_size",     1, sfRenderWindowGetSize     },
    { "render_window_is_open",      1, sfRenderWindowIsOpen      },
    { "render_window_poll_event",   1, sfRenderWindowPollEvent   },
    { "render_window_request_focus",1, sfRenderWindowRequestFocus},

    { "circle_shape_create",        0, sfCircleShapeCreate       },
    { "circle_shape_destroy",       1, sfCircleShapeDestroy      },
    { "circle_shape_set_radius",    2, sfCircleShapeSetRadius    },
    { "circle_shape_set_fillcolor", 2, sfCircleShapeSetFillColor },

    { "sprite_create",              1, sfSpriteCreate            },
    { "sprite_set_texture",         2, sfSpriteSetTexture        },
    { "sprite_set_texture_rect",    2, sfSpriteSetTextureRect    },
    { "sprite_get_position",        1, sfSpriteGetPosition       },
    { "sprite_set_position",        2, sfSpriteSetPosition       },
    { "sprite_get_rotation",        1, sfSpriteGetRotation       },
    { "sprite_set_rotation",        2, sfSpriteSetRotation       },
    { "sprite_get_scale",           1, sfSpriteGetScale          },
    { "sprite_set_scale",           2, sfSpriteSetScale          },
    { "sprite_move",                2, sfSpriteMove              },
    { "sprite_rotate",              2, sfSpriteRotate            },
    { "sprite_scale",               2, sfSpriteScale             },
    { "sprite_flip",                1, sfSpriteFlip              },
    { "sprite_get_global_bounds",   1, sfSpriteGetGlobalBounds   },

    { "texture_load_from_file",     1, sfTextureLoadFromFile     },
    { "texture_get_size",           1, sfTextureGetSize          },
};

ERL_NIF_INIT(Elixir.SFML.Graphics.NIF, nif_funcs, load, NULL, NULL, NULL);
