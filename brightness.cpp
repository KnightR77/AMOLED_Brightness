
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

float value_mapping(float val,
									float org_down,
									float org_up,
									float new_down,
									float new_up){
	if (val >= org_up){
		return new_up;
	}
	if (val <= org_down){
		return 0.25;
	}
	//std::cout<<(val/(org_up-org_down))<<std::endl;
	//std::cout<<(new_up-new_down)<<std::endl;

	return new_down + ((val/(org_up-org_down)) * (new_up-new_down));
}

float get_brightness(){
	float bns=-1;
	std::cout << "Specify a brightness level (0-100)" << std::endl;
	std::cin >> bns;
	bns = value_mapping(bns, 0, 100, 0.25, 1);
	return bns;
}


int main(){
	std::string cmd = "xrandr --output eDP-1 --brightness ";
	std::stringstream ss;
	float brtns = get_brightness();
	//std::cout<<brtns<<std::endl;
	ss << cmd << brtns;
	//std::cout << ss.str()<<std::endl;
	system(ss.str().c_str());
	return 0;
}
