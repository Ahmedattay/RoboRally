#pragma once

#include "Grid.h"

// Base Class for All Game Objects ( Belts, danger zones, .. )
class GameObject
{

protected:

	CellPosition position; // The current cell position of the GameObject
	
public:

	GameObject(const CellPosition & pos); // Constructor for initializing data members
	
	GameObject(const GameObject& oldobj);
	CellPosition GetPosition() const;     // A Getter for position
	void SetPosition(CellPosition pos);

	// ============ Virtual Functions ============

	virtual void Draw(Output* pOut) const = 0;	 // Draws the game object in the window in his position cell 
											     // (drawing depends on GameObject Type, so virtual)

	virtual void Apply(Grid* pGrid, Player* pPlayer) = 0;  // Applys the effect of the GameObject on the passed Player
	                                                       // (The effect depends on the GameObject type, so virtual)
	                                                       // For example, applying a belt is by moving player to the 
														   // end of the belt, and so on

	// The following functions are examples of what should be supported by the GameObject 
	// 
	// They should be overridden by each inherited class

	/// TODO::Decide the parameters that you should pass to each function	

	//Uncomment those functions and implement them in all the derived classes 
	virtual void Save(ofstream &OutFile, GameObjectType) = 0;	// Saves the GameObject parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	// Loads and Reads the GameObject parameters from the file
	virtual GameObjectType GetType()const = 0;

	virtual ~GameObject(); // Virtual destructor
};

