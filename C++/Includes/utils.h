/* Définition des masques */
#define mBitsSet(f,m)			((f)|=(m))
#define mBitsClr(f,m)			((f)&=(~(m)))
#define mBitsTgl(f,m)			((f)^=(m))
#define mBitsMsk(f,m)			((f)& (m))
#define mIsBitsSet(f,m)			(((f)&(m))==(m))
#define mIsBitsClr(f,m)			(((~(f))&(m))==(m))

