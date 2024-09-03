#ifndef __W25Q64_H__
#define __W25Q64_H__

void W25Q64_Init(void);
void W25Q64_ReadID(uint8_t *MID,uint16_t *DID);

void W25Q64_WriteEnable(void);

void W25Q64_WaitBusy(void);

void W25Q64_PageProgram(uint32_t Adress,uint8_t *DataArray,uint16_t Count);

void W25Q64_SectorErase(uint32_t Adress);

void W25Q64_DataRead(uint32_t Adress,uint8_t *DataArray,uint16_t Count);

#endif
