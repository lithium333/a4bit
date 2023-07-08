#include <iostream>
#include <fstream>

uint8_t stuff[]={123,23,44};

int main(int argc, char* argv[])
{

std::fstream fi,fo;
if (argc<2) {
	return -1;
}
fi.open(argv[1],std::ios::in);
fo.open("hardcode.c",std::ios::out);
fo << "uint8_t audio[]={";

uint8_t cur,element=0;
bool firstelement=true;

while(fi.read((char*)&cur,1)) {
	if(firstelement) {
		firstelement=false;
	} else {
		fo << ",";
	}
	fo << ((int)cur);
	element++;
	if(element==16) {
		fo << std::endl;
		element=0;
	}
}

fo << "};" << std::endl;

return 0;
}
