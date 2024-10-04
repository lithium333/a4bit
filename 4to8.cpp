#include <iostream>
#include <fstream>
#include <cstdint>

int main(int argc, char* argv[]) {

std::fstream fi,fo;
fi.open("in4.raw",std::ios::in);
fo.open("out8.raw",std::ios::out);

uint8_t cur,decoded;

while(fi.read((char*)&cur,1)) {
	decoded=(cur/16)<<4;
	fo.write((char*)&decoded,1);
	decoded=(cur%16)<<4;
	fo.write((char*)&decoded,1);
}

fi.close();
fo.close();
return 0;
}
