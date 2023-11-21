#pragma once

class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY);
	AActor(int NewX, int NewY, char NewShape);
	AActor(int NewX, int NewY, char NewShape, int NewSortOrder);
	AActor(int NewX, int NewY, char NewShape, int NewSortOrder, bool NewbCollide);
	~AActor();

	virtual void BeginePlay();
	virtual void Tick();
	virtual void Render();

	inline int GetX() const { return X; }
	inline int GetY() const { return Y; }

	inline void SetX(int NewX) { X = NewX; }
	inline void SetY(int NewY) { Y = NewY; }

	inline bool GetbCollide() const { return bCollide;}
	inline void SetCollide(bool NewColide) { bCollide = NewColide; }

	inline int GetSortOrder() const { return SortOrder; }
	inline void SetSortOrder(int NewSortOrder) { SortOrder = NewSortOrder; }

	virtual bool operator<(const AActor& RHS)const { return this->SortOrder < RHS.SortOrder; }
	
	

protected:
	int X;
	int Y;

	int SortOrder;
	bool bCollide;
	char Shape;

private:

};

