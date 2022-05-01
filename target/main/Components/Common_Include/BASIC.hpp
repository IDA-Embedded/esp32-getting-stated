/*
 * BASIC.hpp
 *
 *  Created on: May 22, 2020
 *      Author: nikolaj
 */
/**
 * @brief header file to interchange between UnitTestMode, ESP32 and RPI.
 *        Macro definition decides what state the system is in.
 */

#ifndef BPS_INCLUDE_BASIC_HPP_
#define BPS_INCLUDE_BASIC_HPP_

#ifdef __ESP32__

#include "sdkconfig.h"
#include <driver/gpio.h>
#include <esp_err.h>
#include <esp_log.h>
#define LOG_PRINT_INFO(tag, format, ...) \
	ESP_LOG_LEVEL_LOCAL(ESP_LOG_INFO, tag, format, ##__VA_ARGS__)
#define LOG_PRINT_ERROR(tag, format, ...) \
	ESP_LOG_LEVEL_LOCAL(ESP_LOG_ERROR, tag, format, ##__VA_ARGS__)
//#define   LOG_PRINT_ERROR( tag, format, ... )         (ESP_LOGE)
#else
#define LOG_PRINT_INFO(LOG_TAG, str) (printf("%s:: %s \n", LOG_TAG, str))
#define LOG_PRINT_ERROR(LOG_TAG, str, str2) (printf("%s:: %s -> %s \n", LOG_TAG, str, str2))
#endif

#ifdef __ESP32__
#define GPIO_PIN gpio_num_t
#define ADC_PIN adc1_channel_t
#else
#define GPIO_PIN uint16_t
#define ADC_PIN uint16_t
#endif
#endif /* BPS_INCLUDE_BASIC_HPP_ */
