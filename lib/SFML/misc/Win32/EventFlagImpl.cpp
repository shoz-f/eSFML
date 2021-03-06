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
{
    m_evantflag = CreateEvent(NULL, TRUE, state, NULL);
}

////////////////////////////////////////////////////////////
EventFlagImpl::~EventFlagImpl()
{
    CloseHandle(m_evantflag);
}

////////////////////////////////////////////////////////////
void EventFlagImpl::wait(unsigned int timeout=INFINITE)
{
    WaitForSingleObject(m_evantflag, timeout);
    ResetEvent(m_evantflag);
}

////////////////////////////////////////////////////////////
void EventFlagImpl::signal()
{
    SetEvent(m_evantflag);
}

} // namespace priv

} // namespace sf
