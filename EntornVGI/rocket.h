#ifndef _ROCKET
#define _ROCKET

#include <string>
#include <mmsystem.h>
#include <mciapi.h>
using namespace std;

//SOME CONSTANTS FOR F9 IN LEO ORBITS
const int MAX_DYNAMIC_PRESSURE_LEO = 82;
const int MAIN_ENGINE_CUTOFF_LEO = 170;
const int STAGE_SEPARATION_LEO = 175;
const int SECOND_ENGINE_START_1_LEO = 180;
const int FAIRING_DEPLOY_LEO = 220;
const int SECOND_ENGINE_CUTOFF_1_LEO = 540;
const int SPACECRAFT_SEPARATION_LEO = 600;

//SOME CONSTANTS FOR F9 IN GTO ORBITS
const int MAX_DYNAMIC_PRESSURE_GTO = 82;
const int MAIN_ENGINE_CUTOFF_GTO = 170;
const int STAGE_SEPARATION_GTO = 175;
const int SECOND_ENGINE_START_1_GTO = 180;
const int FAIRING_DEPLOY_GTO = 220;
const int SECOND_ENGINE_CUTOFF_1_GTO = 540;
const int SECOND_ENGINE_START_2_GTO = 1520;
const int SECOND_ENGINE_CUTOFF_2_GTO = 1585;
const int SPACECRAFT_SEPARATION_GTO = 1615;

//SOME CONSTANTS FOR A F9 WITH FULL THRUST
const float F9_FT_MASS = 549054;//kgs
const float F9_FT_CAPACITY_GTO = 8300;//kgs
const float F9_FT_CAPACITY_LEO = 22800;//kgs

//DATA FROM FIRST STAGE
const float F9_FT_SPECIFIC_IMPULSE_FS_SL = 7607; //seconds (first stage) 
const float F9_FT_SPECIFIC_IMPULSE_FS_VA = 8227; //seconds (first stage)
const float F9_FT_THURST_FS_SL = 282; //kN (first stage) 
const float F9_FT_THURST_FS_VA = 311; //kN (first stage)
const float F9_FT_BURN_TIME_FS_VA = 162; //seconds (first stage)
const float F9_FT_PROPELLANT_MASS_FS = 395700;//kgs
const float F9_FT_INERT_MASS_FS =23100 ;//kgs

//DATA FROM SECOND STAGES
const float F9_FT_BURN_TIME_SS_VA = 397; //seconds (second stage)
const float F9_FT_THURST_SS_VA = 934; //kN (second stage) 
const float F9_FT_SPECIFIC_IMPULSE_SS_VA = 348; //seconds (second stage)
const float F9_FT_PROPELLANT_MASS_SS = 92670;//kgs
const float F9_FT_INERT_MASS_SS = 3900;//kgs


//NEED TO FIND THE REAL VALUES FOR THAT CONSTANTS
const float CONSUME_PER_SECOND_FS=0;
const float CONSUME_PER_SECOND_SS=0;

//REMEMBER TO UPDATE THE WEIGHTS AT EACH STAGE



class Rocket {
public:
	//Coordenadas en que se encontrará el objeto rocket a lo largo de la ejecución
	int m_x;
	int m_y;
	int m_z;
	int m_alpha;
	int m_special;

	bool stop;

	float xo;
	float yo;
	float zo;

	float vyo;
	float vxo;
	float vzo;

	float vx;
	float vy;
	float vz;

	float ax;
	float ay;
	float az;

	bool combustible = true;
	float propellantBonus = 0.0;

	int max_iter = 500;
	int Diff_Fase = 250;

	//Constructor
	Rocket();

	float get_altura();
	
	//Overwrite of the constructor with some parameters
	//Rocket(some params)

	void calcTelemetry();

	void ExecuteTrayectory(int iteracion, float step, GLfloat center[3],int defective);

	void ExecuteTrayectory2(int iteracion, float step, GLfloat center[3],int defective);

	void ExecuteTrayectory3(int iteracion, float step, GLfloat center[3],int defective);

	void ExecuteTrayectory4(int iteracion, float step, GLfloat center[3],int defective);

	void Restart();
	void Initialize();
	Rocket& operator=(const Rocket& needToCopy) {
		crossSection = needToCopy.crossSection;
		this->k = needToCopy.k;
		this->q = needToCopy.q;
		this->x = needToCopy.x;
		this->t = needToCopy.t;
		this->v = needToCopy.v;
		this->y1 = needToCopy.y1;
		this->yc = needToCopy.yc;
		this->qa = needToCopy.qa;
		this->qb = needToCopy.qb;
		this->ta = needToCopy.ta;
		return *this;
	}

	void setGravity(float);
	void setPropellant(int type);


	double gravity;
	float dragCoeffiecient = 0.75;
	float rho = 1.22;//kg/m3
	float diameter;//meters
	float height; //meters
	float mass;//kg
	//boosters
	float thurst = 12500000.0;//Newtons
	float specificImpulse = 269.0;//seconds (2.64km/s)
	float burnTime = 124.0;//seconds
	//first Stage
	float thurstFS = 5250000.0;//Newtons
	float specificImpulseFS = 455.0;//seconds (4.46km/s)
	float burnTimeFS = 480;//seconds

	//need to be calculated
	double crossSection;
	double k;
	double q;
	double x ;
	double t;
	double v;
	double y1;
	double yc;
	double qa;
	double qb;
	double ta;

};


#endif