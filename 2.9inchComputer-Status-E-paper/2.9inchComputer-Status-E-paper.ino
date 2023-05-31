#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <GxEPD2_BW.h>
#include <U8g2_for_Adafruit_GFX.h>
#include "tubiao.h"

const char* ssid = "wifi账号";
const char* password = "wifi密码";

U8G2_FOR_ADAFRUIT_GFX u8g2Fonts;

GxEPD2_BW<GxEPD2_290, GxEPD2_290::HEIGHT> display(GxEPD2_290(/*CS*/ 15, /*DC*/ 4, /*RST*/ 2, /*BUSY*/ 5));  // GDEM029A01 屏幕尺寸和8266引脚设置


WiFiServer server(80);
void text16(const char* str, int16_t x, int16_t y, uint16_t fg_color = GxEPD_WHITE, uint16_t bg_color = GxEPD_BLACK)  //16px黑字
{
  bool r2l = false;
  int8_t baseline = 14;
  u8g2Fonts.setFontMode(1);
  u8g2Fonts.setFont(u8g2_font_wqy16_t_gb2312);
  u8g2Fonts.setBackgroundColor(bg_color);
  u8g2Fonts.setForegroundColor(fg_color);
  if (!r2l) {
    u8g2Fonts.drawUTF8(x, y + baseline, str);
  } else {
    int16_t w = u8g2Fonts.getUTF8Width(str);
    int16_t new_x = display.width() - x - w;
    u8g2Fonts.drawUTF8(new_x, y + baseline, str);
  }
}

void text12(const char* str, int16_t x, int16_t y, uint16_t fg_color = GxEPD_WHITE, uint16_t bg_color = GxEPD_BLACK)  //16px黑字
{
  bool r2l = false;
  int8_t baseline = 10;
  u8g2Fonts.setFontMode(1);
  u8g2Fonts.setFont(u8g2_font_wqy12_t_gb2312);
  u8g2Fonts.setBackgroundColor(bg_color);
  u8g2Fonts.setForegroundColor(fg_color);

  if (!r2l) {
    u8g2Fonts.drawUTF8(x, y + baseline, str);
  } else {
    int16_t w = u8g2Fonts.getUTF8Width(str);
    int16_t new_x = display.width() - x - w;
    u8g2Fonts.drawUTF8(new_x, y + baseline, str);
  }
}

void setup() {
  Serial.begin(115200);
  delay(10);
  display.init(115200, true, 2, false);
  display.setRotation(1);  //  0 是横向
  u8g2Fonts.begin(display);
  u8g2Fonts.setFontDirection(0);
  u8g2Fonts.setForegroundColor(GxEPD_BLACK);  // 设置前景色
  u8g2Fonts.setBackgroundColor(GxEPD_WHITE);  // 设置背景色

  display.fillScreen(GxEPD_WHITE);
  display.setFullWindow();
  display.firstPage();
  u8g2Fonts.setFont(u8g2_font_wqy16_t_gb2312);
  const char* line1 = "电脑状态实时监控";
  int16_t a = (u8g2Fonts.getUTF8Width(line1));
  text16(line1, (296 - a) / 2, 11, GxEPD_BLACK, GxEPD_WHITE);
  display.nextPage();
  display.powerOff();


  con();

  // 尝试连接WiFi网络
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    coned();
    delay(500);
    show();
  }

  Serial.println("");
  Serial.println("WiFi connected");

  // 打印IP地址
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // 启动TCP服务器
  server.begin();
  Serial.println("Server started");
}

void loop() {
  // 等待客户端连接
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // 读取客户端发送的数据
  while (client.connected()) {
    if (client.available()) {
      String json_data = client.readStringUntil('\r');
      Serial.println(json_data);

      // 解析JSON数据
      StaticJsonDocument<200> doc;
      DeserializationError error = deserializeJson(doc, json_data);
      if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.f_str());
        return;
      }

      // 打印解析后的数据
      const char* cpu = doc["cpu"];
      const char* memory = doc["memory"];
      const char* disk = doc["disk"];
      const char* gpu = doc["gpu"];
      String cpu1 = cpu;
      String cpu2 = "CPU:" + cpu1;
      const char* cpu3 = cpu2.c_str();

      String memory1 = memory;
      String memory2 = "内存使用:" + memory1;
      const char* memory3 = memory2.c_str();

      String disk1 = disk;
      String disk2 = "C盘余:" + disk1;
      const char* disk3 = disk2.c_str();

      String gpu1 = gpu;
      String gpu2 = "GPU:" + gpu1;
      const char* gpu3 = gpu2.c_str();

      Serial.print("CPU usage: ");
      Serial.println(cpu3);
      Serial.print("Memory usage: ");
      Serial.println(memory3);
      Serial.print("Disk usage: ");
      Serial.println(disk3);
      Serial.print("gpu_usage: ");
      Serial.println(gpu3);
      display.setPartialWindow(0, 93, 296, 35);
      display.firstPage();
      do {
        u8g2Fonts.setFont(u8g2_font_wqy16_t_gb2312);
        //const char* line1 = "WIFI连接中.......";
        //int16_t a = (u8g2Fonts.getUTF8Width(line1));
        text12(cpu3, 13, 99, GxEPD_BLACK, GxEPD_WHITE);
        text12(memory3, 77, 99, GxEPD_BLACK, GxEPD_WHITE);
        text12(gpu3, 168, 99, GxEPD_BLACK, GxEPD_WHITE);
        text12(disk3, 236, 99, GxEPD_BLACK, GxEPD_WHITE);
      } while (display.nextPage());
      display.powerOff();
    }
  }
}



void con() {
  display.setPartialWindow(0, 32, 296, 93);
  display.firstPage();
  do {

    u8g2Fonts.setFont(u8g2_font_wqy16_t_gb2312);
    const char* line1 = "WIFI连接中.......";
    int16_t a = (u8g2Fonts.getUTF8Width(line1));
    text16(line1, (296 - a) / 2, 65, GxEPD_BLACK, GxEPD_WHITE);

  } while (display.nextPage());
  display.powerOff();
}

void coned() {
  display.setPartialWindow(0, 32, 296, 93);
  display.firstPage();
  do {

    u8g2Fonts.setFont(u8g2_font_wqy16_t_gb2312);
    const char* line1 = "WIFI连接成功！";
    int16_t a = (u8g2Fonts.getUTF8Width(line1));
    text16(line1, (296 - a) / 2, 65, GxEPD_BLACK, GxEPD_WHITE);


  } while (display.nextPage());
  display.powerOff();
}

void show() {
  display.setPartialWindow(0, 0, 296, 128);
  display.firstPage();
  do {
    u8g2Fonts.setFont(u8g2_font_wqy16_t_gb2312);
    const char* line1 = "电脑状态实时监控";
    int16_t a = (u8g2Fonts.getUTF8Width(line1));
    text16(line1, (296 - a) / 2, 11, GxEPD_BLACK, GxEPD_WHITE);
    display.drawInvertedBitmap(12, 38, cpu, 52, 52, GxEPD_BLACK);
    display.drawInvertedBitmap(86, 38, neicun, 52, 52, GxEPD_BLACK);
    display.drawInvertedBitmap(159, 38, gpu, 52, 52, GxEPD_BLACK);
    display.drawInvertedBitmap(233, 38, cpan, 52, 52, GxEPD_BLACK);
    u8g2Fonts.setFont(u8g2_font_wqy12_t_gb2312);
    const char* line2 = "请电脑端运行Computer-Status.py";
    int16_t b = (u8g2Fonts.getUTF8Width(line2));
    text12(line2, (296 - b) / 2, 99, GxEPD_BLACK, GxEPD_WHITE);


  } while (display.nextPage());
  display.powerOff();
}
