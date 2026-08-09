#pragma once

void CRC32_UpdateChecksum(unsigned int& checksum, const void* data, int length);
void CRC32_FinishChecksum(unsigned int& checksum);
unsigned int CRC32_BlockChecksum(const void* data, int length);
