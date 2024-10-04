#include <iostream>
#include <fstream>
#include <cstdint>

int main(int argc, char* argv[]) {

std::fstream fi,fo;
fi.open("in8.raw",std::ios::in);
fo.open("out4.raw",std::ios::out);

bool pos=true;
uint8_t cur,tupleq,part;

while(fi.read((char*)&cur,1)) {
	if(pos) {
		part=((uint8_t)cur)>>4;
		tupleq=(part<<4); // assign MSBs XXXX....
		pos=false;
	} else {
		part=((uint8_t)cur)>>4;
		tupleq+=part; // assign LSBs ....XXXX
		fo.write((char*)&tupleq,1);
		pos=true;
	}
}

fi.close();
fo.close();
return 0;
}
