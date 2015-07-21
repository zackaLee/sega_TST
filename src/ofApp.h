#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <ofFileUtils.h>
#include <ofUtils.h>
#include <dirent.h>
#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void game_exe(string name);
		vector<string> patternUpdate(string name);
		vector<string> emuUpdate(vector<string> inf_res);
		ofDirectory game_search, info_search, info_dir, emu_dir;
		std::vector<string>data, info_result, emu_result, raw_emu_name, raw_info_name, emu_res;
		ofBuffer game_name_buffer;
		ofFile base_Name;
		string fileInfo,emu_info, game_selection, info_result2;
		string pattern;
		string emuInfo;
		int currentFile, currentFile1, infoNum, emuNum, raw_emu_num, raw_info_num, unit = 0;
		ifstream fin;
};
