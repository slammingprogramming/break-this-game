# Videos Folder

This folder contains video assets that may be used for cutscenes, trailers, or background animations within the game.

## Supported Video Formats

- **MP4 (.mp4)**: Widely supported video format, ideal for compatibility across platforms.
- **AVI (.avi)**: Another video format, less commonly used due to larger file sizes.

## How to Add Videos

1. Add your video files to this directory.
2. Ensure that the videos are optimized for performance to prevent lag during playback.
3. Reference the video files in your code where needed.

## Usage Example

To play a video in the game, use the following code snippet:

```cpp
#include "VideoPlayer.h"

// Play a video
VideoPlayer::play("assets/videos/MyVideo.mp4");

Replace "MyVideo.mp4" with the actual name of your video file.