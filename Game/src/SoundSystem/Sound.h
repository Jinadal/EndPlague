#include <stdlib.h>
#include "include/fmod.h"
#include "include/fmod_errors.h"
#include <iostream.h>


	#include <windows.h>
	// link to fmod lib


	//#include <wincompat.h>//_LINUX


/// this is a pointer to the mp3 stream we will be reading from the disk.
FSOUND_SAMPLE* g_sample = NULL;

FSOUND_SAMPLE* g_sample2 = NULL;

int main(int argc,char **argv)
{

	// initialise fmod, 44000 Hz, 64 channels
	if( FSOUND_Init(44000,64,0) == FALSE )
	{
		std::cerr << "[ERROR] Could not initialise fmod\n";
		return 0;
	}
    //------------------------------------------------------------------------
	// attempt to open the mp3 file as a stream
	g_sample = FSOUND_Sample_Load(FSOUND_FREE,"perc.wav",FSOUND_2D,0,0);
	if(!g_sample) {
		std::cerr << "[ERROR] could not open file\n";
		return 0;
	}
	
    g_sample2 = FSOUND_Sample_Load(FSOUND_FREE,"dung.wav",FSOUND_2D,0,0);
	if(!g_sample2) {
		std::cerr << "[ERROR] could not open file\n";
		return 0;
	}	
    // make sure mp3 opened OK
    //------------------------------------------------------------------------
	// start the sound playing
	int ch  = FSOUND_PlaySound(FSOUND_FREE,g_sample);
	int ch2 = FSOUND_PlaySound(FSOUND_FREE,g_sample2);
	
    
    // make the sound loop
	FSOUND_SetLoopMode(ch,FSOUND_LOOP_NORMAL);
	FSOUND_SetLoopMode(ch2,FSOUND_LOOP_NORMAL);

	
    std::cout << "press any key to quit" << std::endl;

	
    // sit and wait for key press
	cin.get();

	// Stop the sound from playing
	FSOUND_StopSound( ch );
    FSOUND_StopSound( ch2 );
	// kill off fmod
	
    FSOUND_Close();

	// done
	return 0;
}

