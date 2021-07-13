/*  crc.h
 *  Adem YILDIZ
 *  This header file contains the standards.
 */

#ifndef _crc_h
#define _crc_h

#define FALSE 0
#define TRUE 1

#define CRC_CCITT // this is a CRC standard
#if defined(CRC_CCITT)
typedef unsigned short crc;
// following list is all about the standard i used
#define CRC_NAME			"CRC-CCITT"
#define POLYNOMIAL			0x1021
#define INITIAL_REMAINDER	0xFFFF
#define FINAL_XOR_VALUE		0x0000
#define REFLECT_DATA		FALSE
#define REFLECT_REMAINDER	FALSE
#define CHECK_VALUE			0x29B1

void crcInit(void);
crc _crc_(unsigned char const message[], int nBytes);

#endif // CRC_H
#endif
