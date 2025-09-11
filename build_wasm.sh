#!/bin/bash

# Build script for WASM version of canvas_ity tiger demo

set -e

echo "Building canvas_ity WASM demo..."

# Create output directory
mkdir -p dist

# Compile with Emscripten
emcc wasm/tiger_wasm.cpp \
    -I. \
    -std=c++14 \
    -O2 \
    -s WASM=1 \
    -s EXPORTED_FUNCTIONS='["_init_tiger", "_render_tiger", "_get_image_data", "_get_width", "_get_height"]' \
    -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap", "getValue", "setValue", "HEAP8", "HEAP32"]' \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s MODULARIZE=1 \
    -s EXPORT_NAME='CanvasItyModule' \
    -s ENVIRONMENT='web' \
    --bind \
    -o dist/canvas_ity_tiger.js

echo "Build complete! Files generated:"
ls -la dist/

echo ""
echo "To serve the demo:"
echo "  cd dist && python3 -m http.server 8000"
echo "  Then open http://localhost:8000/tiger_demo.html"