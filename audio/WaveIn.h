/*------------------------------------------------------------------------------*\
 =============================
   ģ������: wavein.h
 =============================

 [Ŀ��]
 
     ����waveInXXX�������ʹ�ã�ʹ�����     
     	  
 [����]
		
	��ģ�����CWaveIn�࣬���Ǹ���װ��¼���������ࡣ   
 
 [�÷�]
   
    �����ǻ����࣬���鲻Ҫֱ��ʹ�ø���		
	 
 [������]
	
	 Winmm.lib 

 [�޸ļ�¼]
 
  �汾:    1.01.01
  ����:    01-11-1         
  ����:    Brant Q
  ��ע:
    ---------------------------------------	 
  �汾:    1.01.02
  ����:    01-11-14
  ����:    Brant Q
  ��ע:
    
	  ȥ����һЩ����ĺ���,��:AddBuffer\RemoveBuffer,������SetLastMMError��
    GetLastMMError��Ա����,�Լ�waveInErrorMsg


 [��Ȩ]
 
   2000-2002  115�������  ��Ȩ����
                                              
\*------------------------------------------------------------------------------*/
#ifndef _WAVEIN_H_
#define _WAVEIN_H_
#include <mmsystem.h>
void waveInErrorMsg(MMRESULT mmr,TCHAR* szTitle);

class CWaveIn
{
public:
	CWaveIn();
	virtual  ~CWaveIn();

	/// ���豸
	BOOL OpenDev(WAVEFORMATEX* pfmt,DWORD dwCallback,DWORD dwCallbackInstance,DWORD fdwOpen);
	/// �ر��豸
	BOOL CloseDev();
  UINT GetMixerID() {
    UINT uMixerID = 0;
    MMRESULT mmr = mixerGetID((HMIXEROBJ)m_hIn, &uMixerID, MIXER_OBJECTF_HWAVEIN);
    return uMixerID;
  }

	/// ����mmr����
	void SetLastMMError(MMRESULT mmr);
	/// ��ȡmmr����
	MMRESULT GetLastMMError();

	HWAVEIN GetHandle();
	operator HWAVEIN() const;
protected:

	MMRESULT m_mmr;	///< mmr����
	
	HWAVEIN m_hIn;	///< ���

};

#endif