#ifndef _PLAYER_INCLUDED
#define _PLAYER_INCLUDED

#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>
#include <Mmreg.h>
#include <atlbase.h>
#include <vector>
#include <vector>
#include "mat_exception.h"

#pragma comment(lib, "dsound.lib")
#pragma comment(lib, "dxguid.lib")

#ifdef _DEBUG
	#include <assert.h>
	#define DBGASSERT(condition) assert(condition);	
#else
	#define DBGASSERT(condition)
#endif

class Mutex
{
	HANDLE m_hMutex;
public:
	Mutex();
	~Mutex();
	void Get()const;
	void Release()const;
};

/********************************************
  Release the mutex when the object is destroyed.  
  Guaranty that the mutex will be released...
********************************************/
class ScopeGuardMutex
{
	class Mutex *m_pMutex;
public:
	ScopeGuardMutex(Mutex *pMutex);
	~ScopeGuardMutex();
};

HANDLE runThread(LPTHREAD_START_ROUTINE fct, void* param);

class DirectSoundErr
{
public:
	static std::string DirectSoundErr::GetErrDesc(HRESULT hres);
};

class SOUNDFORMAT
{
public:
	unsigned short NbChannels;				// number of channels: 1:mono 2:stéréo
	unsigned short SamplingRate;
	unsigned short NbBitsPerSample;			// bits per sample:	8 ou 16 bits

	void fromWFX( WAVEFORMATEX wfx )
	{
		NbChannels = wfx.nChannels;
		SamplingRate = (unsigned short)wfx.nSamplesPerSec;
		NbBitsPerSample = wfx.wBitsPerSample;
	}

	void toWFX( WAVEFORMATEX &wfx )
	{
		wfx.wFormatTag=WAVE_FORMAT_PCM;
		wfx.nChannels = NbChannels;
		wfx.nSamplesPerSec = SamplingRate;
		wfx.wBitsPerSample = NbBitsPerSample;
		wfx.nBlockAlign = wfx.nChannels * wfx.wBitsPerSample / 8;
		wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign;
		wfx.cbSize=0;	
	}
};

// Abstract audio player
class IPlayer
{
public:
	class SoundEventListener
	{
	public:
		virtual ~SoundEventListener() {};
		virtual void OnSoundPlayerNotify(int eventNumber)=0;	
	};
public:
	IPlayer() {}; 
	virtual ~IPlayer() {};
	virtual void Init()=0;
	virtual void Play(long p_flag)=0;
	virtual void Stop()=0;
	virtual bool CreateSoundBuffer(SOUNDFORMAT format, long bufferLength, long flag)=0;
	virtual void Write(long start, BYTE* data, long size)=0; 
	virtual bool CreateEventReadNotification(std::vector<DWORD>&p_event)=0;	
	virtual void SetSoundEventListener(IPlayer::SoundEventListener* p_listener)=0;	
	virtual void RemoveSoundEventListener()=0;	
};

class Player : public IPlayer
{
private :
	LPDIRECTSOUNDBUFFER	m_lpDSBuffer;		// DirectSound buffer
	LPDIRECTSOUND m_lpDS;					// DirectSound object
	HWND m_hWnd;							// Window handler
	HANDLE* m_pReadEvent;
	HANDLE m_hNotifyEndThread;
	LPDIRECTSOUNDNOTIFY m_lpdsNotify;
	DSBPOSITIONNOTIFY* m_pDSNotify;
	int m_nbReadEvent;
	IPlayer::SoundEventListener* objectListener;
public :
	Player();
	~Player();
	virtual void Init();
	void SetHWnd(HWND p_hWnd);
	virtual void Play(long p_flag);
	virtual void Stop();
	virtual bool CreateSoundBuffer(SOUNDFORMAT format, long bufferLength, long event);
	virtual void Write(long start, BYTE* data, long size);
	virtual bool CreateEventReadNotification(std::vector<DWORD>&p_event);	
	virtual void SetSoundEventListener(IPlayer::SoundEventListener* p_listener);
	virtual void RemoveSoundEventListener();
private :	
	class Mutex* m_mutex;
	void CallEvent(int eventNumber);
	void WaitNotif();
	static void WaitForNotify(Player* p_player);
};

#endif	