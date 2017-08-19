//NetTalk
/*------------------------------------------------------------------------------*\
 =============================
   ģ������: waveout.cpp
 =============================
 
 [��Ȩ]
 
   2000-2002  115�������  ��Ȩ����
                                              
\*------------------------------------------------------------------------------*/
#include <Windows.h>

#include "WaveOut.h"
#pragma comment(lib,"Winmm")

/*------------------------------------------------------------------------------*/
void waveOutErrorMsg(MMRESULT mmr,TCHAR* szTitle)
{
	TCHAR txt[MAXERRORLENGTH];
	waveOutGetErrorText(mmr,txt,MAXERRORLENGTH);
	MessageBox(0,txt,szTitle,MB_OK|MB_ICONWARNING);
}

/*------------------------------------------------------------------------------*/
CWaveOut::CWaveOut()
{
	m_mmr=0;
	m_hOut=0;	
}

/*------------------------------------------------------------------------------*/
//�����������豸
BOOL CWaveOut::OpenDev(WAVEFORMATEX* pfmt,DWORD dwCallback,DWORD dwCallbackInstance,DWORD fdwOpen)
{
	BOOL bRet=FALSE;
	WAVEFORMATEX wf;
	if(!pfmt)//Ĭ�ϸ�ʽ
	{		
		wf.wFormatTag	= WAVE_FORMAT_PCM;
		wf.cbSize		= 0;
		wf.wBitsPerSample = 16;
		wf.nSamplesPerSec = 8000;
		wf.nChannels = 1;
		wf.nAvgBytesPerSec	= wf.nSamplesPerSec*(wf.wBitsPerSample/8);
		wf.nBlockAlign		= wf.nChannels     *(wf.wBitsPerSample/8);
		pfmt = &wf;
	}
	MMRESULT mmr;
	mmr=waveOutOpen(0,WAVE_MAPPER,pfmt,0,0,WAVE_FORMAT_QUERY);
	if(mmr)
	{
		SetLastMMError(mmr);
		goto RET;
	}
	mmr=waveOutOpen(&m_hOut,WAVE_MAPPER,pfmt,dwCallback,dwCallbackInstance,fdwOpen);
	if(mmr)
	{
		SetLastMMError(mmr);
		goto RET;
	}
	bRet=TRUE;
RET:
	return bRet;
}



/*------------------------------------------------------------------------------*/
CWaveOut::operator HWAVEOUT() const
{
	return m_hOut;
}

/*------------------------------------------------------------------------------*/
CWaveOut::~CWaveOut()
{
	
}

/*------------------------------------------------------------------------------*/

MMRESULT CWaveOut::GetLastMMError()
{
	return m_mmr;
}

/*------------------------------------------------------------------------------*/
void CWaveOut::SetLastMMError(MMRESULT mmr)
{
	m_mmr=mmr;
}

/*------------------------------------------------------------------------------*/
BOOL CWaveOut::CloseDev()
{
	BOOL bRet=FALSE;
	if(!m_hOut)
		goto RET;
	m_mmr=waveOutReset(m_hOut);
	if(m_mmr)
		goto RET;
	m_mmr=waveOutClose(m_hOut);
	if(m_mmr)
		goto RET;
	m_hOut=0;
	bRet=TRUE;
RET:
	return bRet;
}

/*------------------------------------------------------------------------------*/
HWAVEOUT CWaveOut::GetHandle()
{
	return m_hOut;
}
