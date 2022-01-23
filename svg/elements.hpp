//! @file elements.hpp
#ifndef __svg_elements_hpp__
#define __svg_elements_hpp__

#include "shape.hpp"

namespace svg {
    class ellipse : public shape {
    protected:
        point center;
        point radius;
    public:
        ellipse(const svg::color &fill, const point &center, const point &radius);
        void draw(png_image &img) const override;
        void translate(const point &t) override;
        void scale(const point &origin, int v) override;
        void rotate(const point &origin, int v) override;
        shape *duplicate() const override;
    };


    class circle : public ellipse {
    public:
        circle(const svg::color &fill, const point &center, const int &radius);
    };

    class polyline : public shape {
    protected:
        std::vector<point> points;
    public:
        polyline(const std::vector<point> &points,const color &color);
        void draw(png_image &img) const override;
        void translate(const point &t) override;
        void rotate(const point &center, int degrees) override;
        void scale(const point &origin, int v) override;

        shape *duplicate() const;
    };

    class line : public polyline{
    public:
        line(const std::vector<point> &points,const color &color);
    };

    class polygon : public shape{
    protected:
        std::vector<point> points;
    public:
        polygon(const std::vector<point> &points,const color &fill);
        void draw(png_image &img) const override;
        void translate(const point &t) override;
        void rotate(const point &center, int degrees) override;
        void scale(const point &origin, int v) override;

        shape *duplicate() const;
    };

    class rect : public polygon{
    public:
        rect(const std::vector<point> &points,const color &fill);
    };
}
#endif
