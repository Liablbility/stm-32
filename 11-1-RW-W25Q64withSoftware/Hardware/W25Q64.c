#include "stm32f10x.h"                  // Device header
#include "MySPI.h"
#include "W25Q64_Ins.h"

void W25Q64_Init(void)
{
	MySPI_Init();
}

void W25Q64_ReadID(uint8_t *MID,uint16_t *DID)
{
	MySPI_Start();
	MySPI_ExchangeByte(W25Q64_JEDEC_ID);
	*MID = MySPI_ExchangeByte(W25Q64_DUMMY_BYTE	);
	*DID = MySPI_ExchangeByte(W25Q64_DUMMY_BYTE	);
	*DID <<= 8;
	*DID |= MySPI_ExchangeByte(W25Q64_DUMMY_BYTE);
	MySPI_Stop();
}

void W25Q64_WriteEnable(void)
{
	MySPI_Start();
	MySPI_ExchangeByte(W25Q64_WRITE_ENABLE);
	MySPI_Stop();
}

void W25Q64_WaitBusy(void)
{
	uint32_t timeout = 100000;
	MySPI_Start();
	MySPI_ExchangeByte(W25Q64_READ_STATUS_REGISTER_1);
	while((MySPI_ExchangeByte(W25Q64_DUMMY_BYTE)&0x01) == 1)
	{
		if(--timeout == 0)
			break;
	}
	MySPI_Stop();
}

void W25Q64_PageProgram(uint32_t Adress,uint8_t *DataArray,uint16_t Count)
{
	uint16_t i;
	
	W25Q64_WriteEnable();
	
	MySPI_Start();
	MySPI_ExchangeByte(W25Q64_PAGE_PROGRAM);
	MySPI_ExchangeByte(Adress>>16);
	MySPI_ExchangeByte(Adress>>8);
	MySPI_ExchangeByte(Adress);
	for(i = 0; i < Count; i++)
	{
		MySPI_ExchangeByte(DataArray[i]);
	}
	MySPI_Stop();
	W25Q64_WaitBusy();
}

void W25Q64_SectorErase(uint32_t Adress)
{
	W25Q64_WriteEnable();
	MySPI_Start();
	MySPI_ExchangeByte(W25Q64_SECTOR_ERASE_4KB);
	MySPI_ExchangeByte(Adress>>16);
	MySPI_ExchangeByte(Adress>>8);
	MySPI_ExchangeByte(Adress);
	MySPI_Stop();
	W25Q64_WaitBusy();
}

void W25Q64_DataRead(uint32_t Adress,uint8_t *DataArray,uint16_t Count)
{
	uint16_t i;
	MySPI_Start();
	MySPI_ExchangeByte(W25Q64_READ_DATA);
	MySPI_ExchangeByte(Adress>>16);
	MySPI_ExchangeByte(Adress>>8);
	MySPI_ExchangeByte(Adress);
	for(i = 0; i < Count; i++)
	{
		DataArray[i] = MySPI_ExchangeByte(W25Q64_DUMMY_BYTE);
	}
	MySPI_Stop();
}
