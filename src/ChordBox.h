#include "ofMain.h"
namespace libitum{
	class ChordBox
	{
	public:
		ChordBox();
		~ChordBox();
		void setup(int genInt);
		void update();
		void draw();	
		
		void SetPos(ofPoint);
		void SetScale(vector<int> scale);
		void SetKey(int key);
		
		void mouseMoved(int x, int y );
		
		// string GetChordName();
		// void drawGenInt(int x, int y);
		
		int genSounds;
		int genInternal;
		int sizeW, sizeH;
		ofPoint pos;
	};
}