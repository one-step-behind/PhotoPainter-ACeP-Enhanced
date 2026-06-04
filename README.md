# Waveshare PhotoPainter (ACeP RP2040) enhanced firmware

**PhotoPainter-ACeP-Enhanced** is a firmware for the Waveshare PhotoPainter (ACeP RP2040 version) e-paper photo frame. This enhanced version *enables automatic slideshow functionality with various operation modes, supporting custom image selection methods.*

This project adapts [@myevit](https://github.com/myevit/)'s [PhotoPainter_B](https://github.com/myevit/PhotoPainter_B) firmware (originally designed for the Spectra6 6-color e-paper display) to work with the ACeP version (7-color) of the Waveshare PhotoPainter.

The new version of **Mode 3** implements *affine permutation-based randomization*, ensuring each image appears exactly once per cycle, eliminating the duplicate selections that occurred with the previous random approach.

## Settings File Format (`settings.txt`)

```txt
Mode=3
TimeInterval=720
CurrentIndex=1
RefreshCycles=0
```

- **Mode**: Operation mode (0-3)
- **TimeInterval**: Time between image changes in minutes
- **CurrentIndex**: Current position in the image list (automatically updated)
- **RefreshCycles** stores the refresh cycles of the display. It is purely informational. Do not change unless you need to, e.g. set a value after tinkering with the device.

For **additional information** about features, operation modes and settings please refer to the original [Readme.md](https://github.com/myevit/PhotoPainter_B/blob/master/README.md) of the above project.

## State file format (`state.txt`)

The state.txt file stores the actual permutation. The format consists of:

- CRC32 of fileList.txt
- Total number of image files / line count of fileList.txt
- Iteration counter
- Multiplicative coefficient (coprime with N)
- Additive offset

```txt
1733624837,161,4,3,87
```

## Image conversion

**Image conversion** can be done with this [Interactive image cropper and converter](https://github.com/one-step-behind/photopainter-cropper-converter). It also creates the fileList.txt which is needed for Mode 2 and the new Mode 3 introduced in this firmware.

## Firmware upload

The programming method is shown below:

1. Connect the device to a USB port
2. Press RUN, then press BOOT
3. release RUN, then release BOOT

A USB flash drive will pop up on the computer and you can drag the pre-compiled [ACeP Enhanced UF2](https://github.com/one-step-behind/PhotoPainter-ACeP-Enhanced/tree/master/extra_uf2/Mode%203) file into it. The device reboots automatically. Then press the NEXT button.

## Recent Updates

- Replaced random index generation with affine permutation for Mode 3 and add CRC32 functionality

## License

This project is available under open-source licensing. Feel free to modify and enhance the code for your own use.
