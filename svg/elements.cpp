#include <iostream>
#include "elements.hpp"

namespace svg {
    //Ellipse begin-----------------
    ellipse::ellipse(const svg::color &fill,
                     const point &center,
                     const point &radius) :
            shape(fill), center(center), radius(radius) {

    }
    void ellipse::draw(png_image &img) const {
        img.draw_ellipse(center, radius, get_color());
    }
    void ellipse::translate(const point &t) {
        center = center.translate(t);
    }
    void ellipse::scale(const point &origin, int v) {
        radius.x *= v;
        radius.y *= v;
        center = center.scale(origin,v);
    }

    void ellipse::rotate(const point &origin, int degrees) {
        center = center.rotate(origin, degrees);
    }
    shape *ellipse::duplicate() const {
        return new ellipse(get_color(), center, radius);
    }
    //Ellipse End-----------------

    //Circle Begin-----------------
    circle::circle(const svg::color &fill, const point &center, const int &radius) : ellipse(fill,center,{radius,radius}) {}
    //Circle End-----------------

    //Polyline Begin-----------------
    polyline::polyline(const std::vector<point> &points, const color &color) : shape(color){
        this->points = points;
        for(auto elem : points){
            std::cout << elem << std::endl;
        }
    }

    void polyline::draw(png_image &img) const{
        for(size_t i = 0; i < points.size(); i+=2){
            img.draw_line(points.at(i),points.at(i+1),get_color());
        }
    }
    //Polyline End-----------------


}
