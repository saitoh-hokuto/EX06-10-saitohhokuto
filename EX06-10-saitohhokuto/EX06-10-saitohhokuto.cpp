#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include<cstdlib>
using namespace std;

class Solid {
public:
	virtual float GetVolume() = 0;
	virtual float GetSurface() = 0;
};

class Box :public Solid{
private:
	float width;
	float height;
	float depth;

public:
	Box(
		float width,
		float height,
		float depth

	){
		this->width = width;
		this->height = height;
		this->depth = depth;
	}

	float GetVolume() {
		return width * height * depth;
	}

	float GetSurface() {
		return(width * height + width * depth + height * depth) * 2;
	}
};

void DisplayVolumeSurface(Solid* solid) {
	cout << "体積=" << solid->GetVolume() << endl;
	cout << "表面積=" << solid->GetSurface() << endl;
}
int main()
{
	Box box{ 5, 5, 5 };
	const int N_TABLE = 1;
	Solid* solid[N_TABLE] = { &box };
	for (int i = 0; i < N_TABLE; i++) {
		DisplayVolumeSurface(solid[i]);
	}
};