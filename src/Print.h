//
//  Print.h
//  cloudSending
//
//  Created by NAOYAIWAMOTO on 2014/03/05.
//
//

#ifndef __cloudSending__Print__
#define __cloudSending__Print__

#include "ofxState.h"
#include "shareData.h"
#include "ofxAnimatableFloat.h"

class Print : public itg::ofxState<SharedData>
{
public:
    void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	string getName();
    
    ofImage bg1, bg2;
    ofImage reciept;
    
    // animation
    ofxAnimatableFloat pos;
    string curveNames;
    AnimCurve curve;

};

#endif /* defined(__cloudSending__Print__) */
