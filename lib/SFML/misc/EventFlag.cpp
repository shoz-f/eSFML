////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
//#include <SFML/System/EventFlag.hpp>
#include "EventFlag.hpp"

#if defined(SFML_SYSTEM_WINDOWS)
    #include "Win32/EventFlagImpl.hpp"
#elif defined(SFML_SYSTEM_LINUX)
    #include "Unix/EventFlagImpl.hpp"
#else
    #error "Not yet implement for this OS"
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
