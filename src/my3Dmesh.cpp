#include "my3Dmesh.hpp"

//=======================================================


myEffectVBO::myEffectVBO(){
    
}

//--------------------------------------------------------------
void myEffectVBO::setup() {
        
    w = 600;
    h = 480;
    
  // Setup for a video file can be done below:
    
    myVideo.load("waves.mp4"); // Loading my video file for the VBO mesh.
    
    
  // Mesh drawing mode setting.
     meshVBO.setMode(OF_PRIMITIVE_POINTS);
    
 
}

//--------------------------------------------------------------

void myEffectVBO::update() {
    
         // Update video from the video file.
         myVideo.update();
    
         //=====================================================
         
         // Updating the video file frame.
         if (myVideo.isFrameNew()) {
             
             // Initialize the mesh
             meshVBO.clear();
             
             // Extract pixel information from pre-loaded video.
             ofPixels pixelsVBO;
             pixelsVBO = myVideo.getPixels();
             
             // Process pixel by pixel.
             for (int i = 0; i < w; i++) {
                 for (int j = 0; j < h; j++) {
                     
                     // Get the pixel RGB value.
                     float r = (float)pixelsVBO[j * myVideo.getWidth() * 3 + i * 3] / 255.0;
                     float g = (float)pixelsVBO[j * myVideo.getWidth() * 3 + i * 3 + 1] / 255.0;
                     float b = (float)pixelsVBO[j * myVideo.getWidth() * 3 + i * 3 + 2] / 255.0;
                     
                     // Calculate brightness from RGB
                     float brightness = (r + g + b) / 3.0f;
                     
                     // Set the position of the vertex from the brightness.
                     glm::vec3 vertex = glm::vec3(i - w, j - h, brightness * 255.0);
                     meshVBO.addVertex(vertex);
                     
                     // The color of the vertex uses the pixel value from the pre-loaded video  as it is.
                     ofFloatColor color = ofFloatColor(r, g, b, 0.3);
                     meshVBO.addColor(color);
                 }
             }
         }
    
         //=====================================================
    
}

//--------------------------------------------------------------
void myEffectVBO::draw(float x, float y, float z, int pixelsSize) {
    
    ofScale(x, y, z);
    glPointSize(pixelsSize);
    meshVBO.draw();
      
}

//==========================LAVA_BALL============================//

lavaBall::lavaBall(){
    
    
}

void lavaBall::setup(ofImage &myTex, float radius) {
    
       icoSphere.setResolution(3);
       icoSphere.setRadius(radius);

       // Getting texture coordinates per vertex to map an image to it.
       icoSphere.mapTexCoordsFromTexture(myTex.getTexture());

       mesh = icoSphere.getMesh();

       originalMesh = mesh;
    
}

void lavaBall::update(float amplitude, float time) {
    
         // Controlling all the verts.
         for(int i = 0; i < mesh.getNumVertices(); i++){

         // Using originalMesh inside the loop, if I continue usign "mesh" the whole scene will be unusable. Pushing the vertices out -> in with SINE. Scaling the the verts. PULSATING SPHERE!
             
            glm::vec3 vertex = originalMesh.getVertex(i);

            float amp = amplitude;
             
            // Multiplying by "time" makes the oscillations faster.
            float t = ofGetElapsedTimef() * time;

            // Phase controls the offset.
             float phase = ofMap(vertex.y, vertex.x, vertex.z, 0, PI, PI);

            // Scaling the vertex.
            vertex *= 2 + amp * sin(t + phase * 2);

            mesh.setVertex(i, vertex);


        }
}

void lavaBall::draw(float x, float y, float z) {
    
          ofTranslate(x, y, z);
          mesh.disableColors();
          mesh.draw();
}
