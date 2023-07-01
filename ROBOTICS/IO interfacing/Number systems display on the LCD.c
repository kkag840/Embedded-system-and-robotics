/*! \mainpage Week-1 Experiment-3: Number systems display on the LCD
 *
 * @author     e-Yantra Team
 * @date       2020/01/31
 *
 * \subsection Aim
 * To represent the same numeral of up to 8-bits in different number systems on the inbuilt LCD and increment that number every 500 milliseconds loop through this infinitely
 *
 * \subsection Connections
 * Interrupt Switch 	:  PE7 				<br>
 * LCD Connections:								<br>
 *		 LCD Pins	  Micro-controller Pins     <br>
 *			  RS  --> PC0						<br>
 *			  RW  --> PC1						<br>
 *			  EN  --> PC2						<br>
 *			  DB7 --> PC7						<br>
 *			  DB6 --> PC6						<br>
 *			  DB5 --> PC5						<br>
 *			  DB4 --> PC4						<br>
 *
 */
#include <stdio.h>                       // Include necessary header files
#include "firebird_simulation.h"		// Header file included that contains macro definitions essential for Firebird V robot
#include <util/delay.h>					// Standard AVR Delay Library
#include "lcd.h"						// LCD Header file included that contains function definitions essential to deal with LCD

//------------------------------------- MACROS -----------------------------------------------------
// If any


//------------------------------------ FUNCTIONS ---------------------------------------------------

/**
 * @brief      Print the static wireframe of labels that will appear on the LCD.<br>
*		       
*  @details     This function demarcates zones for printing the numerals.<br>
 *  			In the subsequent functions you should print the numerals in the spaces (cells) reserved for them,<br>
*				2 cells (1,3) and (1,4) are reserved for the hex number (max FF)<br>
*				3 cells (1,8), (1,9) and (1,10) are reserved for the decimal number (max 255)<br>
*				3 cells (1,14), (1,15) and (1,16) are reserved for the octal number (max 377)<br>
*				8 cells (2,9) ... (2,16) are reserved for the binary number (max 11111111)
*/

//<< NOTE >>: You should not change this function in order to get the required output
void lcd_print_wireframe(void)
{	
	lcd_string(1,1,"H:   D:    O:   ");
	lcd_string(2,1,"Binary: ");
}

//------------------------------ << TODO >>: WRITE YOUR FUNCTIONS TO OUTPUT THE NUMBER IN DIFFERENT NUMBER SYSTEMS ------------------------------
/* << NOTE >>: You may format the number as a string and the use the appropriate function to display that string on the LCD
*		 Check out the function sprintf available in <stdio.h>, which you can read about here: http://www.cplusplus.com/reference/cstdio/sprintf/
*		 Think of combining it with format specifiers, which you can read about here: http://www.cplusplus.com/reference/cstdio/printf/
*/		

/**
 * @brief      Input the number, format it to the binary number system and print it onto the LCD
 *
 * @param[in]  row_num  The row number of the LCD
 * @param[in]  col_num  The col number of the LCD
 * @param[in]  num      The number to be printed
 */
void lcd_print_binary(unsigned char row_num, unsigned char col_num, unsigned char num)
{
   char binary[9];  // Buffer to store the binary representation (8 bits + null terminator)
   unsigned char mask = 0x80;  // Mask to extract each bit of the number

   // Convert the number to binary format
   for (int i = 0; i < 8; i++) {
	   binary[i] = (num & mask) ? '1' : '0';  // Check the current bit and set '1' or '0'
	   mask >>= 1;  // Shift the mask to the right
   }
   binary[8] = '\0';  // Add null terminator to the end of the binary string

   lcd_string(row_num, col_num, binary);  // Print the binary string on the LCD
   }

/**
 * @brief      Input the number, format it to the octal number system and print it onto the LCD
 *
 * @param[in]  row_num  The row number of the LCD
 * @param[in]  col_num  The col number of the LCD
 * @param[in]  num      The number to be printed
 */
void lcd_print_octal(unsigned char row_num, unsigned char col_num, unsigned char num)
{
    char octal[4];
    sprintf(octal, "%03o", num);
    lcd_string(row_num, col_num, octal);	
}

/**
 * @brief      Input the number, format it to the decimal number system and print it onto the LCD
 *
 * @param[in]  row_num  The row number of the LCD
 * @param[in]  col_num  The col number of the LCD
 * @param[in]  num      The number to be printed
 */
void lcd_print_decimal(unsigned char row_num, unsigned char col_num, unsigned char num)
{
    char decimal[4];
    sprintf(decimal, "%03d", num);
    lcd_string(row_num, col_num, decimal);	
}

/**
 * @brief      Input the number, format it to the hexadecimal number system and print it onto the LCD
 *
 * @param[in]  row_num  The row number of the LCD
 * @param[in]  col_num  The col number of the LCD
 * @param[in]  num      The number to be printed
 */
void lcd_print_hexadecimal(unsigned char row_num, unsigned char col_num, unsigned char num)
{
	    char hexadecimal[3];
	    sprintf(hexadecimal, "%02X", num);
	    lcd_string(row_num, col_num, hexadecimal);
}

//------------------------------ << TODO >>: EDIT THE MAIN FUNCTION BELOW------------------------------


/**
 * @brief      the main function, this function runs when your code is executed
 *
 * @details    Initialize the LCD, print the same numeral of up to 8-bits in different number systems on the inbuilt LCD and increment that numeral every 500 milliseconds loop through this infinitely.
 *
 * @return     0
 */
int main(void){
	
	
	lcd_port_config();					// Initialize the LCD port
	lcd_init();							// Initialize the LCD
	lcd_clear();						// Clear the LCD
	lcd_print_wireframe();				// Print wireframe on the LCD
	unsigned char counter = 0;

	//<< TODO >>: FILL THE BLANK FUNCTION PARAMETERS AS PER THE WIREFRAME RULES IN THE FOLLOWING LINES OF CODE
	while(1){
	        lcd_print_hexadecimal(1, 3, counter);  // Print hexadecimal characters on the LCD
	        lcd_print_decimal(1,8 , counter);       // Print decimal characters on the LCD
	        lcd_print_octal(1, 14, counter);         // Print octal characters on the LCD
	        lcd_print_binary(2, 9, counter);         // Print binary characters on the LCD
	        counter++;                              // Increment the counter
	        _delay_ms(500);
	}
}
