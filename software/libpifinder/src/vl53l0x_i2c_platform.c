/*
 * COPYRIGHT (C) STMicroelectronics 2014. All rights reserved.
 *
 * This software is the confidential and proprietary information of
 * STMicroelectronics ("Confidential Information").  You shall not
 * disclose such Confidential Information and shall use it only in
 * accordance with the terms of the license agreement you entered into
 * with STMicroelectronics
 *
 * Programming Golden Rule: Keep it Simple!
 *
 */

/**
 * @file   VL53L0X_platform.h
 * @brief  Function prototype definitions for Ewok Platform layer.
 *
 */


// This is required for usleep to be defined
#define _BSD_SOURCE
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include "vl53l0x_i2c_platform.h"


#ifdef __cplusplus
extern "C" {
#endif


#define VL53L0X_I2C_ADDRESS     0x29

int _i2c = -1;

/**
 * @brief  Initialise platform comms.
 *
 * @param  comms_type      - selects between I2C and SPI
 * @param  comms_speed_khz - unsigned short containing the I2C speed in kHz
 *
 * @return status - status 0 = ok, 1 = error
 *
 */
int32_t VL53L0X_comms_initialise(uint8_t  comms_type, uint16_t comms_speed_khz)
{
    const char * devName = "/dev/i2c-1";

    // Open up the I2C bus
    _i2c = open(devName, O_RDWR);
    if (_i2c == -1)
    {
        perror(devName);
        exit(1);
    }
    else
    {
        printf("Successfully opened I2C interface: %d\n", _i2c);
    }

    if (ioctl(_i2c, I2C_SLAVE, VL53L0X_I2C_ADDRESS) < 0)
    {
        perror("Failed to acquire bus access and/or talk to slave");
        exit(1);
    }
}

/**
 * @brief  Close platform comms.
 *
 * @return status - status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_comms_close(void)
{
    if (_i2c > 0)
    {
        close(_i2c);
    }
}

/**
 * @brief  Cycle Power to Device
 *
 * @return status - status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_cycle_power(void)
{

}


/**
 * @brief Writes the supplied byte buffer to the device
 *
 * Wrapper for SystemVerilog Write Multi task
 *
 * @code
 *
 * Example:
 *
 * uint8_t *spad_enables;
 *
 * int status = VL53L0X_write_multi(RET_SPAD_EN_0, spad_enables, 36);
 *
 * @endcode
 *
 * @param  address - uint8_t device address value
 * @param  index - uint8_t register index value
 * @param  pdata - pointer to uint8_t buffer containing the data to be written
 * @param  count - number of bytes in the supplied byte buffer
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_write_multi(uint8_t address, uint8_t index, uint8_t  *pdata, int32_t count)
{
    #define BUF_SIZE    256
    uint8_t buf[BUF_SIZE];
    if (count > (BUF_SIZE - 1))
    {
        printf("Write too large\n");
        return 1;
    }

    //printf("VL53L0X_write_multi handle/index: %d/%d\n", (int)_i2c, (int)index);

    buf[0] = index;
    for (uint32_t i = 0; i < count; ++i)
    {
        buf[i+1] = pdata[i];
    }

    if (write(_i2c, buf, count + 1) != (count + 1))
    {
        perror("Failed to write to the i2c bus");
        exit(1);
    }

    return 0;
}


/**
 * @brief  Reads the requested number of bytes from the device
 *
 * Wrapper for SystemVerilog Read Multi task
 *
 * @code
 *
 * Example:
 *
 * uint8_t buffer[COMMS_BUFFER_SIZE];
 *
 * int status = status  = VL53L0X_read_multi(DEVICE_ID, buffer, 2)
 *
 * @endcode
 *
 * @param  address - uint8_t device address value
 * @param  index - uint8_t register index value
 * @param  pdata - pointer to the uint8_t buffer to store read data
 * @param  count - number of uint8_t's to read
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_read_multi(uint8_t address,  uint8_t index, uint8_t  *pdata, int32_t count)
{
    //printf("VL53L0X_read_multi address/index: %d/%d\n", (int)address, (int)index);

    uint8_t buf[2];

    buf[0] = index;

    if (write(_i2c, buf, 1) != 1)
    {
        perror("Failed to write to the i2c bus");
        exit(1);
    }

    if (read(_i2c, pdata, count) != count)
    {
        perror("Failed to write to the i2c bus");
        exit(1);
    }
    return 0;

}


/**
 * @brief  Writes a single byte to the device
 *
 * Wrapper for SystemVerilog Write Byte task
 *
 * @code
 *
 * Example:
 *
 * uint8_t page_number = MAIN_SELECT_PAGE;
 *
 * int status = VL53L0X_write_byte(PAGE_SELECT, page_number);
 *
 * @endcode
 *
 * @param  address - uint8_t device address value
 * @param  index - uint8_t register index value
 * @param  data  - uint8_t data value to write
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_write_byte(uint8_t address,  uint8_t index, uint8_t   data)
{
    return VL53L0X_write_multi(address, index, &data, 1);
}


/**
 * @brief  Writes a single word (16-bit unsigned) to the device
 *
 * Manages the big-endian nature of the device (first byte written is the MS byte).
 * Uses SystemVerilog Write Multi task.
 *
 * @code
 *
 * Example:
 *
 * uint16_t nvm_ctrl_pulse_width = 0x0004;
 *
 * int status = VL53L0X_write_word(NVM_CTRL__PULSE_WIDTH_MSB, nvm_ctrl_pulse_width);
 *
 * @endcode
 *
 * @param  address - uint8_t device address value
 * @param  index - uint8_t register index value
 * @param  data  - uin16_t data value write
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_write_word(uint8_t address,  uint8_t index, uint16_t  data)
{
    uint8_t buf[2];
    buf[0] = (data >>  8) & 0xFF;
    buf[1] = (data      ) & 0xFF;
    return VL53L0X_write_multi(address, index, (uint8_t*)buf, 2);
}


/**
 * @brief  Writes a single dword (32-bit unsigned) to the device
 *
 * Manages the big-endian nature of the device (first byte written is the MS byte).
 * Uses SystemVerilog Write Multi task.
 *
 * @code
 *
 * Example:
 *
 * uint32_t nvm_data = 0x0004;
 *
 * int status = VL53L0X_write_dword(NVM_CTRL__DATAIN_MMM, nvm_data);
 *
 * @endcode
 *
 * @param  address - uint8_t device address value
 * @param  index - uint8_t register index value
 * @param  data  - uint32_t data value to write
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_write_dword(uint8_t address, uint8_t index, uint32_t  data)
{
    uint8_t buf[4];
    buf[0] = (data >> 24) & 0xFF;
    buf[1] = (data >> 16) & 0xFF;
    buf[2] = (data >>  8) & 0xFF;
    buf[3] = (data      ) & 0xFF;
    return VL53L0X_write_multi(address, index, (uint8_t*)buf, 4);
}



/**
 * @brief  Reads a single byte from the device
 *
 * Uses SystemVerilog Read Byte task.
 *
 * @code
 *
 * Example:
 *
 * uint8_t device_status = 0;
 *
 * int status = VL53L0X_read_byte(STATUS, &device_status);
 *
 * @endcode
 *
 * @param  address - uint8_t device address value
 * @param  index  - uint8_t register index value
 * @param  pdata  - pointer to uint8_t data value
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_read_byte(uint8_t address,  uint8_t index, uint8_t  *pdata)
{
    return VL53L0X_read_multi(address, index, pdata, 1);
}


/**
 * @brief  Reads a single word (16-bit unsigned) from the device
 *
 * Manages the big-endian nature of the device (first byte read is the MS byte).
 * Uses SystemVerilog Read Multi task.
 *
 * @code
 *
 * Example:
 *
 * uint16_t timeout = 0;
 *
 * int status = VL53L0X_read_word(TIMEOUT_OVERALL_PERIODS_MSB, &timeout);
 *
 * @endcode
 *
 * @param  address - uint8_t device address value
 * @param  index  - uint8_t register index value
 * @param  pdata  - pointer to uint16_t data value
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_read_word(uint8_t address,  uint8_t index, uint16_t *pdata)
{
    uint8_t data[2];
    int result = VL53L0X_read_multi(address, index, (uint8_t*)data, 2);
    *pdata = (data[0] <<  8) |
             (data[1]      );
    return result;
}


/**
 * @brief  Reads a single dword (32-bit unsigned) from the device
 *
 * Manages the big-endian nature of the device (first byte read is the MS byte).
 * Uses SystemVerilog Read Multi task.
 *
 * @code
 *
 * Example:
 *
 * uint32_t range_1 = 0;
 *
 * int status = VL53L0X_read_dword(RANGE_1_MMM, &range_1);
 *
 * @endcode
 *
 * @param  address - uint8_t device address value
 * @param  index - uint8_t register index value
 * @param  pdata - pointer to uint32_t data value
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_read_dword(uint8_t address, uint8_t index, uint32_t *pdata)
{
    uint8_t data[4];
    int result = VL53L0X_read_multi(address, index, (uint8_t*)data, 4);
    *pdata = (data[3]      ) |
             (data[2] <<  8) |
             (data[1] << 16) |
             (data[0] << 24);
    return result;
}


/**
 * @brief  Implements a programmable wait in us
 *
 * Wrapper for SystemVerilog Wait in micro seconds task
 *
 * @param  wait_us - integer wait in micro seconds
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_platform_wait_us(int32_t wait_us)
{
    usleep(wait_us);
    return 0;
}


/**
 * @brief  Implements a programmable wait in ms
 *
 * Wrapper for SystemVerilog Wait in milli seconds task
 *
 * @param  wait_ms - integer wait in milli seconds
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_wait_ms(int32_t wait_ms)
{
    usleep(wait_ms * 1000);
    return 0;
}


/**
 * @brief Set GPIO value
 *
 * @param  level  - input  level - either 0 or 1
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_set_gpio(uint8_t  level)
{
    printf("VL53L0X_set_gpio called\n");
    return 0;
}


/**
 * @brief Get GPIO value
 *
 * @param  plevel - uint8_t pointer to store GPIO level (0 or 1)
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_get_gpio(uint8_t *plevel)
{
    printf("VL53L0X_get_gpio called\n");
    return 0;
}

/**
 * @brief Release force on GPIO
 *
 * @return status - SystemVerilog status 0 = ok, 1 = error
 *
 */

int32_t VL53L0X_release_gpio(void)
{
    printf("VL53L0X_release_gpio called\n");
    return 0;
}



/**
* @brief Get the frequency of the timer used for ranging results time stamps
*
* @param[out] ptimer_freq_hz : pointer for timer frequency
*
* @return status : 0 = ok, 1 = error
*
*/

int32_t VL53L0X_get_timer_frequency(int32_t *ptimer_freq_hz)
{
    printf("VL53L0X_get_timer_frequency called\n");
    return 0;
}


/**
* @brief Get the timer value in units of timer_freq_hz (see VL53L0X_get_timestamp_frequency())
*
* @param[out] ptimer_count : pointer for timer count value
*
* @return status : 0 = ok, 1 = error
*
*/

int32_t VL53L0X_get_timer_value(int32_t *ptimer_count)
{
    printf("VL53L0X_get_timer_value called\n");
    return 0;
}






#ifdef __cplusplus
}
#endif


