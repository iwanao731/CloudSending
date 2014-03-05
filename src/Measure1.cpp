//
//  Measure1.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/04.
//
//

#include "Measure1.h"

int start;
AnimCurve curve;

void Measure1::setup()
{
    // 文字の表示
    myFont.loadFont("font/KozGoPro-ExtraLight.otf", 20, true, true);
    sampleString = L"スーツケースを";
    sampleString2 = L"測量計に乗せてください";
    p1 = ofPoint(210, 200);
    p2 = ofPoint(150, 240);
    
    // 画像の表示
    img.loadImage("Measure1/img/suitcase_.png");
    
    // アニメーション
    start = 0;
	ofxAnimatableFloat f;
	f.animateFromTo( 0, 255 ); //suitcase
	f.setDuration(2);
	f.setRepeatType( LOOP );
    pos = f;
    curve = (AnimCurve) (EASE_IN_EASE_OUT + start);
    pos.setCurve( curve );
    curveNames = ofxAnimatable::getCurveName( curve );
    
}

void Measure1::update()
{
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		getSharedData().counter--;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
	}
    
    float dt = 1.0f / ofGetFrameRate();
    pos.update( dt );
    
}

void Measure1::draw()
{
    ofBackground(100);
    
    // 文字の描画
    ofSetColor(255);
    myFont.drawString(sampleString, p1.x, p1.y);
    myFont.drawStringAsShapes(sampleString2, p2.x, p2.y);
    
    // 画像を描画
    img.draw(150, 320);
    
    // 図形の描画
    ofRect(130, 800, 350, 30);
    
    ofPushMatrix();
    ofSetColor(ofColor(255), 0+pos.val());
    ofTranslate(250, 650);
    float x = 60;
    float y = 30;
    ofTriangle(x, x, x-y, x-y, x+y, x-y);
    
    ofTranslate(0, 50);
    ofSetColor(ofColor(255), 30+pos.val());
    ofTriangle(x, x, x-y, x-y, x+y, x-y);
    
    ofTranslate(0, 50);
    ofSetColor(ofColor(255), 60+pos.val());
    ofTriangle(x, x, x-y, x-y, x+y, x-y);
    
    ofPopMatrix();
    
}

void Measure1::mousePressed(int x, int y, int button)
{
	changeState("Measure2");
}

string Measure1::getName()
{
	return "Measure1";
}