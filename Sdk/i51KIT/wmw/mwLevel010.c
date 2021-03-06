
#include "mwLevelPublic.h"

#if defined(PKIG_SCREEN_240X320)
#elif defined(PKIG_SCREEN_240X400)	
#elif defined(PKIG_SCREEN_320X480)	
#endif

iBOOL mwInitLevel010( void )
{

	iBody*body;//, *staticBody = &(mwSpace->staticBody);
	iShape *shape;
	iS32 radius = WATER_RADIUS;
	iS32 i=0,j=0;
	iVECT pos;
	
	mwInitSpace(CurrLevelNum);	

	for( i=0; i<3; i++){
		for( j=0; j<10; j++){
			iVectInit2(&pos,(j)*8*COORDINATE_RATE+85*COORDINATE_RATE,(i)*8*COORDINATE_RATE+35*COORDINATE_RATE);
			body = i51KitP2CreateBody(mwSpace,&pos, MASS_WATER);
			iVectInit2(&(body->V),0,0);
			iVectInit2(&(body->MAX_V),WATER_MAX_SPEED,WATER_MAX_SPEED);
			shape = i51KitP2CreateShapeCircle(mwSpace, body, radius, &pos);
		}
	}
	mwLevelWordInit(CurrLevelNum);
	mwLevelDuckInit(CurrLevelNum);
	mwLevelPipeInit(CurrLevelNum);
	mwLevelWaitInit(CurrLevelNum);

	mwLevelDrawBKwall();
	i51KitG2DrawImage(mwContainer, MudLevel010, iNULL, iNULL);
	i51KitG2DrawImage(mwContainer, RockLevel010, iNULL, iNULL);

	mwLevelDrawPause();
	mwLevelDrawRestart();
	mwLevelAlgaeInit(CurrLevelNum);
	mwLevelOrganInit(CurrLevelNum);

    i51AdeStdMemcpy16( (void *)TempScreenBuf, (void *)mwScreenBuffer, SCREEN_HEIGHT*SCREEN_WIDTH*2);
	mwLevelSpeedKeepInit(CurrLevelNum);
	mwTempScreenBufUpdate(CurrLevelNum);

	mwLevelDrawDuck();
//	mwLevelDrawOrgan();
	TimeLevelStart = i51AdeOsGetTick();
	return iTRUE;
}

iBOOL mwRunLevel010( void )
{

	iU16 PenDownX = 0;
	iU16 PenDownY = 0;

	i51AdeStdMemcpy16( (void *)(mwScreenBuffer),
			(void *)(&TempScreenBuf[0][0]), 
			SCREEN_WIDTH*SCREEN_HEIGHT*2);

 	mwPublicAnimation(&CrocodileWait);
	mwLevelDrawDuck();
	
	cpWordDraw();
	if( TempScreenUpdataFlag )
	{
		TempScreenUpdataFlag = iFALSE;
		mwTempScreenBufUpdate(CurrLevelNum);
		cpWordDraw();
	}

	if(	OrganMess[0].OrgneState != ORGAN_STATE_DES)
	{
		OrganMess[0].OrganType = SHAPE_TYPE_ORGAN_RED;
	}
	if(	OrganMess[1].OrgneState != ORGAN_STATE_DES)
	{
		OrganMess[1].OrganType = SHAPE_TYPE_ORGAN_GREEN;
	}
	if(	OrganMess[2].OrgneState != ORGAN_STATE_DES)
	{
		OrganMess[2].OrganType = SHAPE_TYPE_ORGAN_BLUE;
	}
//	mwLevelDrawOrgan();
	

 	
	TimeLevelCurr= i51AdeOsGetTick();
	if( TimeLevelCurr- TimeLevelStart < PromptShowTime )
	{
		mwLevelDrawPrompt(CurrLevelNum);
	}

	if(mwKeyData.type==LLP_PEN_INPUT&& mwKeyData.u.pen.type==i51_MSG_PADDOWN )
	{
		PenDownX = mwKeyData.u.pen.x;
		PenDownY = mwKeyData.u.pen.y;

		if(mwLevelPressRestart(PenDownX, PenDownY))
		{
			CurrLevelState = MW_LEVEL_INIT;
		}

		else if( mwLevelPressPause(PenDownX, PenDownY))
		{
			CurrLevelState = MW_LEVEL_PAUSE;
			mwWordPause = iTRUE;
		}
	}

	return iTRUE;
	
}





