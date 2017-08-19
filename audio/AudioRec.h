//NetTalk
/*------------------------------------------------------------------------------*\
 =============================
   ģ������: AudioRec.h
 =============================
 
 [��Ȩ]
 
   2000-2002  115�������  ��Ȩ����
                                              
\*------------------------------------------------------------------------------*/
#ifndef _AUDIOREC_H_
#define _AUDIOREC_H_
#include "WaveIn.h"
#include "WaveBase.h"
/**
@brief ��Ƶ�ɼ���. 
 
*/
class CAudioRec:public CWaveIn, public WaveBase
{
public:
	CAudioRec();
	virtual ~CAudioRec();

	/// �ͷ�
	BOOL Destroy();
	/// ����
	BOOL Create(
		WAVEFORMATEX *pwf, ///< ��ʽ
		DWORD dwCallBack, ///< �ص�
		DWORD dwInst, ///< 
		DWORD fdwOpen, ///< 
		DWORD dwBufSize ///< ��������С
		);
	/// ��ʼ�ɼ�
	BOOL Start();
	/// ֹͣ�ɼ�
	BOOL Stop();

  BOOL Create(int channel, int samplerate, DWORD dwBuffSize);
  void OnWaveDone(WAVEHDR* hdr);
  bool OnWaveAlloc(WAVEHDR* hdr);
  void OnWaveFree(WAVEHDR* hdr);
protected:
  bool m_bStart;
};

#endif