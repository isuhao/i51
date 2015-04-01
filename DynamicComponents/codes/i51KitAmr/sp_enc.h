/*
 * ===================================================================
 *  TS 26.104
 *  R99   V3.4.0 2002-02
 *  REL-4 V4.3.0 2002-02
 *  3GPP AMR Floating-point Speech Codec
 * ===================================================================
 *
 */

/*
 * sp_enc.h
 *
 *
 * Project:
 *    AMR Floating-Point Codec
 *
 * Contains:
 *    Defines interface to AMR encoder
 *
 */
#ifndef _SP_ENC_H
#define _SP_ENC_H

//	Jelo Added 20120321
//#define FLT_MAX  3.40282347e+38F
//#define DBL_MAX  1.79769313486231571e+308
//#define LDBL_MAX 1.79769313486231571e+308L
//	Jelo Added Finished

/*
 * include files
 */
#include "typedef.h"

/*
 * definition of modes for encoder
 */
enum Mode { MR475 = 0,
            MR515,
            MR59,
            MR67,
            MR74,
            MR795,
            MR102,
            MR122,
            MRDTX
};

/*
 * Function prototypes
 */

/*
 * initialize one instance of the speech encoder
 * Stores pointer to filter status struct in *st. This pointer has to
 * be passed to Speech_Encode_Frame in each call.
 * returns 0 on success
 */
void *Speech_Encode_Frame_init (int dtx);
/*
 * reset speech encoder (i.e. set state memory to zero)
 * returns 0 on success
 */
int Speech_Encode_Frame_reset(void *st, int dtx);

/*
 * de-initialize speech encoder (i.e. free status struct)
 * stores NULL in *st
 */
void Speech_Encode_Frame_exit (void **st);

/*
 * Encodes one speech frame
 * Returns analysis parameters
 */
void Speech_Encode_Frame (void *st, enum Mode mode, short *newSpeech,
                   short *prm, enum Mode *usedMode);

#endif