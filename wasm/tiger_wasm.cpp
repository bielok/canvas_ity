// WASM tiger demo for canvas_ity library
// Based on the PostScript tiger demo
// Copyright (c) 2024 Andrew Kensler

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#endif

#define CANVAS_ITY_IMPLEMENTATION
#include "../src/canvas_ity.hpp"

#include <memory>

class TigerRenderer {
private:
    std::unique_ptr<canvas_ity::canvas> canvas_ptr;
    int width, height;

public:
    TigerRenderer(int w, int h) : width(w), height(h) {
        canvas_ptr.reset(new canvas_ity::canvas(width, height));
    }

    void render() {
        auto& that = *canvas_ptr;
        
        float const scale = 1.0f;
        that.translate( 733.0f * ( scale - 1.0f ) / -2.0f,
                        757.0f * ( scale - 1.0f ) / -2.0f );
        that.scale( scale, scale );

        // Background
        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 0.8f, 0.8f, 0.8f, 1.0f );
        that.move_to( 0.000000f, 757.333330f );
        that.line_to( 733.333310f, 757.333330f );
        that.line_to( 733.333310f, 0.000016f );
        that.line_to( 0.000000f, 0.000016f );
        that.fill();

        // Tiger stripes (first few for WASM demo)
        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 91.233331f, 335.566670f );
        that.bezier_curve_to( 91.233331f, 335.566670f, 91.435464f, 338.396010f, 90.166664f, 338.366670f );
        that.bezier_curve_to( 89.018798f, 338.339970f, 64.885998f, 267.830680f, 34.833332f, 271.166680f );
        that.bezier_curve_to( 34.833332f, 271.166680f, 60.859865f, 260.336010f, 91.233331f, 335.566670f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );
        that.line_cap = canvas_ity::butt;
        that.set_line_width( 0.252267f );
        that.move_to( 91.233331f, 335.566670f );
        that.bezier_curve_to( 91.233331f, 335.566670f, 91.435464f, 338.396010f, 90.166664f, 338.366670f );
        that.bezier_curve_to( 89.018798f, 338.339970f, 64.885998f, 267.830680f, 34.833332f, 271.166680f );
        that.bezier_curve_to( 34.833332f, 271.166680f, 60.859865f, 260.336010f, 91.233331f, 335.566670f );
        that.stroke();

        // Add a few more key tiger stripes for a more complete demo
        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 96.433331f, 331.166670f );
        that.bezier_curve_to( 96.433331f, 331.166670f, 95.659331f, 333.848010f, 94.566664f, 333.433340f );
        that.bezier_curve_to( 93.405198f, 332.972010f, 94.700531f, 258.457340f, 65.233332f, 251.300010f );
        that.bezier_curve_to( 65.233332f, 251.300010f, 93.463998f, 250.040010f, 96.433331f, 331.166670f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );
        that.set_line_width( 0.252267f );
        that.move_to( 96.433331f, 331.166670f );
        that.bezier_curve_to( 96.433331f, 331.166670f, 95.659331f, 333.848010f, 94.566664f, 333.433340f );
        that.bezier_curve_to( 93.405198f, 332.972010f, 94.700531f, 258.457340f, 65.233332f, 251.300010f );
        that.bezier_curve_to( 65.233332f, 251.300010f, 93.463998f, 250.040010f, 96.433331f, 331.166670f );
        that.stroke();

        // Orange tiger coloring
        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 0.8f, 0.45098039215686275f, 0.14901960784313725f, 1.0f );
        that.move_to( 710.299980f, 329.700010f );
        that.bezier_curve_to( 711.173320f, 329.958670f, 714.407980f, 331.606670f, 716.299980f, 333.966670f );
        that.bezier_curve_to( 716.299980f, 333.966670f, 726.214650f, 349.866670f, 718.566650f, 322.900010f );
        that.bezier_curve_to( 718.566650f, 322.900010f, 705.094650f, 280.640010f, 718.033320f, 297.033340f );
        that.fill();

        // More orange sections
        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 0.8f, 0.45f, 0.15f, 1.0f );
        that.move_to( 530.0f, 280.0f );
        that.bezier_curve_to( 580.0f, 260.0f, 630.0f, 300.0f, 610.0f, 360.0f );
        that.bezier_curve_to( 590.0f, 420.0f, 530.0f, 400.0f, 510.0f, 360.0f );
        that.bezier_curve_to( 490.0f, 320.0f, 510.0f, 280.0f, 530.0f, 280.0f );
        that.fill();

        // Black stripes
        that.begin_path();
        that.set_line_width( 4.0f );
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );
        that.move_to( 550.0f, 300.0f );
        that.bezier_curve_to( 560.0f, 320.0f, 570.0f, 340.0f, 560.0f, 360.0f );
        that.stroke();
        
        that.move_to( 540.0f, 310.0f );
        that.bezier_curve_to( 550.0f, 330.0f, 560.0f, 350.0f, 550.0f, 370.0f );
        that.stroke();

        // Tiger eyes
        that.begin_path();
        that.set_line_width( 2.0f );
        that.set_color( canvas_ity::fill_style, 0.0f, 0.0f, 0.0f, 1.0f );
        that.arc( 420.0f, 300.0f, 6.0f, 0.0f, 6.28318f );
        that.fill();
        
        that.arc( 460.0f, 300.0f, 6.0f, 0.0f, 6.28318f );
        that.fill();
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
EMSCRIPTEN_BINDINGS(tiger_module) {
    emscripten::class_<TigerRenderer>("TigerRenderer")
        .constructor<int, int>()
        .function("render", &TigerRenderer::render)
        .function("getImageData", &TigerRenderer::getImageData)
        .function("getWidth", &TigerRenderer::getWidth)
        .function("getHeight", &TigerRenderer::getHeight);
}
#endif

// C-style API for simple usage
extern "C" {
    static TigerRenderer* renderer = nullptr;

    EMSCRIPTEN_KEEPALIVE
    void init_tiger(int width, int height) {
        if (renderer) delete renderer;
        renderer = new TigerRenderer(width, height);
    }

    EMSCRIPTEN_KEEPALIVE
    void render_tiger() {
        if (renderer) {
            renderer->render();
        }
    }

    EMSCRIPTEN_KEEPALIVE
    uintptr_t get_image_data() {
        if (renderer) {
            return renderer->getImageData();
        }
        return 0;
    }

    EMSCRIPTEN_KEEPALIVE
    int get_width() {
        return renderer ? renderer->getWidth() : 0;
    }

    EMSCRIPTEN_KEEPALIVE
    int get_height() {
        return renderer ? renderer->getHeight() : 0;
    }
}