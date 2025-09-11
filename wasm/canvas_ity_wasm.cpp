// General-purpose WASM wrapper for canvas_ity library
// Copyright (c) 2024 Andrew Kensler

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#endif

#define CANVAS_ITY_IMPLEMENTATION
#include "../src/canvas_ity.hpp"

#include <memory>

class CanvasItyWrapper {
private:
    std::unique_ptr<canvas_ity::canvas> canvas_ptr;
    int width, height;

public:
    CanvasItyWrapper(int w, int h) : width(w), height(h) {
        canvas_ptr.reset(new canvas_ity::canvas(width, height));
    }

    // Path building methods
    void begin_path() {
        canvas_ptr->begin_path();
    }

    void move_to(float x, float y) {
        canvas_ptr->move_to(x, y);
    }

    void line_to(float x, float y) {
        canvas_ptr->line_to(x, y);
    }

    void close_path() {
        canvas_ptr->close_path();
    }

    void bezier_curve_to(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y) {
        canvas_ptr->bezier_curve_to(cp1x, cp1y, cp2x, cp2y, x, y);
    }

    void quadratic_curve_to(float cpx, float cpy, float x, float y) {
        canvas_ptr->quadratic_curve_to(cpx, cpy, x, y);
    }

    void arc(float x, float y, float radius, float start_angle, float end_angle, bool anticlockwise = false) {
        canvas_ptr->arc(x, y, radius, start_angle, end_angle, anticlockwise);
    }

    void arc_to(float x1, float y1, float x2, float y2, float radius) {
        canvas_ptr->arc_to(x1, y1, x2, y2, radius);
    }

    void rect(float x, float y, float w, float h) {
        canvas_ptr->rectangle(x, y, w, h);
    }

    // Fill and stroke methods
    void fill() {
        canvas_ptr->fill();
    }

    void stroke() {
        canvas_ptr->stroke();
    }

    void fill_rect(float x, float y, float w, float h) {
        canvas_ptr->fill_rectangle(x, y, w, h);
    }

    void stroke_rect(float x, float y, float w, float h) {
        canvas_ptr->stroke_rectangle(x, y, w, h);
    }

    void clear_rect(float x, float y, float w, float h) {
        canvas_ptr->clear_rectangle(x, y, w, h);
    }

    // Style methods
    void set_fill_color(float r, float g, float b, float a) {
        canvas_ptr->set_color(canvas_ity::fill_style, r, g, b, a);
    }

    void set_stroke_color(float r, float g, float b, float a) {
        canvas_ptr->set_color(canvas_ity::stroke_style, r, g, b, a);
    }

    void set_line_width(float width) {
        canvas_ptr->set_line_width(width);
    }

    void set_line_cap(int cap) {
        switch (cap) {
            case 0: canvas_ptr->line_cap = canvas_ity::butt; break;
            case 1: canvas_ptr->line_cap = canvas_ity::circle; break;
            case 2: canvas_ptr->line_cap = canvas_ity::square; break;
        }
    }

    void set_line_join(int join) {
        switch (join) {
            case 0: canvas_ptr->line_join = canvas_ity::bevel; break;
            case 1: canvas_ptr->line_join = canvas_ity::rounded; break;
            case 2: canvas_ptr->line_join = canvas_ity::miter; break;
        }
    }

    void set_line_dash(emscripten::val segments, int count) {
        static std::vector<float> dash_segments;
        dash_segments.clear();
        for (int i = 0; i < count; i++) {
            dash_segments.push_back(segments[i].as<float>());
        }
        canvas_ptr->set_line_dash(dash_segments.data(), count);
    }

    void set_line_dash_offset(float offset) {
        canvas_ptr->line_dash_offset = offset;
    }

    // Shadow methods
    void set_shadow_color(float r, float g, float b, float a) {
        canvas_ptr->set_shadow_color(r, g, b, a);
    }

    void set_shadow_blur(float blur) {
        canvas_ptr->set_shadow_blur(blur);
    }

    void set_shadow_offset(float x, float y) {
        canvas_ptr->shadow_offset_x = x;
        canvas_ptr->shadow_offset_y = y;
    }

    // Gradient methods
    void set_linear_gradient_fill(float x0, float y0, float x1, float y1) {
        canvas_ptr->set_linear_gradient(canvas_ity::fill_style, x0, y0, x1, y1);
    }

    void set_linear_gradient_stroke(float x0, float y0, float x1, float y1) {
        canvas_ptr->set_linear_gradient(canvas_ity::stroke_style, x0, y0, x1, y1);
    }

    void add_color_stop_fill(float offset, float r, float g, float b, float a) {
        canvas_ptr->add_color_stop(canvas_ity::fill_style, offset, r, g, b, a);
    }

    void add_color_stop_stroke(float offset, float r, float g, float b, float a) {
        canvas_ptr->add_color_stop(canvas_ity::stroke_style, offset, r, g, b, a);
    }

    // Composite operation
    void set_global_composite_operation(int op) {
        switch (op) {
            case 0: canvas_ptr->global_composite_operation = canvas_ity::source_over; break;
            case 1: canvas_ptr->global_composite_operation = canvas_ity::source_atop; break;
            case 2: canvas_ptr->global_composite_operation = canvas_ity::source_in; break;
            case 3: canvas_ptr->global_composite_operation = canvas_ity::source_out; break;
            case 4: canvas_ptr->global_composite_operation = canvas_ity::destination_over; break;
            case 5: canvas_ptr->global_composite_operation = canvas_ity::destination_atop; break;
            case 6: canvas_ptr->global_composite_operation = canvas_ity::destination_in; break;
            case 7: canvas_ptr->global_composite_operation = canvas_ity::destination_out; break;
            case 8: canvas_ptr->global_composite_operation = canvas_ity::lighter; break;
            case 9: canvas_ptr->global_composite_operation = canvas_ity::source_copy; break;
            case 10: canvas_ptr->global_composite_operation = canvas_ity::exclusive_or; break;
        }
    }

    // Transform methods
    void translate(float x, float y) {
        canvas_ptr->translate(x, y);
    }

    void rotate(float angle) {
        canvas_ptr->rotate(angle);
    }

    void scale(float x, float y) {
        canvas_ptr->scale(x, y);
    }

    void save() {
        canvas_ptr->save();
    }

    void restore() {
        canvas_ptr->restore();
    }

    // Canvas management
    void clear_canvas() {
        canvas_ptr->clear_rectangle(0, 0, width, height);
    }

    // Get image data as RGBA bytes
    uintptr_t getImageData() {
        static std::vector<unsigned char> image_data;
        image_data.resize(width * height * 4);
        canvas_ptr->get_image_data(image_data.data(), width, height, width * 4, 0, 0);
        return reinterpret_cast<uintptr_t>(image_data.data());
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_BINDINGS(canvas_ity_module) {
    emscripten::class_<CanvasItyWrapper>("CanvasIty")
        .constructor<int, int>()
        // Path methods
        .function("begin_path", &CanvasItyWrapper::begin_path)
        .function("move_to", &CanvasItyWrapper::move_to)
        .function("line_to", &CanvasItyWrapper::line_to)
        .function("close_path", &CanvasItyWrapper::close_path)
        .function("bezier_curve_to", &CanvasItyWrapper::bezier_curve_to)
        .function("quadratic_curve_to", &CanvasItyWrapper::quadratic_curve_to)
        .function("arc", &CanvasItyWrapper::arc)
        .function("arc_to", &CanvasItyWrapper::arc_to)
        .function("rect", &CanvasItyWrapper::rect)
        // Fill and stroke methods
        .function("fill", &CanvasItyWrapper::fill)
        .function("stroke", &CanvasItyWrapper::stroke)
        .function("fill_rect", &CanvasItyWrapper::fill_rect)
        .function("stroke_rect", &CanvasItyWrapper::stroke_rect)
        .function("clear_rect", &CanvasItyWrapper::clear_rect)
        // Style methods
        .function("set_fill_color", &CanvasItyWrapper::set_fill_color)
        .function("set_stroke_color", &CanvasItyWrapper::set_stroke_color)
        .function("set_line_width", &CanvasItyWrapper::set_line_width)
        .function("set_line_cap", &CanvasItyWrapper::set_line_cap)
        .function("set_line_join", &CanvasItyWrapper::set_line_join)
        .function("set_line_dash", &CanvasItyWrapper::set_line_dash)
        .function("set_line_dash_offset", &CanvasItyWrapper::set_line_dash_offset)
        // Shadow methods
        .function("set_shadow_color", &CanvasItyWrapper::set_shadow_color)
        .function("set_shadow_blur", &CanvasItyWrapper::set_shadow_blur)
        .function("set_shadow_offset", &CanvasItyWrapper::set_shadow_offset)
        // Gradient methods
        .function("set_linear_gradient_fill", &CanvasItyWrapper::set_linear_gradient_fill)
        .function("set_linear_gradient_stroke", &CanvasItyWrapper::set_linear_gradient_stroke)
        .function("add_color_stop_fill", &CanvasItyWrapper::add_color_stop_fill)
        .function("add_color_stop_stroke", &CanvasItyWrapper::add_color_stop_stroke)
        // Composite operation
        .function("set_global_composite_operation", &CanvasItyWrapper::set_global_composite_operation)
        // Transform methods
        .function("translate", &CanvasItyWrapper::translate)
        .function("rotate", &CanvasItyWrapper::rotate)
        .function("scale", &CanvasItyWrapper::scale)
        .function("save", &CanvasItyWrapper::save)
        .function("restore", &CanvasItyWrapper::restore)
        // Canvas management
        .function("clear_canvas", &CanvasItyWrapper::clear_canvas)
        .function("getImageData", &CanvasItyWrapper::getImageData)
        .function("getWidth", &CanvasItyWrapper::getWidth)
        .function("getHeight", &CanvasItyWrapper::getHeight);
}
#endif

// C-style API for simple usage
extern "C" {
    static CanvasItyWrapper* canvas = nullptr;

    EMSCRIPTEN_KEEPALIVE
    void init_canvas(int width, int height) {
        if (canvas) delete canvas;
        canvas = new CanvasItyWrapper(width, height);
    }

    EMSCRIPTEN_KEEPALIVE
    void destroy_canvas() {
        if (canvas) {
            delete canvas;
            canvas = nullptr;
        }
    }

    EMSCRIPTEN_KEEPALIVE
    uintptr_t get_image_data() {
        if (canvas) {
            return canvas->getImageData();
        }
        return 0;
    }

    EMSCRIPTEN_KEEPALIVE
    int get_width() {
        return canvas ? canvas->getWidth() : 0;
    }

    EMSCRIPTEN_KEEPALIVE
    int get_height() {
        return canvas ? canvas->getHeight() : 0;
    }

    // Path methods for C API
    EMSCRIPTEN_KEEPALIVE
    void begin_path() { if (canvas) canvas->begin_path(); }

    EMSCRIPTEN_KEEPALIVE
    void move_to(float x, float y) { if (canvas) canvas->move_to(x, y); }

    EMSCRIPTEN_KEEPALIVE
    void line_to(float x, float y) { if (canvas) canvas->line_to(x, y); }

    EMSCRIPTEN_KEEPALIVE
    void close_path() { if (canvas) canvas->close_path(); }

    EMSCRIPTEN_KEEPALIVE
    void fill() { if (canvas) canvas->fill(); }

    EMSCRIPTEN_KEEPALIVE
    void stroke() { if (canvas) canvas->stroke(); }

    EMSCRIPTEN_KEEPALIVE
    void set_fill_color(float r, float g, float b, float a) {
        if (canvas) canvas->set_fill_color(r, g, b, a);
    }

    EMSCRIPTEN_KEEPALIVE
    void set_stroke_color(float r, float g, float b, float a) {
        if (canvas) canvas->set_stroke_color(r, g, b, a);
    }

    EMSCRIPTEN_KEEPALIVE
    void set_line_width(float width) {
        if (canvas) canvas->set_line_width(width);
    }

    EMSCRIPTEN_KEEPALIVE
    void set_line_join(int join) {
        if (canvas) canvas->set_line_join(join);
    }

    EMSCRIPTEN_KEEPALIVE
    void set_line_cap(int cap) {
        if (canvas) canvas->set_line_cap(cap);
    }

    EMSCRIPTEN_KEEPALIVE
    void set_shadow_blur(float blur) {
        if (canvas) canvas->set_shadow_blur(blur);
    }

    EMSCRIPTEN_KEEPALIVE
    void set_shadow_offset(float x, float y) {
        if (canvas) canvas->set_shadow_offset(x, y);
    }

    EMSCRIPTEN_KEEPALIVE
    void set_shadow_color(float r, float g, float b, float a) {
        if (canvas) canvas->set_shadow_color(r, g, b, a);
    }

    EMSCRIPTEN_KEEPALIVE
    void set_linear_gradient_fill(float x0, float y0, float x1, float y1) {
        if (canvas) canvas->set_linear_gradient_fill(x0, y0, x1, y1);
    }

    EMSCRIPTEN_KEEPALIVE
    void add_color_stop_fill(float offset, float r, float g, float b, float a) {
        if (canvas) canvas->add_color_stop_fill(offset, r, g, b, a);
    }

    EMSCRIPTEN_KEEPALIVE
    void set_global_composite_operation(int op) {
        if (canvas) canvas->set_global_composite_operation(op);
    }

    EMSCRIPTEN_KEEPALIVE
    void fill_rect(float x, float y, float w, float h) {
        if (canvas) canvas->fill_rect(x, y, w, h);
    }

    EMSCRIPTEN_KEEPALIVE
    void clear_canvas() {
        if (canvas) canvas->clear_canvas();
    }

    EMSCRIPTEN_KEEPALIVE
    void set_line_dash(emscripten::val segments, int count) {
        if (canvas) canvas->set_line_dash(segments, count);
    }

    EMSCRIPTEN_KEEPALIVE
    void set_line_dash_offset(float offset) {
        if (canvas) canvas->set_line_dash_offset(offset);
    }
}
