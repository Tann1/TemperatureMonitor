#pragma once

#define DEFAULT_SLAVE_ADDR 0x27
#define ENABLE_BIT 0x04 

// Register select                  Table.1 HD44780U
#define COMMAND_REG     0x00
#define READ_BF_AC      0x02
#define DATA_WRITE_REG  0x01
#define DATA_READ_REG   0X03


// Cursor Shifts                    Table.7 HD44780U
#define CURSOR_SHIFT_LEFT   0x10
#define CURSOR_SHIFT_RIGHT  0X14

// Common Instructions
#define CLEAR_DISPLAY   0X01
#define RETURN_HOME     0x02




