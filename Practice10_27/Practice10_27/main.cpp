#include<stdio.h>

class Object
{
public:
	virtual void SetVec(float x,float y,float z)
	{
		vecX = x;
		vecY = y;
		vecZ = z;
	}

	virtual void SetVecX(float n)
	{
		vecX = n;
	}

	virtual void SetVecY(float n)
	{
		vecY = n;
	}

	virtual void SetVecZ(float n)
	{
		vecZ = n;
	}

	float GetVecX()
	{
		printf("%f\n", vecX);
		return vecX;
	}

	float GetVecY()
	{
		printf("%f\n", vecY);
		return vecY;
	}

	float GetVecZ()
	{
		printf("%f\n", vecZ);
		return vecZ;
	}

	virtual void Update() {};

protected:
	//本当はストラクトでやりたい
	float vecX = 0;
	float vecY = 0;
	float vecZ = 0;
};

class Vehicle : public Object
{
public:
	virtual class SpeedUp
	{
	public:
		virtual void SetSpeed(Vehicle& vh, float n)
		{
			vh.speed = n;
		}

		virtual void SetAccel(Vehicle& vh, float n)
		{
			vh.accel = n;
		}
	};

	float GetSpeed()
	{
		printf("%f\n", speed);
		return speed;
	}

	float GetAccel()
	{
		printf("%f\n", accel);
		return accel;
	}

protected:
	float speed = 0;
	float accel = 0;

};

class Car : public Vehicle
{
public:
	virtual class SpeedUp
	{
	public:
		virtual void SetSpeed(Car& car, float n)
		{
			if (n < 0 || n>100)
			{
				printf("値が範囲外です。\n");
				return;
			}

			car.speed = n;
		}

		virtual void SetAccel(Car& car, float n)
		{
			if (n < -5 || n>5)
			{
				printf("値が範囲外です。\n");
				return;
			}

			car.accel = n;
		}

	};

};

int main()
{
	Car car;
	Car::SpeedUp spd;
	car.GetAccel();
	spd.SetAccel(car, 5);
	car.GetAccel();
}