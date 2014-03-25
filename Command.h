//
//  Command.h
//  HelicopterProject
//
//  Created by Hamad Almarri on 2014-03-18.
//  Copyright (c) 2014 Hamad Almarri. All rights reserved.
//

#ifndef HelicopterProject_Command_h
#define HelicopterProject_Command_h

class Command {
public:
	virtual ~Command() { };
	virtual bool execute() = 0;
};


#endif
