//
//  main.cpp
//  HelloArrow
//
//  Created by zhuang yusong on 2017/3/4.
//  Copyright © 2017年 zhuang yusong. All rights reserved.
//

#include <iostream>
#include "Lighting.h"

int main(void)
{
	Lighting app;
	app.initGLApp("Lighting");
	app.init();
	app.run();
	return 0;
}
