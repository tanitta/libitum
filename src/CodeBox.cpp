#include "CodeBox.h"
namespace libitum{
	CodeBox::CodeBox(){
		genSounds = 3;
	};
	CodeBox::~CodeBox(){};
	
	void CodeBox::setup(int genInt){
		genInternal = genInt;
	};
	void CodeBox::update(){};
	void CodeBox::draw(){};
	
	void CodeBox::SetPos(ofPoint point){
		pos = point;
	};
	void CodeBox::SetScale(){};
	void CodeBox::SetKey(){};
}