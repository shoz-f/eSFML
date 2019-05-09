////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "VertexDeque.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/VertexArray.hpp>


namespace sf
{
////////////////////////////////////////////////////////////
VertexDeque::VertexDeque() :
m_vertices(),
m_primitiveType(Points)
{
}


////////////////////////////////////////////////////////////
VertexDeque::VertexDeque(PrimitiveType type, std::size_t vertexCount) :
m_vertices(),
m_vertexCount(vertexCount),
m_primitiveType(type)
{
}


////////////////////////////////////////////////////////////
std::size_t VertexDeque::getVertexCount() const
{
    return m_vertices.size();
}


////////////////////////////////////////////////////////////
Vertex& VertexDeque::operator [](std::size_t index)
{
    return m_vertices[index];
}

////////////////////////////////////////////////////////////
void VertexDeque::setVertexPosition(std::size_t index, Vector2f& pos)
{
    m_vertices[index].position = pos;
}


////////////////////////////////////////////////////////////
void VertexDeque::setVertexColor(std::size_t index, Color& color)
{
    m_vertices[index].color = color;
}


////////////////////////////////////////////////////////////
const Vertex& VertexDeque::operator [](std::size_t index) const
{
    return m_vertices[index];
}


////////////////////////////////////////////////////////////
const Vertex& VertexDeque::getVertex(std::size_t index) const
{
    return m_vertices[index];
}


////////////////////////////////////////////////////////////
void VertexDeque::clear()
{
    m_vertices.clear();
}


////////////////////////////////////////////////////////////
void VertexDeque::resize(std::size_t vertexCount)
{
    m_vertexCount = vertexCount;
    if (vertexCount < m_vertices.size()) {
        m_vertices.resize(vertexCount);
    }
}


////////////////////////////////////////////////////////////
void VertexDeque::push(const Vertex& vertex)
{
    m_vertices.push_front(vertex);
    if (m_vertices.size() > m_vertexCount) {
        m_vertices.pop_back();
    }
}


////////////////////////////////////////////////////////////
void VertexDeque::setPrimitiveType(PrimitiveType type)
{
    m_primitiveType = type;
}


////////////////////////////////////////////////////////////
PrimitiveType VertexDeque::getPrimitiveType() const
{
    return m_primitiveType;
}


////////////////////////////////////////////////////////////
FloatRect VertexDeque::getBounds() const
{
    if (!m_vertices.empty()) {
        float left   = m_vertices[0].position.x;
        float top    = m_vertices[0].position.y;
        float right  = m_vertices[0].position.x;
        float bottom = m_vertices[0].position.y;

        for (std::size_t i = 1; i < m_vertices.size(); ++i) {
            Vector2f position = m_vertices[i].position;

            // Update left and right
            if (position.x < left) {
                left = position.x;
            }
            else if (position.x > right) {
                right = position.x;
            }

            // Update top and bottom
            if (position.y < top) {
                top = position.y;
            }
            else if (position.y > bottom) {
                bottom = position.y;
            }
        }

        return FloatRect(left, top, right - left, bottom - top);
    }
    else {
        // Array is empty
        return FloatRect();
    }
}


////////////////////////////////////////////////////////////
void VertexDeque::draw(RenderTarget& target, RenderStates states) const
{
    if (!m_vertices.empty()) {
        std::size_t count = m_vertices.size();
        std::vector<Vertex> vertices(count);
        std::copy(m_vertices.cbegin(), m_vertices.cend(), vertices.begin());

        target.draw(&vertices[0], count, m_primitiveType, states);
    }
}

} // namespace sf
