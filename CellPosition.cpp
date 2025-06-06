#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v > 4 || v < 0)
	{
		return false;
	}
	else
	{
		vCell = v;
		return true;
	}
	// this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h > 10 || h < 0)
	{
		return false;
	}
	hCell = h;
	return true;// this line sould be changed with your implementation
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file
	bool flag = true;
	if (hCell > 10 || hCell < 0)
	{
		flag = false;
	}
	else if (vCell > 4 || vCell < 0)
	{
		flag = false;
	}

	return flag; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	int cellnum = ((4 - cellPosition.vCell) * 11) + cellPosition.hCell + 1;
	///TODO: Implement this function as described in the .h file

	return cellnum; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{

	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;
	int counter = 0;
	while (cellNum > 11)
	{
		cellNum -= 11;
		counter++;
	}
	position.vCell = 4 - counter;
	position.hCell = cellNum - 1;

	/// TODO: Implement this function as described in the .h file

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum(int addedNum, Direction direction)
{

	/// TODO: Implement this function as described in the .h file

	if (direction == 0)
	{
		vCell -= addedNum;
	}
	else if (direction == 1)
	{
		vCell += addedNum;
	}
	else if (direction == 2)
	{
		hCell += addedNum;
	}
	else if (direction == 3)
	{
		hCell -= addedNum;
	}
	// Note: this function updates the data members (vCell and hCell) of the calling object

}