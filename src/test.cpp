#include <SPI.h>
#include <stdint.h>

//Notes: 16 bit messages, SPOL = 0, CPHA = 0, MSB first

typedef uint16_t Msg;

enum CommandMsg {
  CMD_AX_X = 0 << 14,
  CMD_AX_Y = 1 << 14,
  CMD_AX = 1 << 14,
  CMD_A_REG_OP = 0 << 13,
  CMD_A_DATA_REQ = 1 << 13,
  CMD_A = 1 << 13,
  CMD_OC_OFFSET_CANCELLED = 0 << 12,
  CMD_OC_RAW_ACCEL = 1 << 12,
  CMD_OC = 1 << 12,
  CMD_SD_SIGNED_DATA = 0 << 2,
  CMD_SD_UNSIGNED_DATA = 1 << 2,
  CMD_SD = 1 << 2,
  CMD_ARM_PCM = 0 << 1,
  CMD_ARM_ARMING = 1 << 1,
  CMD_ARM = 1 << 1,
  CMD_P_ODD = 0 << 0,
  CMD_P_EVEN = 1 << 0,
  CMD_P = 1 << 0
};

enum ResponseMsg {
  RES_AX_X = 0 << 13,
  RES_AX_Y = 1 << 13,
  RES_AX = 1 << 13,
  RES_P_ODD = 0 << 12,
  RES_P_EVEN = 1 << 12,
  RES_P = 1 << 12,
  RES_STAT_INIT = 0x00 << 10,
  RES_STAT_NORMAL = 0x01 << 10,
  RES_STAT_ST_ACTIVE = 0x02 << 10,
  RESR_STAT_ERROR = 0x03 << 10,
  RES_STAT = 0x03 << 10,
  RES_DATA = 0x1FF
};

const int SS_PIN = 20;

void initSensor() {
  pinMode(SS_PIN, OUTPUT);
  SPI.begin();
}

Msg transfer(Msg data) {
  Msg res;
  digitalWrite(SS_PIN, LOW);
  res = (SPI.transfer(data << 8)) << 8;
  res |= SPI.transfer(data);
  digitalWrite(SS_PIN, HIGH);
}

void setup() {
  initSensor();
}

void loop() {
  Serial.println(transfer(CMD_AX_X & CMD_P_EVEN));
}

