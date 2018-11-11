////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "EventFlagImpl.hpp"

namespace sf
{
namespace priv
{
////////////////////////////////////////////////////////////
EventFlagImpl::EventFlagImpl(bool state)
: mEventFlag(state)
{
    mLock  = PTHREAD_MUTEX_INITIALIZER;
    mAwake = PTHREAD_COND_INITIALIZER;
}

////////////////////////////////////////////////////////////
EventFlagImpl::~EventFlagImpl()
{
}

////////////////////////////////////////////////////////////
void EventFlagImpl::wait(unsigned int timeout=INFINITE)
{
    pthread_mutex_lock(&mLock);
    while (!mEventFlag) {
        pthread_cond_wait(&mAwake, &mLock);
    }
    mEventFlag = false;
    pthread_mutex_unlock(&mLock);
}

////////////////////////////////////////////////////////////
void EventFlagImpl::signal()
{
    pthread_mutex_lock(&mLock);
    mEventFlag = true;
    pthread_cond_signal(&mAwake);
    pthread_mutex_unlock(&mLock);
}

} // namespace priv

} // namespace sf
