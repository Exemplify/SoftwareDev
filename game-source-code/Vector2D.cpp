#include "Vector2D.h"

// Default Constructor
/**
 * @brief Default constructor for the Vector2D class. Assigns the static origin of the Vector2D class to this Vector2D object
 * @return Vector2D by value.
 */
Vector2D::Vector2D()
{
    *this = origin;
}

// Scalar Constructor
/**
 * @brief Constructor for the Vector2D class by two double scalar parameters, and the vector input type.
 * Constructs the Vector2D object appropriately based from the vectype parameter.
 * @param val1 either as x value of cartesian input or radius value of polar input.
 * @param val2 either as y value of cartesian input or theta value of polar input.
 * @param vectype of the parameters val1 and val2. Default is VectorType::xy.
 * @return Vector2D by value.
 */
Vector2D::Vector2D(double val1, double val2, const VectorType& vectype)
{
    if (vectype == VectorType::xy)
    {
        _xyvec.x = val1;
        _xyvec.y = val2;
        radius();
        theta();
    }
    else if (vectype == VectorType::rt)
    {
        _rtvec.r = val1;
        _rtvec.t = val2;
        xVal();
        yVal();
        theta();
    } 
}

// Vector Constructor for xyVector
/**
 * @brief Constructor for the Vector2D class directly from a xyVector struct.
 * @param vec The xyVector struct used for the Vector2D object construction. Used by constant value.
 * @return Vector2D by value.
 */
Vector2D::Vector2D(const xyVector vec)
{
    _xyvec = vec;
    radius();
    theta();
}

// Vector Constructor for rtVector
/**
 * @brief Constructor for the Vector2D class directly from a rtVector struct.
 * @param vec The rtVector struct used for the Vector2D object construction. Used by constant value.
 * @return Vector2D by value.
 */
Vector2D::Vector2D(const rtVector vec)
{
    _rtvec = vec;
    xVal();
    yVal();
}

// Copy Constructor
/**
 * @brief Copy constructor for the Vector2D class.
 * @param rhs Vector2D value that is used to assign to this. Used by constant reference.
 * @return Vector2D by value.
 */
Vector2D::Vector2D(const Vector2D& rhs)
{
    *this = rhs;
}

//private calculate radius
void Vector2D::radius()
{
    _rtvec.r = sqrt(pow(_xyvec.x,2)+pow(_xyvec.y,2));
}

//private calculate theta
void Vector2D::theta()
{
    _rtvec.t = atan2(_xyvec.y,_xyvec.x);
}

//private calculate x
void Vector2D::xVal()
{
    _xyvec.x = (_rtvec.r)*cos(_rtvec.t);
}

//private calculate y
void Vector2D::yVal()
{
    _xyvec.y = _rtvec.r*sin(_rtvec.t);
}

// return the Vector2D as a xyVector struct (cartesian form)
xyVector Vector2D::getXYVector() const
{
    return _xyvec;
}

//return the Vector2D as a rtVector struct (polar form)
rtVector Vector2D::getRTVector() const
{
    return _rtvec;
}

//overload operators
// assignment operator, Vector2D = Vector2D
Vector2D& Vector2D::operator = (const Vector2D& rhs)
{
    _xyvec = rhs._xyvec;
    _rtvec = rhs._rtvec;
    return *this;
}

// equivalancy operator, Vector2D == Vector2D
bool Vector2D::operator==(const Vector2D& rhs) const
{
    if (magnitude(*this,rhs)>magnitude_tolerance)
        return false;
    return true;
}

// addition and create operator: newVector2D = Vector2D + Vector2D
Vector2D Vector2D::operator + (const Vector2D& rhs) const
{
    double x = _xyvec.x + rhs._xyvec.x;
    double y = _xyvec.y + rhs._xyvec.y;
    Vector2D temp(x,y);
    return temp;
}

// subtraction and create operator: newVector2D = Vector2D - Vector2D
Vector2D Vector2D::operator - (const Vector2D& rhs) const
{
    double x = _xyvec.x - rhs._xyvec.x;
    double y = _xyvec.y - rhs._xyvec.y;
    Vector2D temp(x,y);
    return temp;
}

// Vector multiply and create operator: newVector2D = Vector2D * Vector2D
Vector2D Vector2D::operator * (const Vector2D& rhs) const
{
    double r = _rtvec.r*rhs._rtvec.r;
    double t = _rtvec.t+rhs._rtvec.t;
    Vector2D temp(r,t, VectorType::rt);
    return temp;
}

// scalar multiply and create operator: newVector2D = Vector2D * scalar
Vector2D Vector2D::operator * (const double& scalar) const
{
    double r = _rtvec.r*scalar;
    double t = _rtvec.t;
    Vector2D temp(r,t, VectorType::rt);
    return temp;
}

// scalar division and create operator: newVector2D = Vector2D / scalar
Vector2D Vector2D::operator / (const double& scalar) const
{
    double r = _rtvec.r/scalar;
    double t = _rtvec.t;
    Vector2D temp(r,t, VectorType::rt);
    return temp;
}

// addition assignment operator: thisVector2d = thisVector2D + Vector2D
Vector2D& Vector2D::operator += (const Vector2D& rhs)
{
    _xyvec.x += rhs._xyvec.x;
    _xyvec.y += rhs._xyvec.y;
    radius();
    theta();
    return *this;
}

// subtraction assignment operator: thisVector2D = thisVector2D - Vector2D
Vector2D& Vector2D::operator -= (const Vector2D& rhs)
{
    _xyvec.x -= rhs._xyvec.x;
    _xyvec.y -= rhs._xyvec.y;
    radius();
    theta();
    return *this;
}

// Vector multiply assignemnt operator: thisVector2D = thisVector2D*Vector2D
Vector2D& Vector2D::operator *= (const Vector2D& rhs)
{
    _rtvec.r *= rhs._rtvec.r;
    _rtvec.t += rhs._rtvec.t;
    xVal();
    yVal();
    theta();
    return *this;
}

// scalar multiply assignment operator: thisVector2D = thisVector2D*scalar
Vector2D& Vector2D::operator *= (const double scale)
{
    _rtvec.r *= scale;
    xVal();
    yVal();
    return *this;
}

// scalar division assignment operator: thisVector2D = thisVector2D/scalar
Vector2D& Vector2D::operator /= (const double scale)
{
    _rtvec.r /= scale;
    xVal();
    yVal();
    return *this;
}

// default single input magnitude function
double Vector2D::magnitude(const Vector2D& lhs)
{
    return magnitude(lhs, origin); // also could return _raduis
}


// magnttude between two vectors
double Vector2D::magnitude(const Vector2D& lhs, const Vector2D& rhs)
{
    double dx = lhs._xyvec.x-rhs._xyvec.x;
    double dy = lhs._xyvec.y-rhs._xyvec.y;
    double temp = sqrt(pow(dx,2)+pow(dy,2));
    return temp;
}

Vector2D Vector2D::origin{0,0};
Vector2D Vector2D::right{1, 0};
Vector2D Vector2D::left{-1, 0};
Vector2D Vector2D::up{0, 1};
Vector2D Vector2D::down{0, -1};
double Vector2D::magnitude_tolerance = 0.000000001;

Vector2D Vector2D::normalize() const
{
    Vector2D temp(_rtvec.r/_rtvec.r, _rtvec.t, VectorType::rt);
    return temp;
}