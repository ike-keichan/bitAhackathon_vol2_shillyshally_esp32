
/**
 * @file debug.ino
 * 第2回bitAHackathon,チームShilly Shallyのハードウェアプログラム
 * @brief デバッグに必要な関数を集めたファイル
 * @author Keisuke Ikeda
 * @date 2021.10.31
 */
#include <WiFi.h>

/**
 * @fn
 * httpリクエストの有無を判別する関数
 * @brief httpリクエストの有無を判別し、真偽値を返す関数
 * @param {http_status} httpのステータスコード
 * @return httpリクエストの有無を判別した真偽値
 */
bool has_request(bool http_status)
{
  return http_status > 0;
}


/**
 * @fn
 * センサーのデバッグ関数
 * @brief センサーの取得した値をシリアルモニタに表示する関数
 * @param {sensor_value} センサーの取得した値
 */
void debug_sensor(int sensor_value)
{
  Serial.print("sensor = ");
  Serial.println(sensor_value);
}


/**
 * @fn
 * httpのステータスコードのデバッグ関数
 * @brief httpのステータスコードをシリアルモニタに表示する関数
 * @param {http_status} httpのステータスコード
 */
void debug_http_status(int http_status)
{
  if (has_request(http_status))
  {
    Serial.print("http_status = ");
    Serial.println(http_status);
  }
  else
  {
    Serial.println("Error on HTTP request.");
  }
}

/**
 * @fn
 * httpのペイロードのデバッグ関数
 * @brief httpのペイロードをシリアルモニタに表示する関数
 * @param {http_status} httpのステータスコード
 * @param {http_payload}  httpのペイロード
 */
void debug_http_payload(int http_status, String http_payload)
{
  if (has_request(http_status))
  {
    Serial.print("http_payload = ");
    Serial.println(http_payload);
  }
  else
  {
    Serial.println("Not Found HTTP payload.");
  }
}
