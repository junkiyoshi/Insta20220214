#pragma once
#include "ofMain.h"

class Actor {
public:
	Actor(vector<glm::vec3>& location_list, vector<vector<int>>& next_index_list, vector<int>& destination_list);
	void update(const int& frame_span, vector<glm::vec3>& location_list, vector<vector<int>>& next_index_list, vector<int>& destination_list);
	glm::vec3 getLocation();
	glm::vec3 getPrevLocation();
	deque<glm::vec3> getLog();
	void setColor(ofColor color);
	ofColor getColor();
	float getNoiseSeed();

private:

	int select_index;
	int next_index;
	float noise_seed;

	glm::vec3 location;
	glm::vec3 prev_location;
	deque<glm::vec3> log;
	ofColor color;
};

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key) {};
	void keyReleased(int key) {};
	void mouseMoved(int x, int y) {};
	void mouseDragged(int x, int y, int button) {};
	void mousePressed(int x, int y, int button) {};
	void mouseReleased(int x, int y, int button) {};
	void windowResized(int w, int h) {};
	void dragEvent(ofDragInfo dragInfo) {};
	void gotMessage(ofMessage msg) {};

	glm::vec2 make_point(float theta);

	vector<glm::vec3> location_list;
	vector<vector<int>> next_index_list;
	vector<int> destination_list;

	vector<unique_ptr<Actor>> actor_list;
};