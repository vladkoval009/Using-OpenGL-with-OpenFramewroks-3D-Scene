#pragma once

#include "ofMain.h"
#include "my3Dmesh.hpp"

using namespace glm;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        ofEasyCam cam;
        
        myEffectVBO obj;
        lavaBall mySphere;
        lavaBall myOtherSphere;
        
        ofImage img;
        ofImage img2;
        ofImage img3;
        ofImage img4;
        ofImage img5;
        
        ofMesh tree;

        ofShader shader2;
        
        ofPlanePrimitive  planeBack;
        ofPlanePrimitive  planeGround;
        ofPlanePrimitive  planeLeft;
        ofPlanePrimitive  planeRight;


};
