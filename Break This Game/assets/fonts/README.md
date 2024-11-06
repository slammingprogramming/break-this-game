# Fonts Folder

This folder contains all the font files used in the game. Fonts are crucial for creating an engaging user interface and enhancing the overall aesthetic of the game.

## Supported Font Formats

- **TrueType Fonts (.ttf)**: Standard format for fonts, widely supported.
- **OpenType Fonts (.otf)**: Similar to TTF but includes additional features.

## How to Add Fonts

1. Place the font files in this directory.
2. Ensure the fonts are licensed for use in your project.
3. Update the relevant code to load and use the new fonts in the game.

## Usage Example

To load a font in your game, use the following code snippet:

```cpp
#include "FontLoader.h"

// Load a font
Font myFont = FontLoader::load("assets/fonts/MyFont.ttf");

Make sure to replace "MyFont.ttf" with the actual name of your font file.