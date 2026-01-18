# Waveshare PhotoPainter (ACeP RP2040) enhanced firmware

**PhotoPainter-ACeP-Enhanced** is a firmware for the Waveshare PhotoPainter (ACeP RP2040 version) e-paper photo frame. This enhanced version *enables automatic slideshow functionality with various operation modes, supporting custom image selection methods.*

The project is an adaptation of [@myevit](github.com/myevit/)/[PhotoPainter_B](github.com/myevit/PhotoPainter_B), the (B) version which uses a Spectra6 display, to the ACeP version of the PhotoPainter.

## Settings File Format

```txt
Mode=3
TimeInterval=720
CurrentIndex=1
```

For **additional information** about Features, Operation modes, Settings please refer to the original [Readme.md](https://github.com/myevit/PhotoPainter_B/blob/master/README.md) of the above Project.

## Image conversion

**Image conversion** can be done with this [Interactive image cropper and converter](https://github.com/one-step-behind/photopainter-cropper-converter). It also creates the fileList.txt which is needed for Mode 2 and the new Mode 3 introduced in this firmware.

## Firmware upload

The programming method is shown below:

1. connect the device to a USB port
2. Press RUN, then press BOOT, then release RUN, then release BOOT

A USB flash drive will pop up on the computer and you can drag the provided [Mode 3 UF2](https://github.com/one-step-behind/PhotoPainter-ACeP-Enhanced/tree/master/extra_uf2/Mode%203) file into it. The device reboots automatically. Press the NEXT button.

## License

This project is available under open-source licensing. Feel free to modify and enhance the code for your own use.
