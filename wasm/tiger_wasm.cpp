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

        // Complete PostScript tiger rendering from demos/tiger/tiger.cpp
        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 0.8f, 0.8f, 0.8f, 1.0f );
        that.move_to( 0.000000f, 757.333330f );
        that.line_to( 733.333310f, 757.333330f );
        that.line_to( 733.333310f, 0.000016f );
        that.line_to( 0.000000f, 0.000016f );
        that.fill();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 91.233331f, 335.566670f );
        that.bezier_curve_to( 91.233331f, 335.566670f, 91.435464f, 338.396010f, 90.166664f, 338.366670f );
        that.bezier_curve_to( 89.018798f, 338.339970f, 64.885998f, 267.830680f, 34.833332f, 271.166680f );
        that.bezier_curve_to( 34.833332f, 271.166680f, 60.859865f, 260.336010f, 91.233331f, 335.566670f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.line_cap = canvas_ity::butt;
        that.set_line_width( 0.252267f );
        that.move_to( 91.233331f, 335.566670f );
        that.bezier_curve_to( 91.233331f, 335.566670f, 91.435464f, 338.396010f, 90.166664f, 338.366670f );
        that.bezier_curve_to( 89.018798f, 338.339970f, 64.885998f, 267.830680f, 34.833332f, 271.166680f );
        that.bezier_curve_to( 34.833332f, 271.166680f, 60.859865f, 260.336010f, 91.233331f, 335.566670f );
        that.stroke();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 96.433331f, 331.166670f );
        that.bezier_curve_to( 96.433331f, 331.166670f, 95.659331f, 333.848010f, 94.566664f, 333.433340f );
        that.bezier_curve_to( 93.405198f, 332.972010f, 94.700531f, 258.457340f, 65.233332f, 251.300010f );
        that.bezier_curve_to( 65.233332f, 251.300010f, 93.463998f, 250.040010f, 96.433331f, 331.166670f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.set_line_width( 0.252267f );
        that.move_to( 96.433331f, 331.166670f );
        that.bezier_curve_to( 96.433331f, 331.166670f, 95.659331f, 333.848010f, 94.566664f, 333.433340f );
        that.bezier_curve_to( 93.405198f, 332.972010f, 94.700531f, 258.457340f, 65.233332f, 251.300010f );
        that.bezier_curve_to( 65.233332f, 251.300010f, 93.463998f, 250.040010f, 96.433331f, 331.166670f );
        that.stroke();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 136.833330f, 393.300010f );
        that.bezier_curve_to( 136.833330f, 393.300010f, 139.182660f, 394.673340f, 138.433330f, 395.700010f );
        that.bezier_curve_to( 137.802660f, 396.660010f, 65.680665f, 377.882670f, 51.766665f, 404.766670f );
        that.bezier_curve_to( 51.766665f, 404.766670f, 57.209332f, 377.105340f, 136.833330f, 393.300010f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.set_line_width( 0.252267f );
        that.move_to( 136.833330f, 393.300010f );
        that.bezier_curve_to( 136.833330f, 393.300010f, 139.182660f, 394.673340f, 138.433330f, 395.700010f );
        that.bezier_curve_to( 137.802660f, 396.660010f, 65.680665f, 377.882670f, 51.766665f, 404.766670f );
        that.bezier_curve_to( 51.766665f, 404.766670f, 57.209332f, 377.105340f, 136.833330f, 393.300010f );
        that.stroke();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 132.700000f, 408.233340f );
        that.bezier_curve_to( 132.700000f, 408.233340f, 135.385330f, 408.822670f, 135.100000f, 409.966670f );
        that.bezier_curve_to( 134.701330f, 411.142670f, 60.336398f, 416.044010f, 55.633332f, 445.966670f );
        that.bezier_curve_to( 55.633332f, 445.966670f, 52.052665f, 417.974670f, 132.700000f, 408.233340f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.set_line_width( 0.252267f );
        that.move_to( 132.700000f, 408.233340f );
        that.bezier_curve_to( 132.700000f, 408.233340f, 135.385330f, 408.822670f, 135.100000f, 409.966670f );
        that.bezier_curve_to( 134.701330f, 411.142670f, 60.336398f, 416.044010f, 55.633332f, 445.966670f );
        that.bezier_curve_to( 55.633332f, 445.966670f, 52.052665f, 417.974670f, 132.700000f, 408.233340f );
        that.stroke();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 126.433330f, 400.100010f );
        that.bezier_curve_to( 126.433330f, 400.100010f, 129.095330f, 401.110670f, 128.566660f, 402.233340f );
        that.bezier_curve_to( 128.080260f, 403.305340f, 53.796399f, 397.306670f, 44.833332f, 426.233340f );
        that.bezier_curve_to( 44.833332f, 426.233340f, 45.319332f, 398.009340f, 126.433330f, 400.100010f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.set_line_width( 0.252267f );
        that.move_to( 126.433330f, 400.100010f );
        that.bezier_curve_to( 126.433330f, 400.100010f, 129.095330f, 401.110670f, 128.566660f, 402.233340f );
        that.bezier_curve_to( 128.080260f, 403.305340f, 53.796399f, 397.306670f, 44.833332f, 426.233340f );
        that.bezier_curve_to( 44.833332f, 426.233340f, 45.319332f, 398.009340f, 126.433330f, 400.100010f );
        that.stroke();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 110.833330f, 373.433340f );
        that.bezier_curve_to( 110.833330f, 373.433340f, 112.705200f, 375.454670f, 111.766660f, 376.233340f );
        that.bezier_curve_to( 110.830660f, 376.982670f, 46.674532f, 339.062670f, 25.899999f, 361.166670f );
        that.bezier_curve_to( 25.899999f, 361.166670f, 38.745866f, 335.981340f, 110.833330f, 373.433340f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.set_line_width( 0.252267f );
        that.move_to( 110.833330f, 373.433340f );
        that.bezier_curve_to( 110.833330f, 373.433340f, 112.705200f, 375.454670f, 111.766660f, 376.233340f );
        that.bezier_curve_to( 110.830660f, 376.982670f, 46.674532f, 339.062670f, 25.899999f, 361.166670f );
        that.bezier_curve_to( 25.899999f, 361.166670f, 38.745866f, 335.981340f, 110.833330f, 373.433340f );
        that.stroke();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 99.766664f, 379.566670f );
        that.bezier_curve_to( 99.766664f, 379.566670f, 101.856260f, 381.370670f, 100.966660f, 382.233340f );
        that.bezier_curve_to( 100.166660f, 383.102670f, 32.130666f, 352.685340f, 14.033333f, 376.900010f );
        that.bezier_curve_to( 14.033333f, 376.900010f, 23.904133f, 350.522670f, 99.766664f, 379.566670f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.set_line_width( 0.252267f );
        that.move_to( 99.766664f, 379.566670f );
        that.bezier_curve_to( 99.766664f, 379.566670f, 101.856260f, 381.370670f, 100.966660f, 382.233340f );
        that.bezier_curve_to( 100.166660f, 383.102670f, 32.130666f, 352.685340f, 14.033333f, 376.900010f );
        that.bezier_curve_to( 14.033333f, 376.900010f, 23.904133f, 350.522670f, 99.766664f, 379.566670f );
        that.stroke();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 95.899998f, 385.566670f );
        that.bezier_curve_to( 95.899998f, 385.566670f, 98.265598f, 387.036010f, 97.499998f, 387.966670f );
        that.bezier_curve_to( 96.828664f, 388.981340f, 25.281733f, 368.121340f, 10.700000f, 394.633340f );
        that.bezier_curve_to( 10.700000f, 394.633340f, 16.836400f, 367.098670f, 95.899998f, 385.566670f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.set_line_width( 0.252267f );
        that.move_to( 95.899998f, 385.566670f );
        that.bezier_curve_to( 95.899998f, 385.566670f, 98.265598f, 387.036010f, 97.499998f, 387.966670f );
        that.bezier_curve_to( 96.828664f, 388.981340f, 25.281733f, 368.121340f, 10.700000f, 394.633340f );
        that.bezier_curve_to( 10.700000f, 394.633340f, 16.836400f, 367.098670f, 95.899998f, 385.566670f );
        that.stroke();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 111.633330f, 386.500010f );
        that.bezier_curve_to( 111.633330f, 386.500010f, 113.296400f, 388.704010f, 112.300000f, 389.300010f );
        that.bezier_curve_to( 111.240130f, 389.980010f, 52.472399f, 344.149340f, 29.099999f, 363.433340f );
        that.bezier_curve_to( 29.099999f, 363.433340f, 45.002666f, 340.078670f, 111.633330f, 386.500010f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.set_line_width( 0.252267f );
        that.move_to( 111.633330f, 386.500010f );
        that.bezier_curve_to( 111.633330f, 386.500010f, 113.296400f, 388.704010f, 112.300000f, 389.300010f );
        that.bezier_curve_to( 111.240130f, 389.980010f, 52.472399f, 344.149340f, 29.099999f, 363.433340f );
        that.bezier_curve_to( 29.099999f, 363.433340f, 45.002666f, 340.078670f, 111.633330f, 386.500010f );
        that.stroke();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 82.699998f, 343.966670f );
        that.bezier_curve_to( 82.699998f, 343.966670f, 83.519731f, 346.640010f, 82.299998f, 346.900010f );
        that.bezier_curve_to( 81.173465f, 347.226670f, 39.226532f, 285.626680f, 11.100000f, 296.766670f );
        that.bezier_curve_to( 11.100000f, 296.766670f, 33.359866f, 279.466680f, 82.699998f, 343.966670f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.set_line_width( 0.252267f );
        that.move_to( 82.699998f, 343.966670f );
        that.bezier_curve_to( 82.699998f, 343.966670f, 83.519731f, 346.640010f, 82.299998f, 346.900010f );
        that.bezier_curve_to( 81.173465f, 347.226670f, 39.226532f, 285.626680f, 11.100000f, 296.766670f );
        that.bezier_curve_to( 11.100000f, 296.766670f, 33.359866f, 279.466680f, 82.699998f, 343.966670f );
        that.stroke();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 83.633331f, 354.233340f );
        that.bezier_curve_to( 83.633331f, 354.233340f, 85.089598f, 356.625340f, 84.033331f, 357.166670f );
        that.bezier_curve_to( 82.922931f, 357.702670f, 28.678666f, 306.598670f, 3.633333f, 323.566670f );
        that.bezier_curve_to( 3.633333f, 323.566670f, 21.620799f, 301.849340f, 83.633331f, 354.233340f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.set_line_width( 0.252267f );
        that.move_to( 83.633331f, 354.233340f );
        that.bezier_curve_to( 83.633331f, 354.233340f, 85.089598f, 356.625340f, 84.033331f, 357.166670f );
        that.bezier_curve_to( 82.922931f, 357.702670f, 28.678666f, 306.598670f, 3.633333f, 323.566670f );
        that.bezier_curve_to( 3.633333f, 323.566670f, 21.620799f, 301.849340f, 83.633331f, 354.233340f );
        that.stroke();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 83.499998f, 360.633340f );
        that.bezier_curve_to( 83.499998f, 360.633340f, 85.136398f, 362.890670f, 84.166665f, 363.566670f );
        that.bezier_curve_to( 83.080265f, 364.165340f, 24.311999f, 318.336010f, 0.966667f, 337.566670f );
        that.bezier_curve_to( 0.966667f, 337.566670f, 16.842133f, 314.264010f, 83.499998f, 360.633340f );
        that.fill();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );;
        that.set_line_width( 0.252267f );
        that.move_to( 83.499998f, 360.633340f );
        that.bezier_curve_to( 83.499998f, 360.633340f, 85.136398f, 362.890670f, 84.166665f, 363.566670f );
        that.bezier_curve_to( 83.080265f, 364.165340f, 24.311999f, 318.336010f, 0.966667f, 337.566670f );
        that.bezier_curve_to( 0.966667f, 337.566670f, 16.842133f, 314.264010f, 83.499998f, 360.633340f );
        that.stroke();

        // Main tiger body (large complex path) - from original tiger.cpp
        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 1.0f, 1.0f, 1.0f, 1.0f );
        that.move_to( 80.299998f, 363.166670f );
        that.bezier_curve_to( 80.986931f, 372.032010f, 82.435998f, 381.666670f, 84.966665f, 386.233340f );
        that.bezier_curve_to( 84.966665f, 386.233340f, 79.706798f, 404.428010f, 92.566664f, 423.833340f );
        that.bezier_curve_to( 92.566664f, 423.833340f, 92.026531f, 434.348000f, 94.433331f, 439.033340f );
        that.bezier_curve_to( 94.433331f, 439.033340f, 100.240130f, 451.361340f, 107.233330f, 452.500000f );
        that.bezier_curve_to( 112.976530f, 453.484000f, 125.770260f, 457.985340f, 140.166660f, 460.100000f );
        that.bezier_curve_to( 140.166660f, 460.100000f, 165.360000f, 480.694670f, 160.700000f, 499.433340f );
        that.bezier_curve_to( 160.700000f, 499.433340f, 160.080000f, 523.521340f, 154.833330f, 525.833340f );
        that.bezier_curve_to( 154.833330f, 525.833340f, 171.813330f, 509.441340f, 157.766660f, 534.100000f );
        that.line_to( 151.233330f, 561.700000f );
        that.bezier_curve_to( 151.233330f, 561.700000f, 188.826660f, 529.974670f, 165.900000f, 556.900000f );
        that.line_to( 151.233330f, 595.033330f );
        that.bezier_curve_to( 151.233330f, 595.033330f, 180.026660f, 568.108000f, 169.500000f, 580.366670f );
        that.line_to( 164.833330f, 593.300000f );
        that.bezier_curve_to( 164.833330f, 593.300000f, 228.133330f, 553.441340f, 182.966660f, 596.900000f );
        that.bezier_curve_to( 182.966660f, 596.900000f, 194.693330f, 591.574670f, 201.099990f, 595.700000f );
        that.bezier_curve_to( 201.099990f, 595.700000f, 211.119990f, 593.921330f, 209.899990f, 596.233330f );
        that.bezier_curve_to( 209.899990f, 596.233330f, 179.440000f, 611.521330f, 174.166660f, 638.500000f );
        that.bezier_curve_to( 174.166660f, 638.500000f, 186.480000f, 623.841330f, 181.766660f, 639.700000f );
        that.line_to( 182.433330f, 656.633330f );
        that.bezier_curve_to( 182.433330f, 656.633330f, 188.240000f, 625.014530f, 187.633330f, 680.100000f );
        that.bezier_curve_to( 187.633330f, 680.100000f, 215.813330f, 653.761470f, 198.833330f, 684.233330f );
        that.line_to( 198.833330f, 708.900000f );
        that.bezier_curve_to( 198.833330f, 708.900000f, 221.093330f, 684.854670f, 211.766660f, 703.566660f );
        that.bezier_curve_to( 211.766660f, 703.566660f, 226.373330f, 690.721330f, 220.566660f, 713.033330f );
        that.bezier_curve_to( 220.566660f, 713.033330f, 219.333330f, 728.268260f, 225.766660f, 711.833330f );
        that.bezier_curve_to( 225.766660f, 711.833330f, 249.253330f, 666.961470f, 240.433330f, 705.433330f );
        that.bezier_curve_to( 240.433330f, 705.433330f, 239.279990f, 733.547860f, 246.299990f, 711.833330f );
        that.bezier_curve_to( 246.299990f, 711.833330f, 246.906660f, 727.094800f, 260.433330f, 737.700000f );
        that.bezier_curve_to( 260.433330f, 737.700000f, 258.639990f, 663.147870f, 277.366660f, 715.966660f );
        that.line_to( 283.233330f, 739.966660f );
        that.bezier_curve_to( 283.233330f, 739.966660f, 287.386660f, 726.508260f, 286.833330f, 718.900000f );
        that.bezier_curve_to( 286.833330f, 718.900000f, 308.506660f, 694.828130f, 298.566660f, 730.633330f );
        that.bezier_curve_to( 298.566660f, 730.633330f, 320.826660f, 697.174930f, 316.166660f, 716.500000f );
        that.bezier_curve_to( 316.166660f, 716.500000f, 304.986660f, 740.001600f, 307.366660f, 747.033330f );
        that.bezier_curve_to( 307.366660f, 747.033330f, 331.973330f, 696.001600f, 333.766660f, 693.700000f );
        that.bezier_curve_to( 333.766660f, 693.700000f, 330.799990f, 755.842700f, 346.699990f, 703.033330f );
        that.bezier_curve_to( 346.699990f, 703.033330f, 354.853320f, 720.641600f, 350.699990f, 727.033330f );
        that.bezier_curve_to( 350.699990f, 727.033330f, 362.479990f, 715.361460f, 361.366660f, 710.633330f );
        that.bezier_curve_to( 361.366660f, 710.633330f, 368.053320f, 698.641600f, 372.166660f, 718.633330f );
        that.bezier_curve_to( 372.166660f, 718.633330f, 374.799990f, 732.374930f, 377.099990f, 727.700000f );
        that.bezier_curve_to( 377.099990f, 727.700000f, 383.013320f, 762.882810f, 384.833320f, 729.433330f );
        that.bezier_curve_to( 384.833320f, 729.433330f, 387.119990f, 709.494800f, 376.566660f, 692.500000f );
        that.bezier_curve_to( 376.566660f, 692.500000f, 377.733320f, 687.788000f, 373.633320f, 681.966670f );
        that.bezier_curve_to( 373.633320f, 681.966670f, 393.573320f, 713.601600f, 382.966660f, 671.300000f );
        that.bezier_curve_to( 382.966660f, 671.300000f, 399.441320f, 683.094800f, 401.233320f, 683.033330f );
        that.bezier_curve_to( 401.233320f, 683.033330f, 381.253320f, 649.068270f, 394.166660f, 656.100000f );
        that.bezier_curve_to( 394.166660f, 656.100000f, 386.533320f, 640.854670f, 412.966660f, 658.500000f );
        that.bezier_curve_to( 412.966660f, 658.500000f, 389.466660f, 634.988000f, 415.233320f, 649.033330f );
        that.bezier_curve_to( 415.233320f, 649.033330f, 427.014660f, 658.454670f, 415.899990f, 643.833330f );
        that.bezier_curve_to( 415.899990f, 643.833330f, 394.746660f, 620.321330f, 426.966660f, 646.766670f );
        that.bezier_curve_to( 426.966660f, 646.766670f, 444.027990f, 670.774930f, 445.233320f, 674.900000f );
        that.bezier_curve_to( 445.233320f, 674.900000f, 430.534660f, 632.054670f, 424.033320f, 627.966670f );
        that.bezier_curve_to( 424.033320f, 627.966670f, 436.401320f, 574.561330f, 496.833320f, 597.433330f );
        that.bezier_curve_to( 496.833320f, 597.433330f, 506.801320f, 622.668000f, 513.233320f, 595.700000f );
        that.bezier_curve_to( 513.233320f, 595.700000f, 532.027990f, 586.294670f, 548.433320f, 626.766670f );
        that.bezier_curve_to( 548.433320f, 626.766670f, 554.321320f, 606.828000f, 553.099990f, 602.766670f );
        that.bezier_curve_to( 553.099990f, 602.766670f, 563.121320f, 604.481330f, 561.899990f, 602.766670f );
        that.bezier_curve_to( 561.899990f, 602.766670f, 581.307990f, 609.174670f, 583.099990f, 607.966670f );
        that.bezier_curve_to( 583.099990f, 607.966670f, 593.041320f, 617.974670f, 593.633320f, 612.633330f );
        that.bezier_curve_to( 593.633320f, 612.633330f, 607.121320f, 616.801330f, 604.166650f, 611.566670f );
        that.bezier_curve_to( 604.166650f, 611.566670f, 617.094650f, 634.401600f, 617.633320f, 639.700000f );
        that.line_to( 621.233320f, 619.166670f );
        that.line_to( 624.166650f, 623.300000f );
        that.bezier_curve_to( 624.166650f, 623.300000f, 626.481320f, 612.108000f, 625.366650f, 610.366670f );
        that.bezier_curve_to( 624.134650f, 608.588000f, 654.641320f, 620.321330f, 661.633320f, 650.766670f );
        that.line_to( 664.566650f, 663.166670f );
        that.bezier_curve_to( 664.566650f, 663.166670f, 673.414650f, 641.441600f, 671.099980f, 635.566670f );
        that.bezier_curve_to( 671.099980f, 635.566670f, 678.694650f, 636.747870f, 679.233320f, 643.166670f );
        that.bezier_curve_to( 679.233320f, 643.166670f, 685.147980f, 609.174670f, 678.166650f, 600.366670f );
        that.bezier_curve_to( 678.166650f, 600.366670f, 684.561320f, 599.201330f, 686.299980f, 604.500000f );
        that.line_to( 686.299980f, 593.966670f );
        that.bezier_curve_to( 686.299980f, 593.966670f, 696.881320f, 595.094670f, 696.833320f, 591.566670f );
        that.bezier_curve_to( 696.833320f, 591.566670f, 703.334650f, 585.708000f, 706.299980f, 592.766670f );
        that.bezier_curve_to( 706.299980f, 592.766670f, 688.081320f, 541.121340f, 715.099980f, 569.300000f );
        that.bezier_curve_to( 715.099980f, 569.300000f, 725.627980f, 585.121330f, 720.299980f, 557.566670f );
        that.bezier_curve_to( 715.067980f, 529.974670f, 709.201320f, 527.628000f, 716.299980f, 527.033340f );
        that.bezier_curve_to( 716.299980f, 527.033340f, 717.414650f, 521.761340f, 714.433320f, 519.433340f );
        that.bezier_curve_to( 711.547980f, 517.068000f, 716.299980f, 519.433340f, 716.299980f, 519.433340f );
        that.bezier_curve_to( 716.299980f, 519.433340f, 723.281320f, 525.281340f, 715.633320f, 493.033340f );
        that.bezier_curve_to( 715.633320f, 493.033340f, 725.041320f, 495.361340f, 707.499980f, 452.500000f );
        that.bezier_curve_to( 707.499980f, 452.500000f, 711.547980f, 449.014670f, 705.633320f, 436.633340f );
        that.bezier_curve_to( 705.633320f, 436.633340f, 717.414650f, 443.148000f, 721.499980f, 440.766670f );
        that.bezier_curve_to( 721.499980f, 440.766670f, 720.934650f, 438.454670f, 716.299980f, 432.633340f );
        that.bezier_curve_to( 716.299980f, 432.633340f, 684.561320f, 352.213340f, 714.433320f, 384.500010f );
        that.bezier_curve_to( 714.433320f, 384.500010f, 731.861320f, 404.354670f, 722.433320f, 370.900010f );
        that.bezier_curve_to( 722.433320f, 370.900010f, 709.111980f, 335.700010f, 710.299980f, 329.433340f );
        that.line_to( 80.299998f, 363.166670f );
        that.fill();

        // Main tiger body stroke
        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );
        that.set_line_width( 1.466667f );
        that.move_to( 80.299998f, 363.166670f );
        that.bezier_curve_to( 80.986931f, 372.032010f, 82.435998f, 381.666670f, 84.966665f, 386.233340f );
        that.bezier_curve_to( 84.966665f, 386.233340f, 79.706798f, 404.428010f, 92.566664f, 423.833340f );
        that.bezier_curve_to( 92.566664f, 423.833340f, 92.026531f, 434.348000f, 94.433331f, 439.033340f );
        that.bezier_curve_to( 94.433331f, 439.033340f, 100.240130f, 451.361340f, 107.233330f, 452.500000f );
        that.bezier_curve_to( 112.976530f, 453.484000f, 125.770260f, 457.985340f, 140.166660f, 460.100000f );
        that.bezier_curve_to( 140.166660f, 460.100000f, 165.360000f, 480.694670f, 160.700000f, 499.433340f );
        that.bezier_curve_to( 160.700000f, 499.433340f, 160.080000f, 523.521340f, 154.833330f, 525.833340f );
        that.bezier_curve_to( 154.833330f, 525.833340f, 171.813330f, 509.441340f, 157.766660f, 534.100000f );
        that.line_to( 151.233330f, 561.700000f );
        that.bezier_curve_to( 151.233330f, 561.700000f, 188.826660f, 529.974670f, 165.900000f, 556.900000f );
        that.line_to( 151.233330f, 595.033330f );
        that.bezier_curve_to( 151.233330f, 595.033330f, 180.026660f, 568.108000f, 169.500000f, 580.366670f );
        that.line_to( 164.833330f, 593.300000f );
        that.bezier_curve_to( 164.833330f, 593.300000f, 228.133330f, 553.441340f, 182.966660f, 596.900000f );
        that.bezier_curve_to( 182.966660f, 596.900000f, 194.693330f, 591.574670f, 201.099990f, 595.700000f );
        that.bezier_curve_to( 201.099990f, 595.700000f, 211.119990f, 593.921330f, 209.899990f, 596.233330f );
        that.bezier_curve_to( 209.899990f, 596.233330f, 179.440000f, 611.521330f, 174.166660f, 638.500000f );
        that.bezier_curve_to( 174.166660f, 638.500000f, 186.480000f, 623.841330f, 181.766660f, 639.700000f );
        that.line_to( 182.433330f, 656.633330f );
        that.bezier_curve_to( 182.433330f, 656.633330f, 188.240000f, 625.014530f, 187.633330f, 680.100000f );
        that.bezier_curve_to( 187.633330f, 680.100000f, 215.813330f, 653.761470f, 198.833330f, 684.233330f );
        that.line_to( 198.833330f, 708.900000f );
        that.bezier_curve_to( 198.833330f, 708.900000f, 221.093330f, 684.854670f, 211.766660f, 703.566660f );
        that.bezier_curve_to( 211.766660f, 703.566660f, 226.373330f, 690.721330f, 220.566660f, 713.033330f );
        that.bezier_curve_to( 220.566660f, 713.033330f, 219.333330f, 728.268260f, 225.766660f, 711.833330f );
        that.bezier_curve_to( 225.766660f, 711.833330f, 249.253330f, 666.961470f, 240.433330f, 705.433330f );
        that.bezier_curve_to( 240.433330f, 705.433330f, 239.279990f, 733.547860f, 246.299990f, 711.833330f );
        that.bezier_curve_to( 246.299990f, 711.833330f, 246.906660f, 727.094800f, 260.433330f, 737.700000f );
        that.bezier_curve_to( 260.433330f, 737.700000f, 258.639990f, 663.147870f, 277.366660f, 715.966660f );
        that.line_to( 283.233330f, 739.966660f );
        that.bezier_curve_to( 283.233330f, 739.966660f, 287.386660f, 726.508260f, 286.833330f, 718.900000f );
        that.bezier_curve_to( 286.833330f, 718.900000f, 308.506660f, 694.828130f, 298.566660f, 730.633330f );
        that.bezier_curve_to( 298.566660f, 730.633330f, 320.826660f, 697.174930f, 316.166660f, 716.500000f );
        that.bezier_curve_to( 316.166660f, 716.500000f, 304.986660f, 740.001600f, 307.366660f, 747.033330f );
        that.bezier_curve_to( 307.366660f, 747.033330f, 331.973330f, 696.001600f, 333.766660f, 693.700000f );
        that.bezier_curve_to( 333.766660f, 693.700000f, 330.799990f, 755.842700f, 346.699990f, 703.033330f );
        that.bezier_curve_to( 346.699990f, 703.033330f, 354.853320f, 720.641600f, 350.699990f, 727.033330f );
        that.bezier_curve_to( 350.699990f, 727.033330f, 362.479990f, 715.361460f, 361.366660f, 710.633330f );
        that.bezier_curve_to( 361.366660f, 710.633330f, 368.053320f, 698.641600f, 372.166660f, 718.633330f );
        that.bezier_curve_to( 372.166660f, 718.633330f, 374.799990f, 732.374930f, 377.099990f, 727.700000f );
        that.bezier_curve_to( 377.099990f, 727.700000f, 383.013320f, 762.882810f, 384.833320f, 729.433330f );
        that.bezier_curve_to( 384.833320f, 729.433330f, 387.119990f, 709.494800f, 376.566660f, 692.500000f );
        that.bezier_curve_to( 376.566660f, 692.500000f, 377.733320f, 687.788000f, 373.633320f, 681.966670f );
        that.bezier_curve_to( 373.633320f, 681.966670f, 393.573320f, 713.601600f, 382.966660f, 671.300000f );
        that.bezier_curve_to( 382.966660f, 671.300000f, 399.441320f, 683.094800f, 401.233320f, 683.033330f );
        that.bezier_curve_to( 401.233320f, 683.033330f, 381.253320f, 649.068270f, 394.166660f, 656.100000f );
        that.bezier_curve_to( 394.166660f, 656.100000f, 386.533320f, 640.854670f, 412.966660f, 658.500000f );
        that.bezier_curve_to( 412.966660f, 658.500000f, 389.466660f, 634.988000f, 415.233320f, 649.033330f );
        that.bezier_curve_to( 415.233320f, 649.033330f, 427.014660f, 658.454670f, 415.899990f, 643.833330f );
        that.bezier_curve_to( 415.899990f, 643.833330f, 394.746660f, 620.321330f, 426.966660f, 646.766670f );
        that.bezier_curve_to( 426.966660f, 646.766670f, 444.027990f, 670.774930f, 445.233320f, 674.900000f );
        that.bezier_curve_to( 445.233320f, 674.900000f, 430.534660f, 632.054670f, 424.033320f, 627.966670f );
        that.bezier_curve_to( 424.033320f, 627.966670f, 436.401320f, 574.561330f, 496.833320f, 597.433330f );
        that.bezier_curve_to( 496.833320f, 597.433330f, 506.801320f, 622.668000f, 513.233320f, 595.700000f );
        that.bezier_curve_to( 513.233320f, 595.700000f, 532.027990f, 586.294670f, 548.433320f, 626.766670f );
        that.bezier_curve_to( 548.433320f, 626.766670f, 554.321320f, 606.828000f, 553.099990f, 602.766670f );
        that.bezier_curve_to( 553.099990f, 602.766670f, 563.121320f, 604.481330f, 561.899990f, 602.766670f );
        that.bezier_curve_to( 561.899990f, 602.766670f, 581.307990f, 609.174670f, 583.099990f, 607.966670f );
        that.bezier_curve_to( 583.099990f, 607.966670f, 593.041320f, 617.974670f, 593.633320f, 612.633330f );
        that.bezier_curve_to( 593.633320f, 612.633330f, 607.121320f, 616.801330f, 604.166650f, 611.566670f );
        that.bezier_curve_to( 604.166650f, 611.566670f, 617.094650f, 634.401600f, 617.633320f, 639.700000f );
        that.line_to( 621.233320f, 619.166670f );
        that.line_to( 624.166650f, 623.300000f );
        that.bezier_curve_to( 624.166650f, 623.300000f, 626.481320f, 612.108000f, 625.366650f, 610.366670f );
        that.bezier_curve_to( 624.134650f, 608.588000f, 654.641320f, 620.321330f, 661.633320f, 650.766670f );
        that.line_to( 664.566650f, 663.166670f );
        that.bezier_curve_to( 664.566650f, 663.166670f, 673.414650f, 641.441600f, 671.099980f, 635.566670f );
        that.bezier_curve_to( 671.099980f, 635.566670f, 678.694650f, 636.747870f, 679.233320f, 643.166670f );
        that.bezier_curve_to( 679.233320f, 643.166670f, 685.147980f, 609.174670f, 678.166650f, 600.366670f );
        that.bezier_curve_to( 678.166650f, 600.366670f, 684.561320f, 599.201330f, 686.299980f, 604.500000f );
        that.line_to( 686.299980f, 593.966670f );
        that.bezier_curve_to( 686.299980f, 593.966670f, 696.881320f, 595.094670f, 696.833320f, 591.566670f );
        that.bezier_curve_to( 696.833320f, 591.566670f, 703.334650f, 585.708000f, 706.299980f, 592.766670f );
        that.bezier_curve_to( 706.299980f, 592.766670f, 688.081320f, 541.121340f, 715.099980f, 569.300000f );
        that.bezier_curve_to( 715.099980f, 569.300000f, 725.627980f, 585.121330f, 720.299980f, 557.566670f );
        that.bezier_curve_to( 715.067980f, 529.974670f, 709.201320f, 527.628000f, 716.299980f, 527.033340f );
        that.bezier_curve_to( 716.299980f, 527.033340f, 717.414650f, 521.761340f, 714.433320f, 519.433340f );
        that.bezier_curve_to( 711.547980f, 517.068000f, 716.299980f, 519.433340f, 716.299980f, 519.433340f );
        that.bezier_curve_to( 716.299980f, 519.433340f, 723.281320f, 525.281340f, 715.633320f, 493.033340f );
        that.bezier_curve_to( 715.633320f, 493.033340f, 725.041320f, 495.361340f, 707.499980f, 452.500000f );
        that.bezier_curve_to( 707.499980f, 452.500000f, 711.547980f, 449.014670f, 705.633320f, 436.633340f );
        that.bezier_curve_to( 705.633320f, 436.633340f, 717.414650f, 443.148000f, 721.499980f, 440.766670f );
        that.bezier_curve_to( 721.499980f, 440.766670f, 720.934650f, 438.454670f, 716.299980f, 432.633340f );
        that.bezier_curve_to( 716.299980f, 432.633340f, 684.561320f, 352.213340f, 714.433320f, 384.500010f );
        that.bezier_curve_to( 714.433320f, 384.500010f, 731.861320f, 404.354670f, 722.433320f, 370.900010f );
        that.bezier_curve_to( 722.433320f, 370.900010f, 709.111980f, 335.700010f, 710.299980f, 329.433340f );
        that.stroke();

        // Key orange color sections from original tiger
        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 0.8f, 0.45098039215686275f, 0.14901960784313725f, 1.0f );
        that.move_to( 710.299980f, 329.700010f );
        that.bezier_curve_to( 711.173320f, 329.958670f, 714.407980f, 331.606670f, 716.299980f, 333.966670f );
        that.bezier_curve_to( 716.299980f, 333.966670f, 726.214650f, 349.866670f, 718.566650f, 322.900010f );
        that.bezier_curve_to( 718.566650f, 322.900010f, 705.094650f, 280.640010f, 718.033320f, 297.033340f );
        that.bezier_curve_to( 718.033320f, 297.033340f, 726.801320f, 307.626670f, 722.166650f, 287.700010f );
        that.bezier_curve_to( 716.439980f, 263.586680f, 712.699980f, 254.233340f, 712.699980f, 254.233340f );
        that.bezier_curve_to( 712.699980f, 254.233340f, 729.734650f, 261.280010f, 690.433320f, 203.166680f );
        that.line_to( 703.366650f, 208.500010f );
        that.bezier_curve_to( 703.366650f, 208.500010f, 674.587980f, 150.400010f, 642.966650f, 142.766680f );
        that.line_to( 631.233320f, 133.966680f );
        that.bezier_curve_to( 631.233320f, 133.966680f, 687.494650f, 78.240014f, 668.699980f, 24.233348f );
        that.bezier_curve_to( 668.699980f, 24.233348f, 658.747980f, 16.640015f, 644.699980f, 30.100015f );
        that.bezier_curve_to( 644.699980f, 30.100015f, 635.281320f, 37.173348f, 626.433320f, 34.766681f );
        that.bezier_curve_to( 626.433320f, 34.766681f, 581.307990f, 36.586681f, 578.433320f, 36.633348f );
        that.bezier_curve_to( 575.441320f, 36.586678f, 524.401320f, -17.973317f, 428.166660f, 7.833349f );
        that.bezier_curve_to( 428.166660f, 7.833349f, 420.561320f, 10.773349f, 414.166660f, 9.033349f );
        that.bezier_curve_to( 414.166660f, 9.033349f, 387.119990f, -14.453317f, 315.499990f, 19.033348f );
        that.bezier_curve_to( 315.499990f, 19.033348f, 300.879990f, 21.920015f, 298.566660f, 21.966682f );
        that.bezier_curve_to( 296.186660f, 21.920012f, 292.079990f, 21.920012f, 280.299990f, 31.300015f );
        that.bezier_curve_to( 268.613330f, 40.693348f, 268.026660f, 41.866681f, 265.099990f, 44.233348f );
        that.bezier_curve_to( 265.099990f, 44.233348f, 241.039990f, 60.640014f, 234.033330f, 61.833347f );
        that.bezier_curve_to( 234.033330f, 61.833347f, 216.986660f, 71.200014f, 210.566660f, 85.833347f );
        that.line_to( 205.233330f, 87.566680f );
        that.bezier_curve_to( 205.233330f, 87.566680f, 202.906660f, 98.186680f, 202.299990f, 99.966680f );
        that.bezier_curve_to( 202.299990f, 99.966680f, 195.280000f, 105.226680f, 194.166660f, 113.433350f );
        that.bezier_curve_to( 194.166660f, 113.433350f, 181.200000f, 122.240010f, 181.766660f, 128.633350f );
        that.bezier_curve_to( 181.766660f, 128.633350f, 179.440000f, 136.320010f, 178.300000f, 143.300010f );
        that.bezier_curve_to( 178.300000f, 143.300010f, 167.706660f, 150.400010f, 168.833330f, 154.500010f );
        that.bezier_curve_to( 168.833330f, 154.500010f, 157.733330f, 175.040010f, 159.500000f, 185.033340f );
        that.bezier_curve_to( 159.500000f, 185.033340f, 150.106660f, 184.426680f, 146.033330f, 187.966680f );
        that.bezier_curve_to( 146.033330f, 187.966680f, 144.826660f, 194.986680f, 142.433330f, 195.566680f );
        that.bezier_curve_to( 142.433330f, 195.566680f, 138.373330f, 197.333340f, 141.900000f, 203.166680f );
        that.bezier_curve_to( 141.900000f, 203.166680f, 139.546660f, 207.306680f, 138.966660f, 209.700010f );
        that.bezier_curve_to( 138.966660f, 209.700010f, 140.133330f, 213.760010f, 133.633330f, 221.966680f );
        that.bezier_curve_to( 133.633330f, 221.966680f, 124.293200f, 249.546680f, 127.233330f, 257.166680f );
        that.bezier_curve_to( 127.233330f, 257.166680f, 127.813600f, 264.213340f, 123.766660f, 266.500010f );
        that.bezier_curve_to( 123.766660f, 266.500010f, 118.426530f, 265.973340f, 130.700000f, 283.566680f );
        that.bezier_curve_to( 130.700000f, 283.566680f, 131.919730f, 285.333340f, 127.233330f, 288.900010f );
        that.bezier_curve_to( 127.233330f, 288.900010f, 102.000000f, 294.133340f, 98.433331f, 318.233340f );
        that.bezier_curve_to( 98.433331f, 318.233340f, 78.533331f, 339.893340f, 78.566665f, 347.566670f );
        that.bezier_curve_to( 78.533335f, 350.900010f, 78.930665f, 355.516010f, 79.899998f, 362.233340f );
        that.bezier_curve_to( 79.899998f, 362.233340f, 79.119731f, 374.508010f, 119.633330f, 375.700010f );
        that.bezier_curve_to( 160.080000f, 376.854670f, 710.299980f, 329.700010f, 710.299980f, 329.700010f );
        that.fill();

        // Additional orange color sections from original tiger
        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 0.8f, 0.45098039215686275f, 0.14901960784313725f, 1.0f );
        that.move_to( 101.100000f, 362.500010f );
        that.bezier_curve_to( 64.453065f, 304.693340f, 85.633331f, 387.433340f, 85.633331f, 387.433340f );
        that.bezier_curve_to( 98.480264f, 437.868000f, 288.566660f, 382.766670f, 288.566660f, 382.766670f );
        that.bezier_curve_to( 288.566660f, 382.766670f, 536.134650f, 338.133340f, 552.566650f, 332.233340f );
        that.bezier_curve_to( 568.987990f, 326.400010f, 708.566650f, 335.833340f, 708.566650f, 335.833340f );
        that.line_to( 700.433320f, 311.166670f );
        that.bezier_curve_to( 605.361320f, 243.093340f, 577.201320f, 277.120010f, 557.233320f, 271.300010f );
        that.bezier_curve_to( 537.307990f, 265.386680f, 540.827990f, 279.466680f, 536.166650f, 280.633340f );
        that.bezier_curve_to( 531.441320f, 281.813340f, 473.947990f, 245.440010f, 464.566660f, 246.633340f );
        that.bezier_curve_to( 455.174660f, 247.786680f, 418.006660f, 212.952010f, 439.899990f, 259.566680f );
        that.bezier_curve_to( 463.387990f, 309.386670f, 354.266660f, 317.013340f, 329.633330f, 300.633340f );
        that.bezier_curve_to( 304.986660f, 284.160010f, 340.166660f, 327.566670f, 340.166660f, 327.566670f );
        that.bezier_curve_to( 367.173320f, 356.906670f, 316.699990f, 332.233340f, 316.699990f, 332.233340f );
        that.bezier_curve_to( 266.266660f, 313.493340f, 231.066660f, 351.040010f, 226.433330f, 352.233340f );
        that.bezier_curve_to( 221.679990f, 353.386670f, 214.639990f, 358.080010f, 213.499990f, 348.633340f );
        that.bezier_curve_to( 212.293330f, 339.306670f, 201.278660f, 314.812010f, 154.833330f, 353.433340f );
        that.bezier_curve_to( 125.466660f, 377.734670f, 105.233330f, 345.433340f, 105.233330f, 345.433340f );
        that.line_to( 101.100000f, 362.500010f );
        that.fill();

        // More orange gradient sections
        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 0.9098039215686274f, 0.5019607843137255f, 0.22745098039215686f, 1.0f );
        that.move_to( 466.433320f, 249.166680f );
        that.bezier_curve_to( 457.094660f, 250.348010f, 419.889320f, 215.530680f, 441.899990f, 262.100010f );
        that.bezier_curve_to( 466.187990f, 313.706670f, 356.187990f, 319.573340f, 331.499990f, 303.166670f );
        that.bezier_curve_to( 306.906660f, 286.721340f, 342.166660f, 330.100010f, 342.166660f, 330.100010f );
        that.bezier_curve_to( 369.094660f, 359.468010f, 318.699990f, 334.766670f, 318.699990f, 334.766670f );
        that.bezier_curve_to( 268.186660f, 316.054670f, 232.986660f, 353.601340f, 228.299990f, 354.766670f );
        that.bezier_curve_to( 223.599990f, 355.948010f, 216.559990f, 360.640010f, 215.366660f, 351.300010f );
        that.bezier_curve_to( 214.213330f, 341.868010f, 203.390660f, 317.617340f, 156.700000f, 355.966670f );
        that.bezier_curve_to( 125.574000f, 381.388010f, 105.766660f, 349.966670f, 105.766660f, 349.966670f );
        that.line_to( 101.100000f, 364.766670f );
        that.bezier_curve_to( 64.427065f, 306.373340f, 86.566665f, 391.833340f, 86.566665f, 391.833340f );
        that.bezier_curve_to( 99.440664f, 442.349340f, 290.433330f, 385.300010f, 290.433330f, 385.300010f );
        that.bezier_curve_to( 290.433330f, 385.300010f, 538.054650f, 340.694670f, 554.433320f, 334.766670f );
        that.bezier_curve_to( 570.907990f, 328.961340f, 709.233320f, 338.233340f, 709.233320f, 338.233340f );
        that.line_to( 701.099980f, 312.900010f );
        that.bezier_curve_to( 606.107980f, 244.800010f, 579.121320f, 279.681340f, 559.233320f, 273.833340f );
        that.bezier_curve_to( 539.227990f, 267.948010f, 542.747990f, 282.028010f, 538.033320f, 283.166680f );
        that.bezier_curve_to( 533.361320f, 284.373340f, 475.867990f, 248.000010f, 466.433320f, 249.166680f );
        that.fill();

        // Key black strokes from original tiger
        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );
        that.set_line_width( 1.466667f );
        that.move_to( 139.766660f, 459.833340f );
        that.line_to( 172.033330f, 466.766670f );
        that.stroke();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );
        that.set_line_width( 1.466667f );
        that.move_to( 213.499990f, 697.433330f );
        that.bezier_curve_to( 213.499990f, 697.433330f, 212.733330f, 692.333330f, 199.500000f, 707.700000f );
        that.stroke();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );
        that.set_line_width( 1.466667f );
        that.move_to( 221.499990f, 704.766660f );
        that.bezier_curve_to( 221.499990f, 704.766660f, 224.466660f, 695.266660f, 214.966660f, 701.833330f );
        that.stroke();

        that.begin_path();
        that.set_color( canvas_ity::stroke_style, 0.0f, 0.0f, 0.0f, 1.0f );
        that.set_line_width( 1.466667f );
        that.move_to( 300.699990f, 717.300000f );
        that.bezier_curve_to( 300.699990f, 717.300000f, 302.933330f, 701.133330f, 286.033330f, 720.233330f );
        that.stroke();

        // Black detail spots from original tiger
        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 0.0f, 0.0f, 0.0f, 1.0f );
        that.move_to( 206.433330f, 429.700000f );
        that.bezier_curve_to( 206.433330f, 429.700000f, 214.053330f, 429.068000f, 212.299990f, 431.433340f );
        that.bezier_curve_to( 210.533330f, 433.761340f, 206.966660f, 432.633340f, 206.966660f, 432.633340f );
        that.line_to( 206.433330f, 429.700000f );
        that.fill();

        that.begin_path();
        that.set_line_width( 0.133333f );
        that.set_color( canvas_ity::fill_style, 0.0f, 0.0f, 0.0f, 1.0f );
        that.move_to( 251.633330f, 450.233340f );
        that.bezier_curve_to( 251.633330f, 450.233340f, 259.226660f, 449.601340f, 257.499990f, 451.966670f );
        that.bezier_curve_to( 255.706660f, 454.294670f, 252.166660f, 453.166670f, 252.166660f, 453.166670f );
        that.line_to( 251.633330f, 450.233340f );
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