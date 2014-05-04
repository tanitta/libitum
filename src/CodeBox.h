#include "ofMain.h"
namespace libitum{
	class CodeBox
	{
	public:
		CodeBox();
		~CodeBox();
		void setup(int genInt);
		void update();
		void draw();	
		
		void SetPos(ofPoint);
		void SetScale();
		void SetKey();
		
		int genSounds;
		int genInternal;
		int sizeW, sizeH;
		ofPoint pos;
	};
}