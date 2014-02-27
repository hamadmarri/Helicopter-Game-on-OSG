/*
	ScriptRunner
		Parses the script given through an istream and creates a list of actions to execute.
		Also tells the command to execute itself

		Credits: Tylor Froese, Brian Schwietzer

*/

#include <vector>
#include <fstream>
#include "Command.h"
#include "Render.h"


#ifndef SCRIPTRUNNER_H
#define SCRIPTRUNNER_H
using namespace std;

class ScriptRunner
{
private:
	vector<Command> actions;
	vector<Command> cactions;
	static ScriptRunner* instance;
	
	
protected:
	Render * gameRender;
public:
	static ScriptRunner* ScriptRunner::getInstance(){
		static ScriptRunner *instance = 0;
		if(instance == 0){
			instance = new ScriptRunner();
		}
		return instance;
	}
	ScriptRunner(void);
	~ScriptRunner(void);
	void setRender(Render*);
	void setActions(vector<Command>);
	vector<Command> parseScript(ifstream&);
	void runScripts();
	void doCommand();
	bool getStatus();
	bool isRunning;
};

#endif

