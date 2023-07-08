#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{

std::fstream fi,fo;

fi.open("in8.raw",std::ios::in);
fo.open("4bit.raw",std::ios::out);

int8_t pos=0;
uint8_t cur,duplo,part1,part2;

while(fi.read((char*)&cur,1)) {
	if(pos==0) {
		duplo=0;
		part1=((uint8_t)cur)/16;
		duplo+=(part1<<4);
		pos=1;
	} else {
		part2=((uint8_t)cur)/16;
		duplo+=(part2);
		fo.write((char*)&duplo,1);
		pos=0;
	}
}




return 0;
}
