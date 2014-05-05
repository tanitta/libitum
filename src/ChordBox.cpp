#include "ChordBox.h"
namespace libitum{
	ChordBox::ChordBox(){
		genSounds = 3;
		sizeH = 64;
		sizeW = 128;
	};
	ChordBox::~ChordBox(){};
	
	void ChordBox::setup(int genInt){
		genInternal = genInt;
	};
	void ChordBox::update(){};
	void ChordBox::draw(){
		ofFill();
		ofSetColor(255);
		ofRect(pos, sizeW, sizeH);
		
		ofNoFill();
		ofSetColor(0);
		ofRect(pos, sizeW, sizeH);
	};
	
	//boxの座標を設定．push後すぐに行うこと
	void ChordBox::SetPos(ofPoint point){
		pos = point;
	};
	
	//スケールを設定
	void ChordBox::SetScale(vector<int> scale){};
	
	//キーを設定
	void ChordBox::SetKey(int key){};
	
	//描画系
	void ChordBox::mouseMoved(int x, int y){
		//文字とか
		if (pos.x<x && x<pos.x+sizeW)
		{
			if (pos.y<y && y<pos.y+sizeH)
			{
				//黒くする描画
			}
		}
		
		//枠の表示
		
	}
}