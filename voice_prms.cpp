/*
voice_prms.cpp
*/

#include "voice_prms.h"
#include "audio_fns.h"

void VoicePrms::init(double d)
// call before note is played
{
	pitch = d;
	tm = 0;
	gain = 1;
	note_on = true;
	off_tm = 1.0E+100;
	lev = 0;
}

void VoicePrms::noteOff()
// updates note on variable to signify note off has occured
{
	note_on = false;
    if (off_tm > tm)
    {
		off_tm = tm;
        off_lev = lev;
	}
}

void VoicePrms::upd(SynthPrms sp)
// updates time
{
	tm += sp.tm_step;
}

double VoicePrms::vol(SynthPrms sp)
// returns the volume, based on ADSR function and variables / parameters, also sets the current level
{
	double x;
	lev = AudioFns::aDSR(note_on, off_tm, off_lev, tm, sp.atk * sp.note_tm, sp.dec * sp.note_tm, sp.sus, sp.rel * sp.note_tm);
	x = gain * lev;
	return x;
}

bool VoicePrms::envFin(SynthPrms sp)
// returns true if the volume envelope has finished
{
	return AudioFns::aDSRFin(note_on, off_tm, tm, sp.rel * sp.note_tm);
}