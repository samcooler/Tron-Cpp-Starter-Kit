// MyTronBot.cpp
//
// This is the code file that you will modify in order to create your entry.

#include "MyTronBot.h"
#include "Point.h"
#include "Map.h"
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

using namespace std;

ofstream logfile;

// This is the function that you should edit (although you can edit anything you like)
Direction ChooseMove(Map& map)
{
	// This is some sample code. Once you understand it you can trash it.
	logfile << "starting point: (" << map.me().x << ", " << map.me().y << ")\n";
	logfile << "Moving South\n";
	map.MovePlayer(Me, Direction(South));
	logfile << "new point: (" << map.me().x << ", " << map.me().y << ")\n";

	DirectionSet mymoves = map.GetMoves(map.me());
	DirectionSet::iterator curdir;

	for (curdir = mymoves.begin(); curdir != mymoves.end(); ++curdir)
	{
		
		logfile << "Can go: " << curdir->name <<endl;
	}
	
	Direction move;
	if (!mymoves.empty())
	{
		move = *mymoves.begin();
	}

	return move;
}

int main()
{
	logfile.open( "logfile.txt");
	time_t seconds;
	seconds = time(NULL);
	logfile << "Starting at " << seconds << endl;
	
	// Labels for log output
	
	while (true)
	{
		logfile <<  endl << "Starting new turn" << endl;
		
		
		Map map; // reads map input from the Tron engine
		logfile << "Have map:" << endl << map.Print();
		// N.B:
		// the following write to the log file is not what does the Tron interface
		logfile << ChooseMove(map).WriteMove();
	}
	return 0;
}
