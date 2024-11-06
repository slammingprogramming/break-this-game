# Images Folder

This folder houses all image assets used in the game, including sprites, backgrounds, and UI elements.

## Image Formats

- **PNG (.png)**: Preferred format for images due to its lossless compression and transparency support.
- **JPEG (.jpg)**: Used for larger images where transparency is not required.

## How to Add Images

1. Add your image files to this directory.
2. Maintain consistent naming conventions for easy reference.
3. Reference the images in your code to use them in the game.

## Usage Example

To load an image for a sprite, you can use the following code:

```cpp
#include "ImageLoader.h"

// Load an image
Image myImage = ImageLoader::load("assets/images/MySprite.png");

Replace "MySprite.png" with the actual filename of your image.
