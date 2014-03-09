//
//  Configuration.cpp
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-09.
//  SID: 200288569
//

#include "Configuration.h"

Configuration* Configuration::getInstance(){
    static Configuration *instance = nullptr;
    if(instance == nullptr){
        instance = new Configuration();
        instance->initialize();
    }
    return instance;
}