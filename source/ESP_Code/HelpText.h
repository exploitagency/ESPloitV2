const char HelpText[] PROGMEM = R"=====(
<!DOCTYPE HTML>
<html>
<head><title>ESPloit Help Page</title></head>
<body>
<a href="/"><- BACK TO INDEX</a><br><br>
-----<br>
HELP<br>
-----<br>
<br>
ESPloit v2.0<br>
<br>
Created by Corey Harding<br>
www.LegacySecurityGroup.com / www.Exploit.Agency<br>
<br>
ESPloit is a WiFi controlled HID Keyboard Emulator similar to the USB Rubber Ducky by Hak5. This version was created specifically for the Cactus WHID which is a USB stick that utilizes an ESP-12S WiFi module with a serial connection to a 32u4 microcontroller. The device has 4M of flash storage more than capable of storing the firmware and a number of payloads. Unlike the Rubber Ducky this device has WiFi allowing the device to host its own access point or connect to an existing network. This allows users to upload and pick between payloads or even type out "live payloads" without uploading a file, and like the Rubber Ducky, ESPloit allows you to set up a payload to run upon insertion of the device. The device also supports upgrading the firmware over WiFi, deleting payloads, reformatting the file system, WiFi and basic configuration, and more.<br>
<br>
ESPloit is distributed under the MIT License. The license and copyright notice can not be removed and must be distributed alongside all future copies of the software.<br>
<br>
-----<br>
Initial Flashing<br>
-----<br>
Download and Install the Arduino IDE from http://www.Arduino.cc<br>
Open Arduino IDE.<br>
Go to File - Preferences. Locate the field "Additional Board Manager URLs:"<br>
Add "http://arduino.esp8266.com/stable/package_esp8266com_index.json" without quotes.<br>Click "Ok"<br>
Select Tools - Board - Boards Manager. Search for "esp8266".<br>
Install "esp8266 by ESP8266 community version 2.3.0". Click "Close".<br>
Select Sketch - Include Library - Manage Libraries. Search for "Json".<br>
Install "ArduinoJson by Benoit Blanchon version 5.11.0" and click "Close"<br>
The Arduino IDE is now configured and ready for the code.<br>
<br>
Use git to clone this repo: https://github.com/exploitagency/ESPloitV2.git<br>
or<br>
Download/extract the repo as a zip file: https://github.com/exploitagency/ESPloitV2/archive/master.zip<br>
<br>
Load the esp8266Programmer sketch from the flashing folder.<br>
Select Tools - Board - "LilyPad Arduino USB".<br>
Select the Port your device is connected to under Tools - Port.<br>
Upload the sketch.<br>
<br>
Open the ESP_Code sketch from the source folder.<br>
Select Tools - Board - "Generic ESP8266 Module".<br>
Select Tools - Flash Size - "4M (3M SPIFFS)".<br>
Select Sketch - "Export Compiled Binary".<br>
<br>
Now flash the firmware to the ESP-12S chip using one of the following tools.<br>
Linux: https://github.com/AprilBrother/esptool<br>
Windows: https://github.com/nodemcu/nodemcu-flasher<br>
<br>
NOTE: Do not try to connect to the access point or test anything yet, the device won't work until after the next step.<br>
<br>
Finally open the Arduino_32u4_code sketch from the source folder.<br>
Select Tools - Board - "LilyPad Arduino USB".<br>
Select the Port your device is connected to under Tools - Port.<br>
Upload the sketch.<br>
<br>
Your ESPloit is now ready to configure and or use.<br>
<br>
-----<br>
Initial configuration<br>
-----<br>
<br>
ESPloit by default creates an Access Point with the SSID "Exploit" with a password of "DotAgency".<br>
Connect to this access point and open a web browser pointed to "http://192.168.1.1"<br>
You are now greeted with the main menu of ESPloit. From here there are several options.<br>
<br>
Upload Payload: Upload a payload.txt file<br>
Choose Payload: Choose a payload to run<br>
Live Payload Mode: Type out or copy/paste a payload to run without uploading<br>
Configure ESPloit: Configure WiFi and basic settings<br>
Format File System: Format the file system<br>
Upgrade ESPloit Firmware: Upgrade the ESP-12S ESPloit firmware from a web browser<br>
Help: Brings up this help file<br>
<br>
The default administration username is "admin" and password "hacktheplanet". This username and password is used to Configure ESPloit or to Upgrade the Firmware.<br>
<br>
-----<br>
Resetting to default configuration/Recovering device<br>
-----<br>
<br>
Plug the device into your computer.<br>
Open the Arduino IDE.<br>
Select Tools - Board - "LilyPad Arduino USB".<br>
Select Tools - Port and the port the device is connected to.<br>
Select Tools - "Serial Monitor".<br>
Select "4800 baud".<br>
Now type in "ResetDefaultConfig:". Without the quotes but be sure to include the colon symbol.<br>
Click Send.<br>
You should now receive the following reply "Resetting configuration files back to default settings."<br>
The device has now been reset back to default settings.<br>
Connect to the Access Point with the SSID "Exploit" with a password of "DotAgency".<br>
Open a web browser pointed to "http://192.168.1.1"<br>
The default administration username is "admin" and password "hacktheplanet".<br>
<br>
-----<br>
Configure ESPloit<br>
-----<br>
<br>
Default credentials to access the configuration page:<br>
username "admin"<br>
password "hacktheplanet"<br>
<br>
WiFi Configuration<br>
<br>
Network Type<br>
Access Point Mode: Create a standalone access point(No Internet Connectivity-Requires Close Proximity)<br>
Join Existing Network: Join an existing network(Possible Internet Connectivity-Could use Device Remotely)<br>
<br>
Hidden: Choose whether or not to use a hidden SSID when creating an access point<br>
<br>
SSID: SSID of the access point to create or of the network you are choosing to join<br>
Password: Password of the access point which you wish to create or of the network you are choosing to join<br>
Channel: Channel of the access point you are creating<br>
<br>
IP: IP to set for ESPloit<br>
Gateway: Gateway to use, make it the same as ESPloit's IP if an access point or the same as the router if joining a network<br>
Subnet: Typically set to 255.255.255.0<br>
<br>
ESPloit Administration Settings:<br>
<br>
Username: Username to configure/upgrade ESPloit<br>
Password: Password to configure/upgrade ESPloit<br>
<br>
Payload Settings<br>
<br>
Delay Between Sending Lines of Code in Payload: Delay in milliseconds between sending lines from payload or when manually inserting a "DELAY" in the payload(Default: 2000)<br>
<br>
Automatically Deploy Payload Upon Insetion: Choose Yes or No to automatically deploy a payload when inserting the device<br>
<br>
Automatic Payload: Choose the location of the payload to run upon insertion<br>
<br>
-----<br>
Scripting a Payload<br>
-----<br>
<br>
ESPloit uses its own scripting language and not Ducky Script. Although using pure Ducky Script may be adopted in the future or other projects 32u4 sketches using Ducky Script can be adapted to work with ESPloit's ESP8266 sketch. Ducky scripts are adaptable though with minimal work. Examples of ESPloit's scripting language can be seen below.<br>
<br>
COMMANDS ARE CASE SENSITIVE! Do not insert any spaces after a command unless intentional and as part of a string, etc.<br>
<br>
Commenting code:<br>
--"Rem: Comment"<br>
--Set comments<br>
<br>
Set the deault delay for a specific payload:<br>
--"DefaultDelay:X"<br>
--Overrides the default delay set in the ESPloit configuration portal but only for this specific payload<br>
--Delay is in milliseconds and defined as the wait between sending lines in the payload<br>
--Example: "DefaultDelay:10000" will wait 10 seconds between sending each line in the payload<br>
<br>
Set a one time delay between sending lines in payload<br>
--"CustomDelay:X"<br>
--The default delay will still apply for all other lines except this one<br>
--Example: "CustomDelay:5000" will ignore the default delay for this line and waits 5 seconds before sending the next line in the payload<br>
<br>
To make a generic delay:<br>
-"Delay"<br>
--"Delay" would wait for The Default Delay x 2 before proceeding to next item in payload<br>
<br>
For individual keypresses or combinations of key presses:<br>
-"Press:X" or "Press:X+Y" or "Press:X+Y+Z" and so forth<br>
--Expects Decimal Key Code Values for X,Y,Z,etc<br>
--Sending the following "Press:131+114" with the device's USB plugged into a Windows machine would output KEY_LEFT_GUI(Windows_Key)+r thus launching the RUN prompt<br>
--List of modifier keys(GUI,ALT,CTRL,ETC) at https://www.arduino.cc/en/Reference/KeyboardModifiers<br>
--ASCII table lookup at http://www.asciitable.com/<br>
<br>
To type out strings of text:<br>
-"Print:XYZ" Types out "XYZ"<br>
--Sending the following via software serial "Print:www.Exploit.Agency" would type out "www.Exploit.Agency" on the machine connected via USB<br>
<br>
To type out strings of text and presses ENTER:<br>
-"PrintLine:XYZ" Types out "XYZ" then presses ENTER<br>
--Sending the following "PrintLine:www.Exploit.Agency" would type out "www.Exploit.Agency" on the machine connected via USB and then would press and release the ENTER key<br>
<br>
Move Mouse:<br>
--"MouseMoveUp:X", "MouseMoveDown:X", "MouseMoveLeft:X", "MouseMoveRight:X"<br>
--Valid range of values for X is 1-127<br>
--Moves mouse up, down, left, or right by X amount<br>
--X must be a number<br>
<br>
Mouse Click:<br>
--"MouseClickLEFT:", "MouseClickRIGHT:", "MouseClickMIDDLE:"<br>
--Clicks the LEFT, RIGHT, or MIDDLE mouse button<br>
--Case Sensitive<br>
<br>
-----<br>
Uploading a Payload<br>
-----<br>
<br>
Click browse and choose a payload to upload.<br>
<br>
Names should not contain any special characters and should stick to letters and numbers only.<br>
<br>
Names must be shorter than 21 characters. The SPIFFS file system used has a 31 character limit, 10 characters are used for the folder structure "/payloads/".<br>
<br>
You may save several characters by naming payloads without using an extension.<br>
<br>
-----<br>
Choose a Payload<br>
-----<br>
<br>
This is a list of all payloads that have been uploaded.<br>
<br>
You may click the payload name to see the contents of a payload.<br>
<br>
Click "Run Payload" to run the payload or click "Delete Payload" to delete the payload.<br>
<br>
The file size and filesystem information is also listed on this page.<br>
<br>
-----<br>
Live Payload Mode<br>
-----<br>
<br>
Here you may type out or copy/paste a payload to run without uploading.<br>
<br>
-----<br>
Format File System<br>
-----<br>
<br>
This will erase the contents of the SPIFFS file system including ALL Payloads that have been uploaded.<br>
Formatting may take up to 90 seconds.<br>
All current settings will be retained unless you reboot your device during this process.<br>
<br>
-----<br>
Upgrade ESPloit Firmare<br>
-----<br>
<br>
Authenticate using your username and password set in the configuration page.<br>
<br>
Default credentials to access the firmware upgrade page:<br>
username "admin"<br>
password "hacktheplanet"<br>
<br>
Select "Browse" choose the new firmware to be uploaded to the ESP-12S chip and then click "Upgrade".<br>
<br>
You will need to manually reset the device upon the browser alerting you that the upgrade was successful.<br>
<br>
If you are using this mode to swap the firmware loaded on the ESP-12S chip, and if the new firmware does not support this mode then you must reflash the ESP-12S manually by uploading the programmer sketch to the 32u4 chip and then flash the ESP-12S this way.
</body>
</html>
)=====";
