#ifndef CAMERA_H
#define CAMERA_H

class Camera {
public:
	static Camera* Instance();	
	void Update();
	void Release();

	int GetXPos() { return mPosX; }
	void SetXPos(int newxpos) { mPosX = newxpos; }
	int GetYPos() { return mPosY; }
	void SetYPos(int newypos) { mPosY = newypos; }

	int GetSpeed() { return Speed; }
	void SetSpeed(float s) { Speed = s; }

	int GetVel() { return Vel; }
	void SetVel(int vel) { Vel = vel; }
	
private:
	static Camera* sInstance;
	int mPosX;
	int mPosY;
	int Speed;
	int Vel;
	static float SreenWidth;
	static float SreenHeight;
	Camera();
	~Camera();

};

#endif // !CAMERA_H

