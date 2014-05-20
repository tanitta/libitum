#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(255);
	for (int i = 0; i < 7; ++i)
	{
		chordBoxes.push_back(vector<libitum::ChordBox>());
		for (int j = 0; j < 3; ++j)
		{
			chordBoxes[i].push_back(libitum::ChordBox());
		}
	}
	cout<<chordBoxes.size()<<"\n";
	for (int i = 0; i < chordBoxes.size(); ++i)
	{
		for (int j = 0; j < chordBoxes[i].size(); ++j)
		{
			chordBoxes[i][j] = libitum::ChordBox();
			chordBoxes[i][j].SetPos(ofPoint(i*128,j*64));
		}
	}
	
	// scales.push_back(libitum::Scale("",{1,3,5,6,7,9,11}));
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	for (int i = 0; i < chordBoxes.size(); ++i)
	{
		for (int j = 0; j < chordBoxes[i].size(); ++j)
		{
			chordBoxes[i][j].draw();
		}
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

vector<int> testApp::GetScale(int index){
	vector< vector<int> > scales;
	scales.push_back(vector<int>());
	return scales[index];
};