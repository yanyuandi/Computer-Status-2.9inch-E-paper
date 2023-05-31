#include <pgmspace.h>

const unsigned char cpu[364] = {
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0x1F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x0F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFE,0x0F,0x07,0x07,0xFF,0xF0,
0xFF,0xF0,0x00,0x00,0x00,0xFF,0xF0,
0xFF,0xE0,0x00,0x00,0x00,0x7F,0xF0,
0xFF,0xC0,0x00,0x00,0x00,0x3F,0xF0,
0xFF,0xC3,0xFF,0xFF,0xFC,0x1F,0xF0,
0xFF,0xC7,0xFF,0xFF,0xFE,0x1F,0xF0,
0xFF,0x87,0xFF,0xFF,0xFF,0x1F,0xF0,
0xE0,0x07,0xFF,0xFF,0xFF,0x00,0x70,
0xE0,0x07,0xFF,0xFF,0xFF,0x00,0x30,
0xE0,0x07,0xFF,0xFF,0xFF,0x00,0x30,
0xF0,0x07,0xFF,0xFF,0xFF,0x00,0x70,
0xFF,0x87,0xFE,0x07,0xFF,0x1F,0xF0,
0xFF,0x87,0xF8,0xF3,0xFF,0x1F,0xF0,
0xFF,0x87,0xF9,0xFF,0xFF,0x1F,0xF0,
0xFF,0x87,0xF3,0xFF,0xFF,0x1F,0xF0,
0xFF,0x87,0xF3,0xFF,0xFF,0x1F,0xF0,
0xE0,0x07,0xF3,0xFF,0xFF,0x00,0x30,
0xC0,0x07,0xF3,0xFF,0xFF,0x00,0x30,
0xE0,0x07,0xF3,0xFF,0xFF,0x00,0x30,
0xFF,0x87,0xF3,0xFF,0xFF,0x1F,0xF0,
0xFF,0x87,0xF9,0xFF,0xFF,0x1F,0xF0,
0xFF,0x87,0xF8,0xF3,0xFF,0x1F,0xF0,
0xFF,0x87,0xFC,0x03,0xFF,0x1F,0xF0,
0xFF,0x87,0xFF,0x9F,0xFF,0x1F,0xF0,
0xE0,0x07,0xFF,0xFF,0xFF,0x00,0x70,
0xE0,0x07,0xFF,0xFF,0xFF,0x00,0x30,
0xE0,0x07,0xFF,0xFF,0xFF,0x00,0x30,
0xF0,0x07,0xFF,0xFF,0xFF,0x00,0x70,
0xFF,0x87,0xFF,0xFF,0xFF,0x1F,0xF0,
0xFF,0xC7,0xFF,0xFF,0xFE,0x1F,0xF0,
0xFF,0xC1,0xFF,0xFF,0xFC,0x1F,0xF0,
0xFF,0xE0,0x00,0x00,0x00,0x3F,0xF0,
0xFF,0xE0,0x00,0x00,0x00,0x7F,0xF0,
0xFF,0xF8,0x00,0x00,0x00,0xFF,0xF0,
0xFF,0xFF,0x0F,0x0F,0x87,0xFF,0xF0,
0xFF,0xFF,0x1F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x0F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x9F,0x8F,0x8F,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
};

const unsigned char cpan[364] = {
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xF0,0x00,0x00,0x00,0xFF,0xF0,
0xFF,0xE0,0x00,0x00,0x00,0xFF,0xF0,
0xFF,0xC0,0x00,0x00,0x00,0x7F,0xF0,
0xFF,0xC7,0xFF,0xFF,0xFC,0x7F,0xF0,
0xFF,0xC7,0xFF,0xFF,0xFC,0x7F,0xF0,
0xFF,0xC7,0xFF,0xFF,0xFC,0x7F,0xF0,
0xFF,0xC7,0xFF,0xFF,0xFC,0x7F,0xF0,
0xFF,0xC7,0xFF,0xFF,0xFC,0x7F,0xF0,
0xFF,0xC7,0xFF,0xFF,0xFE,0x3F,0xF0,
0xFF,0xC7,0xFF,0xFF,0xFE,0x3F,0xF0,
0xFF,0x8F,0xFC,0x0F,0xFE,0x3F,0xF0,
0xFF,0x8F,0xF8,0xC7,0xFE,0x3F,0xF0,
0xFF,0x8F,0xF3,0xFF,0xFE,0x3F,0xF0,
0xFF,0x8F,0xF3,0xFF,0xFE,0x3F,0xF0,
0xFF,0x8F,0xE7,0xFF,0xFE,0x3F,0xF0,
0xFF,0x8F,0xE7,0xFF,0xFF,0x1F,0xF0,
0xFF,0x8F,0xE7,0xFF,0xFF,0x1F,0xF0,
0xFF,0x8F,0xE7,0xFF,0xFF,0x1F,0xF0,
0xFF,0x8F,0xF7,0xFF,0xFF,0x1F,0xF0,
0xFF,0x1F,0xF3,0xFF,0xFF,0x1F,0xF0,
0xFF,0x1F,0xF9,0xF7,0xFF,0x1F,0xF0,
0xFF,0x1F,0xF8,0x07,0xFF,0x1F,0xF0,
0xFF,0x1F,0xFE,0x1F,0xFF,0x8F,0xF0,
0xFF,0x1F,0xFF,0xFF,0xFF,0x8F,0xF0,
0xFF,0x1F,0xFF,0xFF,0xFF,0x8F,0xF0,
0xFF,0x1F,0xFF,0xFF,0xFF,0x8F,0xF0,
0xFF,0x3F,0xFF,0xFF,0xFF,0x8F,0xF0,
0xFE,0x10,0x00,0x00,0x00,0x8F,0xF0,
0xFE,0x00,0x00,0x00,0x00,0x0F,0xF0,
0xFE,0x00,0x00,0x00,0x00,0x07,0xF0,
0xFE,0x0F,0xFF,0xFF,0xFF,0x07,0xF0,
0xFE,0x3F,0xFF,0xFF,0xFF,0x87,0xF0,
0xFE,0x3F,0xFF,0xFF,0xFF,0xC7,0xF0,
0xFE,0x3F,0xFF,0xFF,0xFF,0xC7,0xF0,
0xFE,0x3F,0xFF,0xFE,0x03,0xC7,0xF0,
0xFE,0x3F,0xFF,0xFE,0x03,0x87,0xF0,
0xFE,0x0F,0xFF,0xFE,0x02,0x0F,0xF0,
0xFF,0x00,0x00,0x00,0x00,0x1F,0xF0,
0xFF,0x80,0x00,0x00,0x00,0x3F,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
};

const unsigned char gpu[364] = {
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0x1F,0x9F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x0F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x0F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x0F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x0F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x0F,0x8F,0xFF,0xF0,
0xFF,0xFE,0x0F,0x0F,0x07,0xFF,0xF0,
0xFF,0xF0,0x00,0x00,0x00,0xFF,0xF0,
0xFF,0xE0,0x00,0x00,0x00,0x7F,0xF0,
0xFF,0xC0,0x00,0x00,0x00,0x3F,0xF0,
0xFF,0xC3,0xFF,0xFF,0xFC,0x3F,0xF0,
0xFF,0x87,0xFF,0xFF,0xFE,0x1F,0xF0,
0xFF,0x87,0xFF,0xFF,0xFE,0x1F,0xF0,
0xE0,0x0F,0xFF,0xFF,0xFF,0x00,0x70,
0xC0,0x07,0xFF,0xFF,0xFE,0x00,0x30,
0xE0,0x07,0xFF,0xFF,0xFE,0x00,0x30,
0xE0,0x07,0xFF,0x07,0xFE,0x00,0x70,
0xFF,0x87,0xFC,0x01,0xFE,0x1F,0xF0,
0xFF,0x87,0xF8,0xFD,0xFE,0x1F,0xF0,
0xFF,0x87,0xF9,0xFF,0xFE,0x1F,0xF0,
0xFF,0x87,0xFB,0xFF,0xFE,0x1F,0xF0,
0xFF,0x87,0xF3,0xFF,0xFE,0x1F,0xF0,
0xE0,0x07,0xF3,0xE1,0xFE,0x00,0x70,
0xC0,0x07,0xF3,0xE1,0xFE,0x00,0x30,
0xE0,0x07,0xFB,0xFD,0xFE,0x00,0x70,
0xFF,0x87,0xF9,0xF9,0xFE,0x1F,0xF0,
0xFF,0x87,0xF8,0xF9,0xFE,0x1F,0xF0,
0xFF,0x87,0xFC,0x01,0xFE,0x1F,0xF0,
0xFF,0x87,0xFF,0x07,0xFE,0x1F,0xF0,
0xFF,0x87,0xFF,0xFF,0xFE,0x1F,0xF0,
0xE0,0x07,0xFF,0xFF,0xFE,0x00,0x70,
0xC0,0x07,0xFF,0xFF,0xFE,0x00,0x30,
0xE0,0x07,0xFF,0xFF,0xFE,0x00,0x70,
0xF0,0x07,0xFF,0xFF,0xFF,0x00,0xF0,
0xFF,0x87,0xFF,0xFF,0xFE,0x1F,0xF0,
0xFF,0x87,0xFF,0xFF,0xFE,0x1F,0xF0,
0xFF,0xC3,0xFF,0xFF,0xFC,0x3F,0xF0,
0xFF,0xC0,0x00,0x00,0x00,0x3F,0xF0,
0xFF,0xE0,0x00,0x00,0x00,0x7F,0xF0,
0xFF,0xF8,0x00,0x00,0x01,0xFF,0xF0,
0xFF,0xFF,0x0F,0x0F,0x0F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x0F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x0F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x0F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x0F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x0F,0x8F,0xFF,0xF0,
0xFF,0xFF,0x1F,0x9F,0x8F,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
};

const unsigned char neicun[364] = {
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xF8,0x00,0x00,0x00,0x00,0x01,0xF0,
0xF0,0x00,0x00,0x00,0x00,0x00,0xF0,
0xF0,0x00,0x00,0x00,0x00,0x00,0xF0,
0xF0,0x00,0x00,0x00,0x00,0x00,0xF0,
0xF0,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,
0xF0,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,
0xF0,0xE1,0xF0,0xF0,0xF8,0xF0,0xF0,
0xF0,0xE1,0xF0,0xF0,0xF8,0xF0,0xF0,
0xF0,0xE1,0xF0,0xF0,0xF8,0xF0,0xF0,
0xF0,0xE1,0xF0,0xF0,0xF8,0xF0,0xF0,
0xF0,0xE1,0xF0,0xF0,0xF8,0xF0,0xF0,
0xF0,0xE1,0xF0,0xF0,0xF8,0xF0,0xF0,
0xF0,0xE1,0xF0,0xF0,0xF8,0xF0,0xF0,
0xF0,0xE1,0xF0,0xF0,0xF8,0x70,0xF0,
0xF0,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,
0xF0,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,
0xF0,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,
0xF0,0x1F,0xFF,0xFF,0xFF,0x80,0xF0,
0xF0,0x0F,0xFF,0xFF,0xFF,0x00,0xF0,
0xF0,0x1F,0xFF,0xFF,0xFF,0x80,0xF0,
0xF0,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,
0xF0,0xFF,0xFF,0xFF,0xFF,0xF0,0xF0,
0xF0,0xE0,0x00,0x00,0x00,0xF0,0xF0,
0xF0,0xE0,0x00,0x00,0x00,0xF0,0xF0,
0xF0,0xE0,0x00,0x00,0x00,0xF0,0xF0,
0xF0,0x01,0x86,0x04,0x10,0x00,0xF0,
0xF0,0x01,0xC7,0x0E,0x38,0x00,0xF0,
0xF0,0x01,0x86,0x0E,0x38,0x00,0xF0,
0xF8,0x03,0xC7,0x0E,0x3C,0x01,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,
};