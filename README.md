# a4bit: 4-bit raw audio manipultion tools (mono)
- 8to4: convert 8 bit raw to 4 bit raw
- 4to8: convert already existing 4 bit raw to 8 bit raw
- 4play: streams 4 bit raw to sdt::out (to be used in pipe with aplay, example: ./4play my4bitaudio.raw | aplay)
- byte2C: convert binary sample (2x4 or 8 bit) into uint8_t vector into .h file (to be used in MCU)
