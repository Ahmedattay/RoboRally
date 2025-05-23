#include "Workshop.h"
#include "Player.h"
#include"SaveAction.h"
#include"SaveAction.h"


Workshop::Workshop(const CellPosition & workshopPosition):GameObject( workshopPosition)
{

}


void Workshop::Draw(Output * pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid * pGrid, Player * pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;

	pOut->PrintMessage("You have reached a Workshop. Click to continue");
	pIn->GetPointClicked(x, y);

	pOut->PrintMessage("Type 1 for toolkit, Type 2 for hack device, Type 3 for extended memory, click to view the rest of the text");
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("Type 4 for double laser,Type 5 for shield. click to view the rest of the text");
	pIn->GetPointClicked(x, y);
	pOut->PrintMessage("Type 6 for reflection gear, Press anything else and click on the repair icon in the toolbar if you want to repair and reboot");

	int playernum = pGrid->GetCurrentPlayerNum();
	int a = pIn->GetInteger(pOut);
	switch (a)
	{
	case 1:
		if (pPlayer->gettoolkit())
		{
			pGrid->PrintErrorMessage("You already have a toolkit, you can't buy more than one. Click to continue...");
		}
		else
		{
			
			pPlayer->settoolkit(1);
		}
		break;
	case 2:
		if (pPlayer->gethackdevice() == 1)
		{
			pGrid->PrintErrorMessage("You already have a hack device, you can't buy more than one. Click to continue...");
		}
		else
		{
			pPlayer->sethackdevice(1);
		}
		break;
	case 3:
		if (pPlayer->getExMemory())
		{
			pGrid->PrintErrorMessage("You already have an extended memory, activate this one before buying another Click to continue...");
		}
		else
		{
			pPlayer->setExMemory(1);
		}
		break;
	case 4:
		if (pPlayer->getweapon())
		{
			pGrid->PrintErrorMessage("You already have a double laser. Click to continue...");
		}
		else
		{
			pPlayer->setweapon(1);
		}
		break;
	case 5:
		if (pPlayer->GetShield())
		{
			pGrid->PrintErrorMessage("You already have a shield. Click to continue...");
		}
		else
		{
			pPlayer->SetShield(1);
		}
		break;
	case 6:
		if (pPlayer->getReflectionGear() == 1)
		{
			pGrid->PrintErrorMessage("You already have a ReflectionGear. Click to continue...");
		}
		else
		{
			pPlayer->setReflectionGear(1);
		}

	default:
		break;
	}
	pIn->GetPointClicked(x, y);
	pGrid->UpdateInterface();
}
void Workshop::Save(ofstream& OutFile, GameObjectType type) {
	if (!OutFile.is_open()) return;
	else {

		int Data = position.GetCellNum();
		OutFile << Data;

	}
}
GameObjectType Workshop::GetType() const {
	return Workshops;
}

Workshop::~Workshop( )
{
}
