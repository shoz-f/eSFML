/***  File Header  ************************************************************/
/**
* @file NifRes.h
*
* Helper templates for handling NIFs resource object
* @author	Shozo Fukuda
* @date		Create: <%= $date; %>
* @date		Modify: $Date:$
* System	Window<br>
*
* Copyright (C) Shozo Fukuda
*
**/
/**************************************************************************{{{*/
#ifndef _NIFRES_H
#define _NIFRES_H

/***** INCLUDE *****/

/***** CONSTANT *****/

/***** TYPE *****/

/***** MACRO *****/

/***** EXPORT VARIABLE *****/

/***** EXPORT FUNCTION *****/

/***  Module Header  ******************************************************}}}*/
/**
* Mapping Integral Constants to Types
* @par DESCRIPTION
*   utility type, you can use it in "typif" ideom
**/
/**************************************************************************{{{*/
template <int v>
struct Int2Type
{
    enum { value = v };
};

/***  Class Header  *******************************************************}}}*/
/**
* NIFs resouce wrapper for alone/abstruct class objects
* @par DESCRIPTION
*   <<‰ðà‹L“ü>>
* @par EXAMPLE
*
* @see
**/
/**************************************************************************{{{*/
template <class T, bool isAbstruct=false>
class NifRes {
//SETUP:
public:
    static ErlNifResourceType* _ResType;
    static char*               _Name;

    static void _destructor(ErlNifEnv* env, void* ptr)
    {
        T** r = reinterpret_cast<T**>(ptr);
	    delete *r;
    }
  
    static void Define(ErlNifEnv* env, char* name)
    {
        _ResType = enif_open_resource_type(env, NULL, name, _destructor, ERL_NIF_RT_CREATE, NULL);
    }

//CONSTANT:
public:

//LIFECYCLE:
public:
    NifRes(ErlNifEnv* env) : mEnv(env) {}

    virtual ~NifRes() {}

//ACTION:
private:
    void AllocObj(Int2Type<true>)  {}
    void AllocObj(Int2Type<false>) { mObj = new T(); }
protected:
    virtual void AllocObj()
    {
        AllocObj(Int2Type<isAbstruct>());
        *mRes = mObj;
    }

    virtual void BindObj()
    {
        mObj = *mRes;
    }

public:
    bool Create()
    {
        mRes = reinterpret_cast<T**>(enif_alloc_resource(_ResType, sizeof(void*)));
        if (mRes == NULL) {
            return false;
        }
        AllocObj();
        return true;
    }
    
    bool Open(ERL_NIF_TERM term)
    {
        if (enif_get_resource(mEnv, term, _ResType, (void**)&mRes)) {
            BindObj();
            return true;
        }
        else {
            return false;
        }
    }
    
    void Release()
    {
        enif_release_resource(mRes);
    }
    
    ERL_NIF_TERM MkTerm()
    {
        ERL_NIF_TERM term = enif_make_resource(mEnv, mRes);
        enif_release_resource(mRes);
        return term;
    }

//ACCESSOR:
public:

//INQUIRY:
public:

//ATTRIBUTE:
protected:
    ErlNifEnv* mEnv;
public:
    T** mRes;         ///< NIFs resource pointer
    T*  mObj;         ///< SFML object pointer
};

/***  Class Header  *******************************************************}}}*/
/**
* NIFs resouce wrapper for derived class objects
* @par DESCRIPTION
*   <<‰ðà‹L“ü>>
* @par EXAMPLE
*
* @see
**/
/**************************************************************************{{{*/
template<class T, class SUPER>
class NifResChild : public SUPER {
    
//CONSTANT:
public:

//LIFECYCLE:
public:
    NifResChild(ErlNifEnv* env)
    : SUPER(env)
    {}

    virtual ~NifResChild() {}

//ACTION:
protected:
    virtual void AllocObj()
    {
        mObj  = new T();
        *mRes = mObj;
    }

    virtual void BindObj()
    {
        mObj = dynamic_cast<T*>(*mRes);
    }

//ACCESSOR:
public:

//INQUIRY:
public:

//ATTRIBUTE:
public:
    T* mObj;    ///< SFML object pointer
};

#endif
/*** End of NifRes.h ******************************************************}}}*/
