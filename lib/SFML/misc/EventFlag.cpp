////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
//#include <SFML/System/EventFlag.hpp>
#include "EventFlag.hpp"

#if defined(SFML_SYSTEM_WINDOWS)
    //#include <SFML/System/Win32/EventFlagImpl.hpp>
    #include "Win32/EventFlagImpl.hpp"
#else
    #error "Not yet implement for Unix
    //#include <SFML/System/Unix/EventFlagImpl.hpp>
#endif


namespace sf
{
////////////////////////////////////////////////////////////
EventFlag::EventFlag(bool state)
{
    m_eventflagImpl = new priv::EventFlagImpl(state);
}


////////////////////////////////////////////////////////////
EventFlag::~EventFlag()
{
    delete m_eventflagImpl;
}


////////////////////////////////////////////////////////////
void EventFlag::wait(unsigned int timeout)
{
    if (timeout == EventFlag::FOREVER) {
        timeout = INFINITE;
    }
    m_eventflagImpl->wait(timeout);
}


////////////////////////////////////////////////////////////
void EventFlag::signal()
{
    m_eventflagImpl->signal();
}

} // namespace sf
