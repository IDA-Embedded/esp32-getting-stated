# esp32-getting-stated
Simple and robust getting started project for esp32 mcu

# Working with the getting startet project

In order to get started, we need to download the example project onto our computer.
It is expected that the computer runs linux, preferable ubuntu 20 or newer. 

## Installing the basics
We will start out by executing the install script located in the tools folder, with the name 'install_requirements.sh'
Obviously we cannot simply install stuff without knowing what is included. A brief overview of what is installed in the script:

- We will install the newest version of cmake, and ninja. These tools are used to generate makefile which is used to compile the project.
- We will install some CI/CD tools, which is not used in the workshop, but could be used in the future.
- We will install stuff related to the esp32 SDK, this is also found in the getting started guide on espressif's page: 
( Link : https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/ )

In order to execute the script, open op a terminal in the root folder of the project and write 'sudo ./tools/install_requirements.sh'

## Installing the espressif SDK
Next up is downloading and installing the espressif SDK whitch we use to compile the esp32 target
Again looking inside the next install script called 'installESPIDF.sh' located in the tools folder, we can see what is going on:

- First we check if espressif SDK is already installed ( do the folder exist in /home/ ? )
- Then we clone the esp repository ( link https://github.com/espressif/esp-idf.git )
- Then execute espressifs install script

In order to execute the command, open up a terminal in the root folder of the project and write 'make getESPSDK'

## Compile the example project
At this point everything should have been setup correctly and we are ready to compile the example project.
We will be using the simple make command to achive this. 

In order to execute the command, open up a terminal in the root folder of the project and write 'make'

## Flash the project to the target
As the project is now compiled we just need to flash it to our esp32 target.
This will also be done through the make command by writing 'make flash_slow'
- We use the 'flash_slow" command when we are working with esp32Cams as they require a lower baudrate

In order to execute the command, open up a terminal in the root folder of the project and write 'make flash_slow'





