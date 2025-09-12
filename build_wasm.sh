#!/bin/bash

# Build script for WASM version of canvas_ity library

set -e

echo "Building canvas_ity WASM library..."

# Create output directory
mkdir -p dist

# Compile with Emscripten
emcc wasm/canvas_ity_wasm.cpp \
    -I. \
    -std=c++14 \
    -O2 \
    -s WASM=1 \
    -s EXPORTED_FUNCTIONS='["_init_canvas", "_destroy_canvas", "_get_image_data", "_get_width", "_get_height", "_begin_path", "_move_to", "_line_to", "_close_path", "_fill", "_stroke", "_set_fill_color", "_set_stroke_color", "_set_line_width", "_set_line_join", "_set_line_cap", "_set_shadow_blur", "_set_shadow_offset", "_set_shadow_color", "_set_linear_gradient_fill", "_add_color_stop_fill", "_set_global_composite_operation", "_fill_rect", "_clear_canvas", "_set_line_dash", "_set_line_dash_offset"]' \
    -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap", "getValue", "setValue", "HEAP8", "HEAP32"]' \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s MODULARIZE=1 \
    -s EXPORT_NAME='CanvasItyModule' \
    -s ENVIRONMENT='web' \
    -s SINGLE_FILE=1 \
    -s DYNAMIC_EXECUTION=0 \
    --bind \
    -o dist/canvas_ity.js

echo "Build complete! Files generated:"
ls -la dist/

echo ""
echo "To serve the demo:"
echo "  cd dist && python3 -m http.server 8000"
echo "  Then open http://localhost:8000/star_demo.html"
