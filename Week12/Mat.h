#ifndef MAT_H
#define MAT_H
#include "Vec.h"

class Mat
{
    
public:
    float x1;
    float x2;
    float y1;
    float y2;
    static Mat Identity;
    
    
    Mat(float x1, float x2, float y1, float y2);
    
    Mat operator +(const Mat & max)const;
    Mat operator -(const Mat &max)const;
    
};
Mat Mat::Identity = Mat(1.0, 0.0, 0.0, 1.0);
Mat::Mat(float x1, float x2, float y1, float y2)
{
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
}
Mat operator *(const float i, Mat & m)
{
    return Mat(i * m.x1, i * m.x2, i * m.y1, i * m.y2);
}
Vec operator*(const Vec & v, const Mat & m)
{
    return Vec(v.x * m.x1 + v.x * m.x2, v.y * m.y1 + v.y * m.y2);
}
Mat operator *(const Mat &a, const Mat &m)
{
    return Mat(a.x1 *m.x1 + a.x1 *m.x2, a.x2 * m.x1 + a.x2* m.x2, a.y1 * m.y1 + a.y1 * m.y2, a.y2 * m.y2 + a.y2 * m.y1);
}
Mat Mat::operator +(const Mat & m)const
{
    return Mat(x1 + m.x1, x2 + m.x2, y1 + m.y1, y2 + m.y2);
}
Mat Mat::operator -(const Mat &m)const
{
    return Mat(x1 - m.x1, x2 - m.x2, y1 - m.y1, y2 - m.y2);
}


#endif