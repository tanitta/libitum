#include "ofMain.h"
namespace libitum{
	class Scale
	{
	public:
		Scale(string,int[12]);
		~Scale();
		
		void SetName(string n);
		int* GetScale();
		
	private:
		string name;
		int* scale;
	};
}