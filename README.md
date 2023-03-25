# iLOOP Marlin Configurator (iMC)

The iLOOP Marlin Configurator is a configurator for the 3D printing firmware [Marlin](https://marlinfw.org/). Marlin is configured using a huge C++ header file that is compiled into the Marlin build to allow for minimum build size. Altering this file can be tedious and error-prone, which may result in hardware failure or even fire hazards.

iMC simplifies the workflow of configuring Marlin by generating the header file from a set of parameters that can be set in a graphical user interface. This way, parameters can have different input types, fitted to their data type. iMC can also build and deploy Marlin without the need to use an extra tool like [Auto Build Marlin](https://marketplace.visualstudio.com/items?itemName=MarlinFirmware.auto-build).

### About iLOOP

The iLOOP project is a student project of ERIG e.V. and the [Institute of Space Systems](http://space-systems.eu/) of TU Braunschweig that aims to develop an infinite-Z belt 3D printer for additive manufacturing under vacuum conditions. This project is a tech demonstration for a future CubeSat mission. The project is funded by the [DLR](https://www.dlr.de/) as part of the small satellite initiative of the German Federal Government.

**Please note: Although iMC is developed for iLOOP, it can be used to configure any 3D printer that runs the Marlin firmware.**

![Screenshot of the iLOOP Marlin Configurator](https://github.com/SimonBuxx/iloop-marlin-configurator/blob/97cd8d14a3cd940f4694b89983cbd8b4dc9660bc/resources/imc_screenshot.png)
_Screenshot of iMC with an open Marlin workspace_

### Workflow and limitations

To keep track of the configuration, iMC uses a **configuration.json** file in the Marlin base folder. Currently, the software cannot import existing configurations. It starts with a default configuration that you can then fit to your specific needs. Also, iMC currently only generates [Marlin v2.1.2](https://github.com/MarlinFirmware/Marlin/releases/tag/2.1.2) configurations and is available for Windows only.

The usual workflow is as follows:
* Get Marlin v2.1.2, either from their [website](https://marlinfw.org/meta/download/) or directly from [GitHub](https://github.com/MarlinFirmware/Marlin/releases/tag/2.1.2). The folder called **Marlin-2.1.2** is the base folder.
* Open the folder as a workspace in iMC. The software will warn you that no iMC configuration is present. Click on "Save" to generate the configuration.json file containing the default configuration.
* You can then change the parameters on the different pages according to your needs and click on "Configure" to regenerate the **Configuration.h** file inside the folder **Marlin-2.1.2/Marlin**.
* To build and deploy Marlin, use the tools provided in the "Build" menu. See the notes below on how to setup [https://platformio.org/](PlatformIO), which is used to build Marlin.

Have a look around to get an overview over the features of iMC. There is a per-page code preview and you can move and resize all sub windows, as shown in the screenshot above.

### How do I setup PlatformIO?

To build Marlin, you need to install and setup [PlatformIO](https://platformio.org/). Follow the instructions on [their documentation](https://docs.platformio.org/en/latest/core/installation/index.html) and don't forget to set the PATH system variable. If you already have PlatformIO and Auto Build Marlin installed, it is sufficient to set the PATH variable so that the _platformio_ command is available from every directory.

### How do I build iMC?

iMC is developed on Windows using [Qt 6.4.0](https://www.qt.io/) and compiled using MinGW 64-bit. To build it yourself, open the main CMake file in Qt Creator, select the correct build environment and click on "Build". There are tutorials out there if you need assistance.

### Current Development State

There are currently not all configuration pages implemented. The unimplemented pages will be blank and the exported configuration will contain default values for the unimplemented parameters. Chances are that you won't need to alter these anyways but if you do, you will need to change them manually after every config generation. Please note that iMC is currently in an early stage and that needs of the iLOOP project are prioritized.

_DISCLAIMER: Erroneous configuration of a 3D printer may cause damages and/or personal injuries. As stated in the MIT license, the software is provided "as is" and I shall not be liable for any damages caused by this software. There may be bugs that can corrupt the configuration. Always check generated header files before using them._
