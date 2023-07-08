#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{

std::fstream fi,fo;

fi.open("4bit.raw",std::ios::in);
fo.open("out8.raw",std::ios::out);

int8_t pos=0;
uint8_t cur,decoded;

while(fi.read((char*)&cur,1)) {
	decoded=(cur/16)<<4;
	fo.write((char*)&decoded,1);
	decoded=(cur%16)<<4;
	fo.write((char*)&decoded,1);
}




return 0;
}
