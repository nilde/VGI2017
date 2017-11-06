//littlePhysics library
//This library contains a reducted version of all the parameters that 
//we need to make a correct simulation of the rockets launching.
//Libraries needed
#include <math.h>

//CONSTANTS

const float  GRAVITY_ACCELERATION = 9.8;
const float RHO=1.22;



//FUNCTIONS

//Velocity at burnout
float maxVelocity(float xValue,float yValue,float qValue,float tValue){
return (qValue * (1.0 - float( exp (double (-xValue * actualTime ) ))) / (1.0 + float(exp (double (-xValue * actualTime)))));
}

float alttitudeReachedFromBoost(float rocketMass,float kValue,float burnoutVelocity, float thurst){

return ((-rocketMass / (2*kValue))*log(((thurst - rocketMass*GRAVITY_ACCELERATION - kValue*burnoutVelocity**2) / (thurst - rocketMass*GRAVITY_ACCELERATION ))));

}

float alttitudeReachedFromCoast(float rocketMass, float kValue,float burnoutVelocity){

return ((rocketMass/(2*kValue)) * log(((rocketMass*GRAVITY_ACCELERATION + kValue*burnoutVelocity**2) / (rocketMass*GRAVITY_ACCELERATION))));

}

//Calculates top height of the landing
float totalAlttitude(float rocketMass, float kValue,float burnoutVelocity,float thurst){

	return (alttitudeReachedFromBoost(rocketMass,kValue,burnoutVelocity,thurst) + alttitudeReachedFromCoast(rocketMass,kValue,burnoutVelocity)); 
}

//Calculate time elapsed to the top height
float timeElapsedTopHeight(float rocketMass,float Kvalue,float burnoutVelocity){

float qa = sqrt(rocketMass*GRAVITY_ACCELERATION / kValue);
float qb = sqrt(GRAVITY_ACCELERATION*kValue / rocketMass);
return atan(burnoutVelocity / qa) / qb;


}

float calculateBurnoutVelocity(float rocketMass,float dragCoefficient,float rocketCrossAreaSection,float thurst,float motorImpulse){
	float k=0.5*RHO*dragCoefficient*rocketCrossAreaSection;
	float q=sqrt((thurst-rocketMass*GRAVITY_ACCELERATION) /(k));
	float x=(2.0*k*q) / rocketMass;
	float motorBurn = motorImpulse / thurst;

	return (q*(1.0 - exp(-x * motorBurn)) / (1.0 + exp(-x * motorBurn)));
}

float distanceUntilTopHeight(float rocketMass,float kValue,float burnoutVelocity){

	return  (rocketMass / (2.0*kValue)]*log(((rocketMass*GRAVITY_ACCELERATION + kValue*burnoutVelocity**2) / (rocketMass*GRAVITY_ACCELERATION)))); //Modificar los logaritmos

}

float timeToVelocityZero(float rocketMass,float kValue,float burnoutVelocity){

	return (sqrt(rocketMass / (kValue*GRAVITY_ACCELERATION))*arctan(burnoutVelocity / sqrt(rocketMass*GRAVITY_ACCELERATION/kValue)));
}

//Parabolico
float posX(float angle,float VelocityX,float time){
	return VelocityX * time *cos(double(angle));

}

float posY(float posYinit,float initVelocityY,float time,float accelerationY){
	return posYinit + InitVelocityY*time + 0.5*accelerationY*time**2;

}


float VelocityX(float VelocityX,float angle){
	return float(VelocityX*cos(double(angle)));

}

float VelocityY(float angle,float initVelocityY,float time){
	return float(initVelocityY*sin(double(angle)) - GRAVITY_ACCELERATION*time); //modifies if gravity changes

}

float accelerationX(){
	return 0

}

float accelerationY(){
	return -1.0*GRAVITY_ACCELERATION;
}

float posXMax(float VelocityX,float angle){
	return float((VelocityX**2*sin(double(2.0*angle))) / GRAVITY_ACCELERATION);

}
float posYMax(float initVelocityX,float angle){
	return float((initVelocityX**2 *(0.5 - 0.5 * cos(double(2.0*angle)) ))/2.0*GRAVITY_ACCELERATION);

}

float angleGenerated(float previousX,float previousY,float actualX,float actualY){
	float a=actualX - previousX;
	float b=actualY - previousY;
	return asin(a /(sqrt(a**2 + b**2)));
}




