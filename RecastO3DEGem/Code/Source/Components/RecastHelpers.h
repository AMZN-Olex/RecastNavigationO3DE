#pragma once
#include <AzCore/Math/Vector3.h>

namespace RecastO3DE
{
    // +Y is up
    class RecastVector3
    {
    public:
        RecastVector3() = default;

        // Lumberyard coordinate space
        explicit RecastVector3( const AZ::Vector3& in )
        {
            m_x = in.GetX();
            m_y = in.GetZ(); // Notice the flip!
            m_z = in.GetY(); // Notice the flip!
        }

        // Recast coordinate space
        explicit RecastVector3( const float* data )
        {
            m_x = data[0];
            m_y = data[1];
            m_z = data[2];
        }

        float* data() { return &m_x; }

        AZ::Vector3 AsVector3() const
        {
            return AZ::Vector3( m_x, m_z, m_y );
        }

        float m_x = 0, m_y = 0, m_z = 0;
    };

}
