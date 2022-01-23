
#include <iostream>
#include <tinyxml2.h>
#include <sstream>
#include "svg_to_png.hpp"
#include "elements.hpp"

using namespace tinyxml2;

namespace svg {
    // Color parsing
    const std::map<std::string, color> COLORS = {
            {"black",  {0,   0,   0}},
            {"white",  {255, 255, 255}},
            {"red",    {255, 0,   0}},
            {"green",  {0,   255, 0}},
            {"blue",   {0,   0,   255}},
            {"yellow", {255, 255, 0}}
    };

    std::map<std::string, shape> idMap;

    color parse_color(const std::string &str) {
        color c;
        char first_ch = str.at(0);
        if (first_ch == '#') {
            int v;
            std::stringstream ss(str.substr(1));
            ss >> std::hex >> v;
            c.red = (v >> 16);
            c.green = (v >> 8) & 0xFF;
            c.blue = v & 0xFF;
        } else {
            c = COLORS.at(str);
        }
        return c;
    }

    // Transformation parsing

    void parse_transform(shape *s, XMLElement *elem) {
        const char* p_t_attr = elem->Attribute("transform");
        if (p_t_attr == NULL)
            return; // Not defined
        point origin{0,0};
        const char* p_t_o_attr = elem->Attribute("transform-origin");
        if (p_t_o_attr != NULL) {
            std::string str = p_t_o_attr;
            std::stringstream ss(str);
            ss >> origin.x >> origin.y;
        }
        std::string attr(p_t_attr);
        for (char &c: attr) {
            if (c == '(' || c == ')' || c == ',') {
                c = ' ';
            }
        }
        std::stringstream ss(attr);
        std::string type;
        ss >> type;
        if (type == "translate") {
            int x, y;
            ss >> x >> y;
            s->translate({x, y});
        } else if (type == "scale") {
            int v;
            ss >> v;
            s->scale(origin, v);
        } else if (type == "rotate") {
            int v;
            ss >> v;
            s->rotate(origin, v);
        } else {
            std::cout << "Unrecognised transform type: " << type << std::endl;
        }
    }

    // Point list parsing
    void
    parse_points(const std::string &s, std::vector<point> &points) {
        std::stringstream ss(s);
        std::string val;
        while (std::getline(ss, val, ' ')) {
            val.at(val.find(',')) = ' ';
            std::stringstream ss2(val);
            int x, y;
            ss2 >> x >> y;
            points.push_back({x, y});
        }
    }

    void parse_id(const std::string &id,const shape &obj){
        idMap.insert(std::pair<std::string,shape>(id,obj));
    }

    // Shape parsing
    ellipse *parse_ellipse(XMLElement *elem) {
        int cx = elem->IntAttribute("cx");
        int cy = elem->IntAttribute("cy");
        int rx = elem->IntAttribute("rx");
        int ry = elem->IntAttribute("ry");
        color fill = parse_color(elem->Attribute("fill"));
        auto *output = new ellipse(fill, {cx, cy}, {rx, ry});
        XMLError id = elem->QueryAttribute("id", (bool *) "");
        if(id != tinyxml2::XML_NO_ATTRIBUTE){
            parse_id(elem->Attribute("id"),*output->duplicate());
        }
        return output;
    }

    circle *parse_circle(XMLElement *elem) {
        int cx = elem->IntAttribute("cx");
        int cy = elem->IntAttribute("cy");
        int r = elem->IntAttribute("r");
        color fill = parse_color(elem->Attribute("fill"));
        auto *output = new circle(fill,{cx,cy},r);
        XMLError id = elem->QueryAttribute("id", (bool *) "");
        if(id != tinyxml2::XML_NO_ATTRIBUTE){
            parse_id(elem->Attribute("id"),*output->duplicate());
        }
        return output;
    }

    std::vector<std::string> splitString(std::string s,const std::string& delimiter) {
        std::vector<std::string> splitString;
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            splitString.push_back(token);
            s.erase(0, pos + delimiter.length());
        }
        splitString.push_back(s);
        return splitString;
    };


    std::vector<point> getPoints(const char *pointsChar) {
        std::vector<point> pointsOut;
        std::vector<std::string> s = splitString(std::string(pointsChar)," ");
        for(const auto& elem : s){
            size_t separator = elem.find(',');
            pointsOut.push_back({stoi(elem.substr(0,separator)),stoi(elem.substr(separator+1,elem.size()-1))});
        }
        return pointsOut;
    }

    polyline *parse_polyline(XMLElement *elem){
        std::vector<point> points = getPoints(elem->Attribute("points"));
        color color = parse_color(elem->Attribute("stroke"));
        auto *output = new polyline(points,color);
        XMLError id = elem->QueryAttribute("id", (bool *) "");
        if(id != tinyxml2::XML_NO_ATTRIBUTE){
            parse_id(elem->Attribute("id"),*output->duplicate());
        }
        return output;
    }

    polyline *parse_line(XMLElement *elem){
        point point1 = { elem->IntAttribute("x1"),elem->IntAttribute("y1")};
        point point2 = { elem->IntAttribute("x2"),elem->IntAttribute("y2")};
        std::vector<point> points;
        points.push_back(point1);
        points.push_back(point2);
        color color = parse_color(elem->Attribute("stroke"));
        auto *output = new line(points,color);
        XMLError id = elem->QueryAttribute("id", (bool *) "");
        if(id != tinyxml2::XML_NO_ATTRIBUTE){
            parse_id(elem->Attribute("id"),*output->duplicate());
        }
        return output;
    }

    polygon *parse_polygon(XMLElement *elem){
        std::vector<point> points = getPoints(elem->Attribute("points"));
        color color = parse_color(elem->Attribute("fill"));
        auto *output = new polygon(points,color);
        XMLError id = elem->QueryAttribute("id", (bool *) "");
        if(id != tinyxml2::XML_NO_ATTRIBUTE){
            parse_id(elem->Attribute("id"),*output->duplicate());
        }
        return output;
    }

    polygon *parse_rect(XMLElement *elem){
        point point1 = { elem->IntAttribute("x"),elem->IntAttribute("y")};
        point point2 = { elem->IntAttribute("width")+point1.x-1,elem->IntAttribute("height")+point1.y-1};
        std::cout << point1 << std::endl;
        std::cout << point2 << std::endl;
        std::vector<point> points;
        points.push_back(point1);
        points.push_back(point2);
        color color = parse_color(elem->Attribute("fill"));
        auto *output = new rect(points,color);
        XMLError id = elem->QueryAttribute("id", (bool *) "");
        if(id != tinyxml2::XML_NO_ATTRIBUTE){
            parse_id(elem->Attribute("id"),*output->duplicate());
        }
        return output;
    }

    shape *parse_use(XMLElement *elem){
        
    }


    // TODO other parsing functions for elements

    // Loop for parsing shapes
    void parse_shapes(XMLElement *elem, std::vector<shape *> &shapes) {
        for (auto child_elem = elem->FirstChildElement();
             child_elem != NULL;
             child_elem = child_elem->NextSiblingElement()) {
            std::string type(child_elem->Name());
            shape *s;
            // TODO complete
            if (type == "ellipse") {
                s = parse_ellipse(child_elem);
            }
            else if(type == "circle"){
                s = parse_circle(child_elem);
            }
            else if(type == "polyline"){
                s = parse_polyline(child_elem);
            }
            else if(type == "line"){
                s = parse_line(child_elem);
            }
            else if(type == "polygon"){
                s = parse_polygon(child_elem);
            }
            else if(type == "rect"){
                s = parse_rect(child_elem);
            }
            else if(type == "use"){
                s = parse_use(child_elem);
            }
            else {
                std::cout << "Unrecognized shape type: " << type << std::endl;
                continue;
            }
            parse_transform(s, child_elem);
            shapes.push_back(s);
        }
    }

    // Main conversion function.
    // TODO adapt if necessary
    void svg_to_png(const std::string &svg_file, const std::string &png_file) {
        XMLDocument doc;
        XMLError r = doc.LoadFile(svg_file.c_str());
        if (r != XML_SUCCESS) {
            return;
        }
        XMLElement *elem = doc.RootElement();
        std::vector<shape *> shapes;
        parse_shapes(elem, shapes);
        int width = elem->IntAttribute("width");
        int height = elem->IntAttribute("height");
        png_image img(width, height);
        for (auto s: shapes) {
            s->draw(img);
        }
        img.save(png_file);
        for (auto s: shapes) {
            delete s;
        }
    }

}
