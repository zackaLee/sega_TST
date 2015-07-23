#include "ofApp.h"
	
//--------------------------------------------------------------
void ofApp::setup(){
  ofSetWorkingDirectoryToDefault();

	                           //Game search/sort
  //************************************************************//
	game_search.listDir("/home/mini/games/");                            //<-----This is for games directory
	//game_search.allowExt("sh");
	game_search.sort();
	game_search.getFiles();
  	currentFile = 0;
    currentFile1 = 0;
  //sets up a file to write to  
  	/**
    --->open .info file and seach for "bin" type within text 
    --->either way drop emulator path into .txt file with game path 
  	**/

                            //.info Search/Sort
  	//*****************code to get list of files **************//
  	//ofDirectory ;
  	info_dir.listDir("/usr/share/libretro/info/");        //<----This is for .info directory
    info_dir.sort();
  //	int numFiles = info_dir.listDir();
	//*************************loop through files/open and each file in list******************/
  /*	for(int i = 0; i<numFiles; ++i){
   		//open files
   		ifstream fin;
  		std::vector<string>data;
  		//pattern = "bin";
   		fin.open(info_dir.getPath(i).c_str() );
   	//*************************read open file and pattern match text***********************/
   	/*		while(fin!=NULL){
   				std::string str;
   				getline(fin, str);
   				data.push_back(str);
   				size_t found = str.find(pattern);      //<---was pattern[i];    
   				//print found
   					if (found != std::string::npos){
              //ofLogVerbose(info_dir.getPath(i));
              info_result.push_back(info_dir.getName(i));
   					}
   			}
   		
   	}
    //**************************sort and delete duplicates .info results vector*****************/
    /*sort(info_result.begin(),info_result.end());
    info_result.erase( unique(info_result.begin(), info_result.end()), info_result.end() );
   
    //**************************print result of parse**********************/
    /*for(int i = 0; i<(int)info_result.size(); i++){
      cout<<"yes! "<<info_result[i]<<" <------This" <<endl;
    }*/
    //copy vector to string
    //std::copy(info_result.begin(), info_result.end(), emuInfo);
  	



    /***************************Emulator search/sort*****************************************/
    /****************************************************************************************/
    emu_dir.listDir("/usr/lib/libretro/"); //<---This is for emulator directory
    emu_dir.sort();

    ofSetDataPathRoot("/home/mini/programs/_sega/");
    shPath = ofToDataPath("game.sh", true);
    //-- Path to data

    




    /*int emuNum = emu_dir.size();
    int infoNum = info_result.size();
    //extract just name of emu file
    for(int i = 0;i<emuNum; ++i){
      std::string name = emu_dir.getName(i);
      int lastIndex = name.find_last_of(".");
      string res = name.substr(0, lastIndex);
      raw_emu_name.push_back(res);
    //ofLogVerbose(name.substr(0, lastIndex));  
    }
    //extract just name of info file
    for(int i = 0; i<infoNum; ++i){
      std::string name = info_result[i];
      int lastIndex = name.find_last_of(".");
      string res = name.substr(0, lastIndex);
      raw_info_name.push_back(res);
      //ofLogVerbose(info_result[i].substr(0, lastIndex));
    }
    
    //Need to grab name of string in from info reult and match with raw emu name.
    for(int i = 0; i<infoNum; ++i){
        //ofLogVerbose("got emu_dir index");
        for(int p = 0; p<emuNum; ++p){
          //ofLogVerbose("Im in second loop");
          size_t got = raw_emu_name[p].find(raw_info_name[i]);
          if(got != string::npos){ 
            //ofLogVerbose("got_emu_name!");
            string path = emu_dir.getPath(p);        //get names of both
            emu_result.push_back(path);
          }else{
            //ofLogVerbose("dont got emu_name :(");
          }
      }
    }

    for(int i = 0; i<infoNum; ++i){
    cout<<"Emulator :"<<emu_result[i]<<" !\n";
    }

    
    ----Need to----
    --->get pattern from game selection
    --->put filename paths into .sh with game name
	**/

  
	
	
	

}
//--------------------------------------------------------------
void ofApp :: openChildApp(){



  

  char *shPathChar;
  shPathChar = new char[ shPath.length() + 1 ];

  strcpy(shPathChar, shPath.c_str() );
  //--
  int pid = fork();
  cout<<"pid:: "<<pid<<endl;

  switch(pid)
  {
    case -1:
      cout<<"fork() no work.\n"<<endl;
    case 0:
      execl(shPathChar, shPathChar, NULL);
    default:

      return;
  }  
}

//--------------------------------------------------------------
vector<string> ofApp::patternUpdate(string name){
  
  pattern = name;
  int numFiles = info_dir.listDir();
  for(int i = 0; i<numFiles; ++i){
      //open files
      ifstream fin;
      std::vector<string>data;
      //pattern = "bin";
      fin.open(info_dir.getPath(i).c_str() );
    //*************************read open file and pattern match text***********************/
        while(fin!=NULL){
          std::string str;
          getline(fin, str);
          data.push_back(str);
          size_t found = str.find(pattern);      //<---was pattern[i];    
          //print found
            if (found != std::string::npos){
              //ofLogVerbose(info_dir.getPath(i));
              info_result.push_back(info_dir.getName(i));
            }
        }
      
    }



//**************************sort and delete duplicates .info results vector*****************/
    sort(info_result.begin(),info_result.end());
    info_result.erase( unique(info_result.begin(), info_result.end()), info_result.end() );

    
    //std::copy(info_result.begin(), info_result.end(), emuInfo);


    for(int i = 0; i<(int)info_result.size(); i++){
      cout<<"yes! "<<info_result[i]<<" <------This" <<endl;
    }
    
    
    //
    //emuUpdate(info_result);
    return info_result;
    
    //-->Need to work out how to return vector values and pass them places
}


//--------------------------------------------------------------
//--------------------------------------------------------------
vector<string> ofApp::emuUpdate(vector<string> inf_res){
      

      emuNum = emu_dir.size();
      infoNum = inf_res.size();

     //extract just name of emu file
    for(int i = 0;i<emuNum; ++i){
      std::string name = emu_dir.getName(i);
      int lastIndex = name.find_last_of(".");
      string res = name.substr(0, lastIndex);
      raw_emu_name.push_back(res);
    //ofLogVerbose(name.substr(0, lastIndex));  
    }

    //ofLogVerbose("emu_name_stripped!");
    //extract just name of info file
    for(int i = 0; i<infoNum; ++i){
      std::string name = inf_res[i];
      int lastIndex = name.find_last_of(".");
      string res = name.substr(0, lastIndex);
      raw_info_name.push_back(res);
      //ofLogVerbose(info_result[i].substr(0, lastIndex));
    //ofLogVerbose("info_name_stripped");
      }
   //Need to grab name of string in from info reult and match with raw emu name.
      raw_info_num = raw_info_name.size();
      raw_emu_num = raw_emu_name.size();

    for(int i = 0; i<(int)raw_info_num; i++){
        //ofLogVerbose("got emu_dir index");
        for(int p = 0; p<(int)raw_emu_num; p++){
          //ofLogVerbose("Im in second loop");
          size_t got = raw_emu_name[p].find(raw_info_name[i]);
          if(got != std::string::npos){ 
            ofLogVerbose("got_emu_name!");      //get names of both
            emu_result.push_back(emu_dir.getPath(p));
            ofLogVerbose("emu_pushed!");
          }else{
           // ofLogVerbose("dont got emu");
          }
      }
      ofLogVerbose("outta loop 2");
    }

    for(int i = 0; i<infoNum; ++i){
    cout<<"Emulator :"<<emu_result[i]<<" !\n";
    }
    return emu_result;
 
}
//--------------------------------------------------------------
void ofApp::update(){
	 
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(ofColor::white);
  //use a switch case for options of menu?
  if(game_selection.size() > 0)
  {
    ofClear(ofColor::white);
    ofSetColor(ofColor::gray);
    for(int i = 0; i < (int)info_result.size(); i++)
    {
      if(i == currentFile1)
      {
        ofSetColor(ofColor::red);
      }else
       {
        ofSetColor(ofColor::black);
      }
     ofDrawBitmapString(emu_res[i], 50, i*20 + 50);
      }
  }
  else
  {
	ofSetColor(ofColor::gray);
	for(int i = 0; i < (int)game_search.size(); i++)
  {
		if(i == currentFile)
    {
				ofSetColor(ofColor::red);
		}else 
    {
				ofSetColor(ofColor::black);
		}

		fileInfo = "file" + ofToString(i + 1) + " = " + game_search.getName(i);
		ofDrawBitmapString(fileInfo, 50, i*20 + 50);

	  }
  }
}
//--------------------------------------------------------------//
void ofApp::keyPressed(int key){
  //-----------------------First Menu---------------------------//
  //------------------------------------------------------------//
    /*---employ a big switch case statement here-----*/

    switch(unit){
    case 0:

    if ( key == OF_KEY_DOWN && game_search.size() > 0)
    {
      currentFile++;
      currentFile %= game_search.size();
    }
    else if( key == OF_KEY_UP && game_search.size() > 0)
    {
      currentFile--;
      currentFile %= game_search.size();
    }
    else if(key == OF_KEY_RETURN && game_search.size() > 0)
    {
      //Takes current file and searches for suffix and passes it to .info update
      string g = game_search.getName(currentFile);
      int lastIndex = g.find_last_of(".");
      string name = g.substr(lastIndex + 1);
      ofLogVerbose(g.substr(lastIndex + 1));
      
      //Holds results from suffix parse on .info directory
      vector<string> inf_res = patternUpdate(name);
      
      //Holds results of .info and emulator name parse which is path to emulator
      emu_res = emuUpdate(inf_res);
      

      //reads string path to selected file to in games search to a .txt file
      //--->will need to setup bash script to copy
      //------------------------------------------------------
      game_selection = '"' + game_search.getName(currentFile) + '"';
      ofBuffer msg(game_selection.c_str(), game_selection.length());
      ofFile gameName(ofToDataPath("game_select.txt"), ofFile::WriteOnly);
      gameName.create();
      ofBufferToFile("game_select.txt", msg);
      msg.clear();
      gameName.close();
      ofLogVerbose("written out and closed first time");
      unit = 2;
    }
    break;
    case 2:
    //----------------------------Second Menu-------------------------------//
    //----------------------------------------------------------------------//
    if(key == OF_KEY_DOWN && emu_res.size() > 0)
    {
      currentFile1++;
      currentFile1 %= emu_res.size();
    }
    else if(key == OF_KEY_UP && emu_res.size() > 0){
      currentFile1--;
      currentFile1 %= emu_res.size();
    }
    else if(key == OF_KEY_RETURN && emu_res.size() > 0){
       emu_selection.push_back(emu_res[currentFile1]);
       
       ofFile emuName(ofToDataPath("emu_select.txt"), ofFile::WriteOnly);
       emuName.create();
       ofLogVerbose("file opened");

       ofBuffer msg(emu_res[currentFile1]);
       ofBufferToFile("emu_select.txt", msg);
       msg.clear();
       emuName.close();
       ofLogVerbose("Written to out and closed ,second Tiem!");
       unit = 3;
       /* Work on opening file here and putting emu_selection into it */
    }
    break;
    case 3:

    if(key == OF_KEY_RETURN && emu_res.size() > 0)
    {
      openChildApp();
    }
  }//end of switch 
}
    /* clean up and work out back buttons */

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}