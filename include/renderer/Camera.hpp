#pragma once

namespace ee::renderer
{

    class Camera
    {

    private:
        float m_x;
        float m_y;

        float m_width;
        float m_height;

        
    public:
        
        Camera(float _x, float _y, float _w, float _h) : m_x(_x), m_y(_y), m_width(_w), m_height(_h)
        {}

        void setPosition(float _x, float _y) { m_x = _x; m_y = _y; }
        void move(float _dx, float _dy) { m_x += _dx; m_y += _dy; }

        float getX() const { return m_x; }
        float getY() const { return m_y; }
        float getWidth() const { return m_width; }
        float getHeight() const { return m_height; }

        float getScreenX(float _reelX)  const { return _reelX - m_x; }
        float getScreenY(float _reelY) const { return _reelY - m_y; }

    };
}