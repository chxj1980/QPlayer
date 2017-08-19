//NetTalk
/*------------------------------------------------------------------------------*\
 =============================
   ģ������: AudioPlay.h
 =============================
 
 [��Ȩ]
 
   2000-2002  115�������  ��Ȩ����
                                              
\*------------------------------------------------------------------------------*/
#ifndef _AUDIOPLAY_H_
#define _AUDIOPLAY_H_

#include "WaveOut.h"
#include "WaveBase.h"

/// ��Ƶ���ŷ�װ��
class CAudioPlay:public CWaveOut, public WaveBase
{
public:
	
	CAudioPlay();
	virtual  ~CAudioPlay();
	/// ����
	BOOL Create(WAVEFORMATEX *pwf,DWORD dwCallBack,DWORD dwInst,DWORD fdwOpen );
	/// ����
	BOOL Play(char* buf,UINT uSize);
	/// �ͷ�
	BOOL Destroy();
	
  // add by caiqm
  BOOL Create(int channel, int samplerate, DWORD dwBuffSize);
  virtual void OnWaveDone(WAVEHDR* hdr);
  virtual bool OnWaveAlloc(WAVEHDR* hdr);
  virtual void OnWaveFree(WAVEHDR* hdr);

  /// ��ʼ����
  BOOL Start();
  /// ֹͣ����
  BOOL Stop();
protected:
  bool m_bStarted;
};


#endif