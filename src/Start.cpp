//
//  Start.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/04.
//
//

#include "Start.h"

void Start::setup()
{
    // img
    topImg.loadImage("Start/top.jpg");
    
    // e-font
    font.loadFont("font/avenir-next-medium-sc-latin-1.ttf", 50);
    title1  = "CLOUD";
    title2  = "SENDING";
    
    // j-font
    j_font.loadFont("font/KozGoPro-ExtraLight.otf", 20);
    sampleString = L"クラウドセンディング";
}

void Start::update()
{
	if (ofGetElapsedTimeMillis() - getSharedData().lastUpdate > 1000)
	{
		//getSharedData().counter--;
		getSharedData().lastUpdate = ofGetElapsedTimeMillis();
	}
}

void Start::draw()
{
    // img
    topImg.resize(ofGetWidth(), ofGetHeight());
    topImg.draw(0,0);
    
    // e-font
    font.drawString(title1, 50, 150);
    font.drawString(title2, 50, 210);
    
    // j-font
    j_font.drawString(sampleString, 50, 250);
    
	//getSharedData().font.drawString(ofToString(getSharedData().counter), ofGetWidth() >> 1, ofGetHeight() >> 1);
}

void Start::mousePressed(int x, int y, int button)
{
	changeState("Flight");
}

string Start::getName()
{
	return "Start";
}