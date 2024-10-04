#include <iostream>
#include <fstream>
#include <cstdint>

int main(int argc, char* argv[]) {

std::fstream fi,fo;
if (argc<2) {
	return -1;
}
fi.open(argv[1],std::ios::in);
fo.open("audiomem.h",std::ios::out);

fo << "uint8_t audio[]={";
uint8_t cur,element=0;
bool firstelement=true;
uint32_t cnt_by=0;
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
	cnt_by++;
}
fo << "};" << std::endl;
fo << "uint32_t asize=" << cnt_by << ";" << std::endl;

fi.close();
fo.close();
return 0;
}
