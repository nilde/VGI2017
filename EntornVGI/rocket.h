#ifndef _ROCKET
#define _ROCKET

//SOME GENERAL CONSTANTS


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

	int max_iter = 600;

	//Constructor
	Rocket();

	float get_altura();
	
	//Overwrite of the constructor with some parameters
	//Rocket(some params)

	void ExecuteTrayectory(int iteracion, float step, GLfloat center[3]);

	void ExecuteTrayectory_Semi(int iteracion, float step, GLfloat center[3]);

	void Restart();

	void Initialize();

	//No implementada
	float Rocket::angleGenerated(float previousX, float previousY, float actualX, float actualY);
	
	//implementation soon
	void calcTelemetry();
private:
	float time;
	float thurst;
	float stageNumber;
	float weight;
	float height;
	float utilCharge;

};


#endif