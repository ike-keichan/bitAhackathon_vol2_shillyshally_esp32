/**
 * @file main.ino
 * 第2回bitAHackathon,チームShilly Shallyのハードウェアプログラム
 * @brief センサー値の変動を感知し、APIを叩くプログラム
 * @author Keisuke Ikeda
 * @date 2021.10.31
 */
#include <WiFi.h>
#include <HTTPClient.h>

//! 感圧センサーのピン番号
const int sensor_pin = 32;

//! 感圧センサーの値を読み取る閾値
const int threshold = 1000;

//! WiFiのSSID
const char* ssid = "*****";

//! WiFiのパスワード
const char* password =  "*****";

//! APIのエンドポイント
const String endpoint = "https://*****";

//! WiFiの接続状況の真偽値
const bool is_connected_wifi = WiFi.status() != WL_CONNECTED;

/**
 * @fn
 * セットアップ関数
 * @brief 起動時に実行される関数。各種設定を行う。
 */
void setup() 
{
  pinMode(sensor_pin, INPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (!is_connected_wifi)
  {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
}


/**
 * @fn
 * ループ関数
 * @brief 常時実行される関数。
 */
void loop() {
  int sensor_value = analogRead(sensor_pin);
  
  if (is_connected_wifi)
  {
    HTTPClient http;
    http.begin(endpoint);
    debug_sensor(sensor_value);
   
    if (sensor_value >= threshold)
    {
      int http_status = http.GET();
      debug_http_status(http_status);

      String http_payload = http.getString();
      debug_http_payload(http_status, http_payload);
    }
    
    http.end(); 
  }

  delay(200);
}
