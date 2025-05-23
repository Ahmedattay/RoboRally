#include "AddWorkshopAction.h"


AddWorkshopAction::AddWorkshopAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddWorkshopAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	/* Implemented same method in AddBeltAction */
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();    //Output pointer
	Input* pIn = pGrid->GetInput();       //Input pointer 

	// 2- Read the ObjectPos

	pOut->PrintMessage("New Workshop: Click on the cell to add a Workshop ...");
	WorkshopPos = pIn->GetCellClicked();


	// 4- Make the needed validations on the read parameters

	if (WorkshopPos.VCell() == 4 && WorkshopPos.HCell() == 0)
	{
		pOut->PrintMessage("You can't put a game object in the first cell");
		return;
	}



	// 5- Clear status bar
	pOut->ClearStatusBar();   //Use output pointer to clear status bar
}

void AddWorkshopAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a Waterpit object
	Workshop* pWork = new Workshop(WorkshopPos);

	// 2-get a pointer to the Grid from the ApplicationManager
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	// 3-Add the water pit object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pWork);

	// 4-Check if the object was added and print an error message if object couldn't be added
	if (!added)
	{
		pOut->PrintMessage("Workshop couldn't be added");
	}

}

AddWorkshopAction::~AddWorkshopAction()
{
}