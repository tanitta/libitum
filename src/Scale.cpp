#include "Scale.h"
namespace libitum{
	Scale::Scale(string n, int* array){
		name = n;
		scale = array;
	};
	Scale::~Scale(){};
	
	void Scale::SetName(string n){
		name = n;
	};
	
	int* Scale::GetScale(){
		return scale;
	};
}