/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define SOPT5_UART0TXSRC_UART_TX 0x00u /*!<@brief UART 0 transmit data source select: UART0_TX pin */

/*! @name PORTB16 (number 62), U7[4]/UART0_RX_TGTMCU
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_INITPINS_DEBUG_UART_RX_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN 16U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_DEBUG_UART_RX_PIN_MASK (1U << 16U)      /*!<@brief PORT pin mask */
                                                               /* @} */

/*! @name PORTB17 (number 63), U10[1]/UART0_TX_TGTMCU
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_INITPINS_DEBUG_UART_TX_PORT PORTB                /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN 17U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_DEBUG_UART_TX_PIN_MASK (1U << 17U)      /*!<@brief PORT pin mask */
                                                               /* @} */

/*! @name PORTD7 (number 100), D4[4]/LEDRGB_GREEN
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LED_GREEN_GPIO GPIOD               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LED_GREEN_GPIO_PIN_MASK (1U << 7U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITPINS_LED_GREEN_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LED_GREEN_PIN 7U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LED_GREEN_PIN_MASK (1U << 7U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PORTD1 (number 94), D4[1]/LEDRGB_RED
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LED_RED_GPIO GPIOD               /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LED_RED_GPIO_PIN_MASK (1U << 1U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITPINS_LED_RED_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LED_RED_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LED_RED_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*! @name PORTE25 (number 32), D4[3]/LEDRGB_BLUE
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LED_BLUE_GPIO GPIOE                /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LED_BLUE_GPIO_PIN_MASK (1U << 25U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_INITPINS_LED_BLUE_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LED_BLUE_PIN 25U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LED_BLUE_PIN_MASK (1U << 25U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
