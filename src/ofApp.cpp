#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    
      // CAMERA SETTINGS
      cam.setAutoDistance(true);

      // IMAGES
      img.load("lava.jpg");
      img2.load("waves.jpg");
      img3.load("3.jpg");
      img4.load("deadland.jpg");
      img5.load("moon.tif");
    
      // SHADER
      shader2.load("myShader");
    
 
      //  tree.load("tree.ply"); I tried to add my model in .ply format and apply a Phong shader with the golden texture. For some reaoson whenever I tried to convert a model from .obj to .ply - the ply. refused to appear in my scene, weirdly I can preview a perfectly functioning model in xcode. The bunnt.ply is test model from the lab we did before. It loads just fine.

    //========================================================
    
    planeGround.mapTexCoordsFromTexture(img4.getTextureReference());
    
    //=========================================================

    // Setting up my classed here.

    obj.setup();
    mySphere.setup(img,40); // Add your own texture as an image & quickly change the radius of the sphere .
    myOtherSphere.setup(img5,20);

}

//--------------------------------------------------------------
void ofApp::update(){
    
  
    obj.update();
    mySphere.update(0.2,3); // Quickly change the amplitude & time!
    myOtherSphere.update(0.6,2);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
       ofEnableDepthTest();
       ofBackground(0);
       cam.begin();
    
       // My shader begins here.
    
        shader2.begin();
        shader2.setUniform1f("time", ofGetElapsedTimef() * 0.5);
        shader2.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
        shader2.setUniformTexture("tex", img2, 1);
    
    // Making the screen for the shader effect ( rotaing stormy clouds ).
    
    ofPushMatrix();
    planeBack.setPosition(0, 0, -250);
    planeBack.set(600, 500, 100, 100);
    planeBack.draw();
    ofPopMatrix();
          
    ofPushMatrix();
    ofRotateYDeg(90);
    planeRight.setPosition(0, 0, 300);
    planeRight.set(500, 500, 100, 100);
    planeRight.draw();
    ofPopMatrix();
          
    ofPushMatrix();
    ofRotateYDeg(-90);
    planeLeft.setPosition(0, 0, 300);
    planeLeft.set(500, 500, 100, 100);
    planeLeft.draw();
    ofPopMatrix();
    
    shader2.end();
    
    // The shader ends here.
    
    // Texturing the buttom plane with a simple texture.
    
    img4.getTextureReference().bind();
    
    ofPushMatrix();
    ofRotateXDeg(90);
    planeGround.setPosition(0, 0, 250);
    planeGround.set(600, 500, 100, 100);
    planeGround.draw();
    ofPopMatrix();
    
    img4.getTextureReference().unbind();
    
    
    // Building the screnn ends here.

    
    // Here I am calling my 3D effect class.
        
        ofPushMatrix();
        ofTranslate(300, 350, 230);
        ofRotateXDeg(90);
        obj.draw(1,1,3,2);
        ofPopMatrix();
     
        // Here I am calling my lavaBall class.
        img.getTexture().bind();
        mySphere.draw(0,0,0); // Change the position by entereing X,Y,Z coordinates.
        img.getTexture().unbind();
    
        // Drawing my other ball.
    
         img5.getTexture().bind();
         ofRotateXDeg(30);
         myOtherSphere.draw(-200, 100, -100);
         img5.getTexture().unbind();

        // One lonely tree.
//        ofTranslate(0, 100, 0);
//        ofScale(50,50,50);
//        tree.draw();
//        

    cam.end();

}

//--------------------------------------------------------------
