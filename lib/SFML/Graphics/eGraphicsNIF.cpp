// Graphics.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"

#include "eDrawable.h"
#include "eRenderWindow.h"
#include "eCircleShape.h"
#include "eRectangleShape.h"
#include "eConvexShape.h"
#include "eSprite.h"
#include "eTexture.h"
#include "eTransformable.h"

int load(ErlNifEnv *env, void **priv_data, ERL_NIF_TERM load_info)
{
    ResDrawable::Define(env, "sfml_drawable");
    ResRenderWindow::Define(env, "sfml_renderwindow");
    ResTexture::Define(env, "sfml_texture");
    return 0;
}

// Let's define the array of ErlNifFunc beforehand:
static ErlNifFunc nif_funcs[] = {
    // {erl_function_name, erl_function_arity, c_function}
    { "render_window_create",                  2, sfRenderWindowCreate                },
    { "render_window_destroy",                 1, sfRenderWindowDestroy               },
    { "render_window_clear",                   2, sfRenderWindowClear                 },
    { "render_window_draw",                    2, sfRenderWindowDraw                  },
    { "render_window_set_framerate_limit",     2, sfRenderWindowSetFramerateLimit     },
    { "render_window_display",                 1, sfRenderWindowDisplay               },
    { "render_window_get_size",                1, sfRenderWindowGetSize               },
    { "render_window_is_open",                 1, sfRenderWindowIsOpen                },
    { "render_window_poll_event",              1, sfRenderWindowPollEvent             },
    { "render_window_request_focus",           1, sfRenderWindowRequestFocus          },

    { "circle_shape_create",                   0, sfCircleShapeCreate                 },
    { "circle_shape_destroy",                  1, sfCircleShapeDestroy                },
    { "circle_shape_get_radius",               1, sfCircleShapeGetRasius              },
    { "circle_shape_set_radius",               2, sfCircleShapeSetRadius              },
    { "circle_shape_get_point",                1, sfCircleShapeGetPoint               },
    { "circle_shape_get_outline_thickness",    1, sfCircleShapeGetOutlineThickness    },
    { "circle_shape_set_outline_thickness",    2, sfCircleShapeSetOutlineThickness    },
    { "circle_shape_set_texture",              2, sfCircleShapeSetTexture             },
    { "circle_shape_get_texture_rect",         1, sfCircleShapeGetTextureRect         },
    { "circle_shape_set_texture_rect",         2, sfCircleShapeSetTextureRect         },
    { "circle_shape_get_origin",               1, sfCircleShapeGetOrigin              },
    { "circle_shape_set_origin",               2, sfCircleShapeSetOrigin              },
    { "circle_shape_get_position",             1, sfCircleShapeGetPosition            },
    { "circle_shape_set_position",             2, sfCircleShapeSetPosition            },
    { "circle_shape_get_rotation",             1, sfCircleShapeGetRotation            },
    { "circle_shape_set_rotation",             2, sfCircleShapeSetRotation            },
    { "circle_shape_get_scale",                1, sfCircleShapeGetScale               },
    { "circle_shape_set_scale",                2, sfCircleShapeSetScale               },
    { "circle_shape_get_outline_color",        1, sfCircleShapeGetOutlineColor        },
    { "circle_shape_set_outline_color",        2, sfCircleShapeSetOutlineColor        },
    { "circle_shape_get_fill_color",           1, sfCircleShapeGetFillColor           },
    { "circle_shape_set_fill_color",           2, sfCircleShapeSetFillColor           },
    { "circle_shape_move",                     2, sfCircleShapeMove                   },
    { "circle_shape_rotate",                   2, sfCircleShapeRotate                 },
    { "circle_shape_scale",                    2, sfCircleShapeScale                  },
    { "circle_shape_flip",                     1, sfCircleShapeFlip                   },
    { "circle_shape_flop",                     1, sfCircleShapeFlop                   },
    { "circle_shape_get_global_bounds",        1, sfCircleShapeGetGlobalBounds        },

    { "rectangle_shape_create",                0, sfRectangleShapeCreate              },
    { "rectangle_shape_destroy",               1, sfRectangleShapeDestroy             },
    { "rectangle_shape_get_size",              1, sfRectangleShapeGetSize             },
    { "rectangle_shape_set_size",              2, sfRectangleShapeSetSize             },
    { "rectangle_shape_get_point",             1, sfRectangleShapeGetPoint            },
    { "rectangle_shape_get_outline_thickness", 1, sfRectangleShapeGetOutlineThickness },
    { "rectangle_shape_set_outline_thickness", 2, sfRectangleShapeSetOutlineThickness },
    { "rectangle_shape_set_texture",           2, sfRectangleShapeSetTexture          },
    { "rectangle_shape_get_texture_rect",      1, sfRectangleShapeGetTextureRect      },
    { "rectangle_shape_set_texture_rect",      2, sfRectangleShapeSetTextureRect      },
    { "rectangle_shape_get_origin",            1, sfRectangleShapeGetOrigin           },
    { "rectangle_shape_set_origin",            2, sfRectangleShapeSetOrigin           },
    { "rectangle_shape_get_position",          1, sfRectangleShapeGetPosition         },
    { "rectangle_shape_set_position",          2, sfRectangleShapeSetPosition         },
    { "rectangle_shape_get_rotation",          1, sfRectangleShapeGetRotation         },
    { "rectangle_shape_set_rotation",          2, sfRectangleShapeSetRotation         },
    { "rectangle_shape_get_scale",             1, sfRectangleShapeGetScale            },
    { "rectangle_shape_set_scale",             2, sfRectangleShapeSetScale            },
    { "rectangle_shape_get_outline_color",     1, sfRectangleShapeGetOutlineColor     },
    { "rectangle_shape_set_outline_color",     2, sfRectangleShapeSetOutlineColor     },
    { "rectangle_shape_get_fill_color",        1, sfRectangleShapeGetFillColor        },
    { "rectangle_shape_set_fill_color",        2, sfRectangleShapeSetFillColor        },
    { "rectangle_shape_move",                  2, sfRectangleShapeMove                },
    { "rectangle_shape_rotate",                2, sfRectangleShapeRotate              },
    { "rectangle_shape_scale",                 2, sfRectangleShapeScale               },
    { "rectangle_shape_flip",                  1, sfRectangleShapeFlip                },
    { "rectangle_shape_flop",                  1, sfRectangleShapeFlop                },
    { "rectangle_shape_get_global_bounds",     1, sfRectangleShapeGetGlobalBounds     },

    { "convex_shape_create",                   1, sfConvexShapeCreate                 },
    { "convex_shape_get_point_count",          1, sfConvexShapeGetPointCount          },
    { "convex_shape_get_point",                1, sfConvexShapeGetPoint               },
    { "convex_shape_get_outline_thickness",    1, sfConvexShapeGetOutlineThickness    },
    { "convex_shape_set_outline_thickness",    2, sfConvexShapeSetOutlineThickness    },
    { "convex_shape_set_texture",              2, sfConvexShapeSetTexture             },
    { "convex_shape_get_texture_rect",         1, sfConvexShapeGetTextureRect         },
    { "convex_shape_set_texture_rect",         2, sfConvexShapeSetTextureRect         },
    { "convex_shape_get_origin",               1, sfConvexShapeGetOrigin              },
    { "convex_shape_set_origin",               2, sfConvexShapeSetOrigin              },
    { "convex_shape_get_position",             1, sfConvexShapeGetPosition            },
    { "convex_shape_set_position",             2, sfConvexShapeSetPosition            },
    { "convex_shape_get_rotation",             1, sfConvexShapeGetRotation            },
    { "convex_shape_set_rotation",             2, sfConvexShapeSetRotation            },
    { "convex_shape_get_scale",                1, sfConvexShapeGetScale               },
    { "convex_shape_set_scale",                2, sfConvexShapeSetScale               },
    { "convex_shape_get_outline_color",        1, sfConvexShapeGetOutlineColor        },
    { "convex_shape_set_outline_color",        2, sfConvexShapeSetOutlineColor        },
    { "convex_shape_get_fill_color",           1, sfConvexShapeGetFillColor           },
    { "convex_shape_set_fill_color",           2, sfConvexShapeSetFillColor           },
    { "convex_shape_move",                     2, sfConvexShapeMove                   },
    { "convex_shape_rotate",                   2, sfConvexShapeRotate                 },
    { "convex_shape_scale",                    2, sfConvexShapeScale                  },
    { "convex_shape_flip",                     1, sfConvexShapeFlip                   },
    { "convex_shape_flop",                     1, sfConvexShapeFlop                   },
    { "convex_shape_get_global_bounds",        1, sfConvexShapeGetGlobalBounds        },

    { "sprite_create",                         1, sfSpriteCreate                      },
    { "sprite_clone",                          1, sfSpriteClone                       },
    { "sprite_set_texture",                    2, sfSpriteSetTexture                  },
    { "sprite_set_texture_rect",               2, sfSpriteSetTextureRect              },
    { "sprite_get_texture_rect",               1, sfSpriteGetTextureRect              },
    { "sprite_get_origin",                     1, sfSpriteGetOrigin                   },
    { "sprite_set_origin",                     2, sfSpriteSetOrigin                   },
    { "sprite_get_position",                   1, sfSpriteGetPosition                 },
    { "sprite_set_position",                   2, sfSpriteSetPosition                 },
    { "sprite_get_rotation",                   1, sfSpriteGetRotation                 },
    { "sprite_set_rotation",                   2, sfSpriteSetRotation                 },
    { "sprite_get_scale",                      1, sfSpriteGetScale                    },
    { "sprite_set_scale",                      2, sfSpriteSetScale                    },
    { "sprite_get_color",                      1, sfSpriteGetColor                    },
    { "sprite_set_color",                      2, sfSpriteSetColor                    },
    { "sprite_move",                           2, sfSpriteMove                        },
    { "sprite_rotate",                         2, sfSpriteRotate                      },
    { "sprite_scale",                          2, sfSpriteScale                       },
    { "sprite_flip",                           1, sfSpriteFlip                        },
    { "sprite_flop",                           1, sfSpriteFlop                        },
    { "sprite_get_global_bounds",              1, sfSpriteGetGlobalBounds             },

    { "texture_load_from_file",                1, sfTextureLoadFromFile               },
    { "texture_get_size",                      1, sfTextureGetSize                    },

    // { "transformable_move",                 2, sfTransformableMove              },
    // { "transformable_rotate",               2, sfTransformableRotate            },
    // { "transformable_scale",                2, sfTransformableScale             },
};

ERL_NIF_INIT(Elixir.SFML.Graphics.NIF, nif_funcs, load, NULL, NULL, NULL);
