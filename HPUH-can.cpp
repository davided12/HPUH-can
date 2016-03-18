/* HPUH-can library 

MIT license
written by Davide Tarantino
*/

#include "HPUH-can.h"
#include <SPI.h>
#include <mcp_can.h>

MCP_CAN CAN(SPI_CS_PIN);
boolean flagRecv;

void MCP2515_ISR() {
	flagRecv = true;
}

boolean HPUH::init() {
    if (CAN_OK != CAN.begin(CAN_1000KBPS)) {
		return false;
    } else {
		attachInterrupt(INTERR_ID, MCP2515_ISR, FALLING);
		return true;
	}
}

void HPUH::getData() {
    if(flagRecv) 
    {                                   // check if get data

        flagRecv = false;                   // clear flag

        // iterate over all pending messages
        // If either the bus is saturated or the MCU is busy,
        // both RX buffers may be in use and reading a single
        // message does not clear the IRQ conditon.
        
        while (CAN_MSGAVAIL == CAN.checkReceive())
        {

            unsigned long receivedId;
            
            // read data,  len: data length, buf: data buf
            CAN.readMsgBufID(&receivedId, NULL, buf);

			switch (receivedId) {
				case 0x100:
					rpm = combineBytes(buf[2], buf[3]);
					tps = (float) (combineBytes(buf[4], buf[5])) / 10;
				break;
				case 0x101:
					th2o = buf[0] - 40;
					tair = buf[1] - 40;
					toil = buf[2] - 40;
					vbb1 = (float) buf[3] * 0.0705;
					vbb2 = (float) buf[4] * 0.0705;
					vbb3 = (float) buf[5] * 0.0705;
				break;
				case 0x102:
					lambda1 = (float) buf[1] / 100;
					lambda2 = (float) buf[3] / 100;
				break;
				case 0x104:
					speed1 = (float) combineBytes(buf[0], buf[1]) / 100;
					speed2 = (float) combineBytes(buf[2], buf[3]) / 100;
				break;
			}
			
        }
    }

}

unsigned int HPUH::combineBytes(unsigned char low, unsigned char high) {
	return (high << 8) | low;
}
