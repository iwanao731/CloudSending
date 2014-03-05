//
//  Measure2.cpp
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#include "Measure2.h"

void Measure2::setup()
{
    // img
    img.loadImage("Measure2/img/0303-re_date03.png");
    longImg.loadImage("Measure2/img/longimage2.png");
    
    // アニメーション
    ofxAnimatableFloat f;
	f.animateFromTo( 0,100 ); //suitcase
	f.setDuration(2);
	f.setRepeatType( LOOP ); //PLAY_ONCE 
    pos = f;
    AnimCurve curve;
    curve = (AnimCurve) (EASE_IN_EASE_OUT);
    pos.setCurve( curve );
    curveNames = ofxAnimatable::getCurveName( curve );
    
    // font
    font.loadFont("font/avenir-next-medium-sc-latin-1.ttf", 110);
    font2.loadFont("font/avenir-next-medium-sc-latin-1.ttf", 80);
}

void Measure2::update()
{
    float dt = 1.0f / ofGetFrameRate();
    pos.update( dt );
}

void Measure2::draw()
{
    ofSetColor(255);
    longImg.draw(0, -1990+17*pos.val());
    //longImg.draw(0, -2200+25*pos.val());
    
    ofRect(116, 764, 365, -450);
    ofSetColor(0.0, 0.0, 200);
    
    ofRect(116, 764, 365, - pos.val()*4.5); //
    
    // 画像を描画
    ofEnableAlphaBlending();
    ofSetColor(255);
    img.resize(ofGetWidth(), ofGetHeight());
    img.draw(0, 0);
    ofDisableAlphaBlending();
    
    // number
    if(pos.hasFinishedAnimating() == true)
    {
        ofSetColor(255,75,145);
    }else{
        ofSetColor(190);
    }
    font.drawString(ofToString((int)((pos.val())*32/100)), 190, 530);
    
    // 残りの重さ
    int num = 32-pos.val()*32/100;
    font2.drawString(ofToString(num), 220, 930);
}

void Measure2::mousePressed(int x, int y, int button)
{
	changeState("Mission1");
}

string Measure2::getName()
{
	return "Measure2";
}