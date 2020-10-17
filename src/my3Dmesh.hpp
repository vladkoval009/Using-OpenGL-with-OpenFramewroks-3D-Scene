
#include "ofMain.h"

using namespace glm;

class myEffectVBO {

public:
    
    myEffectVBO();
    
    void setup();
    void update();
    void draw(float x, float y, float z, int pixelsSize);
    
private:
    
    int w;
    int h;
        
    ofVboMesh meshVBO;
    ofVideoPlayer myVideo;
  
};

class lavaBall {
    
public:
    
    lavaBall();
    
    void setup(ofImage &myTex, float radius);
    void update(float amplitude, float time);
    void draw(float x, float y, float z);
    
private:
    
    ofIcoSpherePrimitive icoSphere; 
        
    // Wobbling Sphere
    ofMesh mesh;
    ofMesh originalMesh;
    
    int numVerts;
    int meshWidth, meshHeight;
    

    
    
};
