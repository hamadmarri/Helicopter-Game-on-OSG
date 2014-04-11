Rquirements for compilation:
	- Must installed OpenSceneGraph(3.1.10 or above) libraries before compile and set global environment variables for OSG_FILE_PATH and OSG_LIBRARY_PATH.
	- Must compile with compiler that supports C++11.
	- It suppose to be compiled successfully on any environment.

After compilation place setting.txt in the same directory of the executable file, otherwise, default settings will be set.


Run arguments:
--help
--log: followed by log file name
--script: followed by script file name
--test: followed by r for real time test or s for simulator test


By defaults log is enabled, see setting.txt for more info.


Credits:
	Authors:			Fares Alotaibi, Hamad Almarri
	Incorporated code from heli-alternate project by Karim Naqvi
	Models:				http://scenemodels.flightgear.org/objectview.php?id=3303278
						http://scenemodels.flightgear.org/modelview.php?id=320
	RK4:				http://gafferongames.com/game-physics/integration-basics/
	Original authors:	Brian Schweitzer, Karlee Stein, Tylor Froese, Trevor Douglas




read (How to Use the Helicopter Game.pdf)