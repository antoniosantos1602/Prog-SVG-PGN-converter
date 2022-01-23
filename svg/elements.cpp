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
    }

    void polyline::draw(png_image &img) const{
        for(size_t i = 0; i < points.size()-1; i++){
            img.draw_line(points.at(i),points.at(i+1),get_color());
        }
    }

    void polyline::translate(const point &t) {
        for(auto &point : points){
           point.x += t.x;
           point.y += t.y;
        }
    }

    void polyline::scale(const point &origin, int v) {
        for(auto &point : points){
            point = point.scale(origin,v);
        }
    }

    void polyline::rotate(const point &center, int degrees) {
        for(auto &point : points){
            point = point.rotate(center,degrees);
        }
    }
    shape *polyline::duplicate() const {
        return new polyline(points,get_color());
    }
    //Polyline End-----------------

    //line Begin-----------------
    line::line(const std::vector<point> &points, const color &color) : polyline(points,color) {}
    //line End-----------------


    //Polygon Begin-----------------
    polygon::polygon(const std::vector<point> &points, const color &fill) : shape(fill) {
        this->points = points;
    }

    void polygon::draw(png_image &img) const {
        img.draw_polygon(points,get_color());
    }

    void polygon::rotate(const point &center, int degrees) {
        for(auto &point : points){
            point = point.rotate(center,degrees);
        }
    }

    void polygon::translate(const point &t) {
        for(auto &point : points){
            point.x += t.x;
            point.y += t.y;
        }
    }

    void polygon::scale(const point &origin, int v) {
        for(auto &point : points){
            point = point.scale(origin,v);
        }
    }
    shape *polygon::duplicate() const {
        return new polygon(points,get_color());
    }
    //Polygon End-----------------

    //Rect Begin-----------------
    rect::rect(const std::vector<point> &points, const color &fill) : polygon(points,fill) {}
    //Rect End-----------------

    group::group(const std::vector<shape *>& vector,const color &fill) : shape(fill){

    }
}
