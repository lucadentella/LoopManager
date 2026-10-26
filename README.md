# LoopManager

![](https://github.com/lucadentella/LoopManager/raw/main/board.png)

Reverse Loop Manager for DCC model layouts

![](https://img.shields.io/badge/license-CC--BY--NC--SA-green)

## Features :trophy:

 - 3 **monitored** zones
 - **prevents** short-circuits
 - **Arduino** based firmware

## :movie_camera: Tutorial
- [Youtube video](pending)

## :notebook: Documentation
 - [Part list](https://github.com/lucadentella/LoopManager/tree/main/board/partlist.md)

## :wrench: Board
- [Schematics, PDF](https://github.com/lucadentella/LoopManager/raw/main/board/loopmanager-sch.pdf)
- [Gerber files, ZIP](https://github.com/lucadentella/LoopManager/raw/main/board/loopmanager-pcb.zip)
- [Order PCB](https://www.pcbway.com/project/shareproject/TBD)

## :floppy_disk: Firmware
- [Arduino sketch](https://github.com/lucadentella/LoopManager/tree/main/firmware/LoopManager)
 
**Sensitivity**
Open the `config.h` file to change the sensitivity:
```
// Sensors
#define NUM_SAMPLES        5
#define SAMPLE_INTERVAL    10
#define HYSTERESIS_MS      200
```
