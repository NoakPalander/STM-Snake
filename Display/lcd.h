#ifndef LCD_H
#define LCD_H

// Initializes the LCD screen
__attribute__((naked))
void lcd_init(void);

// Clears the LCD screen
__attribute__((naked))
void lcd_clear(void);

// Sets a pixel on the LCD display
__attribute__((naked))
void lcd_set_pixel(int x, int y);

// Clears a pixel on the LCD display
__attribute__((naked))
void lcd_clear_pixel(int x, int y);

#endif // !LCD_H