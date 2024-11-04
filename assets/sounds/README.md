# Sounds Folder

This folder contains all audio files for the game, including sound effects, background music, and voiceovers.

## Supported Audio Formats

- **WAV (.wav)**: Uncompressed audio format, suitable for sound effects.
- **MP3 (.mp3)**: Compressed audio format, ideal for music tracks to save space.
- **OGG (.ogg)**: Open-source compressed audio format, also good for music and sound effects.

## How to Add Sounds

1. Place your audio files in this directory.
2. Ensure the files are licensed for use in the project.
3. Reference the audio files in your code to play sounds during the game.

## Usage Example

To play a sound effect, use the following code snippet:

```cpp
#include "AudioPlayer.h"

// Play a sound
AudioPlayer::play("assets/sounds/MySoundEffect.wav");

Make sure to replace "MySoundEffect.wav" with the actual filename of your sound file.