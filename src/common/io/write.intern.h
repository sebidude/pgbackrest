/***********************************************************************************************************************************
IO Write Interface Internal
***********************************************************************************************************************************/
#ifndef COMMON_IO_WRITE_INTERN_H
#define COMMON_IO_WRITE_INTERN_H

#include "common/io/write.h"

/***********************************************************************************************************************************
Constructor
***********************************************************************************************************************************/
typedef struct IoWriteInterface
{
    void (*close)(void *driver);
    int (*handle)(const void *driver);
    void (*open)(void *driver);
    void (*write)(void *driver, const Buffer *buffer);
} IoWriteInterface;

#define ioWriteNewP(driver, ...)                                                                                                   \
    ioWriteNew(driver, (IoWriteInterface){__VA_ARGS__})

IoWrite *ioWriteNew(void *driver, IoWriteInterface interface);

/***********************************************************************************************************************************
Getters
***********************************************************************************************************************************/
void *ioWriteDriver(IoWrite *this);
const IoWriteInterface *ioWriteInterface(const IoWrite *this);

/***********************************************************************************************************************************
Macros for function logging
***********************************************************************************************************************************/
#define FUNCTION_LOG_IO_WRITE_INTERFACE_TYPE                                                                                       \
    IoWriteInterface
#define FUNCTION_LOG_IO_WRITE_INTERFACE_FORMAT(value, buffer, bufferSize)                                                          \
    objToLog(&value, "IoWriteInterface", buffer, bufferSize)

#endif
