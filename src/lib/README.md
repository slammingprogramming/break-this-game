# `src/lib` Folder

This folder contains reusable libraries, helper modules, and any modular code that supports the core game logic. The `src/lib` folder is designed to house common utilities, third-party libraries, or internally developed modules that can be shared across different parts of the game.

## Dependencies

**Break This Game** relies on several third-party libraries that provide essential functionality:

- **SFML**: Used for graphics, windowing, and input handling.
- **OpenAL**: For audio playback and sound manipulation.
- **GLM**: Provides mathematics and vector manipulation for graphics.
- **OpenGL**: The rendering API used for creating 2D and 3D graphics.
- **Lua**: Supports in-game scripting for dynamic gameplay features.
- **ENet**: Handles networking capabilities for multiplayer features.

## Folder Structure

Each library or module within `src/lib` can be organized into its own subdirectory, allowing for clean separation and easy management.

For example:
src/
└── lib/
    ├── graphics/
    │   ├── Graphics.h
    │   └── Graphics.cpp
    ├── physics/
    │   ├── Physics.h
    │   └── Physics.cpp
    └── utils/
        ├── MathUtils.h
        └── MathUtils.cpp

### Suggested Modules

Below are a few example modules that could be stored in `src/lib`:

- **graphics/**: Code related to rendering, sprites, and other graphical operations.
- **physics/**: Logic for collision detection, movement physics, and game object interactions.
- **utils/**: General utility functions, like mathematical operations, random number generation, or string manipulation.

## How to Use Modules in `src/lib`

Include headers from `src/lib` in other parts of the project to use shared functionalities. For example:

#include "lib/graphics/Graphics.h"
#include "lib/physics/Physics.h"
#include "lib/utils/MathUtils.h"

## Adding New Modules

When adding new modules to `src/lib`, follow these guidelines:
1. **Create a Subdirectory**: Add a new folder for the module (e.g., `src/lib/audio`).
2. **Header and Implementation Files**: Use separate header (`.h`) and implementation (`.cpp`) files.
3. **Documentation**: Include inline documentation in the code, and optionally add a `README.md` within each module’s folder to describe its purpose.

---

This organization helps keep the game’s core code clean and separates reusable logic for better modularity and maintainability.
