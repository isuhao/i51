#ifndef _MW_I51PUBLIC_H_
#define _MW_I51PUBLIC_H_

#include "i51.h"
#include "i51KitAde.h"
#include "i51KitStd.h"
#include "i51KitG2.h"
#include "WheresMyWaterRes.h"
#include "Chipmunk.h"
#include "LLPInput.h"

#include "mwStateMain.h"
#include "mwStateSet.h"
#include "mwStateExit.h"
#include "mwStateMode.h"

#define PKIG_SCREEN_320X480

#if defined(PKIG_SCREEN_240X320)
	#define SCREEN_WIDTH	240
	#define SCREEN_HEIGHT	320
	#define SCREEN_WIDTH_HALF	120
	#define SCREEN_HEIGHT_HALF	160
#elif defined(PKIG_SCREEN_240X400)	
	#define SCREEN_WIDTH	240
	#define SCREEN_HEIGHT	400
	#define SCREEN_WIDTH_HALF	120
	#define SCREEN_HEIGHT_HALF	200
#elif defined(PKIG_SCREEN_320X480)	
	#define SCREEN_WIDTH	320
	#define SCREEN_HEIGHT	480
	#define SCREEN_WIDTH_HALF	160
	#define SCREEN_HEIGHT_HALF	240
	#define RETURN_BUTTON_X 19
	#define RETURN_BUTTON_Y 13
	#define RETURN_BUTTON_W 50
	#define RETURN_BUTTON_H 37
	// ��ǰ��Ļ�ֱ�������
	#define CURR_SCREEN_TYPE	0
	// ˮ�����ΰ뾶
	#define WATER_RADIUS	3.0f
	// ˮ�����ˮ�����ΰ뾶
	#define SPRAY_RADIUS	5.0f
	// ˮ�ε���ϵ��
	#define WATER_E 0.0001f
	// ˮ��Ħ��ϵ��
	#define WATER_U 0.00001f
	// ��������ϵ��
	#define SHAPE_E 0.0001f
	// ����Ħ��ϵ��
	#define SHAPE_U 0.0001f
	// ʯͷ����ֱ�ߺ��
	#define ROCK_SEG_R	4.0f
	// ԡ������ֱ�ߺ��
	#define BATH_SEG_R	4.0f
	//��������ֱ�ߺ��
	#define RECT_SEG_R	4.0f

//	extern iS16 RectSegR[15];
//	extern iS16 RockSegR[15];
//	extern iS16 BathSegR[15];

//�ؿ����߹���δ���ŵ���ʾ����ʱ��
#define Prompt_Time  2000
//�ؿ����߹���δ���ŵ���ʾ��������
#define PromptWord_X 64
#define PromptWord_Y 186
#define PromptWord_W 193
#define PromptWord_H 25
//�ؿ����߹���δ���ŵ���ʾ������
#define PromptFrame_X 30
#define PromptFrame_Y 111
#define PromptFrame_W 256
#define PromptFrame_H 256

#define SideLength 10

// ���ӵ�����Լ������
// ����ɾ��
#define SHAPE_TYPE_NONDELETABLE	0
// ����ɾ��
#define SHAPE_TYPE_DELETABLE	1
// ��ɫ����
#define SHAPE_TYPE_ORGAN_RED	2
// ��ɫ����
#define SHAPE_TYPE_ORGAN_BLUE	3
// ��ɫ����
#define SHAPE_TYPE_ORGAN_GREEN	4
// �����Ѿ�����
#define SHAPE_TYPE_UPDATA		5
// �ؿ���ʼʱ��ʾ�ı���ʱ��
#define PromptShowTime	3000

// ����������и������������
//��
#define WORD_SPACE	0X00
// ���
#define WORD_MUD	0X01
//��ͱ߽�
#define MUD_EDGE	0X04
// ʯͷ
#define WORD_ROCK	0X02
//ʯͷ�߽�
#define ROCK_EDGE	0XF0
// ����
#define WORD_ALGAE	0X08
// ��������
#define ALGAE_ADD	0X18
// ������Ƶĺ���
#define ALGAE_NOSHOW	0XF8


#endif

#define MAX_SCREEN_TYPE	3

#define SHAPE_TYPE_SPACE	0
#define SHAPE_TYPE_MUD		1

typedef enum
{
	// ��
	GAME_STATE_IDLE = 0,
	// ����
	GAME_STATE_START,
	// ������
	GAME_STATE_MAIN,
	// ��Ϸģʽѡ��
	GAME_STATE_MODE,
	// ��Ϸ��
	GAME_STATE_PLAY,
	// ����
	GAME_STATE_SET,
	// �˳�
	GAME_STATE_EXIT

}mwGameState;

#define MW_CONTAIN_PATH (L"WheresMyWater\\wmw.contain")
#define MW_IMAGERE_PATH (L"WheresMyWater\\wmw.re")
#define MW_DATA_PATH (L"WheresMyWater\\GameData.re")

#define WORD_GRAVITY_X	0
#define WORD_GRAVITY_Y	1000

// ����ָ��
extern cpSpace *mwSpace;
// ��Ļָ��
extern iU16* mwScreenBuffer;
// ��������
extern iHANDLE mwKeyQueue;
// ��õİ�������
extern LLPInputStruct mwKeyData;
// ͼƬ�������
extern iHANDLE mwContainer;
// ��Ϸ��һ��״̬�����
extern mwGameState CurrGameState;
// Ӧ�ó��� ID
//extern iS32 AppID;

#define WaterSpray_MAX	40
#define WaterSpray_MIN	20

// ��ǰ��Ϸ��ˮ������
extern iU32 CurrTotalWaterNum;
// �ͷ�������ͷ��ˮ�ı��
extern iU32 WaterSprayFlag;

// Ѽ����Ϣ
typedef struct DuckData
{
	// Ѽ���Ѿ���ˮ����Ĵ���
	iU8 WaterNum;
	// Ѽ���Ƿ񻹴��ڵı��
	iU8 DuckExist;
	// Ѽ����һ�α�ˮ�����ʱ��
	iU32 OldRushTime;
	// Ѽ�ӵ����������
	iRECT Rect;
}DuckData;

// Ѽ�ӹ�����
typedef struct DuckManage
{
	// ��Ѽ������
	iU8 TotalDuckNum;
	// ʣ��Ѽ������
	iU8 ResidueDuckNum;
	//  Ѽ������
	DuckData * DuckMess;
}DuckManage;

//��һ�������£��̶������ڵ�ˮ���ٶȺ㶨
typedef struct SpeedKeep
{
	// �Ƿ�ʼ���ٵı��
	iU8	KeepSpeedFlag;
	// X �����ٶ�
	iS16 SpeedX;
	// Y�����ٶ�
	iS16 SpeedY;
	// Xλ��
	iS16 MoveX;
	// Yλ��
	iS16 MoveY;
	// �ٶȺ㶨������
	iRECT Rect;
}SpeedKeep;

// �������������
typedef struct SpeedKeepManage
{
	// ������������
	iU8 TotalSpeedKeepNum;
	// ��ǰ��ĺ�����������
	iU8 ActiveSpeedKeepNum;
	//  Ѽ������
	SpeedKeep * SpeedKeepMess;
}SpeedKeepManage;

#define SpeedKeepNum 	3

//�������� ����
extern SpeedKeep SpeedKeepMess[SpeedKeepNum];
// �������������
extern SpeedKeepManage SpeedKeep_Manage;

// ����������Ҫ��ˮ�������
#define ORGAN_MAX_WATER	2
// ���ر�ˮ�����ʱ���γ����ʱ����
#define ORGAN_TIME_DELAY	300

// ��������
#define ORGAN_TYPE_RED		1
#define ORGAN_TYPE_BLUE		2
#define ORGAN_TYPE_GREEN	3
// ����״̬
#define ORGAN_STATE_SRC		1
#define ORGAN_STATE_MOVE	2
#define ORGAN_STATE_DES		3

// ���ط���ˮƽ
#define ORGAN_DIR_LEVEL		1
// ���ط���ֱ
#define ORGAN_DIR_VERTICAL		2

typedef struct OrganData
{
	// �������ͣ��ֺ���������
	iU8 OrganType;
	// ���ص�ǰ״̬���ֳ�ʼ���ƶ����ƶ�ֹͣ����
	iU8 OrgneState;
	// �����Ѿ���ˮ����Ĵ���
	iU8 WaterNum;
	// ���ط�����ˮƽ�ʹ�ֱ֮��
	iU8 Direction;
	// ����������X�����ƶ�������
	iS16 OrganMulX;
	// ����������Y�����ƶ�������
	iS16 OrganMulY;
	// �����ϴα�ˮ�����ʱ��
	iU32 OldTime;
	// �������ص�����
	iRECT KeyRect;
	// ����δ����ʱԭʼ����
	iRECT OrganStartRect;
	// ����������ֹͣ����
	iRECT OrganEndRect;
	// ������ǰλ��
	iRECT OrganCurrRect;
}OrganData;

// ���ع�����
typedef struct OrganManage
{
	// �ܻ�������
	iU8 TotalOrganNum;
	// ʣ��ɻ�ؿ�����
	iU8 ResidueOrganNum;
	//  ��������
	OrganData* OrganMess;
}OrganManage;


// Ѽ�Ӷ�ˮ�������Сʱ����
#define DUCK_RUSH_DELAY_TIME 300
// Ѽ����౭ˮ�������
#define DUCK_MAX_RUSH_NUM	2
//ÿһ��Ѽ�Ӹ���
#define DUCK_NUM	3
// Ѽ������
extern DuckData DuckMess[DUCK_NUM];
// Ѽ�ӹ�����
extern DuckManage Duck_Manage;

// ˮ�ξ���ˮ�ܺ����겻��
#define PipeOutX_HOLD	0X10FF
#define PipeOutY_HOLD	0X11FF

// ˮ�ξ���һЩת��ˮ�ܺ���ٶ���ʧ
#define PipeSpeedWeight	0.80f

// ˮ�ξ���ˮ�κ�XY������ٶȷֱ𲻱䡢���ھ���ǰ��Y,����0,ȡX��,ȡY��
#define PipeSpeedX_HOLD	0X12FF
#define PipeSpeedXFromY	0X13FF
#define PipeSpeedXZeor	0X14FF
#define PipeSpeedX_INYX	0X15FF
#define PipeSpeedX_INYY	0X16FF

#define PipeSpeedY_HOLD	0X17FF
#define PipeSpeedYFromX	0X18FF
#define PipeSpeedYZeor	0X19FF
#define PipeSpeedY_INYY	0X1AFF
#define PipeSpeedY_INYX	0X1BFF


// ˮ��������Ϣ
typedef struct PipeData
{
	// ˮ�ܵ�ǰ�Ƿ���Ч�ı��
	iU8 ValidityFlag;
	// ��ˮ������
	iRECT RectWaterIn;
	// ��ˮ������
	iS16 WaterOutX;
	iS16 WaterOutY;
	iS16 SpeedX;
	iS16 SpeedY;
}PipeData;

// ˮ�ܹ�����
typedef struct PipeManage
{
	// ��ǰˮ������
	iU8 PipeNum;
	// ˮ�ܾ�����Ϣ
	PipeData * Data;
}PipeManage;

// ������Ҫ��ˮ����
#define WIN_WATER	10
// ˮ���������
#define MAX_PIPE	7
// �����������
#define MAX_ORGAN	3
// ˮ�ܾ�����Ϣ
extern PipeData PipeMess[MAX_PIPE];
// ˮ�ܹ�����
extern PipeManage Pipe_Manage;
// ԡ��������ˮ������
extern iS16 WaterInBathtub;
// ���ʱ�佱���ķ���
extern iS16 CurrTimeWin;
// ���Ѽ�ӽ����ķ���
extern iS16 CurrDuckWin;
// �����ˮ�����ķ���
extern iS16 CurrWaterWin;
// �ؿ���õ��ܷ�
extern iS16 CurrTotalWin;
// Ѽ���Ƿ���ٵı��
extern iU8 DuckResidueFlag;
// ��Ļ��ʱBuff��Ҫ���µı��
extern iU8 TempScreenUpdataFlag;
// ÿ��������ˮ������
//extern iS8 GriddingWaterNum[SCREEN_HEIGHT/SideLength][SCREEN_WIDTH/SideLength];

// ѡ��ʱ�ı�����������
#define MW_SOUND_NAME_CHOOSE	(L"WheresMyWater\\audio\\SoundChoose.wav")
// ѡ��ʱ�ı����������ֳ���
#define MW_SOUND_LENGTH_CHOOSE	56

// ��ʤʱ�ı�����������
#define MW_SOUND_NAME_WIN	(L"WheresMyWater\\audio\\SoundWin.wav")
// ��ʤʱ�ı����������ֳ���
#define MW_SOUND_LENGTH_WIN	50
// �Ƿ��������ĺ꿪��
#define SOUND_NEED	1
// ѡ��������Ƿ��ڲ��ŵı��
extern iU8 SoundChoosePlay;
// ʤ���������Ƿ��ڲ��ŵı��
extern iU8 SoundWinPlay;

#define ANIMATION_MAX_FRAME	15
//ͼƬ�����ṹ
typedef struct AnimationStr
{
	// ͼƬ���������ļ����
	iHANDLE Container;
	// ����ͼƬ��ID����
	iU16 ImageId[ANIMATION_MAX_FRAME];
	// ͼƬ����
	iS16 ImageWidth;
	// ͼƬ�߶�
	iS16 ImageHeight;
	// ������һ֡��ʱ��
	iU32 OldPlayTime;
	// ��ǰ���ŵ�֡��
	iS16 CurrPlayFrame;
	// ͼƬ��֡��
	iS16 ImageTotalFrame;
	// ��֡�������ʱ����
	iU32 FrameTimeMul;
	// ����һ֡��ͼƬ�߶�
	iU32 FrameHeight;
	// ͼƬ��ʾ��Ŀ�ĵ�����
	iRECT DesRect;
	
}AnimationStr;

// i51 ����ָ��ṹ
extern i51Public_struct *pfunc;

extern iBOOL mwFillCircle( iS32 X, iS32 Y, iU32 R, iCOLOR Color);
extern iBOOL DrawWaterDrop(cpBody *body, cpCircleShape *circle, iCOLOR Color);
extern iBOOL mwPublicAnimation( AnimationStr * AnimationMess );
extern iBOOL mwPublicAnimationEx( AnimationStr * AnimationMess );
extern iBOOL mwPublicDrawPrompt( iU32 DisPlayTime, iU32 StartTime, iU32 DisplayID );

#endif  /* i51Public.h */
