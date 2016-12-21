using namespace std;
template<class T>
class Vec {
public:
    T x;
    T y;
    
    Vec(){
        x = 0;
        y = 0;
    }
    
    Vec (T x, T y){
        this->x = x;
        this->y = y;
    }
    
    Vec operator + (const Vec<T> & v) const{
        return Vec<T>(x + v.x, y + v.y);
    }
    
    Vec operator - (const Vec<T> & v) const{
        return Vec<T>(x - v.x, y - v.y);
    }
    
    Vec operator * (const int&a) const{
        return Vec<T>(a*x, a*y);
    }
    
    
};

ostream& operator<< (ostream& o, const Vec & v){
    o << "(" << v.x << ", " << v.y << ")";
    return o;
}


template<class A>
class Mat
{
    
public:
    A x1;
    A x2;
    A y1;
    A y2;
    static Mat Identity;
    
    
    Mat(A x1, A x2, A y1, A y2);
    
    Mat operator +(const Mat & max)const;
    Mat operator -(const Mat &max)const;
    
};

template<class A>
Mat Mat<A>::Identity = Mat(1.0, 0.0, 0.0, 1.0);
Mat<A>::Mat(T x1, T x2, T y1, T y2)
{
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
}

template<class T>
Mat operator *(const T i, Mat & m)
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
Mat Mat<A>::operator +(const Mat & m)const
{
    return Mat(x1 + m.x1, x2 + m.x2, y1 + m.y1, y2 + m.y2);
}
Mat Mat<A>::operator -(const Mat<T> &m)const
{
 
    return Mat(x1 - m.x1, x2 - m.x2, y1 - m.y1, y2 - m.y2);
}

