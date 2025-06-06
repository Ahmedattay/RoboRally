#pragma once
#include "Action.h"
#include "Grid.h"
#include "Player.h"
/*Repairs the robot instantly, without visiting a workshop
aka restore health points 
calls reboot and repair*/
class UseConsumableToolkit :public Action
{
public:
    UseConsumableToolkit(ApplicationManager* pApp);
    virtual void ReadActionParameters();
    virtual void Execute();
    virtual ~UseConsumableToolkit();
};

