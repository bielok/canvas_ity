# Canvas_ity WASM Star Demo

This directory contains the WebAssembly distribution of the canvas_ity library with an interactive star demo.

![Canvas_ity WASM Star Demo](star_screenshot.png)

## About Canvas_ity

Canvas_ity is a tiny, single-header C++ library for rasterizing immediate-mode 2D vector graphics, closely modeled on the basic W3C HTML5 2D canvas specification. It provides high-quality rendering with gamma-correct blending, trapezoidal antialiasing, and bicubic resampling.

## Demo Features

- **Star Rendering**: Demonstrates the star example from the main canvas_ity README
- **JavaScript API**: All drawing code runs in JavaScript calling into the WASM library
- **General-purpose Library**: Reusable WASM library exposing the full canvas_ity API
- **Interactive Controls**: Render, clear, and download functionality
- **Real-time Rendering**: Immediate feedback from C++ code running in the browser

## Files

- `star_demo.html` - Interactive demo page showing JavaScript usage
- `canvas_ity.js` - Generated Emscripten JavaScript wrapper with full API
- `canvas_ity.wasm` - Compiled WebAssembly module with general-purpose canvas_ity library

## Usage Example

The WASM version provides a general-purpose canvas_ity library that can be called from JavaScript:

```javascript
// Initialize a canvas
canvas.init_canvas(256, 256);

// Build a star path using JavaScript calls to WASM
canvas.begin_path();
canvas.move_to(128.0, 28.0);
canvas.line_to(157.0, 87.0);
// ... more path commands

// Apply styles and effects
canvas.set_shadow_blur(8.0);
canvas.set_fill_color(1.0, 0.9, 0.2, 1.0);
canvas.fill();

// Get the rendered image data
const dataPtr = canvas.get_image_data();
```

## Building

From the project root:

```bash
./build_wasm.sh
```

This requires Emscripten to be installed.

## Running

Serve the `dist/` directory with any HTTP server:

```bash
cd dist
python3 -m http.server 8000
```

Then open `http://localhost:8000/star_demo.html` in your browser.

## Technical Details

The WASM version exposes a comprehensive canvas_ity API to JavaScript including:

### Path Building
- `begin_path()`, `move_to()`, `line_to()`, `close_path()`
- `bezier_curve_to()`, `arc()`, `rect()`

### Fill and Stroke
- `fill()`, `stroke()`, `fill_rect()`, `stroke_rect()`
- `set_fill_color()`, `set_stroke_color()`

### Line Styling
- `set_line_width()`, `set_line_cap()`, `set_line_join()`
- `set_line_dash()`, `set_line_dash_offset()`

### Effects
- `set_shadow_blur()`, `set_shadow_offset()`, `set_shadow_color()`
- `set_linear_gradient_fill()`, `add_color_stop_fill()`
- `set_global_composite_operation()`

### Canvas Management
- `init_canvas()`, `get_image_data()`, `get_width()`, `get_height()`

The demo uses `ImageData` and `putImageData()` to transfer rendered pixels from WASM memory to the HTML5 canvas.

## Features Demonstrated

The star demo showcases:
- Path building with move_to/line_to operations
- Drop shadows with blur and offset
- Fill and stroke operations with different colors
- Line styling (width, join style)
- Linear gradients with multiple color stops
- Composite blending operations (source_atop)
- High-quality antialiasing and gamma-correct rendering

This demonstrates how canvas_ity's full feature set is available through JavaScript calls to the WASM library.