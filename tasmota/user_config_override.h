/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "E2D"               // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "048659569"            // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "192.168.1.122"         // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "mqtt"                 // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "e2d.mqtt"             // [MqttPassword] Optional password

// -- Syslog --------------------------------------
#undef  SYS_LOG_HOST
#define SYS_LOG_HOST      "192.168.1.122"         // [LogHost] (Linux) syslog host

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS     MY_IP                // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY        MY_GW                // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS            MY_DNS               // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!! 
#undef USER_TEMPLATE
  //#define USER_TEMPLATE "{\"NAME\":\"ESP-01S-RGB-LED-v1.0\",\"GPIO\":[255,255,7,255,0,0,0,0,0,0,0,0,0],\"FLAG\":0,\"BASE\":18}"  // [Template] Set JSON template
  //#define USER_TEMPLATE "{\"NAME\":\"ESP32-LCD\",\"GPIO\":[1,1,6400,1,1024,6720,0,0,33,1376,1,6368,1,1,736,672,0,640,608,704,0,7264,992,1,0,0,0,0,1,1,1,1,7584,0,0,7585],\"FLAG\":0,\"BASE\":1}"  // [Template] Set JSON template
  //#define USER_TEMPLATE "{\"NAME\":\"ESP32-CAM\",\"GPIO\":[4992,1,1,1,1,5088,1,1,1,1,1,1,1,1,5089,5090,0,5091,5184,5152,0,5120,5024,5056,0,0,0,0,4928,1,5094,5095,5092,0,0,5093],\"FLAG\":0,\"BASE\":1}"  // [Template] Set JSON template
  //#define USER_TEMPLATE "{\"NAME\":\"ESP32-TTGO-OLED\",\"GPIO\":[0,1,416,1,640,1/,1,1,1,1,1,608,1024,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1,1,7584,0,0,7585],\"FLAG\":0,\"BASE\":1}"  // [Template] Set JSON template
  //#define USER_TEMPLATE "{\"NAME\":\"ESP32-DOIT\",\"GPIO\":[1,1,420,1,640,1376,1,1,1,1,1,608,1024,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,1],\"FLAG\":0,\"BASE\":1}"  // [Template] Set JSON template
  //#define USER_TEMPLATE "{\"NAME\":\"ESP32-DOIT-ili9488\",\"GPIO\":[1,1,416,1,800,1,1,1,672,704,736,6432,1,1,1,1,0,640,608,1,0,1,1,992,0,0,0,0,1,1,1,1,7584,0,0,7585],\"FLAG\":0,\"BASE\":1}"  // [Template] Set JSON template
  //#define USER_TEMPLATE "{\"NAME\":\"ESP32-HUA-ili9488\",\"GPIO\":[1,1,416,1,800,1,1,1,672,704,736,6432,1,1,1,1,0,640,608,1,0,1,1,992,0,0,0,0,1,1,1,1,7584,0,0,7585],\"FLAG\":0,\"BASE\":1}"  // [Template] Set JSON template
  //#define USER_TEMPLATE "{\"NAME\":\"ESP32-HUA-OLED\",\"GPIO\":[1,1,416,1,2688,1,1,1,1,224,0,1,1,1,2656,2592,0,640,608,1,0,1,1,1,0,0,0,0,1,1,1,1,7584,0,0,7585],\"FLAG\":0,\"BASE\":1}"  // [Template] Set JSON template

  //#define USER_TEMPLATE "{\"NAME\":\"ESP32-KIT-ILI9341\",\"GPIO\":[1,1,992,1,6400,1376,1,1,672,704,736,6368,1,1,1,1,0,640,608,480,0,1,1,1,0,0,0,0,1,1,1,1,7584,0,0,7585],\"FLAG\":0,\"BASE\":1}"  // [Template] Set JSON template
  //#define USER_TEMPLATE "{\"NAME\":\"ESP32-DOIT-EPAPER_29\",\"GPIO\":[1,1,416,1,640,1,1,1,1,1,1,608,3840,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,1],\"FLAG\":0,\"BASE\":1}"  // [Template] Set JSON template
/*
#undef MQTT_TOPIC 
#define MQTT_TOPIC "ESP32-Display"

#undef MQTT_GRPTOPIC
#define MQTT_GRPTOPIC  "tasmotas-display"
*/

#define USE_UFILESYS
#define GUI_TRASH_FILE
#define GUI_EDIT_FILE
#define SHOW_SPLASH	

#define USE_DT_VARS
#define USE_DISPLAY
#define USE_DISPLAY_LVGL_ONLY
//#define USE_DISPLAY_SH1106  0x3C

#define JPEG_PICTS
#define USE_XPT2046
#define USE_TOUCH_BUTTONS
#define USE_SDCARD
#define USE_AWATCH

#define USE_APDS9960
#define USE_MLX90614            


#endif // _USER_CONFIG_OVERRIDE_H_