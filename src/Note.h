class Note {
    public :
    Note(float x, float y, float z, int spheresCount) {
        ofVec3f pos = ofVec3f(x, y, z).normalize() * 100;
        
        for (int i = 0; i < spheresCount; i++){
            ofSpherePrimitive sphere;
            sphere.setRadius(1);
            sphere.setPosition(x + i * 5, y + i * 5, z + i * 5);
            spheres.push_back(sphere);
        }
    }
    
    void setPosition(float x, float y, float z) {
        for (int i = 0; i < spheres.size(); i++) {
            spheres[i].setPosition(x + i * 5, y + i * 5, z + i * 5);
        }
    }
    void draw() {
        for (auto sphere : spheres) {
            sphere.draw();
        }
    }
    
    void update() {
        for(auto it = spheres.begin(); it != spheres.end(); it++ ) {
            auto pos = it->getPosition();
            it->setPosition(pos.x * 0.9, pos.y * 0.9, pos.z * 0.9 );
        }
    }
    
    private :
    vector<ofSpherePrimitive> spheres;
    
    
};
