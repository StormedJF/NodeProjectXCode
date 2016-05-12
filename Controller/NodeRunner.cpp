//
//  NodeRunner.c
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#include "NodeController.h"

int main()
{
    NodeController * baseController = new NodeController();
    baseController->start();
    return 0;
}