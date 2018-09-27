#pragma once

#include "eDrawable.h"

class eSprite :public sf::Sprite {
public:
    eSprite() :mHaveTexture(NULL) {}

    ~eSprite()
    {
        releaseTexture();
    }

    void keepTexture(void* r)
    {
        enif_keep_resource(r);
        mHaveTexture = r;
    }

    void releaseTexture()
    {
        enif_release_resource(mHaveTexture);
        mHaveTexture = NULL;
    }

protected:
    void* mHaveTexture;
};

typedef NifResChild<eSprite, ResDrawable> ResSprite;

#define DECL_NIF(name)  ERL_NIF_TERM name(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])

ERL_NIF_TERM sfSpriteCreate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetTexture(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetTextureRect(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

ERL_NIF_TERM sfSpriteGetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetPosition(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

ERL_NIF_TERM sfSpriteGetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetRotation(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

ERL_NIF_TERM sfSpriteGetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteSetScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

ERL_NIF_TERM sfSpriteMove(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteRotate(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteScale(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
ERL_NIF_TERM sfSpriteFlip(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
DECL_NIF(sfSpriteFlop);

ERL_NIF_TERM sfSpriteGetGlobalBounds(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);
